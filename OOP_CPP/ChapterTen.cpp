#include "ChapterTen.h"

using namespace std;

namespace ChapterTen {

	// Write a program to display a digital clock. Use the principle of multiple inheritance for class clock.

	class Time1
	{
	protected:
		int hr;
		int min;
		int sec;
	public:
		Time1(int h, int m, int s);
		void showTime();
	};

	class Date
	{
	protected:
		int date, month, year;
	public:
		Date(int d, int m, int y);
		void showDate();
	};

	Time1::Time1(int h, int m, int s)
	{
		hr = h;
		min = m;
		sec = s;
	}

	class Clock : public Time1, public Date
	{
	private:
		char strg[5];
	public:
		Clock(int h, int m, int s, int da, int mo, int ye);
		void show();
	};

	void Dclock1() {
		class Clock t(11, 59, 40, 15, 8, 2010);
		cout << "DIGITAL CLOCK" << endl;
		t.show();
	}

	void Time1::showTime()
	{
		cout << hr << " :";
		cout << min << " : ";
		cout << sec << "\n";
	}

	Clock::Clock(int h, int m, int s, int da, int mo, int ye) :Time1(h, m, s), Date(da, mo, ye)
	{
		if (h >= 12) strcpy_s(strg, "PM");
		else strcpy_s(strg, "AM");
	};

	void Clock::show()
	{
		cout << setw(2) << hr << " : ";
		cout << setw(2) << min << " : ";
		cout << setw(2) << sec << " ";
		cout << strg << endl;
		cout << date << " : " << month << " : " << year << endl;
	}

	Date::Date(int d, int m, int y)
	{
		date = d;
		month = m;
		year = y;
	}

	void Date::showDate()
	{
		cout << date << " : " << month << " : " << year << "\n";
	}

	// Write a program to demonstrate multilevel inheritance with data members declared “protected”.

	class NameBook
	{
	protected:
		char name[40];
	public:
		NameBook(char * st1) { 
			strcpy_s(name, st1); 
		}

		void show() { 
			cout << "name" << endl; 
		}
	};

	class TeleBook : public NameBook
	{
	protected:
		long telephone;
	public:
		TeleBook(char * st1, long tn);
		void show() { 
			cout << name << " " << telephone << endl; 
		}
	};

	TeleBook::TeleBook(char * stx, long tn) : NameBook(stx)
	{
		telephone = tn;
	};

	class AddressBook : public TeleBook
	{
	public:
		char city[40];
		AddressBook(char * st1, long n, char * st3) : TeleBook(st1, n)
		{
			strcpy_s(city, st3);
		}
		void show()
		{
			cout << name << " " << telephone << " " << city << endl;
		}
	};

	void Multi2() {
		cout << "<-- - multi2.cpp--->" << endl;
		class AddressBook me("prof", 24567890, "Mumbai");
		me.show();
		// cout « me.telephone « endl;
	}

	// Hybrid inheritance

	typedef char string[20];

	class PlainTicket
	{
	protected:
		int fare;
		int classT; //class is reserved word
		string sStation;
	public:
		PlainTicket(int fare, int classT, string sStation);
		void print(); //show()
	};

	class SimpleTicket : public PlainTicket
	{
	protected:
		string dStation;
	public:
		// void print() ; //For testing overloaded
		SimpleTicket(string dStation, int fare, int classT, string sStation);
	};

	class PaxInfo // passenger information
	{
	protected:
		string name;
		int age;
		char sex; //‘M’ or ‘F’
	public:
		PaxInfo(string name, int age, char sex);
	};

	class ReservedTicket : public SimpleTicket, public PaxInfo
	{
	protected:
		long pnrNo;
		int trainNo;
	public:
		ReservedTicket(long PNR, int train,
			string dStation, int fare, int classT, string sStation,
			string name, int age, char sex);
		void print(); //overloaded
	};

	void Hybrid2() {
		cout << "<-hybrid2.cpp--->" <<endl;
		ReservedTicket rt1(500001, 12124, "Dadar", 270, 1, "Pune", "Shahid kapoor", 30, 'M');
		rt1.print();
	}

	PlainTicket::PlainTicket(int fare, int classT, string sStation)
	{
		this->fare = fare;
		this->classT = classT;
		strcpy_s(this->sStation, sStation);
	}

	void PlainTicket::print()
	{
		cout << "***Plain Ticket***" << endl;
		cout << " fare Rs : " << fare << " Class" << endl;
	}

	PaxInfo::PaxInfo(string name, int age, char sex)
	{
		strcpy_s(this->name, name);
		this->age = age;
		this->sex = sex;
	}

	SimpleTicket::SimpleTicket(string dStation, int fare, int classT, string sStation)
		: PlainTicket(fare, classT, sStation)
	{
		strcpy_s(this->dStation, dStation);
	}

