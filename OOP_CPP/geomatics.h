#include <iostream>
#include <math.h>

# define M_PI           3.14159265358979323846  /* pi */	

class Point
{
public:
	Point();
	Point(int, int);
	~Point();
	void setX(int);
	int getX();
	void setY(int);
	int getY();
private:
	int x;
	int y;
};

double distanceOfPoints(Point, Point);

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
private:
	int radius;
	Point center;
};

bool pointInsiteCircle(Circle, Point);



