#include "ChapterTwelve.h"

using namespace std;

namespace ChapterTwelve {

	// Write a program to introduce pointers.

	void Ptr1() {
		int my_marks = 99;
		cout << "<-- - ptr1.cpp--->" << endl;
		int * ptr;
		ptr = &my_marks;
		cout << "1.my_marks are " << *ptr << endl;
		*ptr = 55;
		cout << "2. * ptr is " << *ptr << endl;
		cout << "3.my_marks are " << my_marks << endl;
	}

	// Write a program to illustrate the use of pointer to access array elements.

	void Parr1() {
		int marks[10] = { 80,91,82,63,74,85,96,87,78,59 };
		int *p;
		float avg, sum = 0;
		p = &marks[0];
		cout << "<-- - parr1.cpp--->" << endl;
		cout << marks[3] << endl; // just for debugging
		for (int i = 0; i<10; i++)
			sum = sum + p[i]; // note 1
		avg = sum / 10.0;
		cout << "average is : " << avg << endl;
	}

	// A program consists of the following declaration:
	// int x[5]= {12,113,214,315,416 };
	// What is the meaning of
	// 1. sizeof(x)
	// 2. x
	// 3. (x+2)
	// 4. *x
	// 5. (*x+2) 6)*(x+2)

	void Point1() {
		int x[5] = { 12,113,214,315,416 };
		cout << "<-- - point1.cpp--->" << endl;
		cout << "1." << sizeof(x) << endl;
		cout << "2." << x << endl;
		cout << "3." << (x + 2) << endl;
		cout << "4." << *x << endl;
		cout << "5." << (*x + 2) << endl;
		cout << "6." << *(x + 2) << endl;
	}

	// Write a program to illustrate the use of pointers to function.

	int sum(int *a, int n);
	int avg(int *a, int n);
	const int five = 5;

	void Point2() {
		int box[five] = { 3,4,6,7,9 };
		int(*q)(int *a, int n);
		int(*p)(int *a, int n);
		int(*temp)(int *a, int n);
		p = sum;
		q = avg;
		cout << "<-- - point2.cpp--->" << endl;
		cout << "Using functions the value of sum and avg are" << endl;
		cout << sum(box, five) << endl;
		cout << avg(box, five) << endl;
		cout << "now using pointer p for sum and q for avg\n";
		cout << p(box, five) << endl;
		cout << q(box, five) << endl;
		//now pointers are swapped;
		temp = p;
		p = q;
		q = temp;
		cout << "after swapping p for avg and q for sum" << endl;
		cout << p(box, five) << endl;
		cout << q(box, five) << endl;
	}

	int sum(int *a, int n)
	{
		int i, answer = 0;
		for (i = 0; i<n; i++)
			answer += a[i];
		return answer;
	}

	int avg(int *a, int n)
	{
		int i, answer = 0;
		for (i = 0; i<n; i++)
			answer += a[i];
		answer = answer / n; // note integer division
		return answer;
	}

	// Write a program to demonstrate that delete operator calls the destructor.

	class Period
	{
		int days, months, years;
	public:
		Period(int d, int m, int y)
		{
			cout << "constructor called" << endl;
			days = d;
			months = m;
			years = y;
		};
		~Period()
		{
			cout << "Destructor called " << endl;
		};
		void show()
		{
			cout << days << ":" << months << " : " << years << endl;
		};
	};

	void Delete1() {
		cout << "<-- - delete1.cpp--->" << endl;
		Period *p1 = new Period(1, 1, 2012);
		p1->show();
		delete p1;
		cout << "we are here" << endl;
	}

	// Write a program to allocate different chunks of memory for a two dimensional array of integer.

	const int N = 10;
	const int M = 5;

