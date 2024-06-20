#pragma once
#include "List.h"
#include <iostream>
using namespace std;
class RoundList:public List
{
public:
	RoundList();

	void add(int value);
	void addToEnd(int val);

	int search(int n);
	int firstElement();

	bool search(const int& value) const;

	void removeFirst();
	void remove(int key);
	void insert(int a);
	void clear();

	~RoundList();

	friend ostream& operator <<(ostream& stream, RoundList& rl);
};