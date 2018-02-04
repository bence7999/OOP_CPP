#include "ChapterFive.h"

using namespace std;

// Write a program to demonstrate data hiding.

class Date
{
private:
	int day, month, year;
public:
	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	bool isLeap();
	bool validate();
};

void Hiding() {
	Date date1(13, 13, 2009);
	bool valid = date1.validate();
	if (!valid) {
		cout << "invalid date!" << endl;
		return;
	}
	cout << "<-- - hiding.cpp--->" << endl;
	cout << "Now we are in Year " << date1.getYear() << " AD" << endl;
	bool leap = date1.isLeap();
	if (leap)
		cout << date1.getYear() << "is a leap year." << endl;
	else
		cout << date1.getYear() << "is not a leap year." << endl;
	//date1.day= 10; // Note1
	//cout << date1.day; // Note2
}

// Write a program to demonstrate the use of public method in accessing private data members.

class Date_1
{
private:
	int day, month, year; // data members
public:
	void setDate(int d1, int m1, int y1);// member function or method
	void showDate(); //member function or method
};

void Date1(){
	Date_1 d1;
	cout << "<-- - date1.cpp--->" << endl;
	d1.setDate(10, 3, 2004);
	d1.showDate();
}

void Date_1::setDate(int d1, int m1, int y1) //method definition
{
	day = d1;
	month = m1;
	year = y1;
}

void Date_1::showDate() //method definition
{
	cout << "The date is : " << endl;
	cout << day << " : " << month << " : " << year << endl;
}

// Write a program to illustrate pointer to object.

class Date_2
{
private:
	int day, month, year;
public:
	void setDate(int d, int m, int y);
	void showDate();
};

void Ptrobj1() {
	Date_2 *d1, *d2;
	cout << "<-- - ptrobj1.cpp--->" << endl;
	d1 = new Date_2();
	d1->setDate(2, 3, 2001);
	d1->showDate();
}

void Date_2::setDate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

void Date_2::showDate()
{
	cout << "The date is ";
	cout << day << ":" << month << " : " << year << "\n";
}

// Write a program to demonstrate the parameter passing by value. Also check for side effects.

class Point
{
public:
	int xc, yc;
	void init(int i, int j);
	void show();
	friend int Distance(Point);
};

float distance(Point p);

void Valuepa1() {
	cout << "<-- - valuepa1.cpp--->" << endl;
	Point pt1;
	pt1.init(3, 4);
	cout << "distance from origin is ";
	cout << distance(pt1) << endl;
	pt1.show();
}

void Point::init(int i, int j)
{
	xc = i;
	yc = j;
}

void Point::show()
{
	cout << "xc = " << xc << " yc = " << yc << endl;
}

float distance(Point p)
{
	float temp;
	temp = sqrt(p.xc*p.xc + p.yc*p.yc);
	p.xc = 0; // note 1
	return temp;
}

// Write a program to illustrate the use of static inside a class.

class Player
{
public:
	char name[20];
	int age;
	int runs;
	static char *logo;
	void init(char * name1, int age1, int runs1);
	void show();
};

void Static3A(){
	Player p1, p2, p3;
	p1.init("sachin", 28, 7000);
	p2.init("saurav", 26, 5000);
	cout << "<-- - static3A.cpp--->" << endl;
	p1.show();
	p2.show();
	cout << "Size of class Player is " << sizeof(p1) << " bytes" << endl;
}

void Player::init(char * name1, int age1, int runs1)
{
	strcpy_s(name, name1);
	age = age1;
	runs = runs1;
}

void Player::show()
{
	cout << "showing details of a player\n";
	cout << "name : " << name << endl;
	cout << "age : " << age << endl;
	cout << "runs : " << runs << endl;
	cout << "logo : " << logo << endl;
}

char * Player::logo = "sahara";

// Write a program which counts the number of objects created in the program. Use a static method.

class Point_2
{
	int xc, yc;
public:
	Point_2(int i, int j);
	void show();
	static int num;
	static void show_total();
};

int Point_2::num = 0; // initialization of static data member

void Static5(){
	cout << "<-- - static5.cpp--->" << endl;
	Point_2 PT1(5, 5);
	Point_2 PT2(7, 9);
	Point_2 PT3(2, 3);
	Point_2::show_total();
}

