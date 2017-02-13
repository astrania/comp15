/*
 * BinarySearchTree.cpp
 */

#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>
#include <cassert>

#include "BinarySearchTree.h"

using namespace std;


BinarySearchTree::BinarySearchTree()
{
        // TODO: Students write code here
	root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
}

void BinarySearchTree::post_order_delete(Node *node)
{
        // TODO: students write code here
        // (hint: use a post-order traversal to remove all nodes)
	
	// use postorder to delete 
	if (node != NULL){
		post_order_delete(node->left);
		post_order_delete(node->right);
		delete node;
	}
	node = NULL;
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree &BinarySearchTree::operator= (const BinarySearchTree &source)
{
        // TODO: Students write code here
        // check for self-assignment
	if (this != &source){

        // delete current tree if it exists
	      post_order_delete(root);
	      
        // use pre-order traversal to copy the tree
	      root = pre_order_copy(source.root);
	}
	
        // don't forget to "return *this"
	return *this;
}

Node *BinarySearchTree::pre_order_copy(Node *node) const
{
      
        if (node == NULL){
                return NULL;
	}
        Node *new_node = new Node();
	
	// TODO: Students write code here
        // (hint: use a pre-order traversal to copy details from the
        // node to a new_node)

	new_node->data = node->data;
	new_node->count = node->count;
	new_node->left = pre_order_copy(node->left);
	new_node->right = pre_order_copy(node->right);
	
	return new_node;
}

int BinarySearchTree::find_min() const
{
        if (root == NULL){
                return INT_MIN;
	}
        return find_min(root)->data;
}

Node *BinarySearchTree::find_min(Node *node) const
{
        // TODO: Students write code here
	
	// return NULL if it's null
	if (node == NULL){
		return NULL;
	}
	// base case, leftmost node is found and returned
	else if (node->left == NULL){
		return node;
	}
	// recursively find the leftmost node
	return find_min(node->left);
}

int BinarySearchTree::find_max() const
{
        // TODO: Students write code here
	if (root == NULL){
		return INT_MAX;
	}
	return find_max(root)->data;
}

Node *BinarySearchTree::find_max(Node *node) const
{
        // TODO: Students write code here
	
	// return NULL if the node is NULL
	if (node == NULL){
		return NULL;
	}
	// base case, rightmost node is found and returned
	else if (node->right == NULL){
		return node;
	}
	// recursively find the rightmost node
	return find_max(node->right);
}

bool BinarySearchTree::contains(int value) const
{
        // TODO: Students write code here
	if (root == NULL) {
		return false;
	}
	return contains(root, value);
}

bool BinarySearchTree::contains(Node *node, int value) const
{
        // TODO: Students write code here
	
	// if the tree is empty, return false
	if (node == NULL){
		return false;
	}
	// base case, if finds the value, return true
	else if (node->data == value){
		return true;
	}
	// recursively call left and right depending on 
	// value's relationship to node->data
	else if (value < node->data){
		return contains(node->left, value);
	}
	else {
		return contains(node->right, value);
	}
}

void BinarySearchTree::insert(int value)
{
        insert(root, NULL, value);
}

void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
        // TODO: Students write code here
	
	// insert at root if the tree is empty
	Node *temp = NULL;
	
	if (root == NULL){
		Node *new_node = new Node();
		
		new_node->data = value;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->count = 1;
		
		root = new_node;
		return;
	}
	// base case, insert at a null node
	else temp = root;
	  
	while (temp != NULL){
		
		Node *new_node = new Node();
		
		new_node->data = value;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->count = 1;
		node = new_node;
		
		if(value < parent->data){
			if (temp->left == NULL){
			      temp->left = node;
			      return;
			}
			else temp = temp->left;
		}
		
		else{
			if (temp->right == NULL){
				temp->right = node;
				return;
			}
			else temp = temp->right;
		}
		return;
	}
	// recursively compare the values and call "insert" function
	else if (value < node->data){
		insert(node->left, node, value);
	}
	else if (value > node->data){
		insert(node->right, node, value);
	}
	// increment count if the value is already in the tree
	else {
		node->count++;
	}
}

bool BinarySearchTree::remove(int value)
{
        return remove(root, NULL, value);
}


