#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

extern int count, count_b, count_c,sum_B,sum_C;
extern std::queue<int> queue_;
extern std::mutex mutex_;
extern std::condition_variable cond_;

#ifndef THREAD_H
#define THREAD_H

void f1();
int f2();
int f3();

#endif

