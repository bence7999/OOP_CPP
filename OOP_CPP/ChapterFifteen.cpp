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
		for (i = 0; i < max; i++)
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
		for (i = 0; i < max; i++)
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

	template <class T> 
	LIST<T>::LIST()
	{
		int i;
		for (i = 0; i < MAX; i++);
		a[i] = 0;
		size = 0;
	}

	template <class T> 
	void LIST<T>::addItem(T item)
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
	void LIST<T>::show()
	{
		int i;
		cout << "showing the list" << endl;
		for (i = 0; i < size; i++)
			cout << a[i] << endl;
		cout << "end of list" << endl;
	}

	template <class T> 
	int LIST<T>::check(T item)
	{
		int answer = -1;
		int i;
		for (i = 0; i < size; i++)
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
		if (i < 0) abort();
		if (i >= SIZE) abort();
		a[i] = z;
	}

	template <class T>
	T Sarray<T>::safeget(int i)
	{
		if (i < 0) abort();
		if (i >= SIZE) abort();
		return a[i];
	}

	template <>
	Sarray<float>::Sarray()    // Note 3
	{
		int i;
		for (i = 0; i < SIZE; i++)
			a[i] = i + 0.5;
	}

	template <class T>
	Sarray<T>::Sarray()   // Note 2
	{
		int i;
		for (i = 0; i < SIZE; i++)
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

	template <class T, int SIZE> 
	T & Sarray2<T, SIZE>::operator [](int n)
	{
		if ((n < 0) || (n >= SIZE))
		{
			cout << " Index " << n << "out of bounds" << endl;
			cout << " Now aborting the program " << endl;
			abort();
		}
		return (a[n]);
	}

	template <class T, int SIZE> 
	Sarray2<T, SIZE>::Sarray2()
	{
		int i;
		for (i = 0; i < SIZE; i++)
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
		for (i = 0; i < size; i++)
			cout << a[i] << endl;
		cout << "end of list" << endl;
	}

	template <class T>
	int LIST2<T>::check(T item)
	{
		int answer = -1;
		int i;
		for (i = 0; i < size; i++)
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
		for (i = 0; i < size; i++)
			cout << a[i] << endl;
		cout << "end of list" << endl;
	}

	template <class T>
	int LIST3<T>::check(T item)
	{
		int answer = -1;
		int i;
		for (i = 0; i < size; i++)
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
		for (j = 0; j < size - 1; j++)
			for (i = 0; i < size - 1; i++)
			{
				if (a[i] > a[i + 1])
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

	template <class T>
	T smallestInArray(T a[max]);

	void FindSmallestInArray() {
		cout << "create int array!" << endl;
		int a[max];
		for (int i = 1; i < max + 1; i++) {
			a[i - 1] = i * i;
		}
		cout << smallestInArray(a) << endl;

		cout << "create float array!" << endl;
		float b[max];
		for (int i = 1; i < max + 1; i++) {
			b[i - 1] = (float)10 / i;
		}
		cout << setprecision(6) << smallestInArray(b) << endl;
	}

	template <class T>
	T smallestInArray(T a[max])
	{
		T temp = a[0];
		for (int i = 0; i < max; i++) {
			if (a[i] < temp)
				temp = a[i];
		}
		return temp;
	}

	// 4. Can function templates be overloaded? How does the compiler select one of the overloaded function?

	// 5. What is a class template? List the merits and demerits of using a template in ‘C++’.

	// 6. Distinguish between class templates and function templates.

	// 7. Write a template function for exchanging (swapping) the values between two variables. Use this function in main() for int, double and char type variables.

	template <class T>
	void swap(T &a, T &b);

	void TestSwapping() {
		int a = 1, b = 2;
		cout << "a: " << a << " b: " << b << endl;
		swap(a, b);
		cout << "a: " << a << " b: " << b << endl;
		cout << endl;
		double i = 3.5, j = 8.5;
		cout << "i: " << i << " j: " << j << endl;
		swap(i, j);
		cout << "i: " << i << " j: " << j << endl;
		cout << endl;
		double x = 'a', y = 'b';
		cout << "x: " << (char) x << " y: " << (char)y << endl;
		swap(x, y);
		cout << "x: " << (char)x << " y: " << (char)y << endl;
	}

	template <class T>
	void swap(T &a, T &b) {
		T tmp;
		tmp = b;
		b = a;
		a = tmp;
	}

	// 8. Design a function template to perform matrix addition of two given integer matrices, two floating point matrices and double precision matrices separately.

	const int d1 = 5;
	const int d2 = 3;

	template <class T>
	void mx_add(T* a[], T* b[]);

	void TestMatrixAdd() {
		int* mxp_int1[d1];
		int* mxp_int2[d1];

		for (int i = 0; i < d1; i++) {
			mxp_int1[i] = new (int[d2]);
			mxp_int2[i] = new (int[d2]);
		}
		
		for (int i = 0; i < d1; i++) {
			for (int j = 0; j < d2; j++) {
				mxp_int1[i][j] = i + 1 + j;
				mxp_int2[i][j] = i + 15 + j;
			}
		}
		mx_add(mxp_int1, mxp_int2);
		


		float* mxp_float1[d1];
		float* mxp_float2[d1];

		for (int i = 0; i < d1; i++) {
			mxp_float1[i] = new (float [d2]);
			mxp_float2[i] = new (float [d2]);
		}

		for (int i = 0; i < d1; i++) {
			for (int j = 0; j < d2; j++) {
				mxp_float1[i][j] = 0.5*i + j;
				mxp_float2[i][j] = 0.8*i + j;
			}
		}
		mx_add(mxp_float1, mxp_float2);

		double* mxp_double1[d1];
		double* mxp_double2[d1];

		for (int i = 0; i < d1; i++) {
			mxp_double1[i] = new (double[d2]);
			mxp_double2[i] = new (double[d2]);
		}

		for (int i = 0; i < d1; i++) {
			for (int j = 0; j < d2; j++) {
				mxp_double1[i][j] = i * j;
				mxp_double2[i][j] = i * j * i;
			}
		}
		mx_add(mxp_double1, mxp_double2);
	}

	template <class T>
	void mx_add(T* a[], T* b[]) {
		T tmp[d1][d2];
		for (int i = 0; i < d1; i++) {
			for (int j = 0; j < d2; j++) {
				tmp[i][j] = a[i][j] + b[i][j];
			}
		}

		for (int i = 0; i < d1; i++) {
			for (int j = 0; j < d2; j++) {
				cout << tmp[i][j] << " ";
			}
			cout << endl;
		}
	}

	// 9. Develop a program to create and display a linked list for integers and real numbers using template based class LinkedList.

	template <class T>
	class Node
	{
	public:
		Node(T);
		Node<T>* prev = NULL;
		Node<T>* next = NULL;
		void setValue(T);
		T getValue();
	private:
		T value;
	};

	template <class T>
	Node<T>::Node(T new_value)
	{
		value = new_value;
	}

	template <class T>
	void Node<T>::setValue(T new_value) {
		value = new_Value;
	}

	template <class T>
	T Node<T>::getValue() {
		return value;
	}

	template <class T>
	class LinkedList
	{
	public:
		LinkedList();
		void AddNewElement(T);
		Node<T>* RemoveElement();
		void Show();
	private:
		T value;
		Node<T>* head = NULL;
		Node<T>* tail = NULL;
	};

	template <class T>
	LinkedList<T>::LinkedList()
	{

	}

	void TestLinketList() {
		LinkedList <int> int_list;
		int_list.AddNewElement(5);
		int_list.AddNewElement(10);
		int_list.AddNewElement(15);
		int_list.AddNewElement(20);
		int_list.AddNewElement(25);
		cout << "removed: " << int_list.RemoveElement()->getValue() << endl;
		int_list.Show();
		cout << endl;

		LinkedList <float> float_list;
		float_list.AddNewElement(1.1);
		float_list.AddNewElement(2.2);
		float_list.AddNewElement(3.3);
		float_list.AddNewElement(4.4);
		float_list.AddNewElement(5.5);
		cout << "removed: " << float_list.RemoveElement()->getValue() << endl;
		float_list.Show();

	}

	template <class T>
	void LinkedList<T>::AddNewElement(T new_value) {
		Node<T>* tmp = new Node<T>(new_value);
		if (head == NULL && tail == NULL) { // list is empty
			head = tmp;
			tail = tmp;
		}
		else if (head != NULL && tail != NULL) {
			head->next = tmp;
			tmp->prev = head;
			head = tmp;
		}
	}

	template <class T>
	Node<T>* LinkedList<T>::RemoveElement() {
		Node<T>* rm = tail;
		rm->next->prev = NULL;
		tail = rm->next;
		rm->next = NULL;
		return rm;
	}

	template <class T>
	void LinkedList<T>::Show() {
		if (head == NULL && tail == NULL) {
			cout << "the list is empty" << endl;
		}
		else if (head == tail) {
			cout << head->getValue() << endl;
		}
		else if (head != tail) {
			Node<T>* tmp = tail;
			cout << tmp->getValue() << endl;
			while (tmp->next != NULL)
			{
				cout << tmp->next->getValue() << endl;
				tmp = tmp->next;
			}
		}
	}

	// 10. What is a class template? Write a template-based complete program for adding two objects of the vector class. Use dynamic data members instead of arrays for storing vector elements. 

	template <class T>
	class BaseVector
	{
	public:
		BaseVector();
		~BaseVector();

	private:

	};

	template <class T>
	BaseVector<T>::BaseVector()
	{
	}

	template <class T>
	BaseVector<T>::~BaseVector()
	{
	}

	template <class T>
	class Drived1: public BaseVector<T>
	{
	public:
		Drived1();
		~Drived1();

	private:

	};

	template <class T>
	Drived1<T>::Drived1()
	{
	}

	template <class T>
	Drived1<T>::~Drived1()
	{
	}

	template <class T>
	class Drived2 : public BaseVector<T>
	{
	public:
		Drived2();
		~Drived2();

	private:

	};

	template <class T>
	Drived2<T>::Drived2()
	{
	}

	template <class T>
	Drived2<T>::~Drived2()
	{
	}

	void TestObjAddition() {
		BaseVector<int>* bv[10];

		bv[0] = new BaseVector<int>();
		bv[1] = new Drived1<int>();
		bv[2] = new Drived2<int>();
	}

	// 11. Design a template class for binary search tree. It should have methods search and insert.

	template <class T>
	class BTNode
	{
	public:
		BTNode(T);
		~BTNode();
		BTNode<T>* left = NULL; 
		BTNode<T>* right = NULL;
		T key;
	};

	template <class T>
	BTNode<T>::BTNode(T key)
	{
		this->key = key;
	}

	template <class T>
	BTNode<T>::~BTNode()
	{
	}

	template <class T>
	void insert(BTNode<T>* node, T key) {

		if (key < node->key){
			if (node->left == NULL) {
				node->left = new (BTNode<T>)(key);
			}
			else {
				insert(node->left, key);
			}
		}
		else if (key > node->key) {
			if (node->right == NULL) {
				node->right = new (BTNode<T>)(key);
			}
			else {
				insert(node->right, key);
			}
		}
		else {
			cout << "the given value is already exist!" << endl;
		}
	}

	template <class T>
	bool search(BTNode<T>* node, T key) {
		if (key == node->key) {
			return true;
		}
		else {
			if (key < node->key) {
				if (node->left != NULL)
					search(node->left, key);
				else
					return false;
			}
			else if (key > node->key) {
				if (node->right != NULL)
					search(node->right, key);
				else
					return false;
			}
		}
	}

	template <class T>
	void show(BTNode<T>* node) {
		cout << node->key << endl;
		if (node->left != NULL)
			show(node->left);
		if (node->right != NULL)
			show(node->right);
	}

	void TestBinaryBtree() {
		BTNode<int>* root;
		root = new (BTNode<int>)(50);
		insert(root, 30);
		insert(root, 20);
		insert(root, 40);
		insert(root, 70);
		insert(root, 60);
		insert(root, 80);

		cout << search(root, 60) << endl;
		cout << search(root, 40) << endl;
		cout << search(root, 55) << endl;

		show(root);

		BTNode<double>* root_2;
		root_2 = new (BTNode<double>)(0.5);
		insert(root_2, 0.3);
		insert(root_2, 0.2);
		insert(root_2, 0.4);
		insert(root_2, 0.7);
		insert(root_2, 0.6);
		insert(root_2, 0.8);

		cout << search(root_2, 0.6) << endl;
		cout << search(root_2, 0.4) << endl;
		cout << search(root_2, 0.55) << endl;

		show(root_2);

	}

	// 12. Design a template class for circular queue.

	const int QueueLength = 5;

	template <class T>
	class CircularQueue
	{
	public:
		T queue[QueueLength];
		void AddNewElement(T);
		T RemoveElement();
		bool isFull();
		bool isEmpty();
		void Show();
	private:
		T value;
		int front = -1;
		int rear = -1;
	};

	void TestCicularQueue() {
		CircularQueue<int> cqueue;
		cqueue.RemoveElement();
		cqueue.AddNewElement(1);
		cqueue.AddNewElement(2);
		cqueue.AddNewElement(3);
		cqueue.AddNewElement(4);
		cqueue.AddNewElement(5);
		cqueue.AddNewElement(6);
		cout << "removed: " << cqueue.RemoveElement() << endl;
		cout << "removed: " << cqueue.RemoveElement() << endl;
		cqueue.AddNewElement(6);
		cqueue.AddNewElement(7);
		cqueue.AddNewElement(8);
		cout << "removed: " << cqueue.RemoveElement() << endl;
		cout << "removed: " << cqueue.RemoveElement() << endl;
		cout << "removed: " << cqueue.RemoveElement() << endl;
		cout << "removed: " << cqueue.RemoveElement() << endl;
		cqueue.AddNewElement(9);
		cqueue.AddNewElement(10);
		cout << "removed: " << cqueue.RemoveElement() << endl;
		cout << "removed: " << cqueue.RemoveElement() << endl;
		cout << "removed: " << cqueue.RemoveElement() << endl;
		cout << "removed: " << cqueue.RemoveElement() << endl;
		cqueue.Show();
		/*root.RemoveElement();
		root.RemoveElement();
		root.AddNewElement(6);
		root.AddNewElement(7);*/
	}

	template <class T>
	void CircularQueue<T>::AddNewElement(T new_element) {
		if (isFull())
			cout << "the queue is full" << endl;
		else {
			if (isEmpty()) {
				front = 0;
				rear = 0;
				queue[rear] = new_element;
			}
			else {
				if (rear < QueueLength - 1) {
					queue[rear + 1] = new_element;
					rear++;
				}
				else if (rear == (QueueLength - 1) && front > 0) {
					queue[0] = new_element;
					rear = 0;
				}
			}
		}
	}
		
	template <class T>
	T CircularQueue<T>::RemoveElement() {
		if (isEmpty()) {
			cout << "the queue is empty!" << endl;
			return 0;
		}
		else {
			if (front < QueueLength - 1) {
				front++;
				return queue[front-1];
			}
			else if (front == QueueLength - 1) {
				front = 0;
				return queue[QueueLength - 1];
			}
		}
		return queue[0];
	}

	template <class T>
	void CircularQueue<T>::Show() {
		if (isEmpty())
			cout << "the queue is empty!" << endl;
		else {
			if (rear >= front) {
				for (int i = front; i <= rear; i++)
					cout << i+1 << ": " << queue[i] << endl;
			}
			else {
				for(int i = front; i < QueueLength; i++)
					cout << i+1 << ": " << queue[i] << endl;
				for(int i = 0; i <= rear; i++)
					cout << i+1 << ": " << queue[i] << endl;
			}
		}
		
	}

	template <class T>
	bool CircularQueue<T>::isFull() {
		if (isEmpty())
			return false;
		if ( (front == 0 && (rear + 1) % QueueLength == 0) || front - 1 == rear)
			return true;
		return false;
	}

	template <class T>
	bool CircularQueue<T>::isEmpty() {
		if (front == -1 && rear == -1)
			return true;
		return false;
	}

}