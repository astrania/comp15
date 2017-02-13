#include "List_linked_list.h"

#include <iostream>
#include <cassert>

using namespace std;

/*
 * The following #define allows us to use Card_Node as a type.
 * Because the node structure is private, we would otherwise
 * have to write List_linked_list::Card_node everywhere.
 *
 * I put a few of those in, so you can see what I mean (see
 * the copy constructor.
 */
#define Card_Node List_linked_list::Card_Node


List_linked_list::List_linked_list()
{
	// hint: in your constructor, you might want to set front to NULL
	front = NULL;
}


List_linked_list::~List_linked_list()
{
	// delete list by looping through and deleting each node
	Card_Node *temp = front;
	while (temp != NULL){
		Card_Node *next = temp->next;
		delete temp;
		temp = next;	
	}
}

List_linked_list::Card_Node 
*List_linked_list::copy_card_list(List_linked_list::Card_Node *lst)
{
        // Easy to copy an empty list
	if (lst == NULL)
		return NULL;

        // Otherwise make a new node
        List_linked_list::Card_Node *new_node_p
            = new List_linked_list::Card_Node;

        // Copy node data
        new_node_p->card = lst->card;

        // and copy the rest of the nodes
        new_node_p->next = copy_card_list(lst->next);

        // Return pointer to first node in copied list
        return new_node_p;
}

/*
 * Explicit copy constructor necessary because of cards list 
 * in the heap.
 */
List_linked_list::List_linked_list(const List_linked_list &source)
{
        front = copy_card_list(source.front);
}

/*
 * Explicit operator= overload necessary because of heap-allocated 
 * card nodes
 */
List_linked_list List_linked_list::operator =(const List_linked_list &source)
{
	// check for self-assignment -- return without doing anything
	if (this == &source) {
		return *this;
	}
	// delete all current cards
	while (front != NULL) {
		Card_Node *next = front->next;
		delete front;
		front = next;
	}
	// copy over all cards from source list
	if (source.front == NULL) return *this; // nothing to do

	front = new Card_Node;
	Card_Node *this_current   = front;
	Card_Node *source_current = source.front;

	while (source_current != NULL) {
		// deep copy each Card_Node
		this_current->card = source_current->card;
		if (source_current->next != NULL) {
			Card_Node *new_node = new Card_Node();
			this_current->next  = new_node;
		} 
		else {
			this_current->next = NULL; // at back
		}
		source_current = source_current->next;
		this_current   = this_current->next;
	}
	return *this;
}

void List_linked_list::print_list()
{
	Card_Node *current = front;
	while (current != NULL) {
		current->card.print_card();
		if (current->next != NULL) {
			cout << ",";
		} 
		else {
			cout << "\n";
		}
		current = current->next;
	}
}

void List_linked_list::print_list_int()
{
	Card_Node *current = front;
	while (current != NULL) {
		current->card.print_card_int();
		if (current->next != NULL) {
			cout << ",";
		} 
		else {
			cout << "\n";
		}
		current = current->next;
	}
}

// students must write the following functions in the .cpp file
// return number of cards in hand
int List_linked_list::cards_in_hand()
{
	int num = 0;
	
	Card_Node *current = front;
	
	while (current != NULL){
		num += 1;
		current = current->next;
	}
	return num;
}

// empties the list; front should be NULL
void List_linked_list::make_empty()
{
	Card_Node *current = front;
	Card_Node *prev = NULL;

	while (current != NULL){
		prev = current;
		current = current->next;
		delete prev;
	}
}

// insert a card at the front
// Should allow insert into an empty list
void List_linked_list::insert_at_front(Card c)
{
	Card_Node *newNode = new Card_Node();
	newNode->card = c;

	if (front == NULL){
		front = newNode;
		newNode->next = NULL;
	} 
	else{
		newNode->next = front;
		front = newNode;
	}
}

// insert a card at the back (after the end)
// should allow insert into an empty list
void List_linked_list::insert_at_back(Card c)
{
	Card_Node *newNode = new Card_Node();
	newNode->card = c;
	Card_Node *current = front;
	
	if (front == NULL){
		front = newNode;
		newNode->next = NULL;
	} 
	else{
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
		newNode->next = NULL;
	}	
}

