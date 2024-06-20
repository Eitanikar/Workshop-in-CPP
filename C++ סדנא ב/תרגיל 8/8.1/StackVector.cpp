#include "Vector.cpp"
template <class T>
class StackVector
{
public:
	// constructor requires a starting size
	StackVector<T>(unsigned int capacity = DEF_CAPACITY);
	StackVector<T>(const StackVector& s);

	// Stack operations
	void clear();
	bool isEmpty() const;
	int pop();
	void push(int value);
	int top() const;

protected:
	// data fields
	Vector<T> data;
};


template <class T>
StackVector<T>::StackVector(unsigned int capacity)
	: data(capacity)
{
	// create and initialize a Stack based on Vectors
}

template <class T>
StackVector<T>::StackVector(const StackVector& s)
	: data(s.data)
{ /* copy constructor*/
}


template <class T>
void StackVector<T>::clear()
{
	// clear all elements from Stack, by setting
	// index to bottom of Stack
	data.clear();
}

template <class T>
bool StackVector<T>::isEmpty() const
{
	return data.getSize() == 0;
}

template <class T>
int StackVector<T>::pop()
{
	// return and remove the topmost element in the Stack
	if (isEmpty()) throw "Stack is empty";
	return data.delLast();
}

template <class T>
void StackVector<T>::push(int val)
{
	// push new value onto Stack
	data.insert(val);
}

template <class T>
int StackVector<T>::top() const
{
	// return the intopmost element in the Stack
	if (isEmpty()) throw "Stack is empty";
	return data[data.getSize() - 1];
}