	ReservedTicket::ReservedTicket(long PNR, int train, string dStation, int fare, int classT, string sStation, string name, int age, char sex): SimpleTicket(dStation, fare, classT, sStation),
		PaxInfo(name, age, sex)
	{
		pnrNo = PNR;
		trainNo = train;
		strcpy_s(this->dStation, dStation);
		this->fare = fare;
		this->classT = classT;
		strcpy_s(this->sStation, sStation);
		strcpy_s(this->name, name);
		this->age = age;
		this->sex = sex;
	}

	void ReservedTicket::print()
	{
		cout << "***** Reserved Ticket *****" << endl;
		cout << "PNR No : " << pnrNo << "train No : " << trainNo << endl;
		cout << "From: " << sStation << " To : " << dStation << endl;
		cout << " fare Rs : " << fare << " Class " << classT << endl;
		cout << " Passenger Name Age Sex " << endl;
		cout << setw(15) << name << setw(6) << age << " " << sex << endl;
	};

	// Write a program to illustrate the concept of virtual base class.

	class Employee
	{
	protected:
		int emp_code;
	public:
		Employee();
		void display();
	};

	class Faculty : public virtual Employee
	{
	protected:
		char sub[10];
	public:
		Faculty();
		void display();
	};

	class LabStaff : public virtual Employee
	{
	protected:
		float Lb;
	public:
		LabStaff();
		void display();
	};

	class Instructor : public Faculty, public LabStaff
	{
	public:
		Instructor();
		void display();
	};

	void Vbase1() {
		cout << "<-- - vbase1.cpp--->" << endl;
		Instructor inst1;
		cout << "Display result " << endl;
		inst1.display();

		cout << "-------------------------" << endl;
		Faculty ft;
		ft.display();
		LabStaff ls;
		ls.display();
	}

	Employee::Employee()
	{
		cout << "Enter Employee code : ";
		cin >> emp_code;
	}

	void Employee::display()
	{
		cout << "Employee code : " << emp_code << endl;
	}

	Faculty::Faculty()
	{
		cout << "Enter subject name : ";
		cin >> sub;
	}

	void Faculty::display()
	{
		Employee::display();
		cout << "Subject taught : " << sub << endl;
	}

	LabStaff::LabStaff()
	{
		cout << "Enter Labcode real no : ";
		cin >> Lb;
	}

	void LabStaff::display()
	{
		Employee::display();
		cout << "Lab code : " << Lb << endl;
	}

	Instructor::Instructor()
	{ // no assignment statements
	  // as no attributes to initialize
	}

	void Instructor::display()
	{
		cout << "emp_code : " << emp_code << endl;
		cout << "subject : " << sub << endl;
		cout << "Lab code : " << Lb << endl;
	}

	// Define a class Quadrangle. It should contain a method for finding the centre of gravity. Derive a class Rectangle from class Quadrangle.

	class Quadrangle
	{
	protected:
		int px1, py1, px2, py2, px3, py3, px4, py4;
	public:
		Quadrangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
		void show();
		void centreOfGravity(int &X, int &Y);
	};

	class Rectangle : public Quadrangle
	{
	public:
		Rectangle(int x1, int y1, int x3, int y3);
	};

	void Is_a() {
		cout << "<-- - is_a.cpp--->" << endl;
		int cgx, cgy;
		class Rectangle rect1(125, 125, 250, 250);
		cout << "showing rectangle" << endl;
		rect1.show();
		rect1.centreOfGravity(cgx, cgy);
		cout << "its center of gravity is at " << endl;
		cout << "(" << cgx << ", " << cgy << ")" << endl;
	}

	Quadrangle::Quadrangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	{
		px1 = x1; py1 = y1;
		px2 = x2; py2 = y2;
		px3 = x3; py3 = y3;
		px4 = x4; py4 = y4;
	}

	void Quadrangle::show()
	{
		cout << "The points are : " << endl;
		cout << "(" << px1 << ", " << py1 << ")" << endl;
		cout << "(" << px2 << ", " << py2 << ")" << endl;
		cout << "(" << px3 << ", " << py3 << ")" << endl;
		cout << "(" << px4 << ", " << py4 << ")" << endl;
	}

	void Quadrangle::centreOfGravity(int & X, int & Y)
	{
		X = (px1 + px2 + px3 + px4) / 4;
		Y = (py1 + py2 + py3 + py4) / 4;
		return;
	};

	Rectangle::Rectangle(int x1, int y1, int x3, int y3): Quadrangle(x1, y1, x1, y3, x3, y3, x3, y1)
	{
		// interesting point to note is that
		// this constructor has no body
	};

	// Define a class Point. Define a class Quadrangle. It should contain class Point. Create an object of type Quadrangle. Find the centre of gravity for this Quadrangle.

	class Quadrangle_2;

	class Point
	{
		int xc, yc;
	public:
		void setpoint(int i, int j);
		void show();
		friend class Quadrangle_2;
	};

	class Quadrangle_2
	{
		Point p1, p2, p3, p4;
	public:
		Quadrangle_2(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
		void show();
		Point centre_of_gravity();
	};

