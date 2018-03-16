#include "ChapterThirteen.h"

using namespace std;

namespace ChapterThirteen {

	///  13.1 Polymorphism: a simple example
	// Write a program to study polymorphism. Use the following specifications: Create a base class called creatures. 
	// It should have a constructor and method move to tell about how that creature moves. The data member should be a character array for storing the name of the creature.

	class Creatures
	{
	public:
		char name[40];
		Creatures(char *p);
		void move();
	};

	class Bird : public Creatures
	{
		int speed;
	public:
		void move();
		Bird(int n, char * p);
	};

	class Pet : public Creatures
	{
		int speed;
	public:
		void move();
		Pet(int n, char * p);
	};

	void Poly1() {
		cout << "<-- - poly1.cpp--->" << endl;
		Bird Parrot(5, "Mithu Miyan");
		Parrot.move();
		Pet Cat(1, "Pussy");
		Cat.move();
	}

	Creatures::Creatures(char *p)
	{
		strcpy_s(name, p);
	}

	void Creatures::move()
	{
		cout << "I am " << name << endl;
		cout << "I can move!" << endl;
	}

	Bird::Bird(int n, char *p) : Creatures(p) // Note 1
	{
		speed = n;
	}

	void Bird::move()
	{
		cout << "I am a bird." << endl;
		cout << " My name is : " << name << endl;
		cout << " My Flying speed is : " << speed << endl;
	}

	Pet::Pet(int n, char *p) : Creatures(p){
		speed = n;
	}

	void Pet::move()
	{
		cout << "I am a Cat." << endl;
		cout << " My name is : " << name << endl;
		cout << " My Running speed is : " << speed << endl;
	}

	/// 13.2 Polymorphism using pointer to objects
	// Rewrite Program 13.1 "poly1.cpp" using pointers to derived class objects.

	class Creatures2
	{
	public:
		char name[40];
		Creatures2(char*p);
		void move();
	};

	class Bird2 : public Creatures2
	{
		int speed;
	public:
		void move();
		Bird2(int n, char * p);
	};

	class Pet2 : public Creatures2
	{
		int speed;
	public:
		void move();
		Pet2(int n, char * p);
	};

	void Poly2() {
		cout << "<-- - poly2.cpp--->" << endl;
		Bird2 *Parrot = new Bird2(5, "Mithu Miyan");
		Parrot->move();
		Pet2 *Cat = new Pet2(1, "Pussy");
		Cat->move();
	}

	Creatures2::Creatures2(char *p)
	{
		strcpy_s(name, p);
	}

	void Creatures2::move()
	{
		cout << "I am " << name << endl;
		cout << "I can move!" << endl;
	}

	Bird2::Bird2(int n, char *p) : Creatures2(p) // Note 1
	{
		speed = n;
	}

	void Bird2::move()
	{
		cout << "I am a bird." << endl;
		cout << " My name is : " << name << endl;
		cout << " My Flying speed is : " << speed << endl;
	}

	Pet2::Pet2(int n, char *p) : Creatures2(p)
	{
		speed = n;
	}

	void Pet2::move()
	{
		cout << "I am a Cat." << endl;
		cout << " My name is : " << name << endl;
		cout << " My Running speed is : " << speed << endl;
	}

	/// 13.3 Twist hero se joker ban jana padta hai
	// Write a program allowing base class pointer to point to derived class object.

	class Joker
	{
	protected:
		char name[20];
	public:
		Joker(char *p); //{strcpy(name, p)}
		void show();
	};

	class Hero : public Joker
	{
	public:
		Hero(char * p2);
		void show();
	};

	void Hero1() {
		cout << " << -- - hero1.cpp--->" << endl;
		Joker * bptr; //BC pointer pointing to BC
		Hero * dptr; // DC pointer
		dptr = new Hero("Raj Kapoor");
		//DC pointer pointing to DC object
		cout << "DC pointer pointing to DC object" << endl;
		dptr->show();
		//  hero = joker ; NOTE! compilation error
		bptr = dptr; //BC pointer pointing to DC
		cout << "BC pointer pointing to DC object" << endl;
		bptr->show();
	}

	Joker::Joker(char *p)
	{
		strcpy_s(name, p);
	}