// TODO: Students write code here
// (cannot be a lazy removal)
bool BinarySearchTree::remove(Node *node, Node *parent, int value) 
{
	if (node == NULL) return false;

	// remove a node that is root
	if (root->data == value){
		// check if count is greater than 1
		if (root->count > 1)
			root->count--;
		// remove the root with no children
		else if (root->left == NULL && root->right == NULL) {
				delete root;
				root = NULL;
		}
		// remove the root with one child
		else if (root->left == NULL || root->right == NULL) {
			if (root->left == NULL) {
				Node *temp = root->right;
				delete root;
				root = temp;;
			}
			else {
				Node *temp = root->left;
				delete root;
				root = temp;
			}
		}
		// remove the root with more than one child
		else {
			Node *temp_node = root->right;
			Node *temp_parent = root;
			Node *temp_node_left = temp_node->left;

			while (temp_node_left != NULL) {
				temp_parent = temp_node;
				temp_node = temp_node_left;
				temp_node_left = temp_node_left->left;
			}
			root->data = temp_node->data;
			root->count = temp_node->count;
			if (temp_parent->data > temp_node->data)
				temp_parent->left = temp_node->right;
			else
				temp_parent->right = temp_node->right;
			delete temp_node;
		}
		return true;
	}

	//remove a node that is not a root
	else if (node->data == value){
		if (node->count > 1)
			node->count--;
		//if the node is a leaf, just delete
		else if (node->left == NULL && node->right == NULL) {
			if (parent->data > node->data) {
				delete node;
				parent->left = NULL;
			}
			else {
				delete node;
				parent->right = NULL;
			}
		}
		// else if the node has one child, bypass
		else if (node->left == NULL || node->right == NULL) {
			if (node->left == NULL) {
				if (parent->data > node->data) {
					parent->left = node->right;
					delete node;
				}
				else {
					parent->right = node->right;
					delete node;
				}
			}
			else {
				if (parent->data > node->data) {
					parent->left = node->left;
					delete node;
				}
				else {
					parent->right = node->left;
					delete node;
				}
			}
		}
		// else, the node has two children
		else {
			Node *temp_node = node->right;
			Node *temp_parent = node;
			Node *temp_node_left = temp_node->left;

			while (temp_node_left != NULL) {
				temp_parent = temp_node;
				temp_node = temp_node_left;
				temp_node_left = temp_node_left->left;
			}
			node->data = temp_node->data;
			node->count = temp_node->count;

			if (temp_parent->data > temp_node->data)
				temp_parent->left = temp_node->right;
			else
				temp_parent->right = temp_node->right;
			delete temp_node;
		}
		return true;
	}
	else if (node->data < value)
		return remove(node->right,node,value);
	else
		return remove(node->left,node,value);
}

int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

int BinarySearchTree::tree_height(Node *node) const
{
        // TODO: Students write code here
	
	// check if it's null
	if (node == NULL) {
		return -1;
	}
	// base case, the node is a leaf, whose height is 0
	else if ((node->left == NULL) && (node->right == NULL)){
		return 0;
	}
	// recursive case, returns the maximum of left_height and right_height
	else {
		int left_height;
		int right_height;
		
		left_height = tree_height(node->left) + 1;
		right_height = tree_height(node->right) + 1;
		
		return (left_height>right_height)?left_height:right_height;
	}
}

// returns the total number of nodes
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

int BinarySearchTree::node_count(Node *node) const
{
        // TODO: Students write code here
	
	// count is 0 if the node is null
	if (node == NULL) {
		return 0;
	}
	// count is 1 if the node is a leaf
	else if ((node->left == NULL) && (node->right == NULL)){
		return 1;
	}
	// count is the node plus the number of its children
	else {
		return (1 + node_count(node->left) + node_count(node->right));
	}	
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

int BinarySearchTree::count_total(Node *node) const
{
        // TODO: Students write code here:
	
	// same principle applies here as the node_count function
	if (node == NULL) {
		return 0;
	}
	else if (node->left == NULL and node->right == NULL){
		return ((node->count)*(node->data));
	}
	else {
		int left_count;
		int right_count;
		int sum;
		
		left_count = count_total(node->left);
		right_count = count_total(node->right);
		sum = left_count + right_count;
		
		return (sum + ((node->count) * (node->data)));
	}
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        printPretty(root, 1, 0, std::cout);
}

Node *BinarySearchTree::find_parent(Node *node, Node *child) const
{
        if (node == NULL) {
		return NULL;
	}

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left==child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}
