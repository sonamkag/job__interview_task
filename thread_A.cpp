#include <iostream>
#include <stdlib.h>   //for rand() function.
#include <chrono>     //to make this thread to sleep for a while so that B or C thread could acquire the lock.
#include <thread>
#include "thread.h"

void f1() 
{ 
    for(int i=0; i<100; ++i)
    {
	std::unique_lock<std::mutex> mlock(mutex_);

        int x;
        x=rand() %20+1;
        queue_.push(x);
        count++;
	//std::cout << "x is "<<x<<"\tcount is "<<count<<"\n";
	mlock.unlock();
        cond_.notify_all();
    }
    
   while(true)
   {
	std::unique_lock<std::mutex> mlock(mutex_);
	if (queue_.empty()) { mlock.unlock(); break; }
	else { mlock.unlock();  std::this_thread::sleep_for(std::chrono::seconds(1)); }
   }

   if(sum_B>=sum_C)
    std::cout << "B is the winner.\n";
   else
    std::cout << "C is the winner.\n";
}

