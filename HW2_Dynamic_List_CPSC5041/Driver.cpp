#include <iostream>
#include <string>
#include<sstream>
#include<vector>
#include "DynamicList.h"

using namespace std;

/*
Driver program for demoing DynamicList. It reads input_trace.txt from CWD and 
parses the commands and executes the functions.
*/
int main()
{
	int capacity; //holds the value of capacity to initialize dynmaic list
	string command, line; //holds command string from input file, holds the
	//command line from the input file.
	vector<string> inputs; //holds all the lines of commands from input file 
	//and is used to access commands and values.
	int num; //holds the value of the elements that needs to be added to the 
	//list

	//Opens the file
	ifstream inFile;
	inFile.open("input_trace.txt");
	
	//check to see if file is open and available for parsing
	if (!inFile.is_open()) {
		cerr << "Unable to open file input_trace.tx";
	} 

	//reads the input file and adds the command lines to the vector
	while (inFile >> line) {
		inputs.push_back(line);
	}

	//converts first command from string to int (as it is the capacity of the 
	//dynamic list)
	stringstream capacityInWords(inputs.at(0));
	capacityInWords >> capacity;

	//Initializes the Dynamic list
	DynamicList list(capacity);

	//parses commands from the string vector in the order they were added.
	for (unsigned int i = 1; i < inputs.size(); i++) {
		command = inputs.at(i);
		if (command.compare("ADD") == 0) 
		{
			stringstream ss(inputs.at(i + 1));
			ss >> num;
			list.add_item(num);
		}
		else if (command.compare("DELETE") == 0) 
		{		
			if (!list.remove_item()) 
			{
				cout << "List is empty." << endl;
			}
		}
		else if (command.compare("PRINT") == 0)
		{
			list.print();
		}
		else if (command.compare("EXIT") == 0)
		{
			cout << "EXIT command found..." << endl;
			list.~DynamicList(); //destuctor to deallocate run time memory

		}
	}

	inFile.close();
	cout << "End of program. Thank You" << endl;
	cin.get();
	return 0;
	
}



