#include "Stack.h"

Stack::Stack()
    : data()
{
    // create and initialize a Stack based on Lists
}
Stack::Stack(const Stack& lst)
    : data(lst.data)
{    /* copy constructor*/
}


void Stack::clear()
{
    // clear all elements from Stack, by setting
    // delete all values from List
    data.clear();
}

bool Stack::isEmpty() const
{    // return true if Stack is empty
    return data.isEmpty();
}

int Stack::pop()
{
    // return and remove the topmost element in the Stack
    // get first element in List
    int result = data.firstElement();
    // remove element from List
    data.removeFirst();
    // return value
    return result;
}

void Stack::push(int val)
{
    // push new value onto Stack
    data.add(val);
}

int Stack::top() const
{
    return data.firstElement();
}
