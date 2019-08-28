# job__interview_task
I applied for an internship and was given an assignment related to thread and was given a deadline of 5 days. The task was to create a C++ application with three threads; A, B and C. Thread A generates random integers & pushes them into a shared queue. Threads B and C compete with each other to grab an integer from the queue. The threads B and C compute the sum of integers that they have grabbed from the queue. Once A has finished generating 100 random integers it should signal B and C that it is done generating. Once the queue has been emptied of integers, and A has stopped generating, B and C should die. Thread A should wait for B and C to die. It should compare the sums as computed by B and C. The greatest is the winner.

Following were some additional points to keep in mind:
1. The application should be implemented as multiple C++ files.
2. They should be built using CMake.
3. The project should be maintained as atomic commits in a github repo.
4. The application will be built and tested on Debian GNU/Linux, 'stretch'.
5. Bonus points for modularity and design patterns.
6. Bonus points for using modern C++.
7. Bonus points for quick delivery.


For compiling using CMake use the following command:
>> cmake 
>>
>> make
>>
>> ./thread
