#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class PQueue{
public:
	PQueue(int cap);
	~PQueue();
	void insert(int data);//insert data
	void removeData(int data);//find data and remove it
	int find(int data);//find and return the index of data
	void display();
	void heapSort();

private:
	int* heap;
	int capacity;
	int size;//current size of the heap
};

