#include<iostream>
#include<mutex>
#include<thread>
#include<pair>

using namespace std;


mutex mtx;

int i=0;

void print_thread_id (int id) {
     mtx.lock();
	int k=i;
	for(int z=0;z<1000000;z++)
		i=k+1;
     std::cout << "thread #" << i << '\n';
	mtx.unlock();
}
  
        int main ()
        {
		pair<int,int> a={1,2};
		return 0;
              std::thread threads[1000];
              // spawn 10 threads:
              for (int i=0; i<100; ++i)
                  threads[i] = std::thread(print_thread_id,i+1);
              for (auto& th : threads) th.join();
	
		cout<<i<<endl;
 
              return 0;
              }
  
