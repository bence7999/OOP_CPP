#include "ChapterNine.h"

using namespace std;

namespace ChapterNine {

	// Write a program to demonstrate the principle of inheritance. Use time0 as the base class.

	class Time0
	{
	public:
		int hr, min, sec;
		void settime(int h, int m, int s);
		void show();
	};

	class Clock : public Time0
	{
	public:
		char strg[5]; // for AM PM
		void setAMPM();
	};

	void Time0::settime(int h, int m, int s)
	{
		hr = h;
		min = m;
		sec = s;
	}

	void Time0::show()
	{
		cout << hr << ':';
		cout << min << ':';
		cout << sec << endl;
	}

	void Clock::setAMPM()
	{
		if (hr >= 12) strcpy_s(strg, "PM");
		else strcpy_s(strg, "AM");
	}

	void Inher1() {
		class Clock t;
		cout << "<-- - inher1.cpp--->" << endl;
		t.settime(5, 30, 20);
		t.setAMPM();
		t.show();
		cout << t.strg << endl;
	}

	// Write a program to demonstrate function overriding.

	class Time0_1
	{
	protected:
		int hr;
		int min;
		int sec;
	public:
		void settime(int h, int m, int s);
		void show();
	};

	class Clock_2 : public Time0_1
	{
	private:
		char strg[5]; // for AM PM
	public:
		void setAMPM();
		void show();
	};

	void Overrid1() {
		class Clock_2 t;
		cout << "<-- - overrid1.cpp--->" << endl;
		t.settime(5, 30, 20);
		t.setAMPM();
		t.show();
	}

	void Time0_1::settime(int h, int m, int s)
	{
		hr = h;
		min = m;
		sec = s;
	}

	void Time0_1::show()
	{
		cout << " base class show() in action " << endl;
		cout << hr << ':';
		cout << min << ':';
		cout << sec << endl;
	}

	void Clock_2::setAMPM()
	{
		if (hr >= 12) strcpy_s(strg, "PM");
		else strcpy_s(strg, "AM");
	}

	void Clock_2::show()
	{
		cout << "derived class show() in action" << endl;
		cout << hr << ':';
		cout << sec << ' ';
		cout << strg << endl;
	}

	// Write a program to define a class clock. It should be derived from class time. The program should demonstrate the calling of constructors clearly.

	class Time1
	{
	protected:
		int hr;
		int min;
		int sec;
	public:
		Time1(int h, int m, int s);
	};

	class Clock_3 : public Time1
	{
	private:
		char strg[5]; // for AM PM
	public:
		Clock_3(char * st, int h, int m, int s);
		void show();
	};

	void Constru1() {
		cout << "<-- - constru1.cpp--->" << endl;
		class Clock_3 t("PM", 5, 30, 20);
		t.show();
	}

	Time1::Time1(int h, int m, int s)
	{
		cout << "constructor Time1 starts now " << endl;
		hr = h;
		min = m;
		sec = s;
		cout << "constructor Time1 ends now " << endl;
	}

	Clock_3::Clock_3(char * st, int h, int m, int s) :Time1(h, m, s)
	{
		cout << "constructor Clock starts here " << endl;
		strcpy_s(strg, st);
		cout << "constructor Clock ends here " << endl;
	}

	void Clock_3::show()
	{
		cout << hr << ':';
		cout << min << ':';
		cout << sec << ' ';
		cout << strg << endl;
	}

	// Rewrite Program 9.2 such that we could access private members of the base class.

	class Time0_2
	{
	private:
		int min;
		int sec;
	public:
		int hr;
		void setTime(int h,
			int m, int s);
		void show();
	};

	class Clock_4 : private Time0_2
	{
	private:
		char strg[5]; // for AM PM
	public:
		void defineTime(int h1, int m1, int s1);
		void setAMPM();
		void show();
	};

	void Private3() {
		class Clock_4 t;
		cout << "<-- - private3.cpp--->" << endl;
		t.defineTime(5, 30, 20);
		t.setAMPM();
		t.show();
	}

	void Time0_2::setTime(int h, int m, int s)
	{
		hr = h;
		min = m;
		sec = s;
	}

	void Time0_2::show()
	{
		cout << hr << ':';
		cout << min << ':';
			cout << sec << endl;
	}

	void Clock_4::setAMPM()
	{
		if (hr >= 12) strcpy_s(strg, "PM");
		else strcpy_s(strg, "AM");
	}

	void Clock_4::defineTime(int h1, int m1, int s1)
	{
		setTime(h1, m1, s1);
	}

	void Clock_4::show()
	{
		Time0_2::show();
		cout << strg << endl;
	}

	// Write a program to demonstrate inheritance. Use class Person as the base class and Student as the derived class.

	class Person
	{
	private:
		int rollnum;
	public:
		char name[20];
		Person();
		void print();
	};

