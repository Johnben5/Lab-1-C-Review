#ifndef TODO_LIST_H
#define TODO_LIST_H
#include "TodoListInterface.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class TodoList: public TodoListInterface {
public:
	vector <string> tasks;
	TodoList() {
		cout << "In Constructor" << endl;
		ifstream infile ("TODOList.txt");
		string line;
		if (infile.is_open()) {
			while (getline(infile, line)) {
				cout << line << '\n';
				tasks.push_back(line);
			}
			infile.close();
		}
	}
	virtual ~TodoList() {
		cout << "In Deconstructor" << endl;
		ofstream outfile;
		outfile.open ("TODOList.txt", ofstream::out | ofstream::trunc);
		for(int i = 0; i < tasks.size(); i++) {
			outfile << tasks[i] << endl;
		}
		outfile.close();
	}

	/*
	*   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
	*/
	virtual void add(string _duedate, string _task) {
		cout << "In add" << _duedate << _task << endl;
		tasks.push_back(_duedate);
		tasks.push_back(_task);
	}

	/*
	*   Removes an item from the todo list with the specified task name
	*
	*   Returns 1 if it removes an item, 0 otherwise
	*/
	virtual int remove(string _task) {
		cout << "In remove" << endl;
		bool isTaskFound = false;
		for(int i = 1; i < tasks.size(); i += 2) {
			if(_task.compare(tasks.at(i)) == 0) {
				isTaskFound = true;
				tasks.erase(tasks.begin() - 1 + i, tasks.begin() + i + 1);
			}
		}
		if(isTaskFound == false) {
			cout << "Task not found and nothing will be removed." << endl;
		}
	}

	/*
	*   Prints out the full todo list to the console
	*/
	virtual void printTodoList() {
		cout << "In printTodoList" << endl;
		for(int i = 0; i < tasks.size(); i++) {
			cout << tasks[i] << endl;
		}
	}
	
	/*
	*   Prints out all items of a todo list with a particular due date (specified by _duedate)
	*/
	virtual void printDaysTasks(string _date) {
		cout << "In printDaysTasks" << endl;
		bool isDateFound = false;
		for(int i = 0; i < tasks.size(); i += 2) {
			if(_date.compare(tasks.at(i)) == 0) {
				isDateFound = true;
				cout << tasks[i + 1] << endl;
			}
		}
		if(isDateFound == false) {
			cout << "No tasks were found on that day." << endl;
		}
	}
};

#endif