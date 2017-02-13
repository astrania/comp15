/*
 * Graph.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: Kaimeng Yang
 */
#include <iostream>
#include <stdio.h>
#include <queue>

#include "Graph.h"

using namespace std;

Graph::Graph(Hashtable* h1, Hashtable* h2)
{
	students  = new Hashtable("none",false);
	students2 = new Hashtable("none",false);
	courses = new List_linked_list();
	//h1's key is TA name, value is course name
	//h2's key is course name, value is attended student name
	
	List_linked_list* h1Values = h1->allValues();
	
		int i=0;
		while(i<h1Values->get_current_size()){
			string name = h1Values->string_at(i);
			//if students does not have this name as key, insert
			if(!courses->has_string(name)){
				courses->insert_at_tail(name);
			}
			i++;
		}
		
	/*
	* Loop through h2.allKeys() to insert into students
	*/
	List_linked_list* h2Keys = h2->allKeys();

		i=0;
		while(i<h2Keys->get_current_size()){
			string s = h2Keys->string_at(i);
			if(!courses->has_string(s)){
				courses->insert_at_tail(s);
			}
			i++;
		}
		
	/*
	 * Loop through h1.allKeys() to insert keys into students
	 */
	List_linked_list* h1Keys = h1->allKeys();
	i=0;
	int j=0;
	while(i<h1Keys->get_current_size()){
		string name = h1Keys->string_at(i);
		//if students does not have this name as key, insert
		if(!students->existKey(name)){
			string s;
			char c = j+'0';
			s.push_back(c);
			students->insert(s,name);
			students2->insert(name,s);
			j++;
		}
		i++;
	}
	
	/*
	 * Loop through h2.allValues() to insert into students
	 */
	List_linked_list* h2Values = h2->allValues();

	i=0;
	while(i<h2Values->get_current_size()){
		string s = h2Values->string_at(i);
		if(!students2->existKey(s)){
			string s;
			char c = j+'0';
			s.push_back(c);
			students->insert(s,h2Values->string_at(i));
			students2->insert(h2Values->string_at(i),s);
			j++;
		}
		i++;
	}

	studentNumber = students->numberOfKeys();

	/*
	 * Now you have a hashtable of students' name and its corresponding 
	 * index,create an adjacency matrix (which is really a string array 
	 *  rather than a matrix, sorry for the name confusion. I had adj 
	 *  matrix originally but later changed to array, but didn't want to 
	 *  change its name) according to name's index
	 */
	adjacencyMatrix = new string[studentNumber*studentNumber];
	
	for(int i=0;i<studentNumber*studentNumber;i++)
		adjacencyMatrix[i]="0";

	int index1,index2;
	for(int i = 0; i < studentNumber; i++){
		string ss;
		char c = i+'0'; // convert integer to string
		ss.push_back(c);
		List_linked_list* l = students->get_value(ss);

		string s = l->string_at(1);

		List_linked_list* courses = h1->get_value(s);
		int j=1;

		while(j<courses->get_current_size()) {
			List_linked_list* TAedStudents =
			                  h2->get_value(courses->string_at(j));

			int k=1;

			while(k<TAedStudents->get_current_size()){

				index1 = i;
				string in2 = students2->get_value
				   (TAedStudents->string_at(k))->string_at(1);
				   
				char c = in2[0];
				index2 = c - '0'; //convert string to int

				adjacencyMatrix[index1*studentNumber + index2] 
				                      = courses->string_at(j);
				k++;
			}
			j++;
		}
	}
}

Graph::~Graph()
{
	 delete [] students;
	 delete [] adjacencyMatrix;
	 delete [] students2;
	 delete [] courses;
}


