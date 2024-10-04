
#include <iostream>
#include <chrono>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include "matrix.h"
#define MatixARows 3
#define MatixAColumns 3
#define MatixBRows 3
#define MatixBColumns 3
#define PRODUCTS 5
// Размер очереди
const int QUEUE_SIZE = 10;
template<typename T> class threadsafe_queue
{
private:
    struct node
    {
        std::shared_ptr<T> data;
        std::unique_ptr<node> next;
    };
    std::mutex head_mutex;   //when change the head lock it.
    std::unique_ptr<node> head;
    std::mutex tail_mutex;   //when change the tail lock it.
    node* tail;
    std::condition_variable data_cond_pop;
    std::condition_variable data_cond_push;
    size_t size;
    node* get_tail()
    {
        std::lock_guard<std::mutex> tail_lock(tail_mutex);
        return tail;
    }

    std::unique_ptr<node> pop_head()
    {
        std::unique_ptr<node> old_head=std::move(head);
        head=std::move(old_head->next);
        --size;
        return old_head;
//        std::lock_guard<std::mutex> head_lock(head_mutex);
//        if(head.get()==get_tail())
//        {
//            return nullptr;
//        }
//        std::unique_ptr<node> old_head=std::move(head);
//        head=std::move(old_head->next);
//        return old_head;
    }
    std::unique_lock<std::mutex> wait_for_data(){
        std::unique_lock<std::mutex> head_lock(head_mutex);
        data_cond_pop.wait(head_lock,[&]{return head.get()!=get_tail();});
        return std::move(head_lock);
    }
    std::unique_ptr<node> wait_pop_head()
    {
        std::unique_lock<std::mutex> head_lock(wait_for_data());
        return pop_head();
    }
    std::unique_ptr<node> wait_pop_head(T& value)
    {
        std::unique_lock<std::mutex> head_lock(wait_for_data());
        value=std::move(*head->data);
        return pop_head();
    }

    std::unique_ptr<node> try_pop_head()
    {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if(head.get()==get_tail())
        {
            return std::unique_ptr<node>();
        }
        return pop_head();
    }
    std::unique_ptr<node> try_pop_head(T& value)
    {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if(head.get()==get_tail())
        {
            return std::unique_ptr<node>();
        }
        value=std::move(*head->data);
        return pop_head();
    }

public:

    threadsafe_queue():
            head(new node),tail(head.get())
    {}

    threadsafe_queue(const threadsafe_queue &other) = delete;
    threadsafe_queue &operator=(const threadsafe_queue &other) = delete;

    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_ptr<node> const old_head=wait_pop_head();
        if(old_head) data_cond_push.notify_one();
        return old_head->data;
    }
    void wait_and_pop(T& value) {
        std::unique_ptr<node> const old_head = wait_pop_head(value);
        if(old_head) data_cond_push.notify_one();
    }
    std::shared_ptr<T> try_pop()
    {
        std::unique_ptr<node> old_head=try_pop_head();
        if(old_head) data_cond_push.notify_one();
        return old_head?old_head->data:std::shared_ptr<T>();
    }
    bool try_pop(T& value)
    {
        std::unique_ptr<node> const old_head=try_pop_head(value);
        if(old_head) data_cond_push.notify_one();
        return old_head!= nullptr;
    }
    void empty()
    {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        return (head.get()==get_tail());
    }
    size_t size_queue() const
    {
        //std::lock_guard<std::mutex> head_lock(head_mutex);
        return size;
    }
//    std::shared_ptr<T> wait_and_pop()
//    {
//        auto predicate = [this]() -> bool {
//            bool test = head.get() != get_tail();
//            //std::this_thread::sleep_for(std::chrono::seconds(2));
//            return test;
//        };
//        std::unique_lock<std::mutex> head_lock(head_mutex);
//        bool result = data_cond.wait_for(head_lock, std::chrono::seconds(10), predicate); //#1
//        if (!result) {
//            std::cout << "Timeout occurred and queue is empty!\n";
//            std::terminate();
//        }
//        std::unique_ptr<node> old_head=std::move(head);
//        head=std::move(old_head->next);
//        return old_head->data;
//    }
//
//    std::shared_ptr<T> try_pop()
//    {
//        std::unique_ptr<node> old_head=pop_head();
//        return old_head?old_head->data:std::shared_ptr<T>();
//    }


//    void push(T new_value)
//    {
//        std::shared_ptr<T> new_data(
//                std::make_shared<T>(std::move(new_value)));
//        std::unique_ptr<node> p(new node);
//        node* const new_tail=p.get();
//        std::lock_guard<std::mutex> tail_lock(tail_mutex);
//        tail->data=new_data;
//        tail->next=std::move(p);
//        tail=new_tail;
//    }

    void push(T new_value)
    {
        std::shared_ptr<T> new_data(std::make_shared<T>(std::move(new_value)));
        std::unique_ptr<node> p(new node);
        {
            std::unique_lock<std::mutex> tail_lock(tail_mutex);
            data_cond_push.wait(tail_lock, [&] { return size < PRODUCTS; });
            tail->data=std::move(new_data);
            node* const new_tail=p.get();
            tail->next=std::move(p);
            tail=new_tail;
            ++size;
            tail_lock.unlock();
        }
        data_cond_pop.notify_one();
    }
};

static threadsafe_queue<std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>> queue;

void producer(int id) {
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
    for(int i = 0;i<PRODUCTS;i++){
        std::vector<std::vector<int>> dataMatrixA = generateMatrix(MatixARows, MatixAColumns);
        std::vector<std::vector<int>> dataMatrixB = generateMatrix(MatixBRows, MatixBColumns);
        print(dataMatrixA);
        print(dataMatrixB);
        queue.push(std::pair(dataMatrixA,dataMatrixB));
    }

}

void consumer(int id) {
    for(int i = 0;i<PRODUCTS;i++){
        std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> data = *queue.wait_and_pop();
        std::vector<std::vector<int>> matrixResult;
        multiplication(data.first, data.second, &matrixResult);
        std::string name = "../results/matrix"+std::to_string(queue.size_queue())+".txt";
        writeToFile(matrixResult,name);
        std::cout << "Consumer: got " << id << std::endl;

    }

}


int main() {
    // Количество производителей и потребителей
    int numProducers = 2;
    int numConsumers = 2;

    // Запускаем производителей
    std::vector<std::thread> producers;
    for (int i = 0; i < numProducers; ++i) {
        producers.emplace_back(producer, i + 1);
    }

    // Запускаем потребителей
    std::vector<std::thread> consumers;
    for (int i = 0; i < numConsumers; ++i) {
        consumers.emplace_back(consumer, i + 1);
    }

    // Ждем завершения всех потоков
    for (auto &producer: producers) {
        producer.join();
    }
    for (auto &consumer: consumers) {
        consumer.join();
    }
    std::cout << "End";
}
