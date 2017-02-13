#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>

#include "Hashtable.h"
#include "hashfunc.h"


using namespace std;

Hashtable::Hashtable(std::string fileName,bool reversed)
{
	hashtable = new List_linked_list*[TSIZE];
	for(int i=0;i<TSIZE;i++)
		hashtable[i]= new List_linked_list();
	keys_held = 0;
	capacity = TSIZE;
	
	/*
	 * Read file: fileName
	 * 	Loop through each line and insert() into "hashtable"/
	 *  and insert_at_tail(key) into "keys"
	 */
	if (fileName.compare("none") !=0){
		if (reversed == true) {
			ifstream input;
			input.open(fileName.c_str());
			string line;
			string key;
			string value;

			while (!getline(input, line).eof()){
				int i=0;
				istringstream ss(line);
				string token;
				string key;
				string value;
				while(getline(ss, token, ':')) {
					if(i==0){
						value = token;
					}
					if(i==1){
						key = token;
					}
					if(i==2){
						key=key+token;
						insert(key, value);
					}
					i++;
				}
			}
			input.close();
		}
		else {
			ifstream input;
			input.open(fileName.c_str());
			string line;
			string key;
			string value;

			while (!getline(input, line).eof()){
				int i=0;
				istringstream ss(line);
				string token;
				string key;
				string value;
				while(getline(ss, token, ':')) {
					if(i==0){
						key = token;
					}
					if(i==1){
						value = token;
					}
					if(i==2){
						value=value+token;
						insert(key, value);
					}
					i++;
				}
			}
			input.close();
		}
	}
}

Hashtable::~Hashtable()
{
	delete [] hashtable;
	delete [] keys;
	delete [] values;
}

/*
 * Insert into hashtable
*/
void Hashtable::insert(std::string key,std::string value)
{
	// first check whether hashtable is full, expand if it is
	if(numberOfKeys() + 1 >= capacity * loadFactor)
	 	expand();
	 
	int i = hash_string(key) % capacity;
 
	// if value's never been stored in the table, insert
	if (hashtable[i]->is_empty()){
	 	hashtable[i]->insert_at_tail(key);
	 	hashtable[i]->insert_at_tail(value);
		
	 	keys->insert_at_tail(key);

	 	values->insert_at_tail(value);

	 	keys_held++;
	}
	// if there're values already exixted in the linked list
	// of its key, add the value to last of the linked list
	else {
		if(hashtable[i]->string_at_head().compare(key) == 0){
			hashtable[i]->insert_at_tail(value);
			values->insert_at_tail(value);

		}
		else {
			//collision
			//find the nearest null place
			while(!hashtable[i]->is_empty()){
				if (i==capacity-1)
					i=0;
				else
					i++;
			}
			hashtable[i]->insert_at_tail(key);
			hashtable[i]->insert_at_tail(value);
			keys->insert_at_tail(key);
			values->insert_at_tail(value);
			keys_held++;
		}
	}
}

int Hashtable::numberOfKeys()
{
	return keys_held;
}

/*
* Find value by key,
*  if key does not exits return empty linked_list
*/
List_linked_list* Hashtable::get_value(std::string key)
{

	if(keys->has_string(key)){
		int i = hash_string(key) % capacity;

		if(hashtable[i]->string_at_head().compare(key)  == 0)
			return hashtable[i];
		else {
			while(hashtable[i]->string_at_head().compare(key) != 0){
				if (i==capacity-1)
					i=0;
				else
					i++;
			}
			return hashtable[i];
		}
	}

	List_linked_list* emp = new List_linked_list();
	return emp;

}

List_linked_list* Hashtable::allKeys()
{
	return keys;
}

void Hashtable::expand()
{
	List_linked_list **temp = new List_linked_list*[capacity * 2];
	capacity *= 2;

	for (int i = 0;i < numberOfKeys(); i++) {
		string key = hashtable[i]->string_at_head();
		int index = (int)hash_string(key) % capacity;
		temp[index] = hashtable[index];
	}

	delete [] hashtable;
	hashtable = temp;
}

List_linked_list* Hashtable::allValues(){
	return values;
}

bool Hashtable::existKey(std::string key){
	return keys->has_string(key);
}
