#include "ChapterSix.h"

using namespace std;

namespace ChapterSix {

	// Write a program to demonstrate that un-initialized objects contain arbitrary values.

	void Object1() {
		Date d1;
		Date *d2 = new Date();
		cout << "<-- - object1.cpp--->" << endl;
		cout << "showing d1" << endl;
		d1.showDate();
		cout << "showing d2" << endl;
		d2->showDate();
	}

	// Write a program to demonstrate constructor.

	void Objinit1() {
		cout << "<-- - objinit1.cpp--->" << endl;
		Date d1;
		d1.Init();
		cout << "Showing d1" << endl;
		d1.showDate();
	}

	// Write a program to demonstrate parameterized constructor.

	void Const1() {
		cout << "<-- - const1.cpp--->" << endl;
		Date d1(13, 10, 2003);
		cout << "Showing d1" << endl;
		d1.showDate();
	}

	// Write a program to illustrate "this" pointer.

	void This1() {
		cout << "<-- - this1.cpp--->" << endl;
		Date d1(13, 10, 2003);
		cout << "Showing d1" << endl;
		d1.showDate();
	}

	// Write a program to demonstrate constructor overloading.

	void Const2() {
		cout << "<-- - const2.cpp--->" << endl;
		Date d1;
		Date d2(20, 9, 2003);
		cout << "Showing d1, entered from keyboard " << endl;
		d1.showDate();
		cout << "Showing d2, initialized " << endl;
		d2.showDate();
	}

	// Write a program to demonstrate constructor overloading.

	void Const3() {
		cout << "<-- - const3.cpp--->" << endl;
		Time t1;     //…1
		cout << "showing t1 : ";
		t1.show_time();
		Time t2(9, 15, 0);    //…2
		cout << "college opens time t2 : ";

		t2.show_time();

		Time t3;     //…3
		t3.set_time();
		cout << "lunch break starts time t3 : ";
		t3.show_time();
		Time t4(51300);    //…4
		cout << "lunch break ends time t4 : ";
		t4.show_time();
		Time t5 = Time(17, 15, 0);   //…5
		cout << "The day ends time t5 : ";
		t5.show_time();
	}

	// Write a program with class Date to demonstrate default arguments for the constructors.

	void Default1() {
		cout << "<-- - default1.cpp--->" << endl;
		Date d1(15, 8, 1947);
		cout << "Showing d1" << endl;
		d1.showDate();
		Date d2;
		d2.Init(15, 8);
		cout << "Showing d2" << endl;
		d2.showDate();
	}

	// Write a program to demonstrate default copy constructor

	class Period
	{
	private:

		int days, months, years;

	public:
		void show();
		Period(int d, int m, int y); // constructor
		Period(Period &tmp); //copy constructor
	};

	void Ecopy1() {
		cout << "<-- - ecopy1.cpp--->" << endl;
		Period p1(10, 6, 100);
		p1.show();
		cout << "now using default copy constructor" << endl;
		Period p2(p1);
		p2.show();
	}

	void Period::show()
	{
		cout << "period is : " << days << " : " << months << " : " << years << endl;
	}

	Period::Period(int d, int m, int y)
	{
		days = d;
		months = m;
		years = y;
	}

	// Write a program to demonstrate a user-defined copy constructor.

	void Ecopy2() {
		cout << "<-- - ecopy2.cpp--->" << endl;
		Period p1(10, 6, 100);
		cout << "original object" << endl;
		p1.show();
		cout << "now using explicit copy constructor" << endl;
		Period p2(p1);
		cout << "copied object" << endl;
		p2.show();
	}

	Period::Period(Period &tmp)
	{
		cout << "copy constructor in action " << endl;
		days = tmp.days;
		months = tmp.months;
		years = tmp.years;

	}

	// Write a program to demonstrate initialization of object by hybrid copy constructor. First copy it from existing object and then modify a particular member by a new specified value (hybrid).

