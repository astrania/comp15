# ReadMe for COMP 15 HW2 
## Dynamic Arrays

Every assignment you submit you will include a ReadMe file. The name
could be ReadMe, readme, Read-me.txt, readME, ReadMe.md (the “.md”
stands for “markdown,” which allows lightweight formatting) or almost
anything you like that has the word read followed by the word me. Exact
spelling is not important, the contents are.

The purpose of the ReadMe file is the same as the little paper insert
you get in a new appliance -- to give the reader an introduction and
overview of the product.

Your ReadMe file for the assignments **must** include:

1.  The purpose of your program

2.  List of files with one/or two-line summary

3.  How to compile it (saying "use included Makefile" is ok)

4.  Outline of data structure (depending on the assignment)

5.  Outline of algorithm (depending on the assignment)

The ReadMe file shows the reader, in a quick glance, what the program is
about and gives a general idea of how it works. For short programs the
readme file will be short, for more complicated programs the readme file
will be longer.

Use outline form rather than long discursive paragraphs. A ReadMe file
is an overview.

There is no correct readme format; within these guidelines, devise your
own style.

------------------------------------
1. The purpose of the program: to model the progress
of playing a deck of cards such as adding a card, removing a card, etc., using 
dynamic array.

2. List of files:
	*card.h: defines the physical layout of the program and fuctions 
		 included in the card program             
	*card.cpp: defines a playing card, stores individual playing cards, and 
                   model traditional playing cards from a 52-card deck, with 
		   standard suits and ranks.
	*List_linked_list.h:defines the physical layout of the program and 
			    fuctions included in the list_linked_list program
	*List_linked_list.cpp: uses a linked list to perform various functions
	*hand.h: defines the physical layout of the program and fuctions 
		 included in the hand program 
	*hand.cpp:uses list_linked_list to produce a deck or a hand of cards
	*main.cpp: an overview and summary of all functions
	*COMP15_hw2.pdf: homework instructions in pdf format 
	*COMP15_hw2.txt: homework instructions in txt format 
	*Makefile: compiling and providing specifics
	*Readme.md: a brief introduction and overview of the program
	
3. How to compile it:
	Use included Makefile.
	
4. Outline of data structure:
	The List Abstract Data Type (ADT) is used in the class of
List_linked_list of this project to update the elements in the array.

5. Outline of algorithm:
	The Fisher–Yates shuffle (named after Ronald Fisher and Frank Yates), 
also known as the Knuth shuffle (after Donald Knuth), an algorithm for 
generating a random permutation of a finite set—in plain terms, for randomly 
shuffling the set is used in the function void Hand::shuffle() to randomly 
shuffle the cards of a deck.

6. Acknowledgements of assistance: TA Cecilie and Eliza