/*
 * Queue.cpp
 *
 */

// TODO: Student implements this class
#include <iostream>
#include "Queue.h"
#include <cassert>

using namespace std;

Queue::Queue()
{
	queue_array = new Student[QUEUE_INIT_CAPACITY];
	capacity = QUEUE_INIT_CAPACITY;
	size = 0;
	front = 0;
	back = 0;
}

Queue::~Queue()
{
	delete[] queue_array;
}

void Queue::enqueue(Student s)
{
	if (size == capacity){
		expand();
	}
	
	queue_array[back] = s;
	back++;
	size++;
	
	if (back == capacity){
		back = 0;
	}
}

Student Queue::dequeue()
{
	if (size == 0){
		cout << "Can't dequeue an empty queue" << endl;
	}
	
	Student temp = queue_array[front];
	front++;
	size--;	
	
	if (front == capacity) {
		front = 0;
	}
	
	return temp;
}

bool Queue::is_empty()
{
	if (size == 0){
		return true;
	}
	
	return false;
}

void Queue::expand() {
	Student *new_set_array = new Student[capacity*2];
	
	for (int i=0; i<size; i++) {
		new_set_array[i] = queue_array[front+i];
	}
	
	front = 0;
	back = size;
	
	delete [] queue_array;
	
	queue_array = new_set_array;
	capacity *= 2;
}
	