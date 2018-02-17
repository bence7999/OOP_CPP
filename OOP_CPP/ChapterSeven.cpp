#include "ChapterSeven.h"

using namespace std;

namespace chapterSeven {

	// Write a program to show overloading of unary operator.

	class Complex
	{
		double x, y;
	public:
		Complex(double a, double b);
		void show();
		Complex operator~();
	};

	void Over1A() {
		Complex a(3, 4);
		Complex b(0, 0);
		double p, q;
		cout << "<-- - over1A.cpp--->" << endl;
		cout << "original number a" << endl;
		a.show();
		b = ~a;
		cout << "complex conjugate" << endl;
		b.show();
	}

	Complex::Complex(double a, double b)
	{
		x = a;
		y = b;
	}

	void Complex::show()
	{
		cout << "complex number is ";
		cout << x << " + i " << y << endl;
	}

	Complex Complex::operator~ () // Complex conjugate
	{
		Complex temp(0, 0);
		temp.x = x;
		temp.y = -1 * y;
		return temp;
	}

	// Write a program to demonstrate overloading of operators. Overload operators + and * in the class Complex.

	class Complex_2
	{
		double x, y;
	public:
		void show();
		void read();
		Complex_2 operator+(Complex_2 b);
		Complex_2 operator*(Complex_2 b);
	};

	void Over3() {
		Complex_2 a, b, c;
		double p, q;
		cout << "<-- - over3.cpp--->" << endl;
		a.read();
		a.show();
		b.read();
		b.show();
		c = a + b;
		cout << "after addition" << endl;
		c.show();
		c = a*b;
		cout << "after multiplication" << endl;
		c.show();
	}

	void Complex_2::show()
	{
		cout << "complex number is ";
		cout << x << " + i" << y << endl;
	}

	void Complex_2::read()
	{
		double p, q;
		cout << "give real part : ";
		cin >> p;
		cout << "give imaginary part : ";
		cin >> q;
		x = p;
		y = q;
	}

	Complex_2 Complex_2::operator+ (Complex_2 b)
	{
		Complex_2 z;
		z.x = x + (b.x);
		z.y = y + (b.y);
		return(z);
	}

	Complex_2 Complex_2::operator* (Complex_2 b)
	{
		Complex_2 z;
		z.x = (x*(b.x) - y*(b.y));
		z.y = (x*(b.y) + y*(b.x));
		return(z);
	}

	// Write a program to calculate the interest amount, given the amount and interest rate.

	class IndCur
	{
		long rupee, paise;
	public:
		void print();
		// IndCur() ;
		IndCur(long a, long b);
		IndCur operator*(float rate);
		void operator = (IndCur a);
	};

	void Money5A() {
		cout << "<-- - money5A.cpp--->" << endl;
		IndCur amt1(1000, 50), amt2(0, 0);;
		amt1.print();
		amt2 = (amt1 * 0.12);
		cout << "after multiplying by rate 0.12" << endl;
		amt2.print();
	}

	void IndCur::print()
	{
		cout << "Amount is Rs ";
		cout << rupee << " = ";
		cout.fill('0'); cout.width(2);
		cout << paise << " / -" << endl;
	}

	IndCur::IndCur(long p, long q)
	{
		if ((p < 0) || (q < 0) || (q > 99))
		{
			cout << "initialsation error" << endl;
			cout << "terminating the program" << endl;
			exit(1);
		}
		else
		{
			rupee = p;
			paise = q;
		}
	}

	IndCur IndCur::operator*(float rate)
	{
		IndCur temp(0, 0);
		long dummy;
		dummy = rupee * 100 + paise;
		dummy = floor(double(dummy) * rate + 0.5);
		temp.rupee = dummy / 100;
		temp.paise = dummy % 100;
		return temp;
	}

	void IndCur::operator = (IndCur a)
	{
		rupee = a.rupee;
		paise = a.paise;
	}

	// Write a program to demonstrate binary operator overloading of case 3.

	class IndCur1
	{
		long rupee, paise;
	public:
		void print();
		IndCur1(long a, long b);
		friend IndCur1 operator*(float rate, IndCur1 amt);
	};