	class Pipe
	{
		float innerDia;
		float thickness;
		float length;
		int materialCode;
	public:
		Pipe(float id, float th, float l, int m);
		Pipe(Pipe & x, int m); // hybrid constructor
		void display();
	};

	void Ecopy3() {
		cout << "<-- - ecopy3.cpp--->" << endl;
		Pipe pipe_copper(18.5, 3.5, 1000.0, 10);// object is created
												// and initialized
		Pipe pipe_ss(pipe_copper, 20); // Hybrid constructor called
		Pipe pipe_pvc(pipe_ss, 30); //Hybrid constructor called again
		cout << "pipe copper : " << endl;
		pipe_copper.display();
		cout << "pipe stainless steel : " << endl;
		pipe_ss.display();
		cout << "pipe_pvc:" << endl;
		pipe_pvc.display();
	}

	Pipe::Pipe(float id, float th, float l, int m)

	{
		innerDia = id;
		thickness = th;
		length = l;
		materialCode = m;
	}

	Pipe::Pipe(Pipe & x, int m)  // copy constructor
	{
		innerDia = x.innerDia;
		thickness = x.thickness;
		length = x.length;
		materialCode = m;
	}

	void Pipe::display(void)
	{
		cout << innerDia << " " << thickness << " ";
		cout << length << " " << materialCode << endl;

	}

	// Write a program to study an array of objects without pointers.

	class Student
	{
	public:
		char name[20];
		int rollNum;
		Student();
	};

	void Arrobj1() {
		cout << "<-- - arrobj1.cpp--->" << endl;
		Student std[3]; // ---1---
		cout << "Name of second Student is ";
		cout << std[1].name << endl;;
		cout << "RollNum of second Student is ";
		cout << std[1].rollNum << endl;
	}

	Student::Student() // interactive default constructor
	{
		cout << "Give name : ";
		cin >> name;
		cout << "Give rollNum : ";
		cin >> rollNum;
	}

	// Write a program to illustrate initialization of array of objects defined with the help of pointers.

	void Arrobj2() {
		cout << "<-- - arrobj2.cpp--->" << endl;
		Student *sptr[3]; // note 1
		for (int i = 0; i<3; i++)
			sptr[i] = new Student(); // note2
		cout << "Name of second Student is ";
		cout << sptr[1]->name << endl;;
		cout << "RollNum of second Student is ";
		cout << sptr[1]->rollNum << endl;
	}

	// Write a program to demonstrate a destructor.

	class PERIOD
	{
		int days, months, years;
	public:
		PERIOD(int d, int m, int y);
		~PERIOD();
		void show();
	};

	void Destru2() {
		cout << "<-- - destru2.cpp--->" << endl;
		PERIOD p1(10, 6, 3); // object constructed here
		p1.show();
		p1.PERIOD::~PERIOD(); //note 1
		p1.show();
	}

	void PERIOD::show()
	{
		cout << days << ":" << months << " : " << years << endl;
	}

	PERIOD::PERIOD(int d, int m, int y)
	{
		days = d;
		months = m;
		years = y;
	}

	PERIOD::~PERIOD()
	{
		cout << "Destructor called" << endl;

	}

	// Write a program to illustrate the initialization of an object with initializer list.

	void Inilist1() {
		Time t1 = { 5, 6, 7 };
		cout << "<-- - inilist1.cpp--->" << endl;
		t1.show_time();
	}

	///////////////////////////
	////       TASKS       ////
	/////////////////////////// 

	// 1. Differentiate between: constructors and destructors.

	// 2. Explain the use of constructors and destructors with suitable examples.

	// 3. What are the different types of constructors and destructors one can use in C++ program?

	// 4. Describe the concept of default constructor. Can a parameterized constructor be a default constructor?

	// 5. Can a constructor have parameters? If yes can it have default values?

	// 6. Can destructors be overloaded?

	// 7. Describe the copy constructor and explain its use.

	// 8. Explain what you understand by the term copy initialization.

	// 9. Can we use the initializer list for constructing the object.

	// 10. What are the read-only objects? What is the role of a constructor in such objects?

