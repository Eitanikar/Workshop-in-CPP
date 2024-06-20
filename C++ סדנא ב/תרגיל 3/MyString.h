//EITAN IKAR / 213450661 /exc 3 q 3
#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    int len = 0;
    char* str;
public:
    MyString() //default constructor
    {
        len = 0;
        str = nullptr;
    }
    MyString(const MyString& ms) //copy constructor
    {
        len = ms.len;
        str = new char[len];
        for (int i = 0; i < len; i++)
        {
            str[i] = ms.str[i];
        }
    }
    MyString(int len, char* str) //parametric constructor
    {
        this->len = len;
        this->str = new char[len];
        for (int i = 0; i < len; i++)
        {
            this->str[i] = str[i];
        }
    }

    MyString(MyString&& ms) // move constructor
    {
        len = ms.len;
        str = ms.str; // steal (dont copy) rvalue's data
        ms.str = nullptr;
        ms.len = 0;
        cout << "move ctor" << endl;
    }

    MyString& operator=(MyString&& ms) // move assignment operator
    {
        if (str)
            delete[] str;
        len = ms.len;
        str = ms.str; // steal (dont copy) rvalue's data
        ms.str = nullptr;
        cout << "move assign" << endl;
        return *this;
    }

    bool operator>(const MyString ms)
    {
        int check = strcmp(this->str, ms.str);
        if (check >= 0)
            return false;
        return true;
    }
    bool operator>=(const MyString ms)
    {
        int check = strcmp(this->str, ms.str);
        if (check > 0)
            return false;
        return true;
    }

    bool operator<(const MyString ms)
    {
        int check = strcmp(this->str, ms.str);
        if (check <= 0)
            return false;
        return true;
    }
    bool operator<=(const MyString ms)
    {
        int check = strcmp(this->str, ms.str);
        if (check < 0)
            return false;
        return true;
    }

    bool operator!=(const MyString ms)
    {
        int check = strcmp(this->str, ms.str);
        if (check)
            return true;
        return false;

    }

    char& operator[](int index)
    {
        if (index + 1 > len)
        {
            cout << "ERROR";
            exit(0);
        }
        return str[index];
    }

    MyString insert(int index, const char* str) //method to insert str to *this start from index
    {
        int i, j;
        if (index >= this->len)
        {
            MyString str1(0, nullptr);
            cout << "ERROR" << endl;
            return str1;
        }
        MyString str1(this->len + strlen(str), this->str);
        for (i = 0, j = index; i < strlen(str); i++, j++)
        {
            str1.str[j] = str[j - index];
        }
        for (i = index; i < len; i++, j++)
        {
            str1[j] = this->str[i];
        }
        return str1;
    }

    void print() //method to print the string
    {
        for (int i = 0; i < len; i++)
        {
            cout << str[i];
        }
        cout << endl;
    }
};