// insert a card at an index such that
// all cards following the index will be moved farther
// down the list by one.
// The index can be one after the back of the list
// I.e., you can insert at index 0 into an empty list,
// and you can insert at index 4 in a list with 4 nodes.
// In the first case, the node inserted would become the front
// In the second case, the node inserted would be inserted
// after the current back.
void List_linked_list::insert_at_index(Card c, int index)
{
	Card_Node *newNode = new Card_Node;
	newNode->card = c;
	Card_Node *current = front;
	Card_Node *prev = NULL;
	
	if (index >= 0){
		if(front == NULL){
			front = newNode;
		} 
		else{
			if(index == 0){
			  
				newNode->next = current;
				front = newNode;
				
			} 
			else if(index== (cards_in_hand()+1)) {
				insert_at_back(c);
			}
			else {
				for (int i=0;i<index;i++){
				      prev = current;
				      current = current->next;
				} 
				prev->next = newNode;
				newNode->next = current;
			}
		}
	}
	else {delete newNode;}
}

// replace the card at index
// A card at index must already exist
void List_linked_list::replace_at_index(Card c, int index)
{
	Card_Node *newNode = new Card_Node;
	newNode->card = c;
	Card_Node *current = front;
	Card_Node *prev = NULL;
	
	if (index < cards_in_hand() && index >= 0){
		if(index == 0){
			newNode->next = front->next;
			front = newNode;
		} else {
			for(int i=0; i<index; i++){
				prev = current;
				current = current->next;
			}
			prev->next = newNode;
			newNode->next = current->next;
		}
		delete current;
	}
	else {delete newNode;}
}

// return the card at index.
// allowed to crash if index is not in the list
Card List_linked_list::card_at(int index)
{
	assert (index >= 0 && index < cards_in_hand());
	
	Card_Node *current = front;

	for (int i = 0; i < index; i++){
		current = current -> next;
	}
	return current->card;
}

// return true if the card is in the list
// return false if the card is not in the list
bool List_linked_list::has_card(Card c)
{
	Card_Node *current = front;

	while (current != NULL){
		if(current->card.same_card(c)){
			return true;
		}
		current = current->next;
	}
	return false;
}

// remove the card from the list
// Returns true if the card was removed
// Returns false if the card was not in the list
bool List_linked_list::remove(Card c)
{
	Card_Node *current = front;
	Card_Node *prev = NULL;
	
	while (current != NULL){
		if ((current->card.same_card(c)) && (prev == NULL)){
			front = front->next;
			delete current;
			return true;
		}
		else if ((current->card.same_card(c)) && (prev != NULL)){
			prev->next = current->next;
			delete current;
			return true;
		}
		prev = current;
		current = current->next;	  
	}
		return false;
}

// Remove the card from the front and
// return the card that was removed
// Allowed to fail if list is empty
// NB:  Doesn't lose cards after the first card.
Card List_linked_list::remove_from_front()
{
	assert(front != NULL);
	
	Card_Node *current = front;
	Card card_removed;

	card_removed = current->card;
	front = current->next;
	delete current;
	return card_removed;
}

// Remove the card from the back
// Return the card that was removed
// Allowed to fail if the list is empty
Card List_linked_list::remove_from_back()
{
	Card_Node *current = front;
	Card_Node *prev = NULL;
	Card card_removed;
	
	if(cards_in_hand() == 1){
		front = NULL;
		card_removed = current->card;
	} 
	else{ 
		for (int i=1;i < cards_in_hand();i++){
			prev = current;
			current = current->next;
		}
		card_removed = current->card;
		prev->next = NULL;
	}
	delete current;
	return card_removed;
}

// Remove the card from index
// Return the card that was removed
// Allowed to fail if index is beyond the end of the list
Card List_linked_list::remove_from_index(int index)
{
	Card_Node *current = front;
	Card_Node *prev = NULL;
	Card card_removed;
	
	if (index == 0 && cards_in_hand() > 1){
	    front = current->next;
	    card_removed = current->card;

	}
	else if (index >= 0){
		if(cards_in_hand() == 1){
			front = NULL;
			card_removed = current->card;
		} 
		else{
			for (int i=0; i<index; i++){
				prev = current;
				current = current->next;
			}
			if (prev == NULL){
				front = current->next;
			}
			card_removed = current->card;
			prev->next = current->next;	
		}
	}
	delete current;
	return card_removed;
}
