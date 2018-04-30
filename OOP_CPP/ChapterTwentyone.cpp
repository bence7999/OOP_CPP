#include "ChapterTwentyone.h"
#include "Matrix4.h"
#include "Linked.h"
#include "LinkedT.h"
#include "astro.h"
#include "attrib.h"
//#include "keys.h"
//#include "bitgraph.h"
//#include "cursor1.h"

using namespace std;

namespace ChapterTwentyone {

	/// 21.1.1 Diagonal matrix
	// Write a program to test if a matrix is diagonal or not.
	
	// matrix4.h

	void Matrix3() {
		cout << "<-- - matrix3.cpp--->" << endl;
		Mat10 myMat(3); //constructor
		int i, j, k;
		myMat.show();
		// testing if diagonal
		if (myMat.is_diagonal())
			cout << "The matrix is Diagonal" << endl;
		else cout << "The matrix is Not Diagonal" << endl;
	}

	/// 21.1.2 Symmetrical matrix
	// Write a program to test whether a matrix is symmetrical or not.

	int DataBox[] = { 1,12,13,12,4,23,13,23,9 };

	class Mat4 : public Mat10
	{
	public:
		int isSymmetrical();
	};

	void Matrix4() {
		Mat4 myMat; //constructor
		int i, j, k;
		cout << "<-- - matrix4.cpp--->" << endl;
		myMat.init(DataBox, 3);
		// Printing the matrix
		myMat.show();
		// testing if symmetrical
		if (myMat.isSymmetrical())
			cout << "Matrix is Symmetrical" << endl;
		else cout << "Matrix is Not symmetrical" << endl;
	}

	int Mat4::isSymmetrical()
	{
		int i, j;
		int answer = 1;// true;
		for (i = 0; i<N; i++)
			for (j = 0; j<N; j++)
				if (get(i, j) != get(j, i)) answer = 0; //false
		return answer;
	}

	/// 21.1.3 Template based class Matrix
	// Write a program to multiply two matrices.

	const int THREE = 3;

	template<class T, int N>
	class Matrix
	{
	protected:
		T X[N][N];
	public:
		void multiply(Matrix A, Matrix B, Matrix &C);
		void show();
		Matrix();
		Matrix(T box[9]);
		void set(int i, int j, T val);
		T get(int i, int j);
	};

	int dataA[] = { 1,0,0, 0,1,0, 0,0,1 };
	int dataB[] = { 1,2,3, 14,15,16, 27,28,29 };
	float dataX[] = { 1,0,0, 0,1,0, 0,0,1 };
	float dataY[] = { 1.1,2,3, 14,15,16, 27.1,28,29 };

	void Matrix7() {
		int i, j, k, sum;
		Matrix <int, 3 > A(dataA);
		Matrix <int, THREE> B(dataB);
		Matrix <int, THREE> C;
		cout << "<-- - matrix7.cpp--->" << endl;
		cout << "matrix of integers" << endl;
		// Multiplying Matrices
		A.multiply(A, B, C);
		// printing matrix C
		C.show();
		// *** Now defining matrix of floats ***
		Matrix <float, 3 > X(dataX);
		Matrix <float, THREE> Y(dataY);
		Matrix <float, THREE> Z;
		cout << "matrix of floats" << endl;
		// Multiplying Matrices
		X.multiply(X, Y, Z);
		// printing matrix C
		Z.show();
	}

	template<class T, int N> 
	void Matrix<T, N>::multiply(Matrix<T, N> A, Matrix <T, N>B, Matrix <T, N>&C)
	{
		int i, j, k;
		T sum;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
			{
				sum = 0;
				for (k = 0; k<N; k++)
				{
					sum = sum + A.get(i, k) * B.get(k, j);
				}
				C.set(i, j, sum);
			}
	}

