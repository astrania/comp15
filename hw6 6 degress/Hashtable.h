#ifndef Hashtable_h
#define Hashtable_h

#include <iostream>
#include <stdio.h>
#include <string>

#include "List_linked_list.h"

class Hashtable
{
public:
	Hashtable(std::string fileName,bool reversed);
	~Hashtable();

	void insert(std::string key,std::string value);

	int numberOfKeys();

	List_linked_list* get_value(std::string key);

	List_linked_list* allKeys();

	List_linked_list* allValues();

	bool existKey(std::string key);

	int capacity; // hashtable capacity

private:
	static const int TSIZE = 17;
	double loadFactor = 0.8;

	List_linked_list **hashtable; //the array of key-value pairs
				     //each element in array is a linked_list
				     //head of the linked_list is the key
				     //value is append to key's linked_list

	List_linked_list* keys = new List_linked_list(); // the list of keys
	List_linked_list* values = new List_linked_list(); // the list of values

	int keys_held; // how many keys are currently in the hand
	
	void expand();

};

#endif