	void Money9() {
		cout << "<-- - money9.cpp--->" << endl;
		IndCur1 amt1(1000, 50);
		IndCur1 amt2(0, 0);
		amt1.print();
		amt2 = 1.12 *amt1;
		cout << "after multiplying by 1.12" << endl;
		amt2.print();
	}

	void IndCur1::print()
	{
		cout << "Amount is Rs ";
		cout << rupee << " = ";
		cout.fill('0'); cout.width(2);
		cout << paise << " / -" << endl;
	}

	IndCur1::IndCur1(long p, long q)
	{
		if ((p < 0) || (q < 0) || (q > 99))
		{
			cout << "initialization error" << endl;
			cout << "terminating the program" << endl;
			exit(1);
		}
		else
		{
			rupee = p;
			paise = q;
		}
	}

	IndCur1 operator*(float rate, IndCur1 amt)
	{
		IndCur1 temp(0, 0);
		long dummy;
		dummy = amt.rupee * 100 + amt.paise;
		dummy = floor(double(dummy) * rate + 0.5);
		temp.rupee = dummy / 100;
		temp.paise = dummy % 100;
		return temp;
	}

	// Write a program to overload binary arithmetic operator plus-equal-to (+=) using friend function.

	class DISTANCE
	{
		int feet, inches;
	public:
		DISTANCE(int f, int i);
		void show();
		DISTANCE operator+=(DISTANCE b);
	};

	void Dist2() {
		DISTANCE a(2, 3), b(4, 7), c(0, 0);
		cout << "<-- - dist2.cpp--->" << endl;
		a.show();
		b.show();
		c = a += b;
		cout << "after addition" << endl;
		a.show();
		c.show();
	}

	void DISTANCE::show()
	{
		cout << "distance is ";
		cout << feet << " : " << inches << endl;
	}

	DISTANCE::DISTANCE(int f, int i)
	{
		feet = f;
		inches = i;
	}

	DISTANCE DISTANCE::operator+= (DISTANCE b)
	{
		feet = feet + (b.feet);
		inches = inches + (b.inches);
		return *this;
	}

	// Write a program to overload binary arithmetic operator plus (+) using friend function.

	class Interest; // advance declaration

	class Amount
	{
		long rupee, paise;
	public:
		void print();
		Amount();
		Amount(long p, long q);
		friend Amount operator+(Amount a1, Interest a2);
	};

	class Interest
	{
		long ru, ps;
		int dd, mm, yy;
	public:
		Interest(long p, long q, int dd = 30, int mm = 9, int yy = 9);
		friend Amount operator+(Amount a1, Interest a2); // note 1B
	};

	void Friend3() {
		cout << "<-- - friend3.cpp--->" << endl;
		Amount amt1(50000, 0), amt2;
		Interest int1(5500, 50);
		amt1.print();
		// Adding interest
		amt2 = amt1 + int1;
		cout << "after adding interest" << endl;
		amt2.print();
	}

	void Amount::print()
	{
		cout << "Amount is Rs ";
		cout << rupee << " = ";
		cout.fill('0'); cout.width(2);
		cout << paise << " / -" << endl;
	}

	Amount::Amount()
	{
		rupee = 0;
		paise = 0;
	}

	Amount::Amount(long p, long q)
	{
		rupee = p;
		paise = q;
	}

	Amount operator+(Amount a1, Interest a2)
	{
		Amount temp(0, 0);
		temp.rupee = a1.rupee + a2.ru;
		temp.paise = a1.paise + a2.ps;
		if (temp.paise >= 100)
		{
			temp.paise -= 100;
			temp.rupee += 1;
		}
		return temp;
	}

	Interest::Interest(long p, long q, int dd, int mm, int yy)
	{
		ru = p;
		ps = q;
	}

	// Write a program to overload both prefix and postfix operator ++ (with meaning increment) in class RatNum. Evaluate an expression using both types of operators.

	long gcd(long a, long b); // Greatest common divisor

	class RatNum
	{
		long num, den;
	public:
		RatNum(long a, long b);
		void show();
		RatNum operator+(RatNum nx);
		RatNum operator++();
		RatNum operator++(int);
		void adjust();
	};

