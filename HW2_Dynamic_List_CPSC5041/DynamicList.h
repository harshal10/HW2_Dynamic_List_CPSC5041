#pragma once
#include<iostream>
#include<string>
#include<fstream>


class DynamicList
{
	int list_capacity; //number of elements that can be stored in the list
	int size; //number of elements currently stored in the list
	int *list;//pointer to arrray that holds the elements
	DynamicList(); //suppressed default constructor

public:
	DynamicList(int capacity);//Contrtuctor for the list. It takes in the 
	//initial capacity of the list from the user

	~DynamicList(); //destructor 

	void add_item(int element); //adds an initeger element to the list. After 
	//adding if the size is more than 50% of the capacity, it triggers
	//expand_list.


	bool remove_item(); //removes the last item on the list. It returns true if
	//last item is removed succesfully. False if the list is empty. If the size
	//is less than 25% of capacity after removing, it triggers shrink_list.

	void expand_list(); //when triggered, doubles the capacity of the dynamic
	//list

	void shrink_list(); //when triggered, halves the capacity of the dynamic 
	//list

	int getSize(); //returns the current size of the list
	int getCap(); //returns capacity of the list
	bool isEmpty(); //returns true if list is empty, false otherwise.

	void print(); //prints the list size, ca


};