	void Joker::show()
	{
		cout << "Joker = " << name << endl;
	}

	Hero::Hero(char * p2) :Joker(p2)
	{// no code here 
	
	}

	void Hero::show()
	{
		cout << "Hero = " << name << endl;
	}

	/// 13.5.1 Run time polymorphism in action
	/// 13.4 The twist removed
	// Write a program to show that when base class pointer point to the derived class, method from the derived class is executed, if method in the base class is virtual.

	class Joker2
	{
	protected:
		char name[20];
	public:
		Joker2(char *p); //{strcpy(name, p)}
		virtual void show(); // note 1
	};

	class Hero2 : public Joker2
	{
	public:
		Hero2(char * p2);
		void show();
	};

	void Hero_2() {
		cout << " << -- - hero2.cpp--->" << endl;
		Joker2 * bptr; //BC pointer pointing to BC
		Hero2 * dptr; // DC pointer
		dptr = new Hero2("Raj Kapoor");
		//DC pointer pointing to DC object
		cout << "DC pointer pointing to DC object" << endl;
		dptr->show();
		// hero = joker ; NOTE! compilation error
		bptr = dptr; //BC pointer pointing to DC
		cout << "BC pointer pointing to DC object" << endl;
		bptr->show(); //
	}

	Joker2::Joker2(char *p)
	{
		strcpy_s(name, p);
	}

	void Joker2::show()
	{
		cout << " Joker = " << endl;
	}

	Hero2::Hero2(char * p2) :Joker2(p2)
	{
		// no code required here
	}

	void Hero2::show()
	{
		cout << " Hero = " << name << endl;
	}

	/// 13.8 THE CLIMAX: ARRAY OF DERIVED CLASS OBJECTS
	/// 13.5 Array of derived class objects
	// Calculate the salary of a worker, staff and officer. Use base class Employee. Use the concept of array of base class pointer.

	typedef char string15[15];

	class Employee //abstract base class
	{
	protected:
		float basic;
	public:
		int type;
		virtual void calpay() = 0;
	};

	class Worker : public Employee
	{
		string15 name;
		float gross;
	public:
		Worker(string15 s1, float amt);
		void calpay();
	};

	class Staff : public Employee
	{
		string15 name;
		float gross;
	public:
		Staff(string15 s1, float amt);
		void calpay();
	};

	class Officer : public Employee
	{
		string15 name;
		float gross;
	public:
		Officer(string15 s1, float amt);
		void calpay();
	};

	void Arrobj3() {
		cout << " << -- - arrobj3.cpp--->" << endl;
		Employee *eptr[3];
		eptr[0] = new Worker("tandlekar", 10000);
		eptr[1] = new Staff("Wahgmare", 20000);
		eptr[2] = new Officer("bhole", 30000);
		cout << "Polymorphism of calpay() demonstrated" << endl;
		cout << " Category : Name: Pay " << endl;
		for (int i = 0; i < 3; i++)
			eptr[i]->calpay();
	}

	Worker::Worker(string15 s1, float amt)
	{
		type = 0; // hard coded in the constructor
		strcpy_s(name, s1);
		basic = amt;
	}

	Staff::Staff(string15 s1, float amt)
	{
		type = 1;
		strcpy_s(name, s1);
		basic = amt;
	}

	Officer::Officer(string15 s1, float amt)
	{
		type = 2;
		strcpy_s(name, s1);
		basic = amt;
	}

	void Worker::calpay()
	{
		gross = basic * 1.5 + 1000 /*HRA*/;
		cout << setw(7) << type << setw(13) << name	<< setw(10) << gross << endl;
	}

	void Staff::calpay()
	{
		gross = basic * 1.5 + 2000 /*HRA*/;
		cout << setw(7) << type << setw(13) << name << setw(10) << gross << endl;
	}

	void Officer::calpay()
	{
		gross = basic * 1.5 + 4000 /*HRA*/;
		cout << setw(7) << type << setw(13) << name << setw(10) << gross << endl;
	}