	void Inc2() {
		RatNum n1(1, 1), n2(1, 1), n3(1, 1);
		cout << "<-- - inc2.cpp--->" << endl;
		cout << "n1 is : ";
		n1.show();
		cout << "n2 is : ";
		n2.show();
		cout << "Now adding n1++ + ++n2 " << endl;
		n3 = n1++ + ++n2;
		cout << "result is : ";
		n3.show();
		cout << "n1 is : ";
		n1.show();
		cout << "n2 is : ";
		n2.show();
	}

	RatNum::RatNum(long a, long b)
	{
		num = a;
		den = b;
		adjust();
	}

	void RatNum::show()
	{
		adjust();
		cout << num << " / " << den << endl;
	}

	RatNum RatNum::operator+(RatNum nx)
	{
		RatNum temp(1, 1);
		temp.num = this->num * nx.den + this->den * nx.num;
		temp.den = this->den * nx.den;
		return temp;
	}

	RatNum RatNum::operator++()
	{// this is prefix ++ operation
		RatNum temp(1, 1); //arbitrary initialization
		num = num + den; // pre - increment
		temp.num = num;
		temp.den = den;
		return temp;
	}

	RatNum RatNum::operator++(int)
	{
		RatNum temp(1, 1);
		temp.num = num;
		temp.den = den; //return value created first
		num = num + den; //increment
		return temp; // previously created value now returned
	}

	void RatNum::adjust()
	{
		long temp;
		if (den == 0)
		{
			cout << "division by zero" << endl;
			cout << "exiting from the program " << endl;
			exit(1);
		};
		temp = gcd(num, den);
		num = num / temp;
		den = den / temp;
	}

	long gcd(long a, long b)
	{
		long num1, num2, temp;
		if (a >= b) { num1 = a; num2 = b; }
		else { num1 = b; num2 = a; };
		while (num2 != 0)
		{
			temp = num1%num2;
			num1 = num2;
			num2 = temp;
		}
		return num1;
	}

	// Write a program to demonstrate conversion function.

	class Amount_2
	{
		long rupee, paise;
	public:
		void print();
		Amount_2();
		Amount_2(long p, long q);
		friend Amount_2 operator+(Amount_2 a1, Amount_2 a2);
	};

	class Interest_2
	{
		long ru, ps;
		int dd, mm, yy;
	public:
		Interest_2(long p, long q, int dd = 30, int mm = 9, int yy = 9);
		/*Amount*/  operator Amount_2();   // Note 1
	};

	void Conver1() {
		cout << "<-- - conver1.cpp--->" << endl;
		Amount_2 amt1(10000, 0), amt2;
		Interest_2 int1(1100, 50);
		amt1.print();
		//   Adding interest
		amt2 = amt1 + (Amount_2)int1;
		cout << "after adding interest" << endl;
		amt2.print();
	}

	void Amount_2::print()
	{
		cout << "Amount is Rs  ";
		cout << rupee << " = ";
		cout.fill('0'); cout.width(2);
		cout << paise << " / -" << endl;
	}

	Amount_2::Amount_2()
	{
		rupee = 0;
		paise = 0;
	}

	Amount_2::Amount_2(long p, long q)
	{
		rupee = p;
		paise = q;
	}

	Amount_2 operator+(Amount_2 a1, Amount_2 a2)
	{
		Amount_2 temp(0, 0);
		temp.rupee = a1.rupee + a2.rupee;
		temp.paise = a1.paise + a2.paise;
		if (temp.paise >= 100)
		{
			temp.paise -= 100;
			temp.rupee += 1;
		}
		return temp;
	}

	Interest_2::Interest_2(long p, long q, int dd, int mm, int yy)
	{
		ru = p;
		ps = q;
	}

	Interest_2:: operator Amount_2()
	{
		Amount_2 X(ru, ps); // note2
		return X;
	}

	// Write a program to overload assignment (=) operator.

	class Point
	{
	private:
		int xc, yc;
	public:
		Point(int i, int j);
		// Note1
		void operator =(Point dd)
		{
			cout << "explicit overloading" << endl;
			xc = dd.xc;
			yc = dd.yc;
		}
		void show();
		friend ostream & operator << (ostream & temp, Point p);
	};

