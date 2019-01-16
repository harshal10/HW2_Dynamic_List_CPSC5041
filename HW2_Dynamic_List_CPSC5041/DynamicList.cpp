#include "DynamicList.h"
using namespace std;

DynamicList::DynamicList(int capacity)
{
	this->list_capacity = capacity;
	size = 0;
	list = new int[capacity];
	for (int i = 0; i < size; i++) {
		list[i] = 0;
	}
}

DynamicList::~DynamicList()
{
	delete[] list;
	cout << "Destructor is executed\n";
}

void DynamicList::add_item(int element)
{
	if (size >= list_capacity) {
		expand_list();
	}
	list[size] = element;
	size++;
	if (size > 0.5*list_capacity) {
		expand_list();
	}
}

bool DynamicList::remove_item()
{
	if (isEmpty()) {
		return false;
	}

	size--;
	if (size < 0.25*list_capacity) {
		shrink_list();
	}
	return true;
}

void DynamicList::expand_list()
{
	this->list_capacity *= 2;
	int * tempList = new int[list_capacity];

	for (int i = 0; i < size; i++) {
		tempList[i] = list[i];
	}

	delete[] list;

	list = tempList;
}

void DynamicList::shrink_list()
{
	this->list_capacity /= 2;
	int * tempList = new int[list_capacity];

	for (int i = 0; i < size; i++) {
		tempList[i] = list[i];
	}

	delete[] list;

	list = tempList;
}

int DynamicList::getSize()
{
	return size;
}

int DynamicList::getCap()
{
	return list_capacity;
}

bool DynamicList::isEmpty()
{
	if (size == 0) {
		return true;
	}
	return false;
}

void DynamicList::print()
{
		
	cout << "List capacity    : " << getCap() << endl;
	cout << "List current size: " << getSize() << endl;		
	cout << "List contents    : ";

	for (int i = 0; i < size; i++) {
			cout << list[i] << ", ";
		}
	cout << endl;
}
