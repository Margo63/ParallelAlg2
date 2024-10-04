#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono> // Для задержки
#include "matrix.h"

#define MatixARows 3
#define MatixAColumns 3
#define MatixBRows 3
#define MatixBColumns 3
#define PRODUCTS 5
// Размер очереди
const int QUEUE_SIZE = 10;

// Очередь и мьютекс
std::queue<std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>> dataQueue;
std::mutex queueMutex;
std::condition_variable dataCondition;
int i = 0;

// Функция производителя
void producer(int id) {
    while (i < PRODUCTS) {
        //std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Симуляция работы
        //int data = rand() % 100; // Генерация данных


        //std::unique_lock<std::mutex> lock(queueMutex);
        // Ждем, пока есть место в очереди
//        while (dataQueue.size() >= QUEUE_SIZE) {
//            dataCondition.wait(lock);
//        }
        //dataCondition.wait(lock,[]{return dataQueue.size()>=QUEUE_SIZE;});
        if(dataQueue.size()<=QUEUE_SIZE){
            std::vector<std::vector<int>> dataMatrixA = generateMatrix(MatixARows, MatixAColumns);
            std::vector<std::vector<int>> dataMatrixB = generateMatrix(MatixBRows, MatixBColumns);

            std::lock_guard<std::mutex> lk ( queueMutex ) ;

            dataQueue.push(std::pair(dataMatrixA, dataMatrixB));
            std::cout << "Producer " << id << " produced: " << std::endl;


            // Уведомляем потребителей, что данные готовые
            dataCondition.notify_all();
        }

        //i++;
    }
}

// Функция потребителя
void consumer(int id) {
    while (i < PRODUCTS) {
        std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> data;


        std::unique_lock<std::mutex> lock(queueMutex);
        // Ждем, пока в очереди есть данные
        while (dataQueue.empty()) {
            dataCondition.wait(lock);
        }
        data = dataQueue.front();
        dataQueue.pop();
        std::cout << "Consumer " << id << " consumed: " << std::endl;
        //print(data.first);
        std::vector<std::vector<int>> matrixResult;
        multiplication(data.first, data.second, &matrixResult);
        std::string name = "../results/matrix"+std::to_string(i)+".txt";
        writeToFile(matrixResult,name);
        i++;
        //std::cout << i << "\n";


        // Уведомляем производителей, что в очереди есть место
        dataCondition.notify_all();

        // Симуляция обработки данных
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    // Количество производителей и потребителей
    int numProducers = 1;
    int numConsumers = 1;

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
    return 0;
}