#include<iostream>
#include<mutex>
#include<thread>

using namespace std;


mutex mtx;

void print_thread_id (int id) {
     mtx.lock();
     std::cout << "thread #" << id << '\n';
}
  
        int main ()
        {
              std::thread threads[10];
              // spawn 10 threads:
              for (int i=0; i<10; ++i)
                  threads[i] = std::thread(print_thread_id,i+1);
              for (auto& th : threads) th.join();
 
              return 0;
              }
  
