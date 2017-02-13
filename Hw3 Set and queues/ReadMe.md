# ReadMe for COMP 15 HW3
## ISIS Course Roster and Waitlists

Every assignment you submit you will include a ReadMe.md file.

The purpose of the ReadMe file is the same as the little paper insert
you get in a new appliance --- to give the reader an introduction and
overview of the product.

Your ReadMe file for the assignments **must** include:

On a side note, set_capacity and update_enrollments do not fail
when I run these functions on my local computer, so I have no idea 
why they fail after I make provide and get tested for submission.  

1.  The purpose of your program: modeling the SIS task of placing 
    students into a course that has certain requirements. Namely,it 
    allows students who are majoring in a subject to go directly in 
    to the class roster, and those that are not majors will go onto a 
    waitlist. 

2.  List of files with one/or two-line summary:
    Queue.cpp: models the two waitlists using enque, dequeue, 
	       is_empty, and expand functions. 
    Queue.h: defines the physical layout of the program and fuctions 
	     included in queue.cpp
    IsisCourse.cpp: models the course. Students can enroll, drop, 
		    come off/be placed onto a waitlist etc 
    IsisCourse.h: defines the physical layout of the program and fuctions 
		 included in the IsisCourse.cpp 
    Set.cpp: models the actual roster using add, drop, is_enrolled, 
	     print_class functions
    Set.h: defines the physical layout of the program and fuctions 
		 included in the set.cpp
    Student.h: student struct containing his/her name and major
    default.main.output.txt: default output for main.cpp
    main.cpp: an overview and summary of all functions
    ReadMe.md: a brief introduction and overview of the program

3.  How to compile it: use included Makefile

4.  Outline of data structure (depending on the assignment): 
    Set: A list with no duplicated items. Elements can be removed, added,
	 searched.In this program, students can be removed, added to the
	 roster and checked if they are on the roster. 
    Queue: Items can only be removed from the front using dequeue, and 
	   inserted at the back using enque. Queue is implemented with a 
	   circular buffer,which uses all the space in the queue until
	   we actually fill the queue to capacity. In this program,
	   students will be added and dropped form the waitlists, or 
	   checked whether they are on the watilists or not. 
	 
5.  Outline of algorithm (depending on the assignment)

6.  A list of people who materially helped you on the assignment.  If
    you worked with a friend and you shared ideas, you need to 
    list that person, e.g., "Josh Whedon helped me on this assignment".
    You do not need to list TAs, or professors, but you may feel free
    to do so: Fanying Ye helped me on this assignment. 

The ReadMe file shows the reader, in a quick glance, what the program is
about and gives a general idea of how it works. For short programs the
readme file will be short, for more complicated programs the readme file
will be longer.

Use outline form rather than long discursive paragraphs. A ReadMe file
is an overview.

There is no correct readme format; within these guidelines, devise your
own style.