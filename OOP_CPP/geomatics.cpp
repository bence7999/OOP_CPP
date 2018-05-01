#include "geomatics.h"

using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int a, int b)
{
	x = a;
	y = b;
}

Point::~Point()
{
}

void Point::setX(int a) {
	x = a;
}

int Point::getX() {
	return x;
}

void Point::setY(int b) {
	y = b;
}

int Point::getY() {
	return y;
}

double distanceOfPoints(Point p1, Point p2) {

	double d1 = (p2.getX() - p1.getX()) * (p2.getX() - p1.getX());
	double d2 = (p2.getY() - p1.getY()) * (p2.getY() - p1.getY());
	double distance = sqrt(d1 + d2);
	return distance;

}

Circle::Circle()
{
	radius = 0;
	Point tmp;
	center = tmp;
}

Circle::Circle(int r) {
	radius = r;
	Point tmp;
	center = tmp;
}

Circle::Circle(int a, int b, int r)
{
	radius = r;
	Point tmp(a, b);
	center = tmp;
}

Circle::~Circle()
{
}

void Circle::setR(int r) {
	radius = r;
}

int Circle::getR() {
	return radius;
}

Point Circle::getCenter() {
	return center;
}

double Circle::diameter() {
	double diameter = 2 * radius;
	return diameter;
}

double Circle::circumference() {
	double circumference = 2 * radius * M_PI;
	return circumference;
}

double Circle::area() {
	double area = radius * radius * M_PI;
	return area;
}

bool pointInsiteCircle(Circle c, Point p) {
	double distance = distanceOfPoints(c.getCenter(), p);
	if (distance < c.getR())
		return true;
	else
		return false;
}

