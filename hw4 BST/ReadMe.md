# ReadMe for COMP15 HW4
## Binary Search Tree

1.  The purpose of your program: 
    The program is written to create a binary search tree data structure 
    with the function of contains, find_min, find_max, insert, remove,  
    tree_height, node_count, count_total, which are essential in the 
    process using binary search tree to search for some number.

2.  List of files with one/or two-line summary:
    BinarySearchTree.cpp: models the implementation of a binary search 
    tree 
    BinarySearchTree.h: defines the physical layout of the program and 
    fuctions included in BinarySearchTree.cpp
    main.cpp: an overview and summary of all funsctions
    ReadMe.md: a brief introduction and overview of the program
    PrettyPrint.cpp:printing of the tree

3.  How to compile it: 
    use included Makefile

4.  Outline of data structure: 
    Binary Search Tree: Binary search tree is used in the programming in 
    class BinarySearchTree.Every node includes an int data to show its 
    value, an int count to show its duplicate numbers and two Node pointer 
    pointing to its left child and right child. Also, if any node child 
    is empty, we make its parents corresponding pointer points to NULL. 
    As a results, we can compare to the NULL to find whether we 
    completely go through a subtree or not.
	 
5.  Outline of algorithm (depending on the assignment)
    When we do delete, we use post-order recursive way to delete. Because 
    we need first to delete a node's children before we delete that node. 
    When we do copy a tree, we use a pre-order way to copy, which means we 
    copy the node first, then we copy the left child of the node and right 
    child of the node.

6.  A list of people who materially helped you on the assignment: 
    Fanying Ye helped me on this assignment. 