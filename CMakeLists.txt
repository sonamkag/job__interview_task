cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

project(thread)

add_executable(
	thread
	main.cpp
	thread.h
	thread_A.cpp
	thread_B.cpp
	thread_C.cpp
)