	void Assign1() {
		Point   pt1(5, 5), pt2(6, 6);
		cout << "<-- - assign1.cpp--->" << endl;
		pt2.show();
		pt2 = pt1; // Notice assignment operation
				   //  pt2.operator=(pt1);  // note 2
		pt2.show();
	}

	Point::Point(int i, int j)
	{
		xc = i;   yc = j;
	}

	void Point::show()
	{
		cout << "Point = ";
		cout << "(" << xc;
		cout << ", " << yc << ")" << endl;
	}

	// Write a program to overload operator "<<". Use return by reference.

	class Point_2
	{
	private:
		int xc, yc;
	public:
		Point_2(int i, int j);
		friend ostream & operator << (ostream & temp, Point_2 p);
	};

	void Point5() {
		Point_2 PT1(5, 5);
		Point_2 PT2(10, 10);
		cout << "<-- - point5.cpp--->" << endl;
		cout << "showing PT1 " << endl;
		cout << PT1;
		cout << "showing chaining" << endl;
		cout << PT2 << PT1 << endl;
	}

	Point_2::Point_2(int i, int j)
	{
		xc = i; yc = j;
	}

	ostream & operator << (ostream & temp, Point_2 p)
	{
		temp << "Coordinates " << p.xc << "--" << p.yc << endl;
		return temp;
	}

	// Write a program to overload both unary as well as binary operator in a single class say Complex.

	class COMPLEX_3
	{
		double x, y;
	public:
		COMPLEX_3(double a, double b);
		void write();
		void read();
		COMPLEX_3 operator~();
		COMPLEX_3 operator*(COMPLEX_3 b);
	};

	void Both1() {
		COMPLEX_3 a(3, 4), b(5, -12), c(0, 0);
		double p, q;
		cout << "<-- - both1.cpp--->" << endl;
		c = a * ~a;
		cout << "a * ~a " << endl;
		c.write();
		c = b * ~b;
		cout << "b * ~b " << endl;
		c.write();
	}

	COMPLEX_3::COMPLEX_3(double a, double b)
	{
		x = a;
		y = b;
	}

	void COMPLEX_3::write()
	{
		cout << "complex number is ";
		cout << x << " + i " << y << endl;
	}

	void COMPLEX_3::read()
	{
		double p, q;
		cout << "give real part : ";
		cin >> p;
		cout << "give imaginary part : ";
		cin >> q;
		x = p;
		y = q;
	}

	COMPLEX_3 COMPLEX_3::operator~ ()
	{
		COMPLEX_3 z(0, 0);
		z.x = x;
		z.y = -1 * y;
		return(z);
	}

	COMPLEX_3 COMPLEX_3::operator* (COMPLEX_3 b)
	{
		COMPLEX_3 z(0, 0);
		z.x = (x*(b.x) - y*(b.y));
		z.y = (x*(b.y) + y*(b.x));
		return(z);
	}

	// Design a class ‘polar’ which describes a point in the plain using polar co-ordinates: ‘radius’ and ‘angle’, such a point is shown below: 
	// Use the overloaded ‘+’ operator to add two objects of ‘Polar’ with the help of following formulae: 

	const double M_PI = 3.14159265359;

	double radians(double x)
	{
		return x / 180.0*M_PI;
	}

	double degrees(double x)
	{
		return x / M_PI*180.0;
	}

	class polar
	{
	private:
		double mag, ang;
	public:
		polar(double magnitude, double angle)
		{
			mag = magnitude;
			ang = angle;
		}
		void print();
		friend void polar_to_rect(polar p, double & x, double & y);
		polar operator + (polar py);
	};

	void Polar1() {
		cout << "<-- - polar1.cpp--->" << endl;
		polar *p1, *p2, *p3;
		p1 = new polar(10, radians(30));
		p2 = new polar(10, radians(60));
		p3 = new polar(0, 0); // arbitrary initialization
		p1->print();
		*p3 = *p1 + *p2;
		p3->print();
	}

	void polar::print()
	{
		cout << "Point " << mag << " / _" << degrees(ang) << endl;
	}

	void polar_to_rect(polar p1, double & x, double & y)
	{
		x = p1.mag * cos(p1.ang);
		y = p1.mag * sin(p1.ang);
	}

