//
// Created by Маргарита  on 02.10.2024.
//
#include <iostream>
#include <thread>
#include <sys/wait.h>
#include <queue>
#include <mutex>
#include<fstream>
std::mutex mut ;
std::queue<int> data_queue ;
std::condition_variable data_cond ;

int produce_item(int i){
    std::cout<<"produce item"<<i<<"\n";
    numbers.pop_back();
    return i;
}

void Producer () {
    std::cout<<"producer\n";

    while (!numbers.empty()) {
        int const data=produce_item(numbers.back()) ;
        std::lock_guard<std::mutex> lk ( mut ) ;
        data_queue.push(data) ;
        data_cond.notify_one() ;
    }
}
std::vector<int> answer;
void process(int i){
    std::cout<<"print";
    answer.push_back(i);
//    std::ofstream file("../name_file.txt", std::ios::app);
//
//    if (!file.is_open()) {
//        std::cout << "Error opening the file!\n";
//        return;
//    }
//    file<<i<<"\n";
//    file.close();
}
void Consumer ( ) {
    std::cout<<"consumer\n";
    while (true) {
        std::unique_lock<std::mutex> lk ( mut ) ;
        data_cond.wait ( lk , [ ] { return !data_queue.empty ( ) ; } ) ;
        int data=data_queue.front( ) ;
        data_queue.pop();
        std::cout<<data;
        lk.unlock( ) ;
        process (data);
//        if(data_queue.empty())
//            break;
    }
}
int main(){
    std::vector<int> numbers = {1,2,3,4,5};
    std::cout<<"coarse\n";
    std::thread thread1(Producer, numbers);
    //std::thread thread2(Producer);
    std::thread thread3(Consumer);

    thread1.join();
    //thread2.join();
    thread3.join();
    std::cout<<"\n\nanswer:\n\n";
    for(int elem:answer){
        std::cout<<"elem= "<<elem<<"\n";
    }
}
