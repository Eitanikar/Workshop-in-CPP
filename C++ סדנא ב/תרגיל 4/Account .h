#pragma once
#include<iostream>
using namespace std;

class Account {
private:
	int	accountNumber;
	int code;
	int balance;
	string email;
public:
	Account() {//empty constructor
		this->accountNumber = 0;
		this->code = 0;
		this->balance = 0;
		this->email = "";
	}
	Account(int accn, int code, int balance, string email) {
		if (code < 0 || code > 9999) {
			throw "ERROR: code must be of 4 digits!";
		}
		else if (email.find('@') != std::string::npos) {
			throw "ERROR: email must contain @!";
		}
		else if () {
			throw "ERROR: email must end at .com or .co.il!";
		}
	}

	int get() {

	}
};