	class Student : public Person
	{
	public:
		int marks;
		Student();
		void demo();
	};

	void Perform1() {
		cout << "<-- - perform1.cpp--->" << endl;
		class Student stu1;
		// Note 1
		stu1.print();
		stu1.demo();
		cout << "Class Person Size in Bytes " << sizeof(Person) << endl;
		cout << "Class Student Size in Bytes " << sizeof(Student);
		// cout << stu1.rollnum; //note 2
	}

	void Person::print()
	{
		cout << "Person name ";
		cout << name << " RN is " << rollnum << endl;
	}

	Person::Person()
	{
		cout << "Specify name : ";
		cin >> name;
		cout << "Specify roll number : ";
		cin >> rollnum;
	}

	void Student::demo()
	{
		cout << "method demo starts" << endl;
		//cout << rollnum; // Error 'Person::rollnum' is not accessible
		// note 3
	}

	Student::Student()
	{
		cout << "specify marks : ";
		cin >> marks;
	}

	// Write a program to demonstrate that overriding function can have different signature.

	class Time2
	{
	protected:
		int hr;
		int min;
		int sec;
	public:
		Time2(int h, int m, int s);
		void show();
	};

	class Clock_5 : public Time2
	{
	private:
		char strg[5]; // for AM PM
	public:
		Clock_5(char * st, int h, int m, int s);
		void show(int n);
	};

	void Overrid3() {
		cout << "<-- - overrid3.cpp--->" << endl;
		class Clock_5 t("PM", 5, 30, 20);
		t.show(5);
		// t.show(); //compilation error
		t.Time2::show();
	}

	Time2::Time2(int h, int m, int s)
	{
		hr = h;
		min = m;
		sec = s;
	}

	void Time2::show()
	{
		cout << "base class show() in action " << endl;
		cout << hr << ':';
		cout << min << ':';
		cout << sec << endl;
	}

	Clock_5::Clock_5(char * st, int h, int m, int s) :Time2(h, m, s)
	{
		strcpy_s(strg, st);
	}

	void Clock_5::show(int n)
	{
		cout << "derived class show in action" << endl;
		cout << hr << ':';
		cout << min << ':';
		cout << sec << ' ';
		cout << strg << endl;
	}

	///////////////////////////
	////       TASKS       ////
	/////////////////////////// 

	// 1. Describe the following terms:
	//    1. Base class
	//    2. Derived class

	// 2. Explain how will you decide the size of an object of a given class ?

	// 3. State whether true or false.
	//    1. Inheritance aids data hiding.
	//    2. Base class is never used to create an object.

	// 4. Can a member function in derived class have same name as that of one in base class ?

	// 5. What do you understand by the term public derivation ? What rules / restrictions govern in accessing base class members ?

	// 6. Under what circumstances protected derivation is preferred over private derivation ?

	// 7. What is the difference between function overloading and function overriding ?

	// 8. Can we access a base class function in derive class, if it is actually overridden ?

	// 9. Explain the mechanism to initialize base class members from derived from constructor ?

	// 10. Write a detailed note on use, benefit and cost of inheritance.

	// 11. Under what circumstances derived class may not have a constructor, when the base class has one or more constructors ?

	// 12. Create a base class “rectangle” that contains length and width as data member.
	//     From this class derive a class named box that has additional data member named “depth”.
	//     The function members of the base class should consist of a constructor and an “area()” function.
	//     The derived box class should have a constructor and an override function names “area()” that returns a surface area of “Box” and a volume function.
	//     Write a images program on class calling all the member functions.

	class Rectangle
	{
	public:
		Rectangle(int, int);
		~Rectangle();
		int area();
	protected:
		int length, width;
	};

	Rectangle::Rectangle(int l, int w){
		length = l;
		width = w;
	}

	Rectangle::~Rectangle()
	{
	}

	class Box : public Rectangle 
	{
	public:
		Box(int, int, int);
		~Box();
		int area();
		int volume();
	protected:
		int depth;
	};

	Box::Box(int l, int w, int d) : Rectangle(l, w){
		depth = d;
	}

	Box::~Box()
	{
	}

	void RectangleAndBox() {
		Rectangle* r1 = new Rectangle(10, 20);
		Box* b1 = new Box(10, 20, 30);

		cout << "area of r1: " << r1->area() << endl;

		cout << "area of b1: " << b1->area() << " volume of b1: " << b1->volume() << endl;

		r1->~Rectangle();
		b1->~Box();
	}

	int Rectangle::area() {
		return this->length * this->width;
	}

	int Box::area() {
		return 2 * this->length * this->width + 2 * this->length * this->depth + 2 * this->width * this->depth;
	}

	int Box::volume() {
		return this->length * this->width * this->depth;
	}

