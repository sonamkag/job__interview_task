#include <iostream>
#include <thread>
#include "thread.h"

using namespace std;

int count=0, count_b=0, count_c=0,sum_B=0,sum_C=0;
std::queue<int> queue_;
std::mutex mutex_;
std::condition_variable cond_;

int main()
{
    std::thread A(f1),B(f2),C(f3);
    A.join();
    B.join();
    C.join();
}