	template<class T, int N>
	void Matrix<T, N>::show()
	{
		int i, j;
		cout << "Matrix is " << endl;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				cout << setw(10) << X[i][j];
			}
			cout << endl;
		}
	}

	template<class T, int N>
	Matrix<T, N>::Matrix()
	{
	}

	template<class T, int N>
	Matrix<T, N>::Matrix(T box[9])
	{
		int i, j;
		for (j = 0; j<N; j++)
			for (i = 0; i<N; i++)
				X[i][j] = box[j*N + i];
	}

	template<class T, int N>
	void Matrix<T, N>::set(int i, int j, T val)
	{
		X[i][j] = val;
	}

	template<class T, int N>
	T Matrix<T, N>::get(int i, int j)
	{
		return X[i][j];
	}


	/// 21.2 STATISTICS
	/// 21.2.1 Standard deviation and variance
	// Write a program to find average, variance, and standard deviation of a given sample data.

	const int MAX = 10;

	int A[MAX] = { 14, 29, 1, 15, 16, 27, 28, 2, 19,3 };

	void Stat1() {

		int i;// , j, k
		float sum, avg, vari, sd;
		cout << "<-- - stat1.cpp--->" << endl;

		// Finding average
		sum = 0;
		for (i = 0; i < MAX; i++)
		{
			sum = sum + A[i];
		}
		avg = sum / MAX;
		cout << "average is " << avg << endl;

		// finding variance
		sum = 0;
		for (i = 0; i < MAX; i++)
		{
			sum = sum + (A[i] - avg) * (A[i] - avg);
		}
		vari = sum / MAX;
		cout << "variance = " << vari << endl;

		// finding standard deviation
		sd = sqrt(vari);
		cout << "standard deviation = " << sd << endl;

	}

	/// 21.2.2 Curve fitting (straight line)
	// Write a program to find the best possible straight line passing through given points.

	const int MAXP = 6;

	class Point
	{
	public:
		int x, y;
		void define_point(int x0, int y0);
	};

	void Stline1() {

		cout << "<-- - stline1.cpp--->" << endl;
		Point A[MAXP]; //Array of objects
					   // x y co-ordinates of the points through which straight line is
					   // to be drawn
		int X_data[MAXP] = { 85,108,169,24,212,176 };
		int Y_data[MAXP] = { 39,54,81,12,104,83 };
		int i; // , j, k
		double M, C, temp, sum1, sum2, sum3, sum4;

		// Objects initialized with x,y co-ordinates
		for (i = 0; i <= MAXP; i++)
		{
			A[i].define_point(X_data[i], Y_data[i]);
		}

		// Finding M and C
		sum1 = 0.0; sum2 = 0.0; sum3 = 0.0; sum4 = 0.0;
		for (i = 0; i < MAXP; i++)
		{
			sum1 = sum1 + A[i].x * double(A[i].y);
			sum2 = sum2 + A[i].x;
			sum3 = sum3 + A[i].y;
			sum4 = sum4 + A[i].x * double(A[i].x);
		}

		M = (MAXP * sum1 - sum2 * sum3) / (MAXP *sum4 - sum2 * sum2);
		C = (sum3 - M * sum2) / MAXP;
		cout << "M is " << M << endl;
		cout << "C is " << C << endl;
	}

	void Point::define_point(int x0, int y0)
	{
		x = x0; y = y0;
	}


	/// 21.3 ACCOUNT AND FINANCE
	/// 21.3.1 Bank account
	//  Define a class to represent bank account.Include the following members :
	//  Data members:
	//  1. Name of depositor.
	//  2. Account number.
	//  3. Type and account.
	//  4. Balance amount in the account.
	//  Member functions:
	//  1. To assign initial values.
	//  2. To deposit an amount.
	//  3. To withdraw an amount after checking the balance.
	//  4. To display name and balance.

	class BankAccount
	{
	protected:
		char name[20];
		int accNumber;
		int bal;
	public:
		BankAccount(char *p, int i, int j);
		void deposit(int sum);
		int withdraw(int sum);
		void display();
	};

	void Bank3() {
		
		cout << "<-- - bank3.cpp--->" << endl;
		BankAccount one = BankAccount("bhave", 1, 100);
		one.display();
		one.deposit(1000);
		if (one.withdraw(1500) == 0)
			cout << "transaction fails" << endl;
		one.display();
	}

	BankAccount::BankAccount(char* p, int i, int j)
	{
		strcpy_s(name, p);
		accNumber = i;
		bal = j;
	}

	void BankAccount::display()
	{
		cout << "name : " << name;//<< endl ;
		cout << " number : " << accNumber << endl;
		cout << "balance : " << bal << endl;
	}

	void BankAccount::deposit(int sum)
	{
		bal = bal + sum;
	}

	int BankAccount::withdraw(int sum)
	{
		int answer = 0; //false
		if (bal > sum)
		{
			bal = bal - sum;
			answer = 1;
		}
		return answer;
	}

	/// 21.3.2 Housing loan
	// Write a program to calculate the instalment for a housing loan.

	void Hdfc1() {

		int i, n, N;
		float r, R, Rate;
		float instal, loan, temp;
		cout << "<-- - hdfc1.cpp starts--->" << endl;
		cout << "Give amount of loan : ";
		cin >> loan;
		cout << "Give period in years ";
		cin >> N;
		n = N * 12;
		cout << "Give percentile rate of interest ";
		cin >> Rate;
		r = Rate / 100.0 / 12.0; //12.0 for monthly
		temp = pow((1 + r), n);
		instal = r * loan* temp / (temp - 1);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "The monthly repayment is" << endl;
		cout << instal;

	}

	/// 21.8 Loan repayment details
	// Write a program to show interest and principle portion of an instalment of a housing loan. Also, show the actual balance at the end of every instalment.

	void Hdfc2() {

		int i, N;
		float r, Rate, loan, temp;
		float instal, interest, balance, princ;
		cout << "<-- - hdfc2.cpp--->" << endl;
		cout << "Give amount of loan : ";
		cin >> loan;
		cout << "Give period in years : ";
		cin >> N;
		cout << "Give percentile rate of interest : ";
		cin >> Rate;
		r = Rate / 100.0; // divide by 12.0 for monthly
		temp = pow((1 + r), N);
		instal = r * loan* temp / (temp - 1);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout.setf(ios::showpoint);
		cout << "The yearly repayment is" << endl;
		cout << instal << endl;
		balance = loan;
		cout << "month instalment interest principle\
			balance" << endl;
		for (i = 1; i <= N; i++)
		{
			interest = balance * r;
			balance = balance + interest;
			princ = instal - interest;
			balance = balance - instal;
			cout << setw(4) << i << setw(13) << instal
				<< setw(14) << interest << setw(14) << princ
				<< setw(14) << balance << endl;
		}

	}

	/// 21.3.3 Converting currency
	// Write a program to convert the amount in Singapore dollars into Rupees and Paise.

	class Currency
	{
	protected:
		long full, fraction;
		Currency(long f1, long f2);
	};
	
	class SingDoller;

	class IndCur :public Currency
	{
	public:
		void print();
		IndCur(long a1, long a2);
		IndCur operator*(float rate);
		friend class SingDoller;
	};

	class SingDoller :public Currency
	{
	public:
		void print();
		SingDoller(long a1, long a2);
		operator IndCur();
	};

	void Curren1() {
		cout << "<-- - curren1.cpp--->" << endl;
		IndCur amt1(0, 0);
		// amt1.print();
		SingDoller s1(100, 0);
		amt1 = IndCur(s1);
		amt1.print();
	}

	void IndCur::print()
	{
		cout << "Amount is Rs ";
		cout << full << " = ";
		cout.fill('0'); cout.width(2);
		cout << fraction << " / -" << endl;
	}

	IndCur::IndCur(long a1, long a2) :Currency(a1, a2)
	{
		if ((a1<0) || (a2<0) || (a2>99))
		{
			cout << "wrong initialisation";
			exit(1);
		};
	}

	IndCur IndCur::operator*(float rate)
	{
		IndCur temp(0, 0);
		long dummy;
		dummy = full * 100 + fraction;
		temp.full = rate * 100;
		temp.fraction = dummy / 100;
		return temp;
	}

	SingDoller::SingDoller(long a1, long a2) :Currency(a1, a2)
	{
		if ((a1<0) || (a2<0) || (a2>99))
		{
			cout << "wrong initialisation";
			exit(1);
		};
	}

	Currency::Currency(long f1, long f2)
	{
		full = f1;
		fraction = f2;
	};

	SingDoller:: operator IndCur()
	{
		IndCur temp(0, 0);
		temp.full = full;
		temp.fraction = fraction;
		temp = temp * (28.1);
		return temp;
	};

	/// 21.3.4 Savings bank account: Use of ATM
	// Write a program for a bank which offers ATM services to the customers.

	class IndCur2
	{
	protected:
		long rupee, paise;
	public:
		void print();
		IndCur2(long a = 0, long b = 0);
		IndCur2 operator*(float rate);
		IndCur2 operator+(IndCur2 X);
		IndCur2 operator-(IndCur2 X);
	};

	class SavingsBankAccount
	{
	protected:
		IndCur2 balance;
		int accno;
	public:
		SavingsBankAccount();
		void dep();
		void draw();
		void show();
	};

	void Bank1() {

		cout << "<-- - bank1.cpp--->" << endl;
		cout << "Welcome to MAHA bank " << endl;
		SavingsBankAccount myaccount;
		int i, n, flag = 1;
		char ch;
		while (flag == 1)
		{
			cout << "type 1 for deposit 2 for withdrawl "
				<< "3 knowling balance 4 Quit--: ";
			ch = _getche();
			cout << endl;
			switch (ch)
			{
			case '1': myaccount.dep(); break;
			case '2': myaccount.draw(); break;
			case '3': myaccount.show(); break;
			case '4': flag = 0; break;
			default: cout << "sorry wrong choice of alternative" << endl;
			}
		}
	}

	void IndCur2::print()
	{
		cout << "Amount Rs ";
		cout << rupee << " = "; cout.fill('0'); cout.width(2);
		cout << paise << " / -" << endl;
	}

	IndCur2::IndCur2(long a, long b)
	{
		if ((a < 0) || (b< 0) || (b > 99))
		{
			cout << "initialisation error" << endl;
			cout << "a = " << a << " b = " << b << endl;
			exit(1);
		}
		else
		{
			rupee = a;
			paise = b;
		}

	}

	IndCur2 IndCur2::operator*(float rate)
	{
		IndCur2 temp(0, 0);
		long dummy;
		dummy = rupee * 100 + paise;
		dummy = (long)floor(double(dummy) * rate + 0.5);
		temp.rupee = dummy / 100;
		temp.paise = dummy;
		return temp;
	}

	IndCur2 IndCur2::operator+(IndCur2 X)
	{
		IndCur2 temp(0, 0);
		long dummy;
		dummy = (rupee + X.rupee) * 100 + paise + X.paise;
		// dummy = floor( double(dummy) * rate + 0.5 );
		temp.rupee = dummy / 100;
		temp.paise = dummy;
		return temp;
	}

	IndCur2 IndCur2::operator - (IndCur2 Y)
	{
		IndCur2 temp(0, 0);
		long dummy;
		dummy = (rupee - Y.rupee) * 100 + paise - Y.paise;
		if (dummy < 0)
		{
			cout << "can not sutract" << endl;
			exit(1);
		}
		temp.rupee = dummy / 100;
		temp.paise = dummy;
		return temp;
	}

	SavingsBankAccount::SavingsBankAccount()
	{
		cout << "your account number is 1" << endl;
		accno = 1;
	}

	void SavingsBankAccount::dep()
	{
		long r, p;
		cout << "specify ammount in rupees and paise" << endl;
		cin >> r >> p;
		IndCur2 temp(r, p);
		balance = balance + temp;
		temp.print();
		cout << "is added to your account " << endl;
	}

	void SavingsBankAccount::draw()
	{
		long r, p;
		cout << "specify ammount in rupees and paise" << endl;
		cin >> r >> p;
		IndCur2 temp(r, p);
		balance = balance - temp;
		cout << "after withdrawl your balance ";
		balance.print();
	}

	void SavingsBankAccount::show()
	{
		cout << "your present balnce " << endl;
		balance.print();
	}

	/// 21.4 DYNAMIC DATA STRUCTURES
	/// 21.4.2 Creating a linked list
	// Write a program to create a linked list.

	const int FIVE = 5;

	class Node
	{
	public:
		int key;
		Node * next;
		Node(int n); //for key
	};

	class LinkList
	{
	protected:
		Node * root;
		Node *tail;
	public:
		LinkList();
		void addNode(int M);
		void addNode2(int M);
		void show();
		void show2();
	};

	void Linked1() {

		cout << "<-- - linked1.cpp--->" << endl; int i;
		int A[FIVE] = { 2, 4, 6, 8, 10 };
		//creating a linked list
		LinkList list1;
		for (i = 0; i < FIVE; i++)
			list1.addNode(A[i]);
		// Displaying linked list
		list1.show();
	}

	LinkList::LinkList()
	{
		root = NULL;
	}

	void LinkList::show()
	{
		Node * temp;
		if (root == NULL)
			cout << "Linked List is empty" << endl;
		else
		{
			temp = root;
			while (temp != NULL)
			{
				cout << setw(5) << temp->key;
				temp = temp->next;
				//temp points where temp->next points
			}
		}
	}

	Node::Node(int n) //for key
	{
		key = n;
		next = NULL;
	}

	void LinkList::addNode(int M)
	{
		Node *temp = new Node(M);
		temp->next = root; //temp->next points where root points
		root = temp;
	}

	/// 21.4.3 Creating a linked list where data is in same order as that of its arrival
	/// Create a linked list such that data is in the same order as that which appears in the input (array).

	void Linked2() {

		cout << "<-- - linked2.cpp--->" << endl;
		int i;
		int A[FIVE] = { 2, 4, 6, 8, 10 };
		//creating a linked list
		LinkList list1;
		for (i = 0; i < FIVE; i++)
			list1.addNode(A[i]);
		// Displaying linked list
		list1.show();
	}

	void LinkList::show2()
	{
		Node * temp;
		if (root == NULL)
			cout << "Linked List is empty" << endl;
		else
		{
			temp = root;
			while (temp != NULL)
			{
				cout << setw(5) << temp->key;
				temp = temp->next; //temp points where temp->next points
			}
		}
	}

	void LinkList::addNode2(int M)
	{
		Node *temp = new Node(M);
		if (tail == NULL)
		{
			tail = temp;
			root = tail;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	/// 21.4.4 Searching a linked list
	// Find whether a given integer is present in a given linked list.

	const int TEN = 10;

	class LinkList1 : public LinkList
	{
	public:
		int findNum(int N); // 1 found - 0 notfound
	};

	int LinkList1::findNum(int N)
	{
		int found = 0;
		Node * temp;
		temp = root;
		while ((temp != NULL) && !found)
		{
			cout << "trying " << setw(5) << temp->key << endl;
			if (temp->key == N) { found = 1; }
			else { temp = temp->next; };
		}
		return found;
	}

	void Linked3() {

		cout << "<-- - linked3.cpp--->" << endl;
		int i, N, flag;
		int A[TEN] = { 2, 14,76, 48, 10 ,
			33,42,98, 23, 57 };

		//creating a linked list
		LinkList1 list1;
		for (i = 0; i < TEN; i++)
			list1.addNode(A[i]);

		// searching for data
		cout << "Give the number to find : ";
		cin >> N;
		flag = list1.findNum(N);
		if (flag) cout << "found";
		else cout << "sorry N not found" << endl;
	}

	/// 21.4.5 Inserting a node in a linked list
	// Write a program to insert a node with key value 45 in a linked list. Insert it after a node having key value 42.

	class LinkList2 : public LinkList
	{
	protected:
		Node * ptr;
	public:
		LinkList2();
		int findNum(int N); // 1 found - 0 notfound
		void insert_after(int M);
	};

	void Linked4() {

		cout << "<-- - linked4.cpp--->" << endl;
		int i, N, M;
		int notfound = 1;
		// Node *temp;
		const int TEN = 10;
		int A[TEN] = { 2, 12, 22, 32, 42 , 52, 62, 72, 82, 92 };
		// creating a linked list
		LinkList2 list2;
		for (i = 0; i < TEN; i++)
			list2.addNode(A[i]);
		// list2.show(); // for debugging
		N = 42;
		cout << "finding " << N << endl;
		if (list2.findNum(N))
		{
			cout << "found" << endl;
		} // internal pointer set
		else
		{
			cout << "sorry N not found" << endl;
			cout << "can not proceed further" << endl;
			exit(1);
		}
	}

	LinkList2::LinkList2()
	{
		ptr = NULL;
	};
	
	int LinkList2::findNum(int N)
	{
		int found = 0;
		Node * temp;
		temp = root;
		ptr = NULL; // internal pointer initialised
		while ((temp != NULL) && !found)
		{ // for debugging
		  //cout<< "trying " << setw(5)<<temp->key <<endl;
			if (temp->key == N)
			{
				found = 1; // return value set
				ptr = temp; // internal pointer
			}
			else { temp = temp->next; }
		}
		return found;
	}

	void LinkList2::insert_after(int M) // pointer internal
	{// pointer ptr points to anode within the linked list
		Node * temp;
		if (ptr == NULL)
		{
			cout << "error error error" << endl;
		}
		else
		{
			temp = new Node(M);
			temp->next = ptr->next;
			ptr->next = temp;
			if (tail->next != NULL)
			{
				cout << "tail moved" << endl;
				tail = temp;
			}
		}
	};

	/// 21.4.6 Simulation of stack
	// Write a program to demonstrate working of a stack using linked list.

	template <class T>
	class Stack : public LinkedT::LinkList <T>
	{
	public:
		void pop(T & item);
		void push(T item);
	};

	template <class T>
	void Stack<T>::pop(T &item) //global root
	{
		if (root == NULL)
		{
			cout << endl << "Error "; exit(1);
		}
		else
		{
			item = root->key;
			root = root->next;
		}
	}

	template <class T>
	void Stack<T>::push(T item) //global root
	{
		LinkedT::Node<T> *temp = new LinkedT::Node<T>(item);
		temp->next = root;
		root = temp;
	}

	void Stack3() {

		cout << "<-- - stack3.cpp--->" << endl;
		int i, dataindex, item;
		char itemChar;
		int Data[TEN] = { 12, 14, 76, 48, 10, 33, 42, 98, 23, 57 };
		int Operation[TEN] = { 1, 1, 1, 0, 1, 0, 0, 1, 0, 1 };
		char Data_char[TEN] = { 'B', 'H', 'A', 'V', 'E', 'M', 'A', 'H', 'E', 'H' };
		int Operation_char[TEN] = { 1, 1, 1, 0, 1, 0, 0, 1, 0, 1 };

		//creating a linked list
		Stack<int> stack1;
		cout << "Stack of Integers " << endl;

		// performing ten oprations
		dataindex = 0;
		for (i = 0; i < TEN; i++)
		{
			if (Operation[i] == 1)
			{
				stack1.push(Data[dataindex]);
				cout << "pushed " << Data[dataindex] << " stack->";
				dataindex++;
				stack1.show();
			}
			else
			{
				stack1.pop(item);
				cout << "popped " << item << " stack->";
				stack1.show();
			}
			cout << endl;
		}

		// now with type char

		//creating a linked list
		Stack<char> stack2;
		cout << "Stack of Characters " << endl;

		// performing ten oprations
		dataindex = 0;
		for (i = 0; i < TEN; i++)
		{
			if (Operation_char[i] == 1)
			{
				stack2.push(Data_char[dataindex]);
				cout << "pushed " << Data_char[dataindex]
					<< " stack->";
				dataindex++;
				stack2.show();
			}
			else
			{
				stack2.pop(itemChar);
				cout << "popped " << itemChar << " stack->";
				stack2.show();
			}
			cout << endl;
		}
	}

	/// 21.4.7 Binary search tree
	// Write a program to sort a data file using binary search tree.

	typedef char str40[50];

	class TreeNode
	{
	public:
		str40 key;
		TreeNode *left, *right;
		TreeNode(str40 st) // constructor
		{
			strcpy_s(key, st);
			left = NULL;
			right = NULL;
		}
	};

	class BinarySearchTree
	{
	protected:
		TreeNode * rootMain;
		void visitAllx(TreeNode *root, ofstream &f2);
		void build(TreeNode *root, str40 st);
	public:
		void buildTree(str40 st);
		void visitTree(ofstream &f2);
		BinarySearchTree();
	};

	BinarySearchTree::BinarySearchTree()
	{
		rootMain = NULL;
	}

	void BinarySearchTree::buildTree(str40 st)
	{
		if (rootMain == NULL) // first Node
			rootMain = new TreeNode(st);
		else build(rootMain, st);
	}

	void BinarySearchTree::visitTree(ofstream &f2)
	{
		visitAllx(rootMain, f2);
	}

	void BinarySearchTree::build(TreeNode *root, str40 st)
	{
		if (root == NULL)
		{
			cout << " some error " << endl;
			exit(1);
		}

		if (_stricmp(root->key, st) > 0)
		{
			if (root->left == NULL) root->left = new TreeNode(st);
			else       build(root->left, st);
		}
		else
		{
			if (_stricmp(root->key, st) < 0)
			{
				if (root->right == NULL)root->right = new TreeNode(st);
				else build(root->right, st);
			}
			else { /* no action*/ };
		}
	};

	void BinarySearchTree::visitAllx(TreeNode *root, ofstream &f2)
	{
		int x;
		if (root != NULL)
		{
			visitAllx(root->left, f2);
			f2 << root->key << endl;
			visitAllx(root->right, f2);
		}
	}

	void Tree4() {
		str40 str1;

		//Node *root;
		cout << "<-- - tree4.cpp--->" << endl;

		// getch();
		ifstream f1;
		f1.open("source.txt");
		if (!f1) 
			cout << "error1" << endl;
		ofstream f2;
		f2.open("source.out");
		if (!f2) 
			cout << "error2" << endl;

		BinarySearchTree bst1;
		f1.getline(str1, 48);
		while (strlen(str1) > 0)
		{ //cout < str1<" " ; //for debugging
			bst1.buildTree(str1);
			f1.getline(str1, 48);
		}

		cout << "*** tree built **" << endl;
		bst1.visitTree(f2);
		f1.close();
		f2.close();
		cout << " program over" << endl;
		cout << " See file source.out for output" << endl;
	}

	/// 21.5 TEXT WINDOW
	/// 21.5.1 Using console I/O for three window system
	// Write a program to demonstrate a three window system. First window should read an integer in decimal format. Second and third windows should display it in octal and hexadecimal format, respectively.

	#define maxwin 3

	const int normal = 2;

	const int winmax = 3;

	int prev = 0, curr = 0;

	/*previous and current active window*/

	class Window // W capital
	{
	private:
		int bord;
		int x1, y1, x2, y2;
		int xcor, ycor;
	public:
		Window(int a, int b, int c, int d, int z);
		void draw_bor();
		friend void activate(int i);
	};

	Window *win[maxwin];

	//void new_window(int winnum, int a, int b, int c, int d, int z) ;

	void activate(int i);

	//void draw_bor(int winnum);

	/*
	void Window1() {
		
		char ch1;
		int n, m;
		win[0] = new Window(3, 3, 60, 8, 176);
		win[1] = new Window(3, 11, 32, 23, 177);
		win[2] = new Window(35, 11, 60, 23, 178);
		system("cls");
		win[0]->draw_bor();
		win[1]->draw_bor();
		win[2]->draw_bor();
		activate(0);
		cprintf("input window DEC\r\n");
		activate(1);
		cprintf("output window OCTAL\r\n");
		activate(2);
		cprintf("output window HEX\r\n");
		activate(0);
		cprintf("Give Input : ");
		cscanf("%u", &n);
		cprintf("\n\r");
		activate(1);
		cprintf(" n in octal is %o \r\n", n);
		activate(2);
		activate(2);
		cprintf("n in hex is %X \r\n", n);
		getch();
		activate(0);
		cprintf("Give input : ");
		cscanf("%u", &m);
		cprintf("\n\r");
		activate(1);
		cprintf(" m in octal is %o \r\n", m);
		activate(2);
		cprintf("m in hex is %X \r\n", m);
		activate(0);
		cprintf(" press any key to quit", m);
		getch();
		getch();
	}

	Window::Window(int a, int b, int c, int d, int z)
	{
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
		bord = z;
		xcor = 0;
		ycor = 0;
	}

	void Window::draw_bor()
	{
		int i;
		for (i = x1 - 1; i <= x2 + 1; i++)
		{
			gotoxy(i, y1 - 1); printf("%c", bord);
			gotoxy(i, y2 + 1); printf("%c", bord);
		}

		for (i = y1 - 1; i <= y2 + 1; i++)
		{
			gotoxy(x1 - 1, i); printf("%c", bord);
			gotoxy(x2 + 1, i); printf("%c", bord);
		}

	}

	void activate(int i)
	{
		int x1, y1;
		if ((i<0) || (i>normal))
		{
			printf("EROOR NO x"); abort();
		};
		prev = curr;
		win[curr]->xcor = wherex();
		win[curr]->ycor = wherey();
		curr = i;
		window(win[i]->x1, win[i]->y1,
			win[i]->x2, win[i]->y2);
		x1 = win[curr]->xcor;
		y1 = win[curr]->ycor;
		gotoxy(x1, y1);

	}
	*/


	/// 21.6 ASTROLOGY
	/// 21.6.2 Lord of ascendant
	// Write a program to read ascendant and find the planet who is lord of ascendant.

	void find_lord(int n, int &m);

	void Lord1() {
		int n, m;
		Sign *ascendant;
		Planet *loa; //lord of ascendant
		cout << "<-- - lord1.cpp--->" << endl;
		init_sign();
		init_planet();
		cout << "Specify ascendant no : ";
		cin >> n;
		if (!valid1to12(n))
		{
			cout << "error in input";
			exit(1);
		}
		n = n - 1; // numbers in C++ strt from 0!
		ascendant = &x[n];
		cout << "Your ascendant is " << ascendant->display() << endl;
		loa = &planet[lord[n]];
		cout << "lord of your ascendant is " << loa->display() << endl;
	}

	// Write a program to perform the following tasks.
	// 1. Ask for ascendant ( sign) – a number between 1 and 12 is expected
	// 2. Show the various attributes children, spouse, expenses, luck, etc and ask the user in which he/she is interested? User is expected to type it.
	// 3. Get the house number corresponding to the attribute and display it.
	// 4. Add the house number to ascendant to get the corresponding sign.
	// 5. Find from the table the lord of this sign and display.

	void Attrib1() {
		str20 temp;
		char ch;
		int i, n, MAX;
		int asc_num, found;
		Sign *asc;
		Planet *loa; //loa = lord of ascendant
		cout << "<-- - atttib1.cpp--->" << endl;
		init_sign();
		init_planet();
		MAX = init_attributes();
		// cout << "nos initialized : " << MAX << endl; //for debugging
		cout << "give ascendant 1 to 12 :";
		cin >> asc_num;
		if (!valid1to12(asc_num))
		{
			cout << "error in input";
			exit(1);
		}
		asc_num = asc_num - 1; // Arrays in C++ starts from 0 !
		asc = &x[asc_num];
		cout << "Your ascendant is " << asc->display() << endl;
		cout << "following are the recoded attributes" << endl;
		cout.setf(ios::left);
		for (i = 0; i<MAX; i++)
		{
			cout << setw(17) << attributes[i]->display();
			if ((i + 1) % 4 == 0) cout << endl;
		}
		cout << endl;
		cout << "which one are you interested ? " << endl;
		cout << "spell out : ";
		cin >> temp;
		i = 0; found = 0;
		while ((i<MAX) && (!found))
		{
			if (_stricmp(temp, attributes[i]->display()) == 0)
				found = 1;
			else i++; // important
		}
		if (!found) cout << "sorry some error" << endl;
		else
		{
			n = attributes[i]->get_num();
			cout << "you are interested in " << temp << endl;
			cout << "house number " << n
				<< " is related to this attribute" << endl;
			i = (asc_num + n - 1);
			cout << "Sign " << x[i].display() << " is placed here" << endl
				<< "It\'s lord is " << planet[lord[i]].display() << endl
				<< "The results will depend on strength and position of"
				<< endl << "this planet" << endl;
		}
	}


	/// 21.7.1 Bit map editor
	// Write a program to edit a bitmap.

	#define no_rows 16
	#define no_cols 16
	#define SIZE 18 // cube_SIZE
	//#include "BPGRAPH1.h"

	typedef char TDX[no_rows];
	const char star = ' * ';
	const char dot = '.';

	void Bitmap() {

	}


	///////////////////////////
	////       TASKS       ////
	/////////////////////////// 



}