	void Arrt2() {
		int *p[M];
		int i, j, k;
		cout << "<-- - arrt2.cpp--->" << endl;
		// allocating memory
		for (i = 0; i < M; i++)
			p[i] = new (int[N]);
		// Defining table
		for (i = 0; i<M; i++)    for (j = 0; j<N; j++)
			p[i][j] = (i + 1) * (j + 11);
		// Now printing it
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
				cout << setw(6) << p[i][j];
			cout << endl;
		}
	}

	// Write a program to allocate single chunk of memory for a two dimensional array of integers.

	void Arrt2_2() {
		int(*p)[N];
		int i, j, k;
		cout << "<-- - arrt3.cpp--->" << endl;
		// allocating memory
		p = new (int[M][N]);
		// Defining table
		for (i = 0; i<M; i++)
			for (j = 0; j<N; j++)
				// arrt3.cpp
				p[i][j] = (i + 1) * (j + 21);
		// Now printing it
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
				cout << setw(5) << p[i][j];
			cout << endl;
		}
	}

	// Write a program to sort array of objects using pointers.

	const int max = 55;
	time_t t0, t1;

	class Student
	{
	public:
		char name[1000];
		Student(int i);
		void init(int i);
		int rollNum;
	};

	void Arrobj5() {
		int i, j;
		Student *ptr;
		Student *sptr[max]; // note 1
		cout << "<-- - arrobj5.cpp--->" << endl;
		for (i = 0; i<max; i++)
		{
			sptr[i] = new Student(i); // note2
			if (sptr[i] == NULL)
			{
				cout << i << endl;
				exit(1);
			};
		}
		cout << "RollNum of second Student is ";
		cout << sptr[1]->rollNum << endl;
		time(&t0);
		// bubble sort
		for (int k = 0; k<1000; k++)
		{
			for (i = 0; i<max; i++) sptr[i]->init(i);
			for (i = 0; i<max; i++)
				for (j = 0; j<max - 1; j++)
				{
					if (sptr[j]->rollNum < sptr[j + 1]->rollNum)
					{ // swap
						ptr = sptr[j];
						sptr[j] = sptr[j + 1];
						sptr[j + 1] = ptr;
					}
				}
		}
		time(&t1);
		cout << "time in seconds " << t1 - t0 << endl;
		cout << "RollNum of second Student is ";
		cout << sptr[1]->rollNum << endl;
	}

	Student::Student(int i) // constructor
	{
		rollNum = i;
	}

	void Student::init(int i) //
	{
		rollNum = i;
	}

	// Write a program to develop class Vector for storing integers. !!!! Rosssz

	class Vector
	{
	protected:
		int size, capacity;
		int * p;
	public:
		Vector(int n);
		~Vector();
		int getSize() { return size; };
		int getCapacity() { return capacity; };
		void add(int m);
		void insert(int m, int i);
		int at(int i) { return p[i]; };
		void incrcap();
		void show();
	};

	void Vector::show()
	{
		int i;
		cout << "Vector->";
		for (i = 0; i<size; i++)
		{
			cout << at(i) << "\t";
		}
		cout << endl;
	}

	void Vector::incrcap()
	{
		int tcap = capacity + 3;
		int *q = &tcap;
		for (int j = 0; j<size; j++)
			q[j] = p[j];
		capacity = tcap;
		p = q;
	}

	Vector::Vector(int n)
	{
		p = new int(n);
		size = 0;
		capacity = 3;
	}

	void Vector::add(int m)
	{
		if (size == capacity) incrcap();
		if (size < capacity)
		{
			p[size] = m;
			size++;
		}
		else
		{
			cout << "error2" << endl;
		}
	}

	void Vector::insert(int m, int i)
	{
		if (i >= size) cout << "error1 inserting out of range" << endl;
		else
		{
			if (size > capacity) cout << "serious implemetation error" << endl;
			else
			{
				if (size == capacity) 
					incrcap();
				for (int k = size; k > i; k--)
					p[k] = p[k - 1];
				p[i] = m;
				size++;
			}
		}
	}

	void Vec1() {
		int i;
		int A[] = { 7, 4, 1, 9, 5, 3 , 6 };
		Vector* vect1 = new Vector(3);
		cout << "<-- - vec1.cpp--->" << endl;
		cout << "1) Size of Vector = " << vect1->getSize() << endl;
		cout << "2) Capacity of Vector = " << vect1->getCapacity() << endl;
		cout << "3) Now adding elements " << endl;
		for (i = 0; i<3; i++)
		{
			vect1->add(A[i]);
		}
		cout << "4)Printing vector " << endl;
		vect1->show();
		cout << "5) inserting More elements " << endl;
		vect1->insert(A[3], 0);
		vect1->insert(A[4], 2);
		cout << "6) Vector at this time" << endl;
		vect1->show();
		cout << "7) adding More elements " << endl;    vect1->add(A[5]);
		vect1->add(A[6]);
		cout << "8) Vector at this time" << endl;
		vect1->show();
	}

	// Write a program to study comparison of pointers.

	void Ptr7() {
		int mymarks = 99;
		cout << "<-- - ptr7.cpp--->" << endl;
		/*int * ptr;
		float *ptrf;
		float *ptrf2;
		void *ptrv;
		ptr = &mymarks;
		if (ptr == ptrv)
			cout << "1.equal to pointer to void" << endl;
		else
			cout << "1.Not equal to pointer to void" << endl;
		if (ptrf2 > ptrf)
			cout << "2.Warning Nonportable pointer comparison" << endl;
		ptrf = new float(22.5);
		cout << "3. *ptrf is " << *ptrf << endl;
		delete ptrf;
		cout << "4.deleting allocated memory" << endl;*/
	}

	// Write a program to study "NULL".

	void ptr11() {
		/*cout << "<-- - ptr11.cpp--->" << endl;
		int * ptr1 = new int(4);
		char * ptr2 = new char('a');
		ptr2 = NULL;
		cout << "1." << ptr1 << endl;
		cout << "2." << *ptr1 << endl;
		cout << "3." << ptr2 << endl;
		cout << "4." << *ptr2 << endl;
		cout << "5." << (int)*ptr2 << endl;
		cout << "6." << &ptr2 << endl;*/
	}

	///////////////////////////
	////       TASKS       ////
	/////////////////////////// 

	// 1. Explain the rules regarding comparison of pointers.

	// 2. Explain the syntax and use of ‘*’ and ‘&’ operators.

	// 3. 

}