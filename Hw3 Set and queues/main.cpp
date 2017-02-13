/*
 * main.cpp
 *
 *  Created on: Feb 27, 2016
 *      Author: Kaimeng Yang
 */

#include<iostream>
#include<string>

#include "Student.h"
#include "IsisCourse.h"
#include "Queue.h"
#include "IsisCourse.h"

using namespace std;

static const int NUM_STUDENTS = 11;

void print_student_status(IsisCourse::ENROLLMENT_STATUS status)
{
        if (status == IsisCourse::NONE) {
                cout << "Not enrolled or on a waitlist\n";
        }
        if (status == IsisCourse::ENROLLED) {
                cout << "Enrolled.\n";
        }
        if (status == IsisCourse::MAJOR_WAITLIST) {
                cout << "Major waitlist.\n";
        }
        if (status == IsisCourse::OTHER_WAITLIST) {
                cout << "Other waitlist.\n";
        }
}

void print_all_status(IsisCourse &course)
{
        cout << "Class Size: " << course.get_roster_size() << "\n";
        cout << "Enrolled in Class:\n";
        course.print_list(IsisCourse::ENROLLED);
        cout << "\n";

        cout << "On Major Waitlist:\n";
        course.print_list(IsisCourse::MAJOR_WAITLIST);
        cout << "\n";

        cout << "On Other Waitlist:\n";
        course.print_list(IsisCourse::OTHER_WAITLIST);
        cout << "\n";
}

void print_enrollment(IsisCourse::ENROLLMENT_STATUS es) {
	switch(es) {
	case IsisCourse::NONE:
		cout << "NONE\n";
		break;
	case IsisCourse::ENROLLED:
		cout << "ENROLLED\n";
		break;
	case IsisCourse::MAJOR_WAITLIST:
		cout << "MAJOR_WAITLIST\n";
		break;
	case IsisCourse::OTHER_WAITLIST:
		cout << "OTHER_WAITLIST\n";
		break;
	default:
		cout << "Not a valid output!\n";
		break;
	}
}

// test: get_class_cap, set_class_cap
void test1()  {
	IsisCourse comp15;

	cout << comp15.get_class_cap() << "\n";
	
	comp15.set_class_cap(50);
	cout << comp15.get_class_cap() << "\n";
}

// test: enroll_student, status
void test2(){
	Student students[NUM_STUDENTS] = {
				Student("Green,Alice",true),
				Student("Blue,Misha",true),
				Student("Yellow,John",true),
				Student("Orange,Friya",true),
				Student("Pink,Julia",true),
				
				Student("Black,Henry",true),
				Student("Cyan,Barnaby",true),
				Student("Red,Justin",true),
				Student("Violet,Chester",true),
				Student("Fuchsia,Rebecca",true),
		};
		
		IsisCourse comp15(20); // cap of 20 students;

		for (int i=0;i<NUM_STUDENTS;i++) {
			cout<<i<<endl;
			print_enrollment(comp15.enroll_student(students[i]));	
		}
}

// test: enroll_student, drop_student, update_enrollments
void test3(){
	Student s1;
	s1.name = "Yellow,Alice";
	s1.major = true;
	
	Student s2;
	s2.name = "Orange,Friya";
	s2.major = false;

	Student students[NUM_STUDENTS] = {
		Student("Green,Alice",true),
		Student("Blue,Misha",false),
		Student("Yellow,John",true),
		Student("Orange,Friya",false),
		Student("Pink,Julia",true),
		Student("Black,Henry",false),
		Student("Cyan,Barnaby",true),
		Student("Red,Justin",false),
		Student("Violet,Chester",true),
		Student("Fuchsia,Rebecca",false),
	};	
		
	IsisCourse comp15(20); // cap of 20 students;

	for (int i=0;i<NUM_STUDENTS;i++) {
		comp15.enroll_student(students[i]);
	}
	
	// should print 0
	cout << comp15.drop_student(s1) << "\n";
	
	// should print 1
	cout << comp15.drop_student(s2) << "\n";

}

// test: enroll_student, waitlist_position
void test4() {
	Student students[NUM_STUDENTS] = {
		Student("Green,Alice",true),
		Student("Blue,Misha",false),
		Student("Yellow,John",true),
		Student("Orange,Friya",false),
		Student("Pink,Julia",true),
		Student("Black,Henry",false),
		Student("Cyan,Barnaby",true),
		Student("Red,Justin",false),
		Student("Violet,Chester",true),
		Student("Fuchsia,Rebecca",false),
	};
	
	IsisCourse comp15(20); // cap of 20 students;

	for (int i=0;i<NUM_STUDENTS;i++) {
		comp15.enroll_student(students[i]);
	}
	
	for (int i=0;i<NUM_STUDENTS;i++) {
		cout<< i <<endl;
		print_enrollment(comp15.status(students[i]));

	}

	for (int i=0;i<NUM_STUDENTS;i++) {
		cout<<comp15.waitlist_position(comp15.status(students[i]),
				               students[i]);
		cout<<endl;
	}
}

void print_all_students(Student *students, IsisCourse *course) {
	for (int i=0;i<NUM_STUDENTS;i++) {
			cout << students[i].name << " status: ";
			print_student_status(course->status(students[i]));
		}
}

int main()
{
        Student students[NUM_STUDENTS] = {
                        Student("Green,Alice",true),
                        Student("Blue,Misha",false),
                        Student("Yellow,John",false),
                        Student("Orange,Friya",true),
                        Student("Pink,Julia",true),
                        Student("Black,Henry",false),
                        Student("Cyan,Barnaby",true),
                        Student("Red,Justin",true),
                        Student("Violet,Chester",false),
                        Student("Fuchsia,Rebecca",false),
                        Student("Beige,Barker",true)
        };
	
        IsisCourse comp15(3); // a new course with an enrollment cap of 3

        for (int i = 0; i < NUM_STUDENTS - 1; ++i) { // enroll all but the last
                cout << "Class size: " << comp15.get_roster_size() << "\n";

                cout << "Enrolling " << students[i].name << " (" <<
                                (students[i].major ? "major" : "non-major")
                                << ")\n\t";
                IsisCourse::ENROLLMENT_STATUS status;
                status = comp15.enroll_student(students[i]);
                print_student_status(status);
                cout << "\n";
        }
        cout << "\n";

        print_all_status(comp15);
        print_all_students(students, &comp15);

        cout << "\nIncreasing capacity to 7.\n";

        comp15.set_class_cap(7);

        print_all_status(comp15);
        print_all_students(students, &comp15);

        cout << "\nDone!\n"; 
	
	//test1();
	//test2();
	//test3();
	//test4();

        return 0;
}
