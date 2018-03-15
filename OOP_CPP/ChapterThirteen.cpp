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



}