	/// 13.10.1 A class with virtual function can be instantiated
	/// 13.6 Moving output
	// Write a program to demonstrate the following:
	// 1. A class with virtual function can be instantiated. Such virtual function can also be executed.
	// 2. With virtual function in the base class, derived class object executes the function of its own class.

	void delay(long N); // function prototype

	class Creatures3
	{
	public:
		char name[40];
		Creatures3(char *p);
		virtual void move();
	};

	class Bird3 : public Creatures3
	{
		int speed;
	public:
		void move();
		Bird3(int n, char * p);
	};

	class Pet3 : public Creatures3
	{
		int speed;
	public:
		void move();
		Pet3(int n, char * p);
	};

	void Vbase3() {
		cout << " << -- - vbase3.cpp--->" << endl;
		Creatures3 *ptr1;
		ptr1 = new Creatures3("somebody");
		ptr1->move();
		Bird3 *Parrot;
		Parrot = new Bird3(5, "Mithu Miyan");
		Pet3 * Cat;
		Cat = new Pet3(1, "Pussy");
		ptr1 = Parrot;
		ptr1->move();
		ptr1 = Cat;
		ptr1->move();
	}

	Creatures3::Creatures3(char *p)
	{
		strcpy_s(name, p);
	}

	void Creatures3::move()
	{
		cout << "*** Hello world!";
		cout << " I am " << name;
		cout << " I can move! ***" << endl;
	}

	Bird3::Bird3(int n, char *p) : Creatures3(p)
	{
		speed = n;
	}

	void Bird3::move()
	{
		cout << "I am a bird : My name is : " << name << endl;
		cout << " My Flying speed is : " << speed << endl;
		int i;
		for (i = 5; i < 30; i++)
		{
			_putch('*');
			delay(10000 / speed);
			//delay is inversely proportional to speed
			_putch(' ');
		}
		cout << endl;
	}

	Pet3::Pet3(int n, char *p) : Creatures3(p)
	{
		speed = n;
	}

	void Pet3::move()
	{
		int i;
		cout << "I am a Cat : My name is : " << name << endl;
		cout << " My Running speed is : " << speed << endl;
		for (i = 5; i < 30; i++)
		{
			_putch('#');
			delay(10000 / speed);
			// delay is inversely proportional to speed
			_putch(' ');
		}
		cout << endl;
	}

	void delay(long N)
	{
		long i, j, k;
		float x = 0;
		for (j = 0; j < N; j++)
			for (i = 0; i < 5000; i++)
				x = x / 7;
	}

	/// 13.10.2 Class shape
	/// 13.7 Polymorphism – perimeter of shapes
	// Design a polymorphic class hierarchy for closed shapes such as circle, rectangle and triangle. 
	// Also write a polymorphic function that calculates perimeter of these shapes. Write a program to test these classes.

	// circle rectangle and triangle. Perimeter of these shapes.

	#define M_PI       3.14159265358979323846   // pi

	class Shape
	{
	public:
		virtual void perimeter() = 0;
	};

	class Rectangle : public Shape
	{
	private:
		int x1, y1, x2, y2;
		float peri;
	public:
		Rectangle(int a, int b, int c, int d);
		void perimeter();
	};

	class Circle : public Shape
	{
	private:
		int x0, y0, rad;
		float peri;
	public:
		Circle(int a, int b, int r);
		void perimeter();
	};

	class Triangle : public Shape
	{
	private:
		int x1, y1, x2, y2, x3, y3;
		float peri;
	public:
		Triangle(int a, int b, int c, int d, int e, int f);
		void perimeter();
	};

	void Shape1() {
		cout << " << -- - shape1.cpp--->" << endl;
		Shape *shp[3];
		shp[0] = new Rectangle(0, 0, 4, 4);
		shp[0]->perimeter();
		shp[1] = new Circle(0, 0, 4);
		shp[1]->perimeter();
		shp[2] = new Triangle(2, 2, 4, 4, 2, 4);
		shp[2]->perimeter();
	}

	Rectangle::Rectangle(int a, int b, int c, int d)
	{
		x1 = a; y1 = b;
		x2 = c; y2 = d;
	}

	void Rectangle::perimeter()
	{
		peri = 2 * abs(x2 - x1) + 2 * abs(y2 - y1);
		cout << "perimeter of Rectangle is : " << peri << endl;
	}

