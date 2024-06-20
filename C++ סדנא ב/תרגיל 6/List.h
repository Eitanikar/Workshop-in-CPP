#pragma once
#include "List.h"
#include <iostream>
using namespace std;
class List
{
public:
	//--------------------------------------------
	// inner class link
	// a single element for the linked List 
	//--------------------------------------------
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	};	//end of class Link
public:
	// constructors
	List();
	List(const List&);// copy constructor
	~List();


	// operations
	void add(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void insert(int a);//Inserts an element into the list
	void remove(int key);//Deletes an entry from the list
	List& operator =(const List& l);
	friend ostream& operator <<(ostream& stream, List& l);
	friend istream& operator >>(istream& stream, List& l);
	void clear();

public:
	// data field
	Link* head;
};

