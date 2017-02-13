#include "List_linked_list.h"

#include <iostream>
#include <cassert>

using namespace std;

List_linked_list::List_linked_list()
{
	head = NULL;
}

List_linked_list::~List_linked_list()
{
	Linked_List_Node *current = head;
	// delete list by looping through and deleting each node
	while (current != NULL){
		Linked_List_Node *next = current->next;
		delete current;
		current = next;
	}
}

int List_linked_list::get_current_size()
{
	int i = 0;

	Linked_List_Node *current = head;
	while(current != NULL){
		i++;
		current = current->next;
	}

	return i;
}

void List_linked_list::make_empty()
{
	Linked_List_Node *current = head;
	Linked_List_Node *prev = NULL;

	while(current != NULL){
		prev = current;
		current = current->next;
		delete prev;
	}
	head = NULL;
}

void List_linked_list::insert_at_tail(std::string value)
{
	Linked_List_Node *newNode;
	newNode = (Linked_List_Node*)new(Linked_List_Node);
	newNode->value = value;
	newNode->next = NULL;

	Linked_List_Node *current = head;
	Linked_List_Node *prev = NULL;

	if (current == NULL){
		head = newNode;
	}

	else{
		while(current!=NULL){
			prev = current;
			current = current->next;
		}
		prev->next = newNode;
	}
}

string List_linked_list::string_at_head()
{
	Linked_List_Node *current = head;
	return current->value;
}

string List_linked_list::string_at(int index)
{
	// if index is greater than cards_held, then fail
	//assert(index >= 0 && index < cards_in_hand());
	if(index > get_current_size())
		return "0";

	Linked_List_Node *current = head;
	for (int i=0; i<index;i++)
		current = current->next;

	return current->value;
}

bool List_linked_list::has_string(string s)
{
	Linked_List_Node *current = head;
	while(current != NULL){
		if (current->value.compare(s) == 0)
			return true;
		current = current->next;
	}
	return false;
}
void List_linked_list::print_list()
{
	Linked_List_Node *current = head;
	while(current != NULL){
		cout<<current->value<<endl;
		current = current->next;
	}

}
void List_linked_list::print_list_at_second()
{
	Linked_List_Node *current = head;
	if (head!= NULL)
		current = current->next;
	while(current != NULL){
		cout<<current->value<<endl;
		current = current->next;
	}

}

void List_linked_list::insert_at_head(string s)
{
	Linked_List_Node *newNode = new Linked_List_Node();
	newNode->value = s;

	if (head == NULL){
		head = newNode;
		newNode->next = NULL;
	}
	else{
		newNode->next = head;
		head = newNode;
	}

}
