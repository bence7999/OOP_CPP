#include "ChapterNineteen.h"

using namespace std;

namespace ChapterNineteen {
	
	/// 19.1.1 Declaring and constructing a string
	/// 19.1 Constructors for class string
	// Write a program to study various constructors for class string.

	void String71() {
		cout << "<-- - string71.cpp--->" << endl;
		char * name = "Long Live C++"; // C-string
		string str1; // an empty string
		cout << "1)" << str1 << endl;
		string str2("bhave");
		cout << "2)" << str2 << endl;
		string str3 = "patekar";
		cout << "3)" << str3 << endl;
	}

	/// 19.1.4 Copying one string into another
	/// 19.2 Copying by assignment
	// Write a program to study copying operations on strings.

	void String72() {
		cout << "<-- - string72.cpp--->" << endl;
		string str1 = "Raja";
		string str2 = "Rani";
		cout << "1)" << str1 << endl;
		cout << "2)" << str2 << endl;
		str2 = str1;
		str1 = "Raja Saheb";
		cout << "3)" << str1 << endl;
		cout << "4)" << str2 << endl;
	}

	/// 19.1.5 Comparing strings
	/// 19.3 Comparing strings
	// Write a program to study comparison operations on strings.

	void String75() {
		cout << "<-- - string75.cpp--->" << endl;
		string str1("A");
		string str2("B");
		string str3("a");
		if (str1 == str2)
			cout << "1) (str1 == str2) is true" << endl;
		else cout << "1) (str1 == str2) is false" << endl;
		if (str1 < str2)
			cout << "2) (str1 < str2) is true" << endl;
		else cout << "2qq) (str1 < str2) is false" << endl;
		if (str1 < str3)
			cout << "3) (str1 < str3) is true" << endl;
		else cout << "3) (str1 < str3) is false" << endl;
		cout << "4) (str1 < str3) is " << (str1 < str3) << endl;
	}

	/// 19.1.6 Inspecting a character
	/// 19.4 Looking inside a string
	// Write a program to illustrate various ways to inspect a character within a given string.

	void String76() {
		cout << "<-- - string76.cpp--->" << endl;
		string str1("My name is Anthony Gonsalves");
		cout << "1--->" << str1[0] << endl;
		cout << "2--->" << str1.at(1) << endl;
		//cout << "3--->" << str1[41] << endl;
		//cout << "4--->" << str1.at(41) << endl;
		//  above statement generates exception
	}

	/// 19.1.7 Searching and inserting
	/// 19.5 Searching and inserting with strings
	// Write a program to illustrate methods find() and insert() from class string.

	void String77() {
		cout << "<-- - string77.cpp--->" << endl;
		string str1("star wars");
		cout << "1)" << str1 << endl;
		cout << "2)" << str1.find("war") << endl;
		str1.insert(9, " trilogy");
		cout << "3)" << str1 << endl;
	}

	/// 19.1.8 Concatenation of strings
	/// 19.6 Concatenation of strings
	// Write a program to illustrate concatenation of strings.

	void String74() {
		cout << "<-- - string74.cpp--->" << endl;
		string str1("Long live ");
		string str2(" C++");
		cout << "1)" << str1 + str2 << endl;
		string str3 = str1 + str2;
		cout << "2)" << str3 << endl;
		str1 += str2;
		cout << "3)" << str1 << endl;
	}

	/// 19.2 TYPE Bool
	/// 19.7 Type bool
	// Write a small program to demonstrate data type bool.

	void Bool1() {
		int age = 40;
		bool flag;
		cout << "<-- - bool1.cpp--->" << endl;
		flag = true;
		if (flag) cout << "true" << endl;
		else cout << "false" << endl;
		flag = age >60;
		if (flag) cout << "true" << endl;
		else cout << "false" << endl;
		cout << "flag is " << flag << endl;
	}

	/// 19.4.1 List
	/// 19.8 List used as queue
	// Write a program to simulate queue using container "list" supplied by STL.

	void List1() {
		const int SIZE = 10;
		int box[SIZE] = { 7, 5, 0, 3, 6, 0, 1 ,2,0, 4 };
		int k, j;
		cout << "<-- - list1.cpp--->" << endl;
		cout << "the data" << endl;
		for (k = 0; k<SIZE; k++)
			cout << " " << box[k];
		cout << endl;
		list< int > myList;
		list<int>::const_iterator itFront = myList.begin();
		for (j = 0; j<SIZE; j++)
		{
			if (box[j] != 0) // ender
			{
				cout << "entering queue " << box[j] << endl;
				myList.push_back(box[j]);
			}
			else
			{
				cout << " leaving queue " << myList.front() << endl;
				myList.pop_front();
			}
		}
		cout << "Queue at the end " << endl;
		for (list<int>::const_iterator iter = myList.begin();
			iter != myList.end(); ++iter)
			cout << *iter << " ";
		cout << endl;
	}