	void Has_a() {
		Quadrangle_2 abc(50, 150, 200, 150, 100, 80, 180, 100);
		Point PT1;
		cout <<	"<-- - has_a.cpp--->" << endl;
		abc.show();
		PT1 = abc.centre_of_gravity();
		cout << "center of gravity at " << endl;
		PT1.show();
	}

	Quadrangle_2::Quadrangle_2(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	{
		p1.setpoint(x1, y1);
		p2.setpoint(x2, y2);
		p3.setpoint(x3, y3);
		p4.setpoint(x4, y4);
	}

	void Quadrangle_2::show()
	{
		cout << "A quadrangle consists of following points" << endl;
		p1.show(); p2.show(); p3.show();
		p4.show();
		cout << endl;
	}

	void Point::setpoint(int i, int j)
	{
		xc = i; yc = j;
	}

	void Point::show()
	{
		cout << "Point = ";
		cout << "(" << xc;
		cout << ", " << yc << ")" << endl;
	}

	Point Quadrangle_2::centre_of_gravity()
	{
		Point temp;
		int xg, yg;
		xg = p1.xc + p2.xc + p3.xc + p4.xc;
		xg = xg / 4;
		yg = p1.yc + p2.yc + p3.yc + p4.yc;
		yg = yg / 4;
		temp.xc = xg; temp.yc = yg;
		return temp;
	};

	///////////////////////////
	////       TASKS       ////
	///////////////////////////

	// 1. What do you understand by the term multiple inheritance?

	// 2. Why access specifier protected is useful in multilevel inheritance?

	// 3. Explain ‘Ambiguity Resolution in Multiple Inheritances’.

	// 4. What is the practical problem (difficulty) with multipath inheritance? How is it solved?

	// 5. Write a detailed note on classification of inheritance.

	// 6. What are the different forms of inheritance supported by C++? Explain by writing statements of each type.

	// 7. What type of relationship exists between class StraightLine and class Point? Write a simple program to illustrate your answer.

	class Pont
	{
	public:
		int x, y;
		Pont();
		Pont(int, int);
		void setPoint(int, int);
		~Pont();
	};

	Pont::Pont() {
		x = 0;
		y = 0;
	}

	Pont::Pont(int x, int y){
		this->x = x;
		this->y = y;
	}

	void Pont::setPoint(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Pont::~Pont()
	{
	}

	class StraightLine
	{
	public:
		StraightLine(int x1, int y1, int x2, int y2);
		~StraightLine();
		void getEquation();
	private:
		Pont p1, p2;
	};

	StraightLine::StraightLine(int x1, int y1, int x2, int y2){
		this->p1.setPoint(x1, y1);
		this->p2.setPoint(x2, y2);
	}

	StraightLine::~StraightLine(){}

	void StraightLine::getEquation() {
		int x1 = this->p1.x;
		int y1 = this->p1.y;
		int x2 = this->p2.x;
		int y2 = this->p2.y;
		//cout << "x1: " << x1 << " y1: " << y1 << " x2: " << x2 << " y2: " << y2 << endl;
		
		int ivx = x2 - x1;
		int ivy = y2 - y1;
		//cout << "iranyvec x: " << ivx << " iranyvec y: " << ivy << endl;

		int nvx = ivy;
		int nvy = -1 * ivx;
		//cout << "normalcev x: " << nvx << " normalvec y" << nvy << endl;

		cout << nvx << "x + " << nvy << "y = " << nvx * x1 + nvy * y1 << endl;
	}

	void PointInLine() {
		StraightLine sl(-4, 3, 5, -2);
		sl.getEquation();
		StraightLine sl2(1, 2, 3, 4);
		sl2.getEquation();
		StraightLine sl3(6, -11, 8, 5);
		sl3.getEquation();
	}

	// 8. What type of relationship exists between class Manager and class Employee? Write a simple program to illustrate your answer.

	class Employee2
	{
	public:
		Employee2(int);
		~Employee2();

	private:
		int emp_id;
	};

	Employee2::Employee2(int id){
		emp_id = id;
	}

	Employee2::~Employee2()
	{
	}

	class Manager: public Employee2
	{
	public:
		Manager(int, int);
		~Manager();

	private:
		int salary;
	};

	Manager::Manager(int id, int sal):Employee2(id){
		salary = sal;
	}

	Manager::~Manager()
	{
	}

	// 9. Consider a case of university having the disciplines of Engineering, Medicine, Management, and Science. 
	//    There are many colleges in the university. Assuming a college can run a course pertaining to only one discipline, draw the class diagram. 
	//    To which type does this structure belong? How will you classify it?

	// 10. In the above problem, assume that a college can run courses pertaining to any two disciplines. Draw the class diagram. What will be the type of this structure? How will you classify it?
	
	// 11. Redesign class “ReservedTicket” such that it has it has object(s) of class paxInfo as is member(has–a relationship).


}