	// 11. List some of the special properties of the constructor and destructor functions

	// 12. Distinguish between:
	//     1. Constructors with arguments and default constructors
	//     2. Default constructors and constructors with default arguments

	// 13. Explain the concept of this pointer.

	// 14. Define suitable constructors for the following classes:
	//     1. Point

	/*class Point
	{
	public:
		Point(int, int);
		~Point();
		int x, y;
	private:

	};*/

	/*Point::Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}*/

	//     2. Temperature

	class Temperature
	{
	public:
		Temperature(int);
		~Temperature();
		int temp;
	private:

	};

	Temperature::Temperature(int t)
	{
		this->temp = t;
	}

	//     3. StraightLine

	class StraightLine
	{
	public:
		StraightLine(int, int);
		~StraightLine();
		int length, width;
	private:

	};

	StraightLine::StraightLine(int l, int w)
	{
		this->length = l;
		this->width = w;
	}

	//     4. Book

	class Book
	{
	public:
		Book(int, string);
		~Book();
		int page_num;
		string title;
	private:

	};

	Book::Book(int pn, string t)
	{
		this->page_num = pn;
		this->title = t;
	}

	// 15. Define suitable constructor(s) for string class defined as below.

	class Strings
	{
		int length;
		char a[40];
	public:
		Strings();
		Strings(int, char[]);
	};

	Strings::Strings() {
		length = 10;
		a[40] = {'a'};
	}

	Strings::Strings(int l, char a[]) {
		this->length = l;
		strcpy_s(this->a, a);
	}

	// 16. Illustrate with an example the concept of an array of objects.

	void ArrayOfObject() {
		Strings str[3];
	}

	// 17. Define a class to represent bank account. Include the following members:

	class BankAccaunt
	{
	public:
		BankAccaunt();
		~BankAccaunt();
		void SetDeposit();
		void Withdraw();
		void Display();
	private:
		string depositor;
		int accauntNum, accauntType, balanceAmount;
	};

	BankAccaunt::BankAccaunt()
	{
		cout << "give me the name of the depositor: ";
		cin >> depositor;
		cout << "give me the accaount number: ";
		cin >> accauntNum;
		cout << "give me the type of the accaunt: ";
		cin >> accauntType;
		cout << "give me the balance amount in the accaunt: ";
		cin >> balanceAmount;
	}

	BankAccaunt::~BankAccaunt()
	{
		cout << "delete BankAccaunt!";
	}

	void BankAccaunt::SetDeposit() {

	}

	void BankAccaunt::Withdraw() {

	}

	void BankAccaunt::Display() {
		cout << "name: " << depositor << ", balance: " << balanceAmount;
	}

	void CheckingBankAccaunt() {
		BankAccaunt ba;
		ba.~BankAccaunt();
	}

	// 18. Define a class Circle with suitable constructor. Write a program to find the area of a circle using method area().

	void AreaOfCircle() {
		Circle c1(2, 3, 4);
		Circle c2;

		cout << c1.area() << endl;
		cout << c2.area() << endl;
	}

	// 19. Define a class Dice with suitable constructor. Write a program to find the new value using method throwDice(); (Hint: The constructor must initialize pseudo random number generator.)

	class Dice
	{
	public:
		Dice();
		~Dice();
		void throwDice();
		void print();
	private:
		int number;
	};

	Dice::Dice()
	{
		number = rand() % 6 + 1;
	}

	Dice::~Dice()
	{
		cout << "destroy dice!" << endl;
	}

	void Dice::throwDice() {
		number = rand() % 6 + 1;
	}

	void Dice::print() {
		cout << number << endl;
	}

	void diceGame() {
		Dice d1;
		d1.print();
		for (int i = 0; i < 100; i++) {
			d1.throwDice();
			d1.print();
		}

	}

	// 20. Design simple class rectangle with attributes (x1, y1, x2, y2, x3, y3, x4, y4) as vertices. Develop methods isRectangle() and isSquare() for the class. Write a suitable program to use this class. 
	//     Use initializer list to initialize the object.

