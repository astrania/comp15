//
// COMP15 HW6:    DEGREES
// Created by:    Kaimeng Yang
// Completed on:  April 25, 2016
//
//  

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cassert>
#include <fstream>
#include <sstream>

#include "hashfunc.h"
#include "Hashtable.h"
#include "Graph.h"

using namespace std;
void usageAbort(string progname, string message)
{
        cerr << message << endl
             << "Usage:  " << progname << " command" << endl
             << "     where command is one of "
             << "ls, lc, taed, roster, paths, shortestpath"
             << endl;
	     
        exit(1);
}

void readNumbers(istream &input, Graph* g, Hashtable* h1,Hashtable* h2)
{
	string temp;
	int i=0;
	string algorithm,name1,name2;

	while (input >> temp) {
		algorithm = temp;
		if (input.fail()){
			return;
		}
		if ((algorithm != "ls") && (algorithm != "lc")
						&& (algorithm != "ls")
						&& (algorithm != "taed")
						&& (algorithm != "roster")
						&& (algorithm != "paths")
					      && (algorithm != "shortestpath"))
			usageAbort(algorithm, "Input command not a valid");

			if (algorithm.compare("ls") == 0){
				g->printls();
				//return;
			}

			if (algorithm.compare("lc") == 0){
				g->printlc();
				//return;
			}

			if (algorithm.compare("taed") == 0){
				input >> name1;
				h1->get_value(name1)->print_list_at_second();
				//return;
			}

			if (algorithm.compare("roster") == 0){
				input >> name1;
				h2->get_value(name1)->print_list_at_second();
				//return;
			}

			if (algorithm.compare("paths") == 0){
				input >> name1;
				input >> name2;
				cout<<"name1:"<<name1<<",name2:"<<name2<<endl;
				g->path(name1,name2);
				//return;
			}

			if (algorithm.compare("shortestpath") == 0 ){
				input >> name1;
				input >> name2;
				g->shortesPath(name1,name2);
				//return;
			}

	}

        return;
}


int main(int argc, char *argv[])
{
        string filename1 = string(argv[1]);
        string filename2 = string(argv[2]);
	
        Hashtable* h1 = new Hashtable(filename2,false);
        Hashtable* h2 = new Hashtable(filename1,true);

        Graph* g = new Graph(h1,h2);
     
        readNumbers(cin,g,h1,h2);

        return 0;
}