	/// 19.4.2 Vector
	/// 19.9 Vector
	// Write a program to demonstrate working of a vector.

	void Vector1() {
		const int SIZE = 6;
		int box[SIZE] = { 1, 2, 3, 4, 5, 6 };
		int i, num;
		std::vector< int > integers(SIZE);
		cout << "<-- - vector1.cpp--->" << endl;
		for (i = 0; i<SIZE; i++)
			integers[i] = box[i];
		//   displaying elements
		cout << "displaying Vector elements" << endl;
		for (i = 0; i<SIZE; i++)
			cout << i << " " << integers[i] << endl;
		// adding element at the end
		integers.push_back(272);
		// inserting element in the middle
		integers.at(3) = 172;
		// size of vector
		num = integers.size();
		// Now printing
		cout << "displaying Vector elements" << endl;
		for (i = 0; i<num; i++)
			cout << i << " " << integers[i] << endl;
	}

	/// 19.6.1 Function objects
	/// 19.10 Function objects in use 
	// Write a program to demonstrate use of function object.

	const int sixx = 6;

	template<class T>
	class lessThan
	{
	public:
		lessThan() {};
		int operator () (T a, T b)
		{
			return a<b;
		};
	};

	template <class T>
	void sort1(T A[], int N, lessThan<T> ls)
	{
		int i, j;
		T temp;
		for (i = 0; i<N - 1; i++) //outer
			for (j = 0; j<N - 1; j++)
			{
				if (ls(A[j], A[j + 1]))
				{
					temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
	};

	void Funcobj1() {
		int k;
		/* lessThan<int> ls ; // for debugging
		cout << ls( 12,3) <<endl;
		*/
		cout << "<-- - funcobj1.cpp--->" << endl;
		int box[] = { 3, 5, 1, 7, 2, 9 };
		sort1(box, sixx, lessThan<int>());
		for (k = 0; k < sixx; k++)
			cout << " " << box[k];
		cout << endl;
	}

	/// 19.9 RUN TIME TYPE INFORMATION RTTI
	/// 19.9.1 "typeid" operator
	// Write a program to demonstrate runtime type information (RTTI)

	class Joker
	{
	protected:
		char name[20];
	public:
		Joker(char *p);//{strcpy(name, p)}
		virtual void show(); // note 1
	};

	class Hero : public Joker
	{
	public:
		Hero(char * p2);
		void show();
	};

	class SuperStar : public Joker
	{
	public:
		SuperStar(char * p2);
		void show();
	};

	void Typeid2() {
		int num = 7;
		float *sum;
		Joker *bptr1, *bptr2, *bptr3;
		bptr1 = new Joker("Mr Joker");
		bptr2 = new Hero("Raj Kapoor");
		bptr3 = new SuperStar("Raj Kapoor");
		cout << "<-- - typeid2.cpp--->" << endl;
		cout << typeid(num).name() << endl;
		cout << typeid(sum).name() << endl;
		cout << typeid(*bptr1).name() << endl;
		cout << typeid(*bptr2).name() << endl;
		cout << typeid(*bptr3).name() << endl;
	}

	Joker::Joker(char *p)
	{
		strcpy_s(name, p);
	}

	void Joker::show()
	{
		cout << " Joker = " << endl;
	}

	Hero::Hero(char * p2) :Joker(p2)
	{   // no code required here
	}

	void Hero::show()
	{
		cout << " Hero = " << name << endl;
	}

	SuperStar::SuperStar(char * p2) :Joker(p2)
	{   // no code required here 
	}

	void SuperStar::show()
	{
		cout << " SuperStar = " << name << endl;
	};

	///////////////////////////
	////       TASKS       ////
	/////////////////////////// 

	// 1. Write a program to read a small text file and create a files “words.txt” which contains all the words from the given file. Use type string.

	void FileReadWriteByString() {
		ifstream f1("input.txt");
		if (!f1)
		{
			cout << "Cannot open input.txt for input" << endl;
			cout << " quitting the program";
			exit(1);
		}
		ofstream f2("words.txt");
		string str;
		while (getline(f1, str))
		{
			f2 << str << endl;
		}
		f1.close();
		f2.close();

	}

	// 2. Write a program to read a file of words, and prepare a output file “sorted.text” where words are sorted alphabetically. (Place only one word on one line in the output.)

	const int max = 200;

	void ReadAndWriteAphabetic() {
		string array[max] = {""};

		ifstream f1("word_order.txt");
		if (!f1)
		{
			cout << "Cannot open input.txt for input" << endl;
			cout << " quitting the program";
			exit(1);
		}
		string word;
		int i = 0;
		while (f1 >> word)
		{
			array[i] = word;
			i++;
		}
		sort(array, array + max);
		ofstream f2("ordered_words.txt");
		for (int i = 0; i < max; i++) {
			if (array[i] != "")
				f2 << array[i] << endl;
		}
	}

	// 3. Write a program to encrypt a text file such that output contains only alphabets and numbers and punctuators (no special characters). Assume similar condition on input.

	void EncriyptFile() {

	}

	// 4. List the facilities from STL from any two different implementations of C++ (Turbo C++ 4.5, C++ builder, VC++, GNU C++ for Linux etc.)

	// 5. Assume that type bool is not available in particular Version of C++ you are using. Write a program to define a class BOOL. An object of this class should behave as if a variable of type bool.

	class WrongType : public exception
	{
	public:
		char* what()
		{
			return "Unknown Type Exception!";
		};
	};

	class BOOL
	{
	public:
		BOOL();
		BOOL(int);
		BOOL(bool);
		~BOOL();
		friend ostream& operator<<(ostream &, BOOL);
	private:
		int boolean;
	};

	BOOL::BOOL()
	{
		boolean = 0;
	}

	BOOL::BOOL(int i) {
		if (i < 1)
			boolean = 0;
		else
			boolean = 1;
	}

	BOOL::BOOL(bool b) {
		boolean = b;
	}

	BOOL::~BOOL()
	{
	}

	ostream & operator<< (ostream & temp, BOOL b)
	{
		temp << b.boolean;
		return temp;
	}

	void TestOfBOOL() {
		BOOL a = 1;
		BOOL b = true;
		cout << a << endl;
		cout << b << endl;
		cout << true << endl;
	}

	// 5. Develop application program using any two of the following STL algorithms:
	//    1. random_shuffle
	//    2. search
	//    3. merge
	//    4. find
	//    5. rotate

	// 6. Define a class Card (for a playing card) and use STL function sort to sort a deck of cards.

	enum rank_map {
		two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8, nine = 9, ten = 10, Jack = 10, Queen = 10, King = 10, Ace = 11
	};

	const string color[4] = { "Clubs", "Diamonds", "Hearts", "Spades" };
	const string rank[13] = { "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "Jack", "Queen", "King", "Ace" };

	class Card
	{
	public:
		Card(string, string);
		~Card();
		string get_color() {
			return color;
		}
		string get_rank() {
			return rank;
		}
	private:
		string color;
		string rank;
	};

	Card::Card(string c, string r)
	{
		color = c;
		rank = r;
	}

	Card::~Card()
	{
	}

	class Deck
	{
	public:
		Deck();
		~Deck();
		Card* deck[52];
		void sort();
		void exchange(int, int);
	private:

	};

	Deck::Deck()
	{
		int num = 0;
		for (int c = 0; c < 4; c++) {
			for (int r = 0; r < 13; r++){
				deck[num] = new Card(color[c], rank[r]);
				num++;
			}
		}
	}

	Deck::~Deck()
	{
	}

	void Deck::sort() {
		srand(time(NULL));
		for (int i = 0; i < 500; i++) {
			int num1 = rand() % rand();
			int num2 = rand() % rand();
			num1 = num1 % 52;
			num2 = num2 % 52;
			this->exchange(num1, num2);
		}
		cout << endl;
	}

	void Deck::exchange(int num1, int num2) {
		Card *tmp = this->deck[num1];
		this->deck[num1] = this->deck[num2];
		this->deck[num2] = tmp;
	}

	void CardGame() {
		Deck deck;
		deck.sort();
		for (int i = 0; i < 52; i++) {
			cout << deck.deck[i]->get_color() << " : " << deck.deck[i]->get_rank() << endl;
		}
		
	}

	// 8. Develop a program to covert an infix expression into postfix expression using vector stack from STL.

	void InFixToPostFix() {
		stack<char> stack;
		vector<char> output;

		map<char, int> rank;
		rank['*'] = 3;
		rank['/'] = 3;
		rank['+'] = 2;
		rank['-'] = 2;
		rank['('] = 1;

		string num_str = "123456790";

		string expression = "(1+2)*(3+4)";
		//cout << "give me the expression" << endl;
		//cin >> expression;

		string::iterator it;

		for (it = expression.begin(); it != expression.end(); it++) {
			if (num_str.find(*it) != string::npos) {
				output.push_back(*it);
			}
			else if (*it == '(') {
				stack.push(*it);
			}
			else if (*it == ')') {
				char tmp = stack.top();
				stack.pop();
				while (tmp != '(')
				{
					output.push_back(tmp);
					tmp = stack.top();
					stack.pop();
				}
			}
			else {
				while (!stack.empty() && rank[stack.top()] >= rank[*it])
				{
					char tmp = stack.top();
					output.push_back(tmp);
					stack.pop();
				}
				stack.push(*it);
			}
		}
		while (!stack.empty())
		{
			char tmp = stack.top();
			stack.pop();
			output.push_back(tmp);
		}
		for (vector<char>::iterator it = output.begin(); it != output.end(); ++it) {
			cout << *it;
		}
		cout << endl;
	}

}