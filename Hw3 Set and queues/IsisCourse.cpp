/*
 * IsisCourse.cpp
 *
 */

#include <iostream>
#include <exception>
#include <stdexcept>
#include "IsisCourse.h"

using namespace std;
using std::runtime_error;

IsisCourse::IsisCourse()
{
        class_capacity = 0; // no students allowed in yet
}

IsisCourse::IsisCourse(int init_capacity)
{
        // TODO: Student writes code here
	class_capacity = init_capacity;
}

IsisCourse::~IsisCourse()
{
        // nothing to do
}

void IsisCourse::set_class_cap(int cap)
{
        if (cap < class_capacity)
                throw runtime_error("IsisCourse:  "
                                    "class capacity cannot be lowered");
        class_capacity = cap;
        if (roster.size() < class_capacity) {
                update_enrollments();
        }
}

int IsisCourse::get_class_cap()
{
	return class_capacity;
}

/*
 * See the enrollment logic from the assignment handout or
 * the IsisCourse.h file!
 */
IsisCourse::ENROLLMENT_STATUS IsisCourse::enroll_student(Student s)
{
        // TODO: Student writes code here
	
	Queue *major_waitlist_queue = &major_waitlist;
	Queue *other_waitlist_queue = &other_waitlist;
	
	// Major students can enroll if class capacity allows
	if(s.major == true) {
		if (roster.size() < class_capacity){
			roster.add(s);
			return ENROLLED;
	        }
	        // otherwise major students go to major waitlist
	        else { 
			major_waitlist_queue->enqueue(s);
			return MAJOR_WAITLIST;
		}
	}
	//Non major students go directly to other waitlist
	else {
		other_waitlist_queue->enqueue(s);
		return OTHER_WAITLIST;
	}
}

bool IsisCourse::drop_student(Student s)
{
        bool found_student = false;     // if we find the student to drop
        // TODO: Student writes code here

        // if we dropped a student, there should be room on
        // the roster
	if (roster.drop(s)){
		found_student = true;
		update_enrollments();
	}
	
	else {
		// drop a student from a major waitlist
		Queue *waitlist_queue; 
		waitlist_queue = &major_waitlist;
		Student temp;
		Queue temp_queue;
		
		while (waitlist_queue->is_empty() != true){
			temp = waitlist_queue->dequeue();
			if (temp.name != s.name){
				temp_queue.enqueue(temp);
			}
			else{
				found_student = true;
			}
		}
		
		while (temp_queue.is_empty() != true){
			temp = temp_queue.dequeue();
			waitlist_queue->enqueue(temp);
		}
		
		
		// drop a student from other waitlist
		waitlist_queue = &other_waitlist;
		while (waitlist_queue->is_empty() != true){
			temp = waitlist_queue->dequeue();
			if (temp.name != s.name){
				temp_queue.enqueue(temp);
			}
			else{
				found_student = true;
			}
		}
		
		while (temp_queue.is_empty() != true){
			temp = temp_queue.dequeue();
			waitlist_queue->enqueue(temp);
		}
	}
	
        return found_student;
}

int IsisCourse::waitlist_position(ENROLLMENT_STATUS status, Student s)
{
        // TODO: Student writes code here
	
	// students who are not on any of the waitlists 
	if (status == NONE | status == ENROLLED) {
		cout << "Not on any waitlists" << endl;
	}
	
	int pos = 0;
	Queue *waitlist_queue;
	waitlist_queue = &major_waitlist;
	Student temp;
	Queue temp_queue;
	int i = 1;
	
	// find waitlist position for students on MAJOR_WAITLIST
	if (status == MAJOR_WAITLIST){
		while (waitlist_queue->is_empty() != true){
			temp = waitlist_queue->dequeue();
			temp_queue.enqueue(temp);
			if (temp.name != s.name){
				i++;
			}
			else {
				pos = i;
			}
		}
		
		while (temp_queue.is_empty() != true){
			temp = temp_queue.dequeue();
			waitlist_queue->enqueue(temp);
		}
	}
	
	// find waitlist position for students on OTHER_WAITLIST
	else if (status == OTHER_WAITLIST){
		waitlist_queue = &other_waitlist;
		
		while (waitlist_queue->is_empty() != true){
			temp = waitlist_queue->dequeue();
			if (temp.name != s.name){
				i++;
			}
			else {
				pos = i;
			}
		}
		
		while (temp_queue.is_empty() != true){
			temp = temp_queue.dequeue();
			waitlist_queue->enqueue(temp);
		}
	}
	
	return pos;
}

/* 
 * Return an ENROLLMENT_STATUS that says which list
 * (or none) that the student is on.
 */
IsisCourse::ENROLLMENT_STATUS IsisCourse::status(Student s)
{
        // TODO: Student writes code here	
	Queue *waitlist_queue;
	waitlist_queue = &major_waitlist;

	Student temp;
	Queue temp_queue;
	
	ENROLLMENT_STATUS status = NONE;
	
	// find and return "ENROLLED" status
	if (roster.is_enrolled(s)){
		status = ENROLLED;
	}
	
	// find and return "MAJOR_WAITLIST" status
	else if(s.major == true){
		while (waitlist_queue->is_empty() != true){
			temp = waitlist_queue->dequeue();
			temp_queue.enqueue(temp);
			if (temp.name == s.name){
				status = MAJOR_WAITLIST;
			}
		}
		
		while (temp_queue.is_empty() != true){
			temp = temp_queue.dequeue();
			waitlist_queue->enqueue(temp);
		}
	}
	
	// find and return return "OTHER_WAITLIST" status
	else {
		waitlist_queue = &other_waitlist;
		
		while (waitlist_queue->is_empty() != true){
			temp = waitlist_queue->dequeue();
			temp_queue.enqueue(temp);
			if (temp.name == s.name){
				status = OTHER_WAITLIST;
			}
		}
		
		while (temp_queue.is_empty() != true){
			temp = temp_queue.dequeue();
			waitlist_queue->enqueue(temp);
		}
	}
	
	return status;
}

void IsisCourse::print_list(ENROLLMENT_STATUS status)
{
        Queue *waitlist_queue;
        Queue  temp_queue;
	Student temp;

        if (status == ENROLLED) {
                roster.print_class();
                return;
        }
        
        if (status == MAJOR_WAITLIST) {
                waitlist_queue = &major_waitlist;
        } else {
                waitlist_queue = &other_waitlist;
        }
        // now handle printing the queue

        // TODO: Student writes code here
	int i = 1;
	
	while (waitlist_queue->is_empty() != true){
		temp = waitlist_queue->dequeue();
		cout << i++ <<". " << temp.name << "\n";
		temp_queue.enqueue(temp);
	}
	
	while (temp_queue.is_empty() != true){
		temp = temp_queue.dequeue();
		waitlist_queue->enqueue(temp);
	}
}

/*
 * Put students from the waitlists into the class
 * in priority (majors first, then others), up to
 * the class capacity.
 */
void IsisCourse::update_enrollments()
{
        // TODO: Student writes code here
	while (roster.size() < class_capacity &&
			(major_waitlist.is_empty() != true|
					other_waitlist.is_empty() != true)){
		if(major_waitlist.is_empty() != true){
			roster.add(major_waitlist.dequeue());
		}
		
		else if(other_waitlist.is_empty() != true){
			roster.add(other_waitlist.dequeue());
		}
	}	
}
