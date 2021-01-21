#ifndef TODO_LIST_H
#define TODO_LIST_H
#include "TodoListInterface.h"

#include <iostream>
#include <string>

using namespace std;

class TodoList: public TodoListInterface {
public:
    TodoList() {
      cout << "In Constructor" << endl;
    }
    virtual ~TodoList() {
      cout << "In Deconstructor" << endl;
    }

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task) {
      cout << "In add" << endl;
    }

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task) {
      cout << "In remove" << endl;
    }

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList() {
      cout << "In printTodoList" << endl;
    }
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date) {
      cout << "In printDaysTasks" << endl;
    }
};

#endif