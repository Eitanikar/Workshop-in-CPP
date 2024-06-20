/*
eitan ikar / 213450661 / exc 8 q 1
 The program use vector to calculate math function
*/
#include <iostream>
#include "StackVector.cpp"
using namespace std;


string infixToPostfix(string exp)
{
	string str;
	StackVector<char> stk;
	char ch = exp[0];
	for (int i = 0; i < exp.length(); i++, ch = exp[i])
	{
		if (ch == '(')
		{
			stk.push(ch);
		}

		else if (ch == ')')
		{
			while (!stk.isEmpty() && stk.top() != '(')
			{
				str += stk.pop();
				str += ' ';
			}
			stk.pop();
		}

		else if (ch == '*' || ch == '/')
		{
			while (!stk.isEmpty() && stk.top() != '(')
			{
				str += stk.pop();
				str += ' ';
			}
			stk.push(ch);
		}

		else if (ch == '+' || ch == '-')
		{
			while (!stk.isEmpty() && stk.top() != '(' && stk.top() != '/' && stk.top() != '*')
			{
				str += stk.pop();
				str += ' ';
			}
			stk.push(ch);
		}

		else
		{
			str += ch;
			while (i < exp.length() - 1 && exp[i + 1] >= '0' && exp[i + 1] <= '9')
			{
				i++;
				ch = exp[i];
				str += ch;
			}
			str += ' ';
		}

	}

	while (!stk.isEmpty())
	{
		str += stk.pop();
	}
	return str;
}

int calcPostfix(string exp)
{
	StackVector<int> stk;
	char ch = exp[0];
	int secondOperand = 0, temp = 0;
	for (int i = 0; i < exp.length(); i++, ch = exp[i])
	{
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			temp = 0;
			while (exp[i] >= '0' && exp[i] <= '9') // until the number is ends
			{
				temp = temp * 10 + (exp[i] - '0');
				i++;
			}

			stk.push(temp); // put the number in the stack
		}

		if (exp[i] == '+')
		{
			secondOperand = stk.pop();
			stk.push(stk.pop() + secondOperand);
		}

		if (exp[i] == '-')
		{
			secondOperand = stk.pop();
			stk.push(stk.pop() - secondOperand);
		}

		if (exp[i] == '*')
		{
			secondOperand = stk.pop();
			stk.push(stk.pop() * secondOperand);
		}

		if (exp[i] == '/')
		{
			secondOperand = stk.pop();
			stk.push(stk.pop() / secondOperand);
		}

	}
	return stk.pop();
}

int main() {

	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << "in postfix form: " << postfix << endl;
	cout << "calculated value: " << calcPostfix(postfix) << endl;
	return 0;
}

/*
exapmle of runnig:

enter an infix expression as a string
(5+3)*((20/10)+(8-6))
in postfix form: 5 3 + 20 10 / 8 6 - + *
calculated value: 32

*/