Point_2::Point_2(int i, int j)
{
	xc = i;
	yc = j;
	num++;
}

void Point_2::show()
{
	cout << "Point = ";
	cout << "(" << xc;
	cout << ", " << yc << ")" << endl;
}

void Point_2::show_total()
{
	cout << "total Points created = "
		<< num << endl;
}

// Write a program to compare two time objects. Develop method compare() to decide whether time t1 is equal to time t2 or not.

class TIME
{
private:
	int hr, min, sec;
public:
	void set_time(int h, int m, int s);
	void show_time();
	friend int compare(TIME tx, TIME ty); //---1---
};

void Comapre1(){
	TIME t1, t2;
	cout << "<-- - compare1.cpp--->" << endl;
	t1.set_time(12, 12, 12);
	cout << " time t1 is ";
	t1.show_time();
	t2.set_time(13, 13, 13);
	cout << " time t2 is ";
	t2.show_time();
	cout << "are times equal ? ";
	if (compare(t1, t2)) //---2---
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

void TIME::set_time(int h, int m, int s) //method definition
{
	hr = h;
	min = m;
	sec = s;
}

void TIME::show_time() //method definition
{
	// cout << "The time is "<< endl;
	cout << hr << " : " << min << " : " << sec << endl;
}

int compare(TIME tx, TIME ty) //---3---
{
	int answer = 0;
	long s1, s2;
	s1 = ((tx.hr * 60) + tx.min) * 60 + tx.sec; //---4---
	s2 = ((ty.hr * 60) + ty.min) * 60 + ty.sec; //---5---
	if (s2 == s1) answer = 1;
	return answer;
}

// Write a program to find the total cost of books in library, using friend function.

class RefBooks; //Note 1. Advance declaration of RefBooks

class TextBooks
{
private:
	int qty;
	float price;
public:
	void getdata();
	void showdata();
	friend float ttlval(TextBooks & t, RefBooks & r);
	// 2. above line is not possible without 1.
};

class RefBooks
{
private:
	int qty;
	float price;
public:
	void getdata();
	void showdata();
	friend float ttlval(TextBooks & t, RefBooks & r);
};

void Library1() {
	TextBooks t1;
	RefBooks r1;
	float total;
	cout << "<-- - library1.cpp--->" << endl;
	t1.getdata();
	r1.getdata();
	total = ttlval(t1, r1);
	cout << "-- - Result-- - " << endl;
	//  t1.showdata();
	//  r1.showdata();
	cout << "Total value of Books = Rs." << total << endl;
}

float ttlval(TextBooks & t, RefBooks & r)
{
	float ans;
	ans = t.qty * t.price + r.qty * r.price;
	return ans;
}

void TextBooks::getdata()
{
	cout << "Enter details for Text Books " << endl;
	cout << "Number of books: ";
	cin >> qty;
	cout << "Average price of each book: ";
	cin >> price;
}

void RefBooks::getdata()
{
	cout << "Enter details for Reference Books " << endl;
	cout << "Number of books: ";
	cin >> qty;
	cout << "Average price of each book: ";
	cin >> price;
}

void TextBooks::showdata() {
	cout << "qty: " << qty << endl;
	cout << "price: " << price << endl;
}

void RefBooks::showdata() {
	cout << "qty: " << qty << endl;
	cout << "price: " << price << endl;
}

// Rewrite Program 5.9 with following modifications. Declare class RefBooks as friend in class TextBooks. 
// Declare method ttlval() in class RefBooks with object of class TextBooks as parameter(pass by value). Do not use any friend function.

class RefBooks_2; // 1. Advance declaration of RefBooks

class TextBooks_2
{
private:
	int qty;
	float price;
public:
	void getdata();
	void showdata();
	friend RefBooks_2;
};

class RefBooks_2
{
private:
	int qty;
	float price;
public:
	void getdata();
	void showdata();
	float ttlval(TextBooks_2 t);
};

void Lib2() {
	TextBooks_2 t1;
	RefBooks_2 r1;
	float total;
	cout << "<-- - lib2.cpp--->" << endl;
	t1.getdata();
	r1.getdata();
	total = r1.ttlval(t1);
	cout << "-- - Result-- - " << endl;
	cout << "Total value of Books = Rs." << total << endl;
}

float RefBooks_2::ttlval(TextBooks_2 t)
{
	float ans;
	ans = qty*price + t.qty * t.price;
	return ans;
}

void TextBooks_2::getdata()
{
	cout << "Enter details for Text Books " << endl;
	cout << "Number of books : ";
	cin >> qty;
	cout << "Average price of each book : ";
	cin >> price;
}

void TextBooks_2::showdata()
{
	cout << "Text Books " << endl;
	cout << "Number of books : " << qty << endl;
	cout << "Average price of a book : " << price << endl;
}

void RefBooks_2::getdata()
{
	cout << "Enter details for Reference Books " << endl;
	cout << "Number of books : ";
	cin >> qty;
	cout << "Average price of each book : ";
	cin >> price;
}

void RefBooks_2::showdata()
{
	cout << "Reference Books " << endl;
	cout << "Number of books : " << qty << endl;
	cout << "Average price of a book : " << price << endl;
}

// Write a program to illustrate static methods start, stop and show from a suitably defined timer class.

class BPtimer
{
private:
	static long t0;
	static time_t t00;
	static long t1;
	static time_t t01;
	static long t2;
	//static time_t t02;
public:
	static void start()
	{
		t0 = time(&t00);
	}
	static void stop()
	{
		t1 = time(&t01);
		t2 = t1 - t0;
	}
	static int show()
	{
		return t2;
	}
};

// Initialization of static members
long BPtimer::t0 = 0;
long BPtimer::t1 = 0;
long BPtimer::t2 = 0;
time_t BPtimer::t00 = 0;
time_t BPtimer::t01 = 0;

void Timer1() {
	int dummy;
	cout << "<-- - timer1.cpp--->" << endl;
	BPtimer::start();
	cout << "type an integer " << endl;
	cin >> dummy;
	BPtimer::stop();
	cout << "time measured = "
		<< BPtimer::show()
		<< " Seconds" << endl;
}

// Write a program to study use of non-static methods to measure time delay. Assume that a subsidiary event (like tea break) occurs during the main event (guest lecture). 
// Measure the gross time, which is the time for the main event as well as the time of the middle or subsidiary event.

class BPtimer_2
{
private:
	long t0;
	long t1;
	long t2;
	time_t t00;
	time_t t01;
public:
	void start()
	{
		t0 = time(&t00);
	}
	void stop()
	{
		t1 = time(&t01);
		t2 = t1 - t0;
	}
	int show()
	{
		return t2;
	}
	BPtimer_2()
	{
		t0 = t1 = t2 = 0;
	}
};

void Timer2() {
	int dummy1;
	BPtimer_2 tim1, tim2;
	cout << "<-- - timer2.cpp-- - >" << endl;
	cout << "main event starts" << endl;
	tim1.start();
	cout << "type an integer : ";
	cin >> dummy1;
	cout << "subsidiary event starts" << endl;
	tim2.start();
	cout << "type another number : ";
	cin >> dummy1;
	cout << "subsidiary event ends" << endl;
	tim2.stop();
	cout << "type one more number : ";
	cin >> dummy1;
	tim1.stop();
	cout << "main event ends" << endl;
	cout << "gross time = "
		<< tim1.show() << " Seconds" << endl;
	cout << "middle time = "
		<< tim2.show() << " Seconds" << endl;
}

// Define a class for complex number. Write a program to read and print the complex number.

class Complex
{
	double x, y;
public:
	void write();
	void read();
};

void Complex1() {
	Complex a;
	cout << "<-- - complex1.cpp--->" << endl;
	a.read();
	a.write();
}

void Complex::write()
{
	cout << "complex number is(";
	cout << x << " + j " << y << ") " << endl;
}

void Complex::read()
{
	double p, q;
	cout << "give real part : ";
	cin >> p;
	cout << "give imaginary part : ";
	cin >> q;
	x = p;
	y = q;
}

// Develop friend methods for adding and multiplying complex numbers.

class Complex_2
{
	double x, y;
public:
	void write();
	void read();
	friend Complex_2 addComplex(Complex_2 a, Complex_2 b);
	friend Complex_2 multiComplex(Complex_2 a, Complex_2 b);
	friend Complex_2 conjugateComplex(Complex_2 a);
	friend Complex_2 divideComplex(Complex_2 a, Complex_2 b);
	friend Complex_2 subtactComplex(Complex_2 a, Complex_2 b);
};

void Complex2() {
	Complex_2 a, b, c;
	double p, q;
	cout << "<-- - complex2.cpp--->" << endl;
	a.read();
	a.write();
	b.read();
	b.write();
	c = addComplex(a, b);
	cout << endl << "After addition " << endl;
	c.write();
	c = multiComplex(a, b);
	cout << endl << "After multiplication " << endl;
	c.write();
	c = subtactComplex(a, b);
	cout << endl << "After subtraction " << endl;
	c.write();
	c = divideComplex(a, b);
	cout << endl << "After dividing " << endl;
	c.write();
}

void Complex_2::write()
{
	cout << "complex number is ";
	cout << x << " + j" << y << endl;
}

void Complex_2::read()
{
	double    p, q;
	cout << "Give real part : ";
	cin >> p;
	cout << "Give imaginary part : ";
	cin >> q;
	x = p;
	y = q;
}

Complex_2 addComplex(Complex_2 a, Complex_2 b)
{
	Complex_2 z;
	z.x = (a.x) + (b.x);
	z.y = (a.y) + (b.y);
	return(z);
}

Complex_2 multiComplex(Complex_2 a, Complex_2 b)
{
	Complex_2 z;
	z.x = ((a.x)*(b.x)) - ((a.y)*(b.y));
	z.y = ((a.x)*(b.y)) + ((a.y)*(b.x));
	return(z);
}

// Write a program to demonstrate passing of objects by reference in C language style.

class Money
{
public:
	long rupee, paise;
	void init(long a, long b);
	void print();
};

void Double(Money * m) // note D capital
{
	long temp;
	int carry = 0;
	temp = m->paise * 2;
	if (temp >= 100)
	{
		m->paise = temp - 100;
		carry = 1;
	}
	else m->paise = temp;
	m->rupee = m->rupee * 2 + carry;
}

void Cstyle1() {
	cout << "<-- - cstyle1.cpp--->" << endl;
	Money amt1;
	Money *amt2 = new Money();
	amt1.init(150, 20);
	amt2->init(250, 70);
	cout << "before doubling" << endl;
	amt1.print();
	Double(&amt1);
	cout << "after doubling" << endl;
	amt1.print();
	cout << "before doubling" << endl;
	amt2->print();
	Double(amt2);
	cout << "after doubling" << endl;
	amt2->print();
}

void Money::init(long a, long b)
{
	rupee = a;
	paise = b;
};

void Money::print()
{
	cout << "Amount is Rs ";
	cout << rupee << " = ";
	cout.fill('0'); cout.width(2);
	cout << paise << " / -" << endl;
}

///////////////////////////
////       TASKS       ////
/////////////////////////// 

// 1. What is a class in C++? How does it compare with structure in C?

// 2. Define the following terms with the help of meaningful examples:
//    1. Objects
//    2. Class
//    3. Method
//    4. Encapsulation

// 3. What are access specifiers? List all the three access specifiers and discuss their advantages and disadvantages.

// 4. Explain what are merits and demerits of passing objects as a value parameter?

// 5. Explain what are merits and demerits of passing objects as a variable parameter?

// 6. What are inline functions? What are the advantages of inline functions?

// 7. Explain with an example the use of �Friend� function.

// 8. What are friend functions? What are its implications on information hiding?

// 9. What are static class members? What are their advantages and disadvantages?

// 10. Can a function return an object?

// 11. What will happen if all the data members and methods of a class are private?

// 12. Explain the ideal class definition.

// 13. For the class defined earlier for complex numbers, develop functions for the following tasks.
//     1. Divide a complex number by another.
//     2. Subtract one complex number from the other.
//     3. Find the conjugate of a complex number.

Complex_2 conjugateComplex(Complex_2 a)
{
	Complex_2 z;
	z.x = a.x;
	z.y = -1 * a.y;
	return(z);
}

Complex_2 subtactComplex(Complex_2 a, Complex_2 b)
{
	Complex_2 z;
	z.x = (a.x) - (b.x);
	z.y = (a.y) - (b.y);
	return(z);
}

Complex_2 divideComplex(Complex_2 a, Complex_2 b)
{
	Complex_2 con = conjugateComplex(b);
	Complex_2 numerator = multiComplex(a, con);
	Complex_2 denominator = multiComplex(b, con);
	Complex_2 z;
	z.x = numerator.x / denominator.x;
	z.y = numerator.y / denominator.x;

	return(z);
}

// 14. In simple class Date, add Boolean method isLeap() which tests if the year is leap year or not.

bool Date::isLeap() {
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			// year is divisible by 400, hence the year is a leap year
			if (year % 400 == 0)
				//cout << year << "is a leap year." << endl;
				return 1;
			else
				//cout << year << "is not a leap year." << endl;
				return 0;
		}
		else
			//cout << year << "is a leap year." << endl;
			return 1;
	}
	else
		//cout << year << "is not a leap year." << endl;
		return 0;
}

