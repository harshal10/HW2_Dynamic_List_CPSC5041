The package contains: README, input_trace.txt, DynamicList.cpp, DynamicList.h and Driver.cpp
Driver.cpp takes input from input_trace.txt file. No other input is needed.
Driver executes the commands from the input file and prints results to the screen. 

input_trace.txt pre-conditions:
1. First line must be an int that specifies the initial capacity of the list.
2. following commands are supported by the driver:
	ADD <int value>
	DELETE
	PRINT
	EXIT
3. Commands are case sensitive. Must be in all caps.
4. Value that needs to be added must follow 'ADD' after a space.
5. EXIT command will execute the destructor and end driver program.

Assumptions:

1. Dynamic List is required to store int values only.
1. Input method for using Dynamic List my change.


	
	