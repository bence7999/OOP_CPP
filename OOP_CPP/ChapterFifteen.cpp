#include "ChapterFifteen.h"

using namespace std;

namespace ChapterFifteen {

	/// 15.2 FUNCTION TEMPLATE
	/// 15.1 Template -– -function add
	// Write a program to develop template function add().

	template <class T>
	void add(T a, T b, T& c);

	void Tfunc1() {
		cout << "<-- - tfunc1.cpp--->" << endl;
		int mark1 = 3, mark2 = 4, mark3 = 0;
		add(mark1, mark2, mark3);
		cout << "mark3 = " << mark3 << endl;
		char ch1 = ' ', ch2 = 'B', ch3 = ' ? ';
		add(ch1, ch2, ch3);
		cout << "ch3 is--->" << ch3 << "<-- - " << endl;
	}

	template <class T>
	void add(T a, T b, T& c)
	{
		c = a + b;
	}

	/// 15.2 FUNCTION TEMPLATE
	/// 15.2 Template -– function sort I
	// Write a program to develop template function sort().

	const int max = 25;

	template <class T>
	void sort(T a[max]);

	void Tfunc2() {
		int a[max];
		cout << "<-- - tfunc2.cpp--->" << endl;
		int i;
		for (i = 0; i< max; i++)
			a[i] = 100 - 4 * i; //array initialization
		sort(a);
		cout << "After sorting" << endl;
		cout << a[0] << " " << a[1] << " " << a[2];
	}

