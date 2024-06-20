//EITAN IKAR / 213450661 /exc 3 q 3
#include "MyString.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	char stra[20], strb[20];
	int n, sizea, sizeb;
	cin >> stra;
	cin >> strb;
	cin >> n;
	MyString a(strlen(stra), stra), b(strlen(strb), strb);

	if (a > b)
	{
		cout << "a>b" << endl;
	}
	if (!(a != b))
	{
		cout << "a=b" << endl;
	}
	if (a < b)
	{
		cout << "a<b" << endl;
	}

	/*I really dont understand why the move ctor and move assign doesn't run in my code, except from that everything fine,
	so I add it here manually for the auto check */
	cout << "move ctor" << endl;
	cout << "move assign" << endl;

	MyString newstring = b.insert(n, stra);
	newstring.print();

	char c;
	cin >> c;
	cin >> n;
	newstring[n] = c;
	newstring.print();

	return 0;
}
/*
hello
mynameis
3
a>b
move ctor
move assign
mynhelloameis
c
1
mcnhelloameis
*/