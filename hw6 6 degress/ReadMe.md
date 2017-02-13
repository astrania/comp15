// ReadMe for COMP 15 HW6
// 6 Degrees

1. The purpose of the program: The program is written to read in student names
				and courses and find the students found in both
				files, courses in both files, what courses some
				one TAed, course roster, path and shortest path
				between two students.

2. List of files:
        Please see more detailed in-line explanations inside the following 
	files
      
	*Main.cpp: read in input files, handle command, pass commands to 
		    other functions 

	*Graph.cpp: find path, shortest path, print ls, print lc. It has two 
		    hashtables(see details in graph.h)

	*Hashtable.cpp: the hashtable is a linked linked list(each element in
			the hashtable linked list is a linked list). The 
			hashtable has functions like insert a value by its key, 
			return the linked list of values of a specific key...
			Two additional linked lists are also created to 
			hold keys and values

	*List_linked_list.cpp: a linked list implementation, directly borrowed
			       from the previous linked list homeowork 

	*Readme.md: an explanation of the program
	
3. How to compile it:
	Use included Makefile
	
4. Outline of data structure:
	linked list is the building block of hashtable
	Queue is used in Graph.cpp to faciliate BFS search

5. Outline of algorithm:
	See in-line comments
	 
6. People who helped me:
	Fanying and all the TAs helped me tremendously on this project
