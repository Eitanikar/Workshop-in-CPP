#include "QueueStack.h"

QueueStack::QueueStack() : data()
{
	// create and initialize a Queue based on Lists
	this->data = new Stack();
}

void QueueStack::clear()
{
	// clear all elements from Stack, by setting
	// delete all values from List
	while (!isEmpty())
	{
		dequeue();
	}
}
int QueueStack::dequeue()
{
	int returnData;
	Stack* temp = new Stack();
	while (!isEmpty()) // empty the stack to temp stack
	{
		temp->push(this->data->pop());
	}
	returnData = temp->pop(); // save the last value of the original stack (the first value that pushed) and remove it from temp stack
	while (!temp->isEmpty()) // return the values to the original stack
	{
		this->data->push(temp->pop());
	}
	return returnData;
}

void QueueStack::enqueue(int value)
{
	this->data->push(value);
}

int QueueStack::front()
{
	int returnData;
	Stack* temp = new Stack();
	while (!isEmpty()) // empty the stack to temp stack
	{
		temp->push(this->data->pop());
	}
	returnData = temp->top(); // save the last value of the original stack (the first value that pushed)
	while (!temp->isEmpty()) // return the values to the original stack
	{
		this->data->push(temp->pop());
	}
	return returnData;
}

bool QueueStack::isEmpty() const
{
	if (this->data->isEmpty())
	{
		return true;
	}

	else
	{
		return false;
	}
}