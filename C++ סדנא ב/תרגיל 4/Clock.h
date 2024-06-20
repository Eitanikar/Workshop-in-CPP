 #pragma once
#include<iostream>
using namespace std;

class Clock {
private:
	int hour = 0;
	int minute = 0;
	int second = 0;
public:
	Clock(){};
	Clock(int hour, int min, int sec) {//parametric consturctor
			if (sec < 0) {
				this->hour = 0;
				this->minute = 0;
				this->second = 0;
				throw "Invalid time - negative number of seconds.";
			}
			else if (sec > 23) {
				this->hour = 0;
				this->minute = 0;
				this->second = 0;
				throw "Invalid time - more than 60 seconds.";
			}
			else if (min < 0) {
				this->hour = 0;
				this->minute = 0;
				this->second = 0;
				throw "Invalid time - negative number of minutes.";
			}
			else if (min > 59) {
				this->hour = 0;
				this->minute = 0;
				this->second = 0;
				throw "Invalid time - more than 60 minutes.";
			}
			else if (hour < 0) {
				this->hour = 0;
				this->minute = 0;
				this->second = 0;
				throw "Invalid time - negative number of hours."; 
			}
			else if (hour > 23) {
				this->hour = 0;
				this->minute = 0;
				this->second = 0;
				throw "Invalid time - more than 24 hours.";
			}
			else {
				this->hour = hour;
				this->minute = min;
				this->second = sec;
			}
	}

	// set/get methods ahead:
	void sethour(int hour) {
		if (0 < hour || hour > 23)
			this->hour = hour;
		else
			throw "ERROR";
	}
	int gethour() {
		return hour;
	}

	void setminute(int min) {
		if (0 < min || min > 59)
			this->minute = min;
	}
	int getminute() {
		return minute;
	}

	void setsecond(int sec) {
		if (0 < sec || sec > 59)
			this->second = sec;
	}
	int getsecond() {
		return second;
	}

	// operator overload:

	Clock operator+= (int x) {// example: 22:55:40 + 20 = 22:56:00
		Clock temp = *this;
		if ((this->second + x) % 59 > 0) {
			if (this->minute == 59) {
				if (this->hour == 23) {
					this->hour = 0;
					this->minute = 0;
					this->second = (this->second + x - 60);
					return temp;
				}
				else {
					this->hour++;
					this->minute = 0;
					this->second = (this->second + x - 60);
					return temp;
				}
			}
			else {
				this->minute++;
				this->second = (this->second + x - 60);
				return temp;
			}
		}
		else
			this->second = (this->second + x - 60);
		return temp;
	}

	friend ostream& operator<<(ostream& os, const Clock c) { //cout operator
		if (c.hour < 10 || c.minute < 10 || c.minute < 10) {
			if (c.hour < 10) {
				if (c.minute < 10) {
					if (c.second < 10) {
						os << 0 << c.hour << ':' << 0 << c.minute << ':' << 0 << c.second;
					}
					else
						if (c.hour < 10) {
							if (c.minute < 10) {
								os << 0 << c.hour << ':' << 0 << c.minute << ':'<< c.second;
							}
						}
				}
				else
					if (c.hour < 10) {
						if (c.second < 10) {
							os << 0 << c.hour << ':' << c.minute << ':' << 0 << c.second;
						}
					}
			}
			else
				if (c.minute < 10) {
					if (c.second < 10) {
						os << c.hour << ':' << 0 << c.minute << ':' << 0 << c.second;
					}
				}
				else
					if (c.minute < 10) {
						os << c.hour << ':' << c.minute << ':' << 0 << c.second;
					}
		}
		else
			os << c.hour << ':' << c.minute << ':' << c.second;
		return os;
	}

	friend istream& operator>>(istream& is, const Clock c) {
		Clock temp(c.hour, c.minute, c.second);
		is >> temp;
	/*	if (0 < temp.hour > 23) {
			if (0 < y > 59) {
				if (0 < z > 59) {
					c.hour = x;
					this->minute = y;
					this->second = z;
				}
			}
		}
		else {
			if (z < 0) {
				this->hour = 0;
				this->minute = 0;
				this->second = 0;
				throw "Invalid time - negative number of seconds.";
			}
			if (z > 23) {
				this->hour = 0;
				this->minute = 0;
				this->second = 0;
				throw "Invalid time - more than 60 seconds.";
			}
			if (y < 0) {
				this->hour = 0;
				this->minute = 0;
				this->second = 0;
				throw "Invalid time - negative number of minutes.";
			}
			if (y > 59) {
				this->hour = 0;
				this->minute = 0;
				this->second = 0;
				throw "Invalid time - more than 60 minutes.";
			}
			if (x < 0) {
				this->hour = 0;
				this->minute = 0;
				this->second = 0;
				throw "Invalid time - negative number of hours.";
			}
			if (x > 23) {
				this->hour = 0;
				this->minute = 0;
				this->second = 0;
				throw "Invalid time - more than 24 hours.";
			}
		}*/
		return is;
	}
};