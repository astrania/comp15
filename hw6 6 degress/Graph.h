/*
 * Graph.h
 *
 *  Created on: Apr 23, 2016
 *      Author:
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>

#include "Hashtable.h"
using namespace std;

class Graph
{
public:
	Graph(Hashtable* h1, Hashtable* h2);
	~Graph();

	void path(string name1,string name2,vector<int> pathNum);
	void path(string name1,string name2);
	
	void shortesPath(string name1,string name2);

	void printls();
	void printlc();

private:
	int studentNumber;
	
	vector<vector<int> > paths;

	vector<int>  shortestPath;

	//in the adjacencyMatrix
	//value is the name of the path(course name)
	//if no path linking two students, put '0' there
	std::string *adjacencyMatrix;

	//list of all student names
	Hashtable* students; //key:index, value:name
	Hashtable* students2;//key:name, value:index

	//list of all courses
	List_linked_list *courses;
};
