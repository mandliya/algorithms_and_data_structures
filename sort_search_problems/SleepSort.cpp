//This is the most simple implementation of sleeping sort in c++//
#include<iostream>
#include<thread>
#include<vector>
#include <chrono>
using namespace std;

void sleepSort(int*, int);
void sleep(int);

int main()
{
	//initialize an array of integers to be sorted
	// Doesn't work for negative numbers
	int arr[] = { 3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	//find the max element in arr
	//Why to ding max? Read below
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}
	max++;

	//call the function SLEEPSORT()
	sleepSort(arr, n);

	//make the main thread to go to sleep for 1 second more then
	//the largest number in the list.
	//this ensures all the threads are over before main finishes execution.
	std::this_thread::sleep_for(std::chrono::seconds(max));


	return(0);
}

void sleep( int i) {
	//make the thread to sleep for I seconds.
	std::this_thread::sleep_for(std::chrono::seconds(i));
	cout << i << " ";
}

void sleepSort(int* arr, int n) {
	thread* threads;
	threads = new thread[n];
	for (int i = 0; i < n; i++) {
		//a new thread is created for each element of an array, which goes to sleep for arr[i] seconds.
		threads[i] = (thread(sleep, arr[i]));
	}
}
