#ifndef List_linked_list_h
#define List_linked_list_h

#include <iostream> // for NULL


struct Linked_List_Node {
	std::string value;
	Linked_List_Node *next;
};

class List_linked_list
{
public:
	List_linked_list(); // constructor
	~List_linked_list();
	
	//void print_list();
	bool is_empty() { return head == NULL; }

	// returns the number of nodes in the list
	int get_current_size();

	// empties the list; head should equal NULL 
	void make_empty(); 

	// inserts a card at the tail (final node)
	// should allow insert into an empty list
	void insert_at_tail(std::string value);

	void print_list();
	void print_list_at_second();

	bool has_string(std::string s);

	std::string string_at_head();
	std::string string_at(int index);
	void insert_at_head(std::string s);

private:
	Linked_List_Node *head; // the head of the list
};

#endif // List_linked_list_h