	polar polar::operator + (polar py)
	{
		double x1, y1, x2, y2;
		polar pz(0, 0);
		polar_to_rect(py, x1, y1);
		polar_to_rect(*this, x2, y2);
		//   x = Y cos (a)
		pz.ang = atan((y1 + y2) / (x1 + x2));
		// y = Y sin (a)
		pz.mag = sqrt((x1 + x2)*(x1 + x2)
			+ (y1 + y2)*(y1 + y2));
		return pz;
	}

	// Write a program to overload + operator for adding rational number.

	long gcd2(long, long);

	class RatNum_2
	{
		long num, den;
		double value;
	public:
		RatNum_2(long a, long b);
		void show();
		RatNum_2 operator+(RatNum_2 nx);
		RatNum_2 operator*(RatNum_2 nx);
		void adjust();
	};

	void Ratnum1() {
		RatNum_2 n1(7, 13), n2(6, 13), n3(26, 7), n4(1, 1);
		cout.precision(10);
		cout.width(10);
		cout.setf(ios::showpoint);
		cout << "<-- - ratnum1.cpp--->" << endl;
		n1.show();
		n2.show();
		cout << "showing n1 + n2 " << endl;
		n4 = n1 + n2;
		n4.show();
		cout << "showing n1 * n3 " << endl;
		n4 = n1*n3;
		n4.show();
	}

	RatNum_2::RatNum_2(long a, long b)
	{
		num = a;
		den = b;
		adjust();
	}

	void RatNum_2::show()
	{
		adjust();
		cout << "rational number ";
		cout << num << " / " << den << endl;
	}

	RatNum_2 RatNum_2::operator*(RatNum_2 nx)
	{
		RatNum_2 temp(1, 1); //arbitrary initialization
		temp.num = this->num * nx.num;
		temp.den = this->den * nx.den;
		return temp;
	}

	RatNum_2 RatNum_2::operator+(RatNum_2 nx)
	{
		RatNum_2 temp(1, 1);
		temp.num = this->num * nx.den + this->den * nx.num;
		temp.den = this->den * nx.den;
		return temp;
	}

	void RatNum_2::adjust()
	{
		long temp;
		if (den == 0)
		{
			cout << "division by zero" << endl;
			cout << "exiting from the program " << endl;
			exit(1);
		};
		temp = gcd2(num, den);
		num = num / temp;
		den = den / temp;
	};

	long gcd2(long a, long b)
	{
		long num1, num2, temp;
		if (a >= b) { num1 = a; num2 = b; }
		else { num1 = b; num2 = a; };
		while (num2 != 0)
		{
			temp = num1%num2;
			num1 = num2;
			num2 = temp;
		}
		return num1;
	}

	///////////////////////////
	////       TASKS       ////
	/////////////////////////// 

	// 1. What is operator overloading?

	// 2. Differentiate between function overloading and operator overloading by giving examples.

	// 3. List the operators that cannot be overloaded. What may be the reasons for the same?

	// 4. What are the limitations of operator overloading?

	// 5. What is operator overloading? What is the use of operator overloading? If the meaning of any operator is changed, will compiler generate error?

	// 6. Is it possible for operator function to return by reference? If yes develop a suitable application using this principle.

	// 7. What differences exist between overloading of binary and unary operators?

	// 8. Can we overload ++ as well as -- operator? What about pre- and post-increment?

	// 9. What do you understand by conversion function? Discuss various types (flavours) of conversion functions.

	// 10. Explain the technique of type conversion from one class type to another class type with example.

	// 11. We have two classes ‘X’ and ‘Y’. If ‘a’ is an object of X and ‘b’ is an object of Y and we want to say “a=b”. What type of conversion routine should be used and where?

	// 12. Define simple class Vector and write a program to overload arithmetic operator plus(+) for adding vectors.

	class Vektor
	{
	public:
		Vektor();
		Vektor(int, int);
		~Vektor();
		Vektor operator+(Vektor v);
		void show();
	private:
		int magnitude, direction;
	};

