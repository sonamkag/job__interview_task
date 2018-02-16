#include <iostream>
#include "thread.h"

int f2() 
{ 
    while(true)
    {
	std::unique_lock<std::mutex> mlock(mutex_);
	
        while(queue_.empty())
	{
	   if(count_b+count_c == 100){ break;}
	   cond_.wait(mlock); 
	}
	
	//std::cout << "f2 in" << std::endl;
	if (queue_.empty())
	{
		if (count_c + count_b == 100) { mlock.unlock(); break; }
		mlock.unlock();
	}
        else 
	{

		int x;
		x=queue_.front();
		queue_.pop();
		count_b++;
		sum_B+=x;
		//std::cout << "\tsum_B is "<<sum_B<<"\tcount_b is"<<count_b<<"\n";
		//std::cout << " \t\t\t count_b+  count_c = " << (count_b + count_c) << std::endl;

		if (count_b + count_c == 100) 
		{
			mlock.unlock(); break;
			//std::cout << "total consumption has been reached. at b" << std::endl;
		}
		else mlock.unlock();
	}

    }

    //std::cout << "b is finished" << std::endl;
    return sum_B;
}