void Graph::path(string name1, string name2)
{
	paths.clear();
	if( !students2->existKey(name1) || !students2->existKey(name2)){
		cout<<"Student not found"<<endl;
		return;
	}
	vector<int> pathNum;
	path(name1,name2,pathNum);

	for (int i=0; i<int(paths.size());i++) {
		vector<int> onePath = paths[i];
		for(int j=0; j<int(onePath.size());j++){
			int num = onePath[j];
			if(j==0){
				string ss;
				char c = num+'0';
				ss.push_back(c);
				cout<<students->get_value(ss)->string_at(1);
				cout<<" ";
			}
			else{
				cout<<"+- ";
				int last = onePath[j-1];
				cout<<adjacencyMatrix[last*studentNumber + num];
				cout<<" -> ";
				string ss;
				char c = num +'0';
				ss.push_back(c);
				cout<<students->get_value(ss)->string_at(1);
				cout<<" ";
			}
		}
		cout<<endl;
	}

}

void Graph::path(string name1, string name2,vector<int> pathNum)
{
	string in = students2->get_value(name1)->string_at(1);
	int index1 = in[0] - '0';

	pathNum.push_back(index1);

	in = students2->get_value(name2)->string_at(1);
	int index2 = in[0] - '0';

	for(int i=0;i<studentNumber;i++){
		if(i!=index2 && 
		   adjacencyMatrix[index1*studentNumber + i].compare("0")!=0){
			string ss;
			char c = i +'0';
			ss.push_back(c);
			string nextName = students->get_value(ss)->string_at(1);
			path(nextName,name2,pathNum);
		}
		else if (i==index2 && 
		adjacencyMatrix[index1*studentNumber + index2].compare("0")!=0){
			pathNum.push_back(index2);
			paths.push_back(pathNum);
		}
	}
	return;
}

// Dijkstra
void Graph::shortesPath(std::string name1, std::string name2)
{
	// check if names exist
	if( !students2->existKey(name1) || !students2->existKey(name2)){
		cout<<"Student not found"<<endl;
		return;
	}

	shortestPath.clear();

	string in = students2->get_value(name1)->string_at(1);
	int index1 = in[0] - '0';

	in = students2->get_value(name2)->string_at(1);
	int index2 = in[0] - '0';
	
	// keep two arrays to mark visited and wherefrom
	bool* visited = new bool[studentNumber];
	int* wherefrom = new int[studentNumber];
	for(int i=0;i<studentNumber;i++){
		visited[i] = false;
		wherefrom[i] = -1;
	}
	
	// BFS using queue
	list<int> queue;
	queue.push_back(index1);
	visited[index1] = true;

	while(!queue.empty())
	{
		int s = queue.front();
		queue.pop_front();

		for(int i=0; i<studentNumber;i++){
			if(!visited[i] &&
		        adjacencyMatrix[s*studentNumber + i].compare("0")!=0){
				visited[i] = true;
				queue.push_back(i);
				wherefrom[i] = s;

				if(i == index2){
					List_linked_list* tmp =
							new List_linked_list();

					int tt = i;
					while(tt!=-1){
						string ss;
						char c = tt +'0';
						ss.push_back(c);
						tmp->insert_at_head(ss);
						tt = wherefrom[tt];
					}

					string current;
					string prev;
					for(int t=0;
					     t<tmp->get_current_size();t++){
						string s = tmp->string_at(t);
						current = s;
						string current_name = 
			                   students->get_value(s)->string_at(1);
						if(t==0){
							cout << current_name
							                  <<" ";
							prev = current;

						}
						else{
							cout<<"+- ";
							int i1 = prev[0]-'0';		
							int i2 = current[0]-'0';
								
							cout<<adjacencyMatrix
							[i1*studentNumber + i2];
							cout<<" -> ";
							cout << 
							current_name<<" ";
							prev = current;
						}

					}
				}
			}
		}

	}
	cout << endl;
	delete [] visited;
	delete [] wherefrom;

}

void Graph::printls()
{
	students2->allKeys()->print_list();
}

void Graph::printlc()
{
	courses->print_list();
}