﻿#include "geomatics.h"

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
	num++;
}

Point::~Point()
{
}

void Point::init(int a, int b) {
	x = a;
	y = b;
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

void Point::show()
{
	cout << "xc = " << x << " yc = " << y << endl;
}

int Point::num = 0; // initialization of static data member

void Point::show_total()
{
	cout << "total Points created = "
		<< num << endl;
}

double distanceOfPoints(Point p1, Point p2) {

	double d1 = (p2.x - p1.x) * (p2.x - p1.x);
	double d2 = (p2.y - p1.y) * (p2.y - p1.y);
	double distance = sqrt(d1 + d2);
	return distance;

}

double distanceFromOrigin(Point p) {
	double temp;
	temp = sqrt(p.x * p.x + p.y * p.y);
	return temp;
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

bool inCircle(Circle c, Point p) {
	float distance = distanceOfPoints(p, c.getCenter());
	if (distance < c.radius)
		return true;
	else
		return false;
}

bool pointInsiteCircle(Circle c, Point p) {
	double distance = distanceOfPoints(c.getCenter(), p);
	if (distance < c.getR())
		return true;
	else
		return false;
}

Triangle::Triangle()
{
	A = Point();
	B = Point();
	C = Point();
}

Triangle::Triangle(Point a, Point b, Point c) {
	A = a;
	B = b;
	C = c;
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	A = Point(x1, y1);
	B = Point(x2, y2);
	C = Point(x3, y3);
}

Triangle::~Triangle()
{
}

double Triangle::area() {
	return 0.0;
}

double Triangle::circumference() {
	getDistances();
	double circumference = d1 + d2 + d3;
	return circumference;
}

bool Triangle::isConstructible() {
	getDistances();

	if (d1 + d2 <= d3 && d2 + d3 <= d1 && d2 + d1 <= d2)
		return false;
	else
		return true;
}

int Triangle::typeOf() {
	getDistances();

	if ((d1 == d2) && (d1 == d3))
		return 1;
	//cout << "This is a equilateral triangle!" << endl;
	else if (((d1 == d2) && (d1 != d3)) || ((d2 == d3) && (d2 != d1)) || ((d3 == d1) && (d3 != d1)))
		return 2;
	//cout << "This is a isosceles triangle!" << endl;
	else if ((d1 != d2) && (d2 != d3) && (d3 != d1))
		return 3;
	//cout << "This is a scalene triangle!" << endl;
}

void Triangle::getDistances() {
	d1 = distanceOfPoints(A, B);
	d2 = distanceOfPoints(B, C);
	d3 = distanceOfPoints(C, A);
}