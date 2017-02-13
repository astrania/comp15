/*
 * Set.cpp
 *
 * Add your code below.  Do not change the print function.
 *
 */

#include <iostream>
#include "Set.h"

using namespace std;

// TODO --- students complete this class
Set::Set()
{
	set_array = new Student[INIT_CAPACITY];
	capacity = INIT_CAPACITY;
	class_size = 0;
}

Set::~Set()
{
	delete[] set_array;
}

bool Set::add(Student s)
{
	if(is_enrolled(s)){
	      return false;
	}
	
	if(class_size == capacity){
		expand();
	}
	      
	set_array[class_size] = s;
	class_size++;
	return true;
}

bool Set::drop(Student s)
{
	for(int i=0; i<class_size; i++){
		if(s.name == set_array[i].name){
			for (int j=i; j<class_size-1; j++){
				set_array[j] = set_array[j+1];
			}
			class_size--;
			return true;
		}
	}
	return false;
}

bool Set::is_enrolled(Student s)
{
	for(int i=0; i<class_size; i++){
		if(s.name == set_array[i].name){
			return true;
		}
	}
	return false;
}

int Set::size()
{
	return class_size;
}

void Set::expand()
{
	Student *new_set_array = new Student[capacity*2];
	
	for(int i=0; i<class_size; i++){
		new_set_array[i] = set_array[i];
	}
	delete[] set_array;
	set_array = new_set_array;
	capacity = capacity * 2;
}

void Set::print_class()
{
        for (int i = 0; i < class_size; i++) {
                Student s = set_array[i];
                cout << s.name << ", "
                                << (s.major ? "Major" : "Non-Major")
                                << "\n";
        }
}