	void VektorAddOperator() {
		Vektor v1(2, 3), v2(1, 2), v3;
		v1.show();
		v2.show();
		v3 = v1 + v2;
		v3.show();
	}

	Vektor::Vektor() {
		this->magnitude = 0;
		this->direction = 0;
	}

	Vektor::Vektor(int m, int d)
	{
		this->magnitude = m;
		this->direction = d;
	}

	Vektor Vektor::operator+(Vektor v) {
		Vektor tmp;
		tmp.direction = this->direction + v.direction;
		tmp.magnitude = this->magnitude + v.magnitude;
		return tmp;
	}

	void Vektor::show() {
		cout << "{" << this->magnitude << "," << this->direction << "}" << endl;
	}

	Vektor::~Vektor()
	{
	}

	// 13. Design classes PolarPoint and RectaPoint. Both the classes are for points such that first one is based on polar coordinates while the other stores rectangular co-ordinates. 
	//     Overload assignment (=) operator to copy an object of PolarPoint class to object of RectaPoint class.

	class RectaPoint;

	class PolarPoint
	{
	public:
		PolarPoint(float, float);
		~PolarPoint();
		void operator=(RectaPoint);
		void show();
		float getDistance() {
			return distance;
		}
		float getAngle() {
			return angle;
		}
	private:
		float distance, angle;
	};

	PolarPoint::PolarPoint(float d, float a) {
		this->angle = a * M_PI / 180;
		this->distance = d;
	}

	PolarPoint::~PolarPoint() {}

	class RectaPoint
	{
	public:
		RectaPoint(float, float);
		~RectaPoint();
		float getx() {
			return xc;
		}
		float gety() {
			return yc;
		}
		void operator=(PolarPoint);
		void show();
	private:
		float xc, yc;
	};

	RectaPoint::RectaPoint(float x, float y) {
		this->xc = x;
		this->yc = y;
	}

	RectaPoint::~RectaPoint() {}

	void PolarEqualRecta() {
		PolarPoint pp1(10, 45), pp2(0, 0);
		pp1.show();
		RectaPoint rp1(7.07, 7.07), rp2(0, 0);
		rp1.show();

		pp2 = rp1;
		pp2.show();

		rp2 = pp1;
		rp2.show();
	}

	void PolarPoint::show() {
		cout << "Polar co: distance: " << this->distance << " angle: " << this->angle * 180 / M_PI << endl;
	}

	void PolarPoint::operator=(RectaPoint rp) {
		this->distance = sqrt(pow(rp.getx(), 2) + pow(rp.gety(), 2));
		this->angle = atan(rp.getx() / rp.gety());
	}

	void RectaPoint::show() {
		cout << "Certangular co: x: " << this->xc << " y: " << this->yc << endl;
	}

	void RectaPoint::operator=(PolarPoint pp) {
		this->xc = pp.getDistance() * cos(pp.getAngle());
		this->yc = pp.getDistance() * sin(pp.getAngle());
	}

	// 14. For classes PolarPoint and RectaPoint (from previous problem) design conversion functions to convert object of one type to another. 
	//     It goes without saying that such functions will be substitute for overloaded assignment operator.

	// 15. Create a class Float that contains one float data member; overload all four arithmetic operators, so that they operate on the objects of Float.

	class Float
	{
	public:
		Float(float);
		~Float();
		Float operator+(Float);
		Float operator-(Float);
		Float operator*(Float);
		Float operator/(Float);
		Float operator^(int);
		friend ostream & operator <<(ostream&, Float);
	private:
		float data;
	};

	Float::Float(float f) {
		this->data = f;
	}

	Float::~Float() {}

	void UserFloat() {
		Float f1(1), f2(2), f3(0);
		cout << "float1: " << f1 << endl;
		cout << "float2: " << f2 << endl;
		f3 = f1 + f2;
		cout << "float1 + float2: " << f3 << endl;
		f3 = f1 - f2;
		cout << "float1 - float2: " << f3 << endl;
		f3 = f1 * f2;
		cout << "float1 * float2: " << f3 << endl;
		f3 = f1 / f2;
		cout << "float1 / float2: " << f3 << endl;
	}

	Float Float::operator+(Float f) {
		Float tmp(0);
		tmp.data = this->data + f.data;
		return tmp;
	}

