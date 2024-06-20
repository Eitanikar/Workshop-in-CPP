#pragma once

class Point {

private:
	float x;
	float y;
public:
	Point();
	Point(float x, float y);
	Point(const Point& p);
	void setX(float x);
	void setY(float y);
	float getX();
	float getY();
	float distance(Point p);
};

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}

Point::Point(const Point& p) {
	this->x = p.x;
	this->y = p.y;
}

void Point::setX(float x) {
	this->x = x;
}

void Point::setY(float y) {
	this->y = y;
}

float Point::getX() {
	return this->x;
}

float Point::getY() {
	return this->y;
}

float Point::distance(Point p) {
	float dis;
	dis = sqrt(powf(this->x - p.x, 2) + powf(this->y - p.y, 2));
	return dis;
}