	void RertanglePrograme() {
		Point p1(2, 2), p2(6, 2), p3(6, 4), p4(2, 4);
		Rectangle r1(p1, p2, p3, p4);
		cout << r1.isRectangle() << endl;
		cout << r1.isSquare() << endl;
	}

	// 21. Design a simple class Message with attribute char *p and method void show(). The constructor should interactively obtain a string and store it in a dynamically allocated memory using pointer p.
	//     Design a destructor for the class. It should release the dynamically allocate memory.
	class Message
	{
	public:
		Message(char*);
		~Message();
		void show();
	private:
		char* p;
	};

	Message::Message(char* p)
	{
		this->p = p;
	}

	Message::~Message()
	{
	}

	void Message::show() {

	}

	// 22. Define a class student with attributes roll_number and marks. Create an array of objects of 10 students of the class. Write a program to find out the roll numbers of all the students who have 60 or more marks.

	class Student_3
	{
	public:
		Student_3();
		~Student_3();
		friend void findStudents(Student_3[], int);
	private:
		int roll_number, marks;
 	};

	Student_3::Student_3()
	{
		cout << "roll number: ";
		cin >> roll_number;
		cout << "num of marks: ";
		cin >> marks;
	}

	Student_3::~Student_3()
	{
	}

	void MoreMarksStudents() {
		Student_3 stu[10];
		findStudents(stu, 10);
	}

	void findStudents(Student_3 stu[], int num) {
		for (int i = 0; i < num; i++) {
			if (stu[i].marks > 60) {
				cout << stu[i].roll_number << endl;
			}
		}
	}

	// 23. Define a class Donation with attributes for name of donor and amount. There should not be any constructor defined for the class. 
	//     Method init() should be used to initialize an object. Create an array of 10 donations. Write a program to read data from console. Process the array to find out total donations received by the trust.

	class Donation
	{
	public:
		void init();
		//Donation(char *p, long amt);
		friend void FindTotalDonation(Donation[], int);
	private:
		string name;
		int amount;
	};

	void Donation::init() {
		cout << "give me a nama of the donor: ";
		cin >> name;
		cout << "give me the amount: ";
		cin >> amount;
	}

	void Donors() {
		Donation don[10];
		for (int i = 0; i < 10; i++) {
			don[i].init();
		}
		FindTotalDonation(don, 10);
	}

	void FindTotalDonation(Donation d[], int num) {
		int sum = 0;
		for (int i = 0; i < num; i++) {
			sum += d[i].amount;
		}
		cout << "num of total donation is: " << sum << endl;
	}

	// 24. Modify the program of donations such that class should have only one constructor Donation (char *p, long amt). Create an array of 10 pointers to class donation. Why do we need pointers in this program?

	/*Donation::Donation(char *p, long amt) {
		amount = amt;
		name = p;

	}

	void Donors2() {
		Donation d1("alma1", 55);
		Donation d2("alma2", 56);
		Donation d3("alma3", 57);
		Donation d4("alma4", 58);
		Donation d5("alma5", 59);
		Donation d6("alma6", 60);
		Donation d7("alma7", 61);
		Donation d8("alma8", 62);
		Donation d9("alma9", 63);
		Donation d10 ("alma10", 64);
		Donation don[10] = { d1, d2, d3, d4, d5, d6, d7, d8, d9, d10 };
		FindTotalDonation(don, 10);
	}*/

	// 25. Consider a declaration
	//     Where class Card represents a playing card. Under what circumstances this declaration will fail to compile?
	//     Write a program to design the suitable class card so that the above declaration succeeds.

	class Card
	{
	public:
		Card();
		~Card();

	private:
		int numberOfCard;
	};

	Card::Card()
	{
	}

	Card::~Card()
	{
	}

	Card myDeck[52];

	// 26. Design a constructor for class Date such that input parameter is a string in the format “dd:mm:yy”. Assume that the dates are from this century only.

	void DateString() {
		Date d1("01:10:2017");
		d1.showDate();
	}

}