	Circle::Circle(int a, int b, int r)
	{
		x0 = a;
		y0 = b;
		rad = r;
	}

	void Circle::perimeter()
	{
		peri = 2 * M_PI * rad;
		cout << "perimeter of Circle is : " << peri << endl;
	}

	Triangle::Triangle(int a, int b, int c, int d, int e, int f)
	{
		x1 = a; y1 = b;
		x2 = c; y2 = d;
		x3 = e; y3 = f;
	}

	void Triangle::perimeter()
	{
		peri = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))
			 + sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2))
			 + sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
		cout << "perimeter of triangle is : " << peri << endl;
	}

	///////////////////////////
	////       TASKS       ////
	/////////////////////////// 

	// 1. What is the difference between static and dynamic binding?

	// 2. Differentiate between early binding and late binding.

	// 3. Object-oriented programming is programming with Polymorphism. Justify this with a good example.

	// 4. Can a derived class pointer point to base class object? Can a base class pointer point to derived class object?

	// 5. How is polymorphism achieved at run time? Explain with C++ coding.

	// 6. Explain the use of virtual functions with an example in the situation, where base class pointer points to derived class object.

	// 7. Write down all the rules with respect to virtual functions.

	// 8. What are pure virtual functions? Can classes having such functions be instantiated?

	// 9. What are abstract classes? Can such classes be instantiated?

	// 10. What is the use of an array of base class pointers?

	// 11. Discuss advantages and disadvantages of “array of base class pointers”

	// 12. Why member functions are not virtual by default?

	// 13. Study the concept of “interface” from java language. Can this concept be implemented (directly or indirectly) in C++?

	// 14. Define base class Window with virtual function show(). Let TextWindow and SplWindow classes inherit class window. 
	//     Class SplWindow is TextWindow with title bar. Write a program to demonstrate that pointer to class Window can display a text or special window.

	class Window
	{
	public:
		Window();
		~Window();
		virtual void show();
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
		void show();
	private:

	};

	TextWindow::TextWindow()
	{
	}

	TextWindow::~TextWindow()
	{
	}

	class SplWindow: public Window
	{
	public:
		SplWindow();
		~SplWindow();
		void show();
	private:

	};

	SplWindow::SplWindow()
	{
	}

	SplWindow::~SplWindow()
	{
	}

	void PointerToBase() {
		Window *ptr;
		ptr = new Window();
		ptr->show();
		ptr = new TextWindow();
		ptr->show();
		ptr = new SplWindow();
		ptr->show();
	}

	void Window::show() {
		cout << "This is a base Window!" << endl;
	}

	void TextWindow::show() {
		cout << "This is an inherited TextWindow!" << endl;
	}

	void SplWindow::show() {
		cout << "This is an inherited SplWindow!" << endl;
	}

	// 15. Imagine a publishing company that markets both book and audiocassette version to its works. 
	//     Create a class publication that stores the title (a string) and price (type float) of a publication. 
	//     From this class derive two classes: book, which adds a page count (type int); and tape, which adds a playing time in minutes (type float). 
	//     Each of these three classes should have a getdata() function to gets its data from the user at the keyboard, and a putdata() function to display its data. 
	//     Write a main( ) program in C++ to test the book and tape classes by creating instances of them, asking the user to fill in data with getdata(), and then displaying the data with putdata().

	class Publication
	{
	public:
		Publication();
		~Publication();
		string getTitle();
		void setTitle(string);
		float getPrite();
		void setPrice(float);
	private:
		string title;
		float price;
	};

	Publication::Publication()
	{
	}

	Publication::~Publication()
	{
	}

	class Book: public Publication
	{
	public:
		Book();
		~Book();
		int getPageCount();
		void setPageCount(int);
	private:
		int page_count;
	};

	Book::Book()
	{
	}

	Book::~Book()
	{
	}

	class Tape: public Publication
	{
	public:
		Tape();
		~Tape();
		float getPlayingTime();
		void setPlayingTime(float);
	private:
		float playing_time;
	};

	Tape::Tape()
	{
	}

	Tape::~Tape()
	{
	}

	void TestPublic() {
		Book *b1 = new Book();
		b1->setTitle("This is a Titile");
		b1->setPrice(1500);
		b1->setPageCount(345);

		Tape *t1 = new Tape();
		t1->setTitle("Best Songs");
		t1->setPrice(1450);
		t1->setPlayingTime(1.50);

		cout << "title: " << b1->getTitle() << endl;
		cout << "price: " << b1->getPrite() << endl;
		cout << "Page Count: " << b1->getPageCount() << endl;

		cout << "title: " << t1->getTitle() << endl;
		cout << "price: " << t1->getPrite() << endl;
		cout << "Playing Time: " << t1->getPlayingTime() << endl;
	}

	void Publication::setTitle(string t) {
		title = t;
	}

	string Publication::getTitle() {
		return title;
	}

	void Publication::setPrice(float p) {
		price = p;
	}

	float Publication::getPrite() {
		return price;
	}

	void Book::setPageCount(int pc) {
		page_count = pc;
	}

	int Book::getPageCount() {
		return page_count;
	}

	void Tape::setPlayingTime(float pt) {
		playing_time = pt;
	}

	float Tape::getPlayingTime() {
		return playing_time;
	}

	// 16. Write a class employee with two functions get_data() and put_data() to read the name and number of employee and display them, respectively. 
	//     Drive two classes, one manager and other scientist. In manager class add one more variable title. In scientist class add more variable publication and display them.

	class Employee2
	{
	public:
		Employee2();
		~Employee2();
		void get_data();
		void put_data(string, int);
	private:
		string name;
		int number;
	};

	Employee2::Employee2()
	{
	}

	Employee2::~Employee2()
	{
	}

	void Employee2::get_data() {
		cout << "name: " << name << endl;
		cout << "number: " << number << endl;
	}

	void Employee2::put_data(string pname, int pnumber) {
		name = pname;
		number = pnumber;
	}

	class Manager: public Employee2
	{
	public:
		Manager(string);
		~Manager();
		void show();
	private:
		string title;
	};

	Manager::Manager(string t)
	{
		title = t;
	}

	Manager::~Manager()
	{
	}

	void Manager::show() {
		cout << "title: " << title << endl;
	}

	class Scientist: public Employee2
	{
	public:
		Scientist(int);
		~Scientist();
		void show();
	private:
		int publication;
	};

	Scientist::Scientist(int p)
	{
		publication = p;
	}

	Scientist::~Scientist()
	{
	}

	void Scientist::show() {
		cout << "publication: " << publication << endl;
	}

	void TestOfEmployee2() {
		Manager *mg1 = new Manager("title1");
		mg1->put_data("name 1", 10);

		Scientist *sc1 = new Scientist(2010);
		sc1->put_data("name2", 20);

		mg1->get_data();
		mg1->show();

		sc1->get_data();
		sc1->show();
	}

	// 17. Write a program in C++ that contains a class derived from base. The base class should have a virtual function show() and it should be overridden. 
	//     Try to call show() from the constructor of the base class and display the result.

	class BaseClass
	{
	public:
		BaseClass();
		~BaseClass();
		virtual void show() = 0;
	private:

	};

	BaseClass::BaseClass()
	{
		//show();
	}

	BaseClass::~BaseClass()
	{
	}

	class DrivenClass: public BaseClass
	{
	public:
		DrivenClass();
		~DrivenClass();
		void show() {
			cout << "this is a drive class" << endl;
		}
	private:

	};

	DrivenClass::DrivenClass()
	{
	}

	DrivenClass::~DrivenClass()
	{
	}

	void TestVirtualOverridenFunc() {
		DrivenClass *dc = new DrivenClass(); // Linker error
	}

	// 18. Design a polymorphic class hierarchy for students of university. They are two types of students: day scholars and hostellers. 
	//     Assume that day scholars are having 30% fee concession (as they are not availing hostel facilities). Write a program to test this class. 
	//     Hint: Let “Student” be the abstract base class with method fee as pure virtual function. The derived classes may be named as Std_Dscho and Std_Host.

	class Student
	{
	public:
		Student(string, string, int);
		~Student();
		virtual void show() = 0;
		virtual float buy(int) = 0;
		string name;
		string department;
		int age;
		int price = 150;
	};

	Student::Student(string n, string d, int a)
	{
		name = n;
		department = d;
		age = a;
	}

	Student::~Student()
	{
	}

	class Std_Dscho : public Student
	{
	public:
		Std_Dscho(string, string, int, string);
		~Std_Dscho();
		void show();
		float buy(int money);
	private:
		string home_city;
		float conces = 0.3;
	};

	Std_Dscho::Std_Dscho(string n, string d, int a, string h): Student(n, d, a)
	{
		home_city = h;
	}

	Std_Dscho::~Std_Dscho()
	{
	}

	class Std_Host : public Student
	{
	public:
		Std_Host(string, string, int, string);
		~Std_Host();
		void show();
		float buy(int money);
	private:
		string hostel_name;
		float conces = 1.0;
	};

	Std_Host::Std_Host(string n, string d, int a, string h): Student(n, d, a)
	{
		hostel_name = h;
	}

	Std_Host::~Std_Host()
	{
	}

	void TestStudents() {
		Std_Dscho *ds = new Std_Dscho("Endre", "Info", 28, "Kiralyhago");
		Std_Host *hs = new Std_Host("Viktor", "Mernok", 26, "Gyori u");

		cout << "buy: " << ds->buy(15000) << endl;
		ds->show();

		cout << "buy: " << hs->buy(15000) << endl;
		hs->show();
	}

	void Std_Dscho::show() {
		cout << "name: " << name << " department: " << department << " age: " << age << endl;
		cout << "home_city: " << home_city << endl;
	}

	void Std_Host::show() {
		cout << "name: " << name << " department: " << department << " age: " << age << endl;
		cout << "hostel_name: " << hostel_name << endl;
	}

	float Std_Dscho::buy(int money) {
		return money / (price * conces);
	}

	float Std_Host::buy(int money) {
		return money / (price * conces);
	}

	// 19. Design a polymorphic class hierarchy for closed shapes such as circle, rectangle and triangle. Also write a polymorphic function that calculates area of these shapes. 
	//     Write a program to test these classes.

	class Shape2
	{
	public:
		Shape2();
		~Shape2();
		virtual void area() = 0;
	};

	Shape2::Shape2()
	{
	}

	Shape2::~Shape2()
	{
	}

	class Circle2: public Shape2
	{
	public:
		Circle2(int, int, int);
		~Circle2();
		void area();
	private:
		int radius;
		int x; int y;
	};

	Circle2::Circle2(int r, int xc, int yc)
	{
		radius = r; x = xc; y = yc;
	}

	Circle2::~Circle2()
	{
	}

	class Rectangle2: Shape2
	{
	public:
		Rectangle2(int, int, int, int, int, int, int, int);
		~Rectangle2();
		void area();
	private:
		int x1, y1, x2, y2, x3, y3, x4, y4;
	};

	Rectangle2::Rectangle2(int a, int b, int c, int d, int e, int f, int g, int h)
	{
		x1 = a; y1 = b; x2 = c; y2 = d;
		x3 = e; y3 = f; x4 = g; y4 = h;
	}

	Rectangle2::~Rectangle2()
	{
	}

	class Triangle2: public Shape2
	{
	public:
		Triangle2(int, int, int, int, int, int);
		~Triangle2();
		void area();
	private:
		int x1, y1, x2, y2, x3, y3;
	};

	Triangle2::Triangle2(int a, int b, int c, int d, int e, int f)
	{
		x1 = a; y1 = b;
		x2 = c; y2 = d;
		x3 = e; y3 = f;
	}

	Triangle2::~Triangle2()
	{
	}

	void TestShape2() {

	}

	void Circle2::area() {
		float area = radius * radius * M_PI;
		cout << "area of circle: " << area << endl;
	}

	void Rectangle2::area() {
		float a = (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
		float b = (y3 - y2) * (y3 - y2) + (x3 - x2) * (x3 - x2);
		float area = a * b;
		cout << "area of rectangle: " << area << endl;
	}

	void Triangle2::area() {
		float h = 1;
		float base = (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
		float area = 0.5 * base * h;
		cout << "area of triangle: " << area << endl;
	}

}