	Float Float::operator-(Float f) {
		Float tmp(0);
		tmp.data = this->data - f.data;
		return tmp;
	}

	Float Float::operator*(Float f) {
		Float tmp(0);
		tmp.data = this->data * f.data;
		return tmp;
	}

	Float Float::operator/(Float f) {
		Float tmp(0);
		tmp.data = this->data / f.data;
		return tmp;
	}

	ostream & operator << (ostream & temp, Float f) {
		temp << f.data;
		return temp;
	}

	// 16. Overload ‘^’ operator for calculating power function value (for example 8=2^3). Write a program to test this operator. 
	//     Use a simple class Float which stores floating point numbers. Check your answer with function pow().

	void OverloadPow() {
		Float f1(3), f2(0);
		cout << "float1: " << f1 << endl;

		f2 = f1 ^ 3;
		cout << f2 << endl;
	}

	Float Float::operator^(int p) {
		Float tmp(0);
		tmp.data = pow(this->data, p);
		return tmp;
	}

	// 17. Design classes Dollar and Rupee support the following statements:
	//     d1 = Dollar ( r1) ;
	//     r2 = (Rupee) d2 ;
	//     Write a complete program which does such conversions according to the world market value.
	//     Take $ 1 = Rupees 39.45 as a conversion factor.

	class Rupee;

	class Dollar
	{
	public:
		Dollar(float);
		Dollar(Rupee);
		~Dollar();
		operator Rupee();
		void show();
		float getDollar() {
			return dollar;
		}
	private:
		float dollar;
	};

	class Rupee
	{
	public:
		Rupee(float);
		~Rupee();
		operator Dollar();
		void show();
		float getRupee() {
			return rupee;
		}
	private:
		float rupee;
	};

	Dollar::Dollar(float d) {
		this->dollar = d;
	}

	Dollar::Dollar(Rupee r) {
		float rate = 39.45;
		this->dollar = r.getRupee() / rate;
	}

	Dollar::~Dollar() {}

	Rupee::Rupee(float r){
		this->rupee = r;
	}

	Rupee::~Rupee() {}

	void DollarToRupee() {
		Dollar d1(5), d2(7);
		Rupee r1(40), r2(2);
		d1 = Dollar (r1);
		r2 = (Rupee) d2;

		d1.show();
		d2.show();
		r1.show();
		r2.show();
	}

	void Dollar::show() {
		cout << "Dollar: " << this->dollar << endl;
	}

	void Rupee::show() {
		cout << "Rupee: " << this->rupee << endl;
	}

	Dollar:: operator Rupee() {
		float rate = 39.45;
		Rupee r(rate * dollar);
		return r;
	}

	// 18. Let pt1 be the object of class Point. Is it possible that following statement
	//     pt1 << cout ;
	//     prints the object value. If possible write the complete program.

	ostream & operator << (ostream & temp, Point p) {
		temp << "x: " << p.xc << " y: " << p.yc;
		return temp;
	}

	void PrintPoint() {
		Point pt1(1, 1);
		cout << pt1 << endl;
	}

	// 19. Design a conversion function to convert a rational number to double value.

	class RationalNum
	{
	public:
		RationalNum(float);
		~RationalNum();
		void show();
		friend double rational_to_double(RationalNum);
	private:
		int p, q;
	};

	RationalNum::RationalNum(float n){
		float num = n;
		num = abs(num);
		num -= int(num);
		for(int i = 0; i < 5; i++) {
			num = num * 10;
			num -= int(num);
		}
		long divisor = pow(10, 5);
		long nn = n*divisor;
		long GrCoDi = gcd(nn, divisor);
		this->p = n * divisor / GrCoDi;
		this->q = divisor / GrCoDi;
	}

	RationalNum::~RationalNum()
	{
	}

	void RationalToDouble() {
		RationalNum r(3.56), r2(3), r3(3.5);
		double d = rational_to_double(r);
		cout << d << endl;
	}

	void RationalNum::show() {
		cout << "p: " << p << " q: " << q << endl;
	}

	double rational_to_double(RationalNum rn) {
		double d = (double) rn.p / (double) rn.q;
		return d;
	}
	
}