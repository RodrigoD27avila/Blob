#pragma once

class Point {
private:
	double x, y;

public:
	Point(double x, double y) 
		: x(x), y(y)
	{}

	double getX() {return x;}
	double getY() {return y;}

	void setX(double x) {this->x = x;}
	void setY(double y) {this->y = y;}

	double distance(const Point &p2);
};