	// 13. Design a class PlainTicket for unreserved plain computerized railway ticket. Derive a class ReservedTicket from this class.
	
	class PlainTicket
	{
	public:
		PlainTicket();
		~PlainTicket();

	private:

	};

	PlainTicket::PlainTicket()
	{
	}

	PlainTicket::~PlainTicket()
	{
	}

	class ReservedTicket: public PlainTicket
	{
	public:
		ReservedTicket();
		~ReservedTicket();

	private:

	};

	ReservedTicket::ReservedTicket()
	{
	}

	ReservedTicket::~ReservedTicket()
	{
	}

	// 14. Design a class Window. Derive two classes TextWindow and TitleWindow representing text - window and title bar.

	class Window
	{
	public:
		Window();
		~Window();

	private:

	};

	Window::Window()
	{
	}

	Window::~Window()
	{
	}

	class TextWindow: public Window
	{
	public:
		TextWindow();
		~TextWindow();

	private:

	};

	TextWindow::TextWindow()
	{
	}

	TextWindow::~TextWindow()
	{
	}

	class TitleWindow: public Window
	{
	public:
		TitleWindow();
		~TitleWindow();

	private:

	};

	TitleWindow::TitleWindow()
	{
	}

	TitleWindow::~TitleWindow()
	{
	}

	// 15. Study the following declaration of class Linked List with elements as integers.
	//     Derive class Stack (of integers) from class linked list. Class stack must have methods push() and pop(). Write a program to test both these classes.

	struct Node
	{
		int integer;
		Node* next;
	};

	class LinkList
	{
	protected:
		Node *root;
		Node *tail;
	public:
		LinkList();
		void addNode(int M);
		void show();
	};

	LinkList::LinkList() {
		this->root = NULL;
		this->tail = NULL;
	}

	void LinkList::addNode(int M) {
		Node* tmp = new Node;
		tmp->integer = M;
		if (tail == NULL) {
			tail = tmp;
			root = tmp;
		}
		else {
			tmp->next = root;
			root = tmp;
		}
	}

	void LinkList::show() {
		if (this->root == NULL) {
			cout << "the list is empty!" << endl;
		}
		else {
			Node* tmp = this->root;
			cout << tmp->integer << endl;
			while (tmp != this->tail)
			{
				tmp = tmp->next;
				cout << tmp->integer << endl;
			}
			cout << "end of linkedlist" << endl;
		}
	}

	class Stack: public LinkList
	{
	public:
		Stack();
		~Stack();
		void push(int);
		int pop();
	private:
	};

	Stack::Stack()
	{
		this->root = NULL;
		this->tail = NULL;
	}

	Stack::~Stack()
	{
	}

	void Stack::push(int n) {
		this->addNode(n);
	}

	int Stack::pop() {
		if (root != NULL) {
			Node* tmp = root;
			if (root != tail) {
				root = root->next;
				return tmp->integer;
			}
			else
			{
				int retval = tmp->integer;
				root = NULL;
				tail = NULL;
				return retval;
			}
		}
		else
		{
			cout << "the stack is empty!" << endl;
		}


	}

	void TestLinkedList() {
		LinkList ll;
		ll.show();
		ll.addNode(1);
		ll.addNode(2);
		ll.addNode(3);
		ll.addNode(4);
		ll.addNode(5);
		ll.show();

		Stack st;
		st.show();
		st.push(1);
		st.push(2);
		st.push(3);
		st.show();
		st.pop();
		st.show();
	}

	// 16. Develop class "Queue" as derived class with class LinkedList as base class. The class queue should have methods
	//	   void enter(int n); // enter element at end
	//     int leave() // remove first element
	
	class Queue: public LinkList
	{
	public:
		Queue();
		~Queue();
		void enter(int n);
		int leave();
	private:

	};

	Queue::Queue()
	{
		this->root = NULL;
		this->tail = NULL;
	}

	Queue::~Queue()
	{
	}

	void Queue::enter(int n) {
		Node* tmp = new Node;
		tmp->integer = n;
		if (tail != NULL) {
			tail->next = tmp;
			tail = tmp;
		}
		else {
			tail = tmp;
			root = tmp;
		}
	}

	int Queue::leave() {
		if (root == NULL) {
			cout << "the queue is empty!" << endl;
		}
		else
		{
			if (root == tail) {
				int retval = root->integer;
				root = NULL;
				tail = NULL;
				return retval;
			}
			else
			{
				Node* tmp = root;
				root = root->next;
				return tmp->integer;
			}
		}
	}

	void CheckQueue() {
		Queue q;
		q.show();
		q.enter(1);
		q.enter(2);
		q.enter(3);
		q.enter(4);
		q.enter(5);
		q.show();
		q.leave();
		q.leave();
		q.show();
	}

}