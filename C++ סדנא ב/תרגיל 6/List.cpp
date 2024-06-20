#include "List.h"
#include <iostream>
using namespace std;


//  class Link implementation
List::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}


List::Link::Link(const Link& source) : value(source.value), next(source.next)
{}

//  class List implementation
List::List() : head(nullptr)
{
	// no further initialization
}

List::List(const List& l)//copy constructor
{
	Link* src, * trg;
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}
List& List::operator =(const List& l)
{
	Link* src, * trg;
	if (l.head == nullptr)//If the list is empty
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)//As long as the list is not over
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
	return *this;
}
ostream& operator <<(ostream& stream, List& l)
{
	try
	{
		List::Link* temp = l.head;
		if (l.head == nullptr)throw 1;////If the list is empty
		else
		{
			while (temp->next != nullptr)
			{
				stream << temp->value << " ";
				temp = temp->next;
			}
			stream << temp->value << endl;
		}
		return stream;
	}
	catch (int a)
	{
		switch (a)
		{
		case 1:cout << "Error" << endl;
			break;
		}
	}

}
istream& operator >>(istream& stream, List& l)
{
	int temp;
	cin >> temp;
	List::Link* newLink = new List::Link(temp, nullptr);
	l.head = newLink;
	cin >> temp;
	while (temp < newLink->value)
	{

		newLink->next = new List::Link(temp, nullptr);
		newLink = newLink->next;
		cin >> temp;

	}
	return  stream;


}
void List::insert(int a)
{
	Link* current = head;
	Link* previous = current;
	if (a >= current->value)//If the value obtained is greater than the 
		//element at the top of the list.
	{
		add(a);
		return;
	}
	else
	{
		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
			if (a >= current->value && a<previous->value || a > current->value && a <= previous->value)//Inserts the organ in the appropriate place
			{
				Link* newlink = new Link(a, current);
				previous->next = newlink;
				return;
			}
		}
		Link* newlink = new Link(a, nullptr);
		current->next = newlink;
	}
}
void List::remove(int key)
{
	try
	{

		Link* current = head;
		Link* previous = current;
		if (key == current->value)//If the value obtained is greater than the 
			//element at the top of the list.
		{
			removeFirst();
		}
		else
		{

			while (current->next != nullptr)
			{
				previous = current;
				current = current->next;
				if (key == current->value)
				{
					previous->next = current->next;//Deletes the selected member
					delete current;
					return;
				}

			}
			throw "value not found";

		}
	}
	catch (const char* msg)
	{
		cout << msg << endl;

	}

}

List::~List()
{
	clear();
}


void List::clear()
{
	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != nullptr; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;
}

bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == nullptr;
}

void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

bool  List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}


void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}