// 15. In simple class Date, add boolean method validate() which validates the date value. Validating requires checking the value of variable day. 
//     It should be greater than zero and less than or equal to maximum value for the given month. Hint: Use previously developed method isleap().

bool Date::validate() {

	if (year > 0 && year < 2019) {
		if (month > 0 && month < 12){
			if (day > 0 && day < 31) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}

}

// 16. In simple class Point, design a friend method which calculates and returns the Distance of that point from origin.

int Distance(Point p) {
	return sqrt(pow(p.xc,2)+pow(p.yc,2));
}

// 17. Declare a class FixedDeposit with two long members as rupee, paise and an integer member period. Develop method long maturityAmount() returning maturity amount assuming 10% interest rate. 

class FixedDeposit {
	long rupee, paise;
	int period;
public:
	FixedDeposit(long r, long pa, int pe);
	long maturityAmount();
};

long FixedDeposit::maturityAmount() {
	return period * (100 * rupee + paise) * 0.1;
}

void Deposit() {
	FixedDeposit df(10, 32, 5);
	cout << "the interest is : " << df.maturityAmount() << endl;

}

FixedDeposit::FixedDeposit(long r, long pa, int pe) {
	rupee = r;
	paise = pa;
	period = pe;
}

// 18. Declare class circle with integer attributes xcor, ycor and rad declared private. Declare a class Point with private attributes x and y. 
//     Define boolean function inCircle(Circle c1, Point p1) to test whether the point p1 is inside the circle c1. Is it necessary that this function is a friend function? If not, then in which class should it be declared?

class Point_3;

class Circle {
	int xcor, ycor, rad;
public:
	Circle(int, int, int);
	friend bool inCircle(Circle c1, Point_3 p1);
};

class Point_3 {
	int x, y;
public:
	Point_3(int, int);
	friend bool inCircle(Circle c1, Point_3 p1);
};

void CheckInCircle() {
	Circle c(4 , 4, 7);
	Point_3 p(5, 6);

	bool in = inCircle(c, p);
	if (in)
		cout << "the given point is inside the given circle!" << endl;
	else
		cout << "the given point is not inside the given circle!" << endl;
}

bool inCircle(Circle c1, Point_3 p1) {
	float distance = sqrt(pow(c1.xcor - p1.x, 2) + pow(c1.ycor - p1.y, 2));
	if (distance < c1.rad)
		return true;
	else
		return false;
}

Circle::Circle(int x, int y, int r) {
	xcor = x;
	ycor = y;
	rad = r;
}

Point_3::Point_3(int x, int y) {
	x = x;
	y = y;
}

// 19. Declare a class SavingsBankAccount with private data members accNum and balance. If you have to include attribute rateOfInterest, will you make it static? Write a small program using few objects of this class.

class SavingsBankAccount {
	int accNum, balance;
};

// 20. Define a class Box with attributes length, breadth and height. Write a program to find the volume of the box using method volume().

class Box {
	int length, breadth, height;
public:
	Box(int, int, int);
	int Volume();
};

void GetVolume() {
	Box b(3, 4, 7);
	cout << "volume of box: " << b.Volume() << endl;
}

Box::Box(int l, int b, int h) {
	length = l;
	breadth = b;
	height = h;
}

int Box::Volume() {
	return length * breadth * height;
}

// 21. Design a class Card to represent standard playing card. It should have at least one member to store the value and at least one method to display (show() or print() ).

class Card {
	int value;
public:
	Card(int);
	void print();
};

void CardGame() {
	Card c(5);
	c.print();
}

Card::Card(int c) {
	value = c;
}

void Card::print() {
	cout << value << endl;
}
