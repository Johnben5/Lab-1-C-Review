#include <iostream>
#include <fstream>
#include <string>
#include "TodoList.h"
using namespace std;

int main(int argc, char *argv[]) {
  TodoList mylist;
  string firstarg = argv[1];
  if(firstarg.compare("add") == 0) {
    string date = argv[2];
    string task = argv[3];
    mylist.add(date, task);
  }
	if(firstarg.compare("remove") == 0) {
		string task = argv[2];
		mylist.remove(task);
	}
	if(firstarg.compare("printList") == 0) {
		mylist.printTodoList();
	}
	if(firstarg.compare("printDay") == 0) {
		string date = argv[2];
		mylist.printDaysTasks(date);
	}
  return 0;
}