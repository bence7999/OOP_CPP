#include <iostream>
#include <math.h>

# define M_PI           3.14159265358979323846  /* pi */	

class Point
{
public:
	Point();
	Point(int, int);
	~Point();
	void init(int, int);
	void setX(int);
	int getX();
	void setY(int);
	int getY();
	void show();
	static int num;
	static void show_total();
	friend double distanceFromOrigin(Point);
	friend double distanceOfPoints(Point, Point);
private:
	int x;
	int y;
};



class Circle
{
public:
	Circle();
	Circle(int);
	Circle(int, int, int);
	~Circle();
	void setR(int);
	int getR();
	Point getCenter();
	double diameter();
	double circumference();
	double area();
	friend bool inCircle(Circle, Point);
private:
	int radius;
	Point center;
};

bool pointInsiteCircle(Circle, Point);

class Poligon
{
public:
	virtual double area() = 0;
	virtual double circumference() = 0;

};

class Triangle: public Poligon
{
public:
	Triangle();
	Triangle(Point, Point, Point);
	Triangle(int, int, int, int, int, int);
	~Triangle();
	double area();
	double circumference();
	bool isConstructible();
	void getDistances();
	int typeOf();
private:
	Point A, B, C;
	double d1, d2, d3;
};


