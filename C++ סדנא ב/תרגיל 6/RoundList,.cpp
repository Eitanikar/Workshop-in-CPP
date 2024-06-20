#include "List.h"
#include "RoundList.h"
#include <iostream>
using namespace std;


RoundList::RoundList() : List() {};


void::RoundList::addToEnd(int val)
{
	if (isEmpty())
	{
		head = new Link(val, head);
		head->next = head;
		return;

	}
	Link* current = head;
	current = current->next;
	while (current != head)
	{
		current = current->next;
	}
	Link* newlink = new Link(val, current->next);
	current->next = newlink;
	head = newlink;
}
int::RoundList::search(int n)
{
	if (isEmpty())
	{
		return -1;
	}
	Link* current = head;
	for (int i = 0; i <= n; i++)
	{
		current = current->next;

	}
	return current->value;
}
ostream& operator <<(ostream& stream, RoundList& rl)
{
	try
	{
		if (rl.isEmpty())throw 1;
		RoundList::Link* current = rl.head->next;
		stream << current->value << " ";
		current = current->next;
		while (current != rl.head->next)
		{
			stream << current->value << " ";
			current = current->next;
		}
		//stream << current->value << endl;
		return stream;

	}
	catch (int a)
	{
		cout << endl;
	}
	return stream;

}
int::RoundList::firstElement()
{
	if (isEmpty())throw "the List is empty, no first Element";
	return head->next->value;
}
bool::RoundList::search(const int& value) const
{
	for (Link* p = head->next; p != head; p = p->next)
		if (value == p->value)
			return true;
	// not found
	return false;

}
void ::RoundList::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head->next;
	if (p->next == head->next)
	{
		p->next = nullptr;
		delete p;
		head = nullptr;
		return;
	}
	// reassign the first node
	head->next = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;

}

void ::RoundList::insert(int a)
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
void::RoundList::add(int value)
{
	if (head == nullptr)
	{

		head = new Link(value, head);
		head->next = head;
		return;
	}
	//Link* current = head->next;
	head->next = new Link(value, head->next);
}

void::RoundList::remove(int key)
{
	try
	{

		Link* current = head;
		Link* previous = current;
		if (key == head->value)//If the value obtained is greater than the
			//element at the top of the list.
		{
			previous->next = current->next;//Deletes the selected member
			delete current;
			head = previous;
			return;
		}
		else
		{

			current = current->next;
			if (key == current->value)
			{
				removeFirst();
				return;
			}
			while (current->next != head)
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
void ::RoundList::clear()
{
	// empty all elements from the List
	if (isEmpty())
	{
		head = nullptr;
		return;
	}

	Link* theNext;
	for (Link* p = head->next; p != head; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;

}
RoundList::~RoundList()
{
	clear();
}