	template <class T>
	void sort(T a[max])
	{
		int i, j;
		T temp;
		for (i = 0; i < max - 1; i++) {
			for (j = 0; j < max - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}

	}

	/// 15.2 FUNCTION TEMPLATE
	/// 15.4 Template – function sort III
	// Sort the array of class student using template function sort().

	class student
	{
		private:
			int rollNum;
		public:
			void init(int i);
			void show();
			int friend operator >(student s1, student s2);
		};

	void Tfunc4() {
		student std[max];
		cout << "<-- - tfunc4.cpp--->" << endl;
		int i;
		for (i = 0; i<max; i++)
			std[i].init(60 - 2 * i); //initializing roll number
		sort(std);
		cout << "After  sorting" << endl;
		cout << "roll numbers" << endl;
		std[0].show();
		std[1].show();
		std[2].show();
	}

	void student::init(int i)
	{
		rollNum = i;
	}

	void student::show()
	{
		cout << rollNum << endl;
	}

	int operator > (student s1, student s2)
	{
		int answer = 0;
		if (s1.rollNum > s2.rollNum)
			answer = 1;
		return answer;
	}

	/// 15.2.1 Overloading of template functions
	/// 15.5 Overloading template function
	// Write a program to overload template function.

	template <class T>
	T add(T a, T b)// " first one"
	{
		cout << "first one" << endl;
		return a + b;
	}

	template <class T>
	T add(T a, int b)// " second one"
	{
		cout << "second one" << endl;
		return a + b;
	}

	long add(long a, long b)// non template function
	{
		cout << "long function called" << endl;
		return a + b;
	};

	void Tover3() {
		cout << "<-- - tover3.cpp--->" << endl;
		float mark1 = 3, mark2 = 4, mark3 = 0;
		mark3 = add(mark1, mark2);
		cout << "mark3 = " << mark3 << endl;
		mark3 = add(mark1, 1);
		cout << "mark3 = " << mark3 << endl;
		long l = 22, m = 33, n = 0;
		n = add(l, m);
		cout << "n = " << n << endl;
		// n = add(3,3); // note 1
	}

	/// 15.3 CLASS TEMPLATES
	/// 15.6 Class template
	// Write a program to create class LIST. It should be using items of template T. Instantiate LIST with type int.

	const int MAX = 100;

	template <class T>
	class LIST
	{
	private:
		T a[MAX];
		int size;
	public:
		LIST();
		int check(T item);
		void addItem(T item);
		void show();
	};

	void Tclass1() {
		LIST <int> mylist;
		cout << "<-- - tclass1.cpp--->" << endl;
		mylist.addItem(12);
		mylist.addItem(7);
		mylist.addItem(12);
		mylist.show();
	}

	template <class T> LIST<T>::LIST()
	{
		int i;
		for (i = 0; i < MAX; i++);
		a[i] = 0;
		size = 0;
	}

	template <class T> void LIST<T>::addItem(T item)
	{
		if (size >= MAX)
		{
			cout << "error" << endl;
			cout << char(7) << "overflow" << endl;
		}
		else
		{
			if (check(item) == -1)
			{
				a[size] = item;
				size++;
			}
			else
				cout << "duplicate entry rejected" << endl;
		}
	}

	template <class T> void LIST<T>::show()
	{
		int i;
		cout << "showing the list" << endl;
		for (i = 0; i<size; i++)
			cout << a[i] << endl;
		cout << "end of list" << endl;
	}

	template <class T> int LIST<T>::check(T item)
	{
		int answer = -1;
		int i;
		for (i = 0; i<size; i++)
		{
			if (a[i] == item)
				answer = i;
			if (answer != -1) break;
		};
		return answer;
	}

	/* rule book of list
	1) only integers as components.
	2) no duplicates
	3) maximum number 100;
	*/

	/// 15.6 END OF CHAPTER PROGRAMS
	/// 15.7 Array with bound checking
	// Write a program to create class to implement a "Safe Array". It should be using template <class T>.

	const int SIZE = 100;

	template <class T>
	class Sarray
	{
	private:
		T a[SIZE];
	public:
		Sarray();
		void safeput(T z, int i);
		T safeget(int i);
	};

	void Tclass4() {
		Sarray <int> my_array;
		Sarray <float> your_array;
		cout << "<-- - tclass4.cpp starts--->" << endl;
		// my_array.safeput(57,101);    // Note 1
		cout << my_array.safeget(10) << endl;
		cout << my_array.safeget(9) << endl;
		cout << your_array.safeget(10);
	}

	template <class T> 
	void Sarray<T>::safeput(T z, int i)
	{
		if (i<0) abort();
		if (i >= SIZE) abort();
		a[i] = z;
	}

	template <class T> 
	T Sarray<T>::safeget(int i)
	{
		if (i<0) abort();
		if (i >= SIZE) abort();
		return a[i];
	}

	template <>
	Sarray<float>::Sarray()    // Note 3
	{
		int i;
		for (i = 0; i<SIZE; i++)
			a[i] = i + 0.5;
	}

	template <class T> 
	Sarray<T>::Sarray()   // Note 2
	{
		int i;
		for (i = 0; i<SIZE; i++)
			a[i] = i;
	}

	/// 15.6.2 Array with bounds checking II
	/// 15.8 Safe array II
	// Write a program to create a template class to implement a "Safe Array" in elegant manner. It should be using template <class T, int SIZE>.

	template <class T, int SIZE>
	class Sarray2
	{
	private:
		T a[SIZE];
	public:
		Sarray2();
		T & operator[] (int n);
	};

	void Tclass6() {
		//int asize =10;
		Sarray2 <int, 100> my_array;
		cout << "<-- - tclass6.cpp starts--->" << endl;
		cout << my_array[10] << endl;
		// now initializing 10 th element
		my_array[10] = 4700;
		// now printing 10 th element
		cout << my_array[10] << endl;
		cout << my_array[150];
	}

	template <class T, int SIZE> T & Sarray2<T, SIZE>::operator [](int n)
	{
		if ((n < 0) || (n >= SIZE))
		{
			cout << " Index " << n << "out of bounds" << endl;
			cout << " Now aborting the program " << endl;
			abort();
		}
		return (a[n]);
	}

	template <class T, int SIZE> Sarray2<T, SIZE>::Sarray2()
	{
		int i;
		for (i = 0; i<SIZE; i++)
			a[i] = i * 2;
	}

	/// 15.6.3 Static members in class template
	/// 15.9 Static members in template class
	// Write a program to demonstrate use of static members in a template class. Also demonstrate use of friend function in such a class.

	template <class T>
	class LIST2
	{
	private:
		T a[MAX];
		int size;
		static int count;
	public:
		LIST2();
		int check(T item);
		void addItem(T item);
		void show();
		static void showCount()
		{
			cout << "count is " << count << endl; ;
		};
		friend void showSize(LIST2<T> x);
	};

	int LIST2<int>::count = 0;

	void Tpower3() {
		LIST2 <int> mylist;
		cout << "<-- - tpower3.cpp--->" << endl;
		mylist.addItem(12);
		mylist.addItem(7);
		mylist.addItem(12);
		mylist.show();
		mylist.showCount();
		LIST2 <int> mylist1;
		mylist.showCount();
		showSize(mylist);
		showSize(mylist1);
	}

	template <class T> 
	LIST2<T>::LIST2()
	{
		int i;
		for (i = 0; i < MAX; i++);
		a[i] = 0;
		size = 0;
		count = count + 1;
	}

	template <class T> 
	void LIST2<T>::addItem(T item)
	{
		if (size >= MAX)
		{
			cout << "error" << endl;
			cout << char(7) << "overflow" << endl;
		}
		else
		{
			if (check(item) == -1)
			{
				a[size] = item;
				size++;
			}
			else
				cout << "duplicate entry rejected" << endl;
		}
	}

	template <class T> 
	void LIST2<T>::show()
	{
		int i;
		cout << "showing the list" << endl;
		for (i = 0; i<size; i++)
			cout << a[i] << endl;
		cout << "end of list" << endl;
	}

	template <class T> 
	int LIST2<T>::check(T item)
	{
		int answer = -1;
		int i;
		for (i = 0; i<size; i++)
		{
			if (a[i] == item)
				answer = i;
			if (answer != -1) break;
		};
		return answer;
	}

	void showSize(LIST2<int> x)
	{
		cout << "showSize in action : " << x.size << endl;
	};

	/// 15.6.4 Class template and inheritance
	/// 15.10 Inheriting template class
	// Write a program to demonstrate inheritance of a template class.

	template <class T>
	class LIST3
	{
	protected:
		T a[MAX];
		int size;
	public:
		LIST3();
		int check(T item);
		void addItem(T item);
		void show();
	};

	class OrderedList :public LIST3<int>
	{
	public:
		void addItem(int item);
		void sort();
	};

	void Tinher1() {
		//LIST <int> mylist;
		OrderedList list1;
		cout << "<-- - tinher1.cpp--->" << endl;
		list1.addItem(12);
		list1.addItem(7);
		list1.addItem(12);
		list1.addItem(32);
		list1.addItem(3);
		list1.show();
	}

	template <class T> 
	LIST3<T>::LIST3()
	{
		int i;
		for (i = 0; i < MAX; i++);
		a[i] = 0;
		size = 0;
	}

	template <class T> 
	void LIST3<T>::addItem(T item)
	{
		if (size >= MAX)
		{
			cout << "error" << endl;
			cout << char(7) << "overflow" << endl;
		}
		else
		{
			if (check(item) == -1)
			{
				a[size] = item;
				size++;
			}
			else
				cout << "duplicate entry rejected" << endl;
		}
	}

	template <class T> 
	void LIST3<T>::show()
	{
		int i;
		cout << "showing the list" << endl;
		for (i = 0; i<size; i++)
			cout << a[i] << endl;
		cout << "end of list" << endl;
	}

	template <class T> 
	int LIST3<T>::check(T item)
	{
		int answer = -1;
		int i;
		for (i = 0; i<size; i++)
		{
			if (a[i] == item)
				answer = i;
			if (answer != -1) break;
		};
		return answer;
	}

	// template <class T>
	void OrderedList::addItem(int item)
	{
		if (size >= MAX)
		{
			cout << "error" << endl;
			cout << char(7) << "overflow" << endl;
		}
		else
		{
			if (check(item) == -1)
			{
				a[size] = item;
				size++;
				sort();
			}
			else
				cout << "duplicate entry rejected" << endl;
		}
	}

	void OrderedList::sort()
	{
		int i, j, temp;
		for (j = 0; j< size - 1; j++)
			for (i = 0; i< size - 1; i++)
			{
				if (a[i]>a[i + 1])
				{
					temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
				};
			}
	}

	///////////////////////////
	////       TASKS       ////
	///////////////////////////

	// 1. What is generic programming? What are its advantages? State some of its applications.

	// 2. What is function template?

	// 3. Write a function template to find the smallest elements in an array.


}