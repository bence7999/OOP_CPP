#include "ChapterThree.h"

using namespace std;

void pass_fail(int mark);

void FunctionPrototypeCall() {
	pass_fail(5);
}

void pass_fail(int mark)
{
	if (mark >= 40)
		cout << "pass" << endl;
	else
		cout << "fail" << endl;
}

int gcd(int m, int n) // Greatest common divisor 
{
	cout << m << " " << n << endl; //for debugging
	if (n == 0) return m;
	else if (n > m) gcd(n, m);
	else gcd(n, m%n);
}

void InputParameters() {
	int k, m, n;
	cout << "<-- - gcd1.cpp--->" << endl;
	cout << "give a numbers m and n :";
	cin >> m >> n;
	// n must b2 2 or more
	if ((m <= 0) || (n <= 0))
		cout << "wrong data" << endl;
	else
	{
		k = gcd(m, n);
		cout << " GCD is : " << k;
	}
}

void swap(int &a, int & b);

void Swapping() {
	int i = 10, j = 20;
	cout << "initial values" << endl;
	cout << " i = " << i << " j = " << j << endl;
	swap(i, j);
	cout << "after swapping" << endl;
	cout << " i = " << i << " j = " << j << endl;
}

void swap(int &a, int & b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int max_marks = 60;
float f1(int marks)
{
	float per;
	per = 100.0 * marks / max_marks;
	return (per);
}

void GlobalLocal() {
	int i;
	float percent;
	cout << "<-- - global1.cpp--->" << endl;
	cout << "Give marks : ";
	cin >> i;
	percent = f1(i);
	cout << "percentage is " << percent << endl;
}

int add(int i, int j)
{
	int temp;
	temp = i + j;
	return temp;
};

float add(float x, float y)
{
	float tmp;
	tmp = x + y;
	return tmp;
};

void FUnctionOverloading() {
	int k, m = 3, n = 4; float z, a = 3.5, b = 5.5;
	cout << "<-- - fover1.cpp--->" << endl;
	k = add(m, n);
	cout << " after adding k is " << k << endl;
	z = add(a, b);
	cout << " after adding z is " << z << endl;
}

long fib(int n)
{
	if ((n == 0) || (n == 1)) return 1;
	else return fib(n - 1) + fib(n - 2);
}

void Fibb2() {
	int n;
	long value;
	cout << "<-- - fibb2.cpp--->" << endl;
	cout << "give n : ";
	cin >> n;
	value = fib(n);
	cout << "value is " << value << endl;
}

const int maxx = 10;
void sortb(int b[], int max);

void Bubble1() {
	int i;
	int a[maxx] = { 26,11,67,89,34,92,43,9,88,54 };
	cout << "<-- - bubble1.cpp--->" << endl;
	cout << "Before sorting" << endl;
	for (i = 0; i<maxx; i++)
		cout << setw(6) << a[i];
	cout << endl;
	sortb(a, maxx); //array passed as reference
	cout << "After sorting" << endl;
	for (i = 0; i<maxx; i++)
		cout << setw(6) << a[i];
	cout << endl;
}

void sortb(int b[], int max){
	int i, j;
	int temp;

	for (i = 0; i < max - 1; i++) {
		for (j = 0; j<max - 1; j++)
		{
			if (b[j] > b[j + 1])
			{
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
		}
	}
		
}

struct point
{
	int x;
	int y;
};

float distance(point a, point b)
{
	float d;
	d = (a.x - b.x)* (a.x - b.x)
		+ (b.y - a.y)* (b.y - a.y);
	d = sqrt(d);
	return(d);
}

void Struct3() {
	point *p1, *p2;
	float dist;
	cout << "<-- - struct3.cpp--->" << endl;
	p1 = new point;
	p2 = new point;
	// structure is initialized here
	(*p1).x = (*p1).y = 2;
	p2->x = 5;
	p2->y = 6;
	dist = distance(*p1, *p2);
	cout << "distance between two points\n " << dist << endl;
}

void Aunion1() {
	union
	{
		int num1;
		long num2;
	};
	cout << "<-- - aunion1.cpp--->" << endl;
	num2 = 256 * 256l + 5; // Note 1
	cout << num2 << endl;
	cout << num1 << endl; ;
}

void Cla1(int argc, char *argv[]) {
	cout << "<-- - cla1.cpp--->" << endl;
	cout << "1.No of arguments " << argc << endl;
	cout << "2.The path " << argv[0] << endl;
	cout << "3.The first argument " << argv[1] << endl;
	cout << "4.The second argument " << argv[2] << endl;
}

void Binary1() {
	char box[10];
	int sum, i;
	cout << "<-- - binary1.out--->" << endl;
	cout << "Give 4 bit binary string : ";
	cin >> box;
	sum = 0;
	for (i = 0; i<4; i++)
	{
		sum = sum * 2;
		if (box[i] == '1') sum = sum + 1;
	}
	cout << "equivalent decimal number is " << sum << endl;
}

///////////////////////////
////       TASKS       ////
/////////////////////////// 

// 1. Discuss the salient features of C++ in comparison to C.

// 2. Discuss two different methods of passing parameters to a function.

// 3. Discuss the strengths and weakness of technique of recursion. Is task of finding nth Fibonacci number a good candidate for recursion?

// 4. Write a program to find 100th Fibonacci number.

void fibonacci(int n)
{
	double i = 0, j = 1, k, t;
	if (n == 0)
		return;
		for(k = 1; k <= n; ++k)
		{
			t = i + j;
			i = j;
			j = t;
		}
	cout << j << endl;
}

void FobonacciNumbers() {


	cout << "100th bibonacci number: ";
	fibonacci(99);
}

// 5. Write a function to finds roots of quadratic equation.

void FindRootsOfQE() {
	// ax^2+bx+c = 0 -> a != 0
	// D = b^2-4ac
	// x = (-b +- sqrt(D))/2a

	cout << "Give me 3 numbers a, b and c: ";
	float a, b, c;

	cin >> a >> b >> c;

	float D = b*b - 4 * a*c;

	if (D > 0) {
		int x1, x2;
		x1 = ((-b + sqrt(D)) / 2 * a);
		x2 = ((-b - sqrt(D)) / 2 * a);
		cout << "x1: " << x1 << endl << "x2: " << x2 << endl;
	}
	else if (D == 0) {
		int x1;
		x1 = ((-b + sqrt(D)) / 2 * a);
		cout << "x1 == x2: " << x1;
	}
	else if (D < 0) {
		float real, imag;
		real = -b / (2 * a);
		imag = sqrt(-D) / (2 * a);
		cout << "x1: " << real << " + " << imag << "i" << endl;
		cout << "x2: " << real << " - " << imag << "i" << endl;
	}
}

// 6. Find the size of largest array handled by your compiler if the data type of elements is
// (i)char

void MaxSizeOfCharArr() {
	// char arr[1033990]; // OK
	// char arr[1033991]; // NOK
}

// (ii) int

void MaxSizeOfIntArr() {
	// int arr[258341]; // OK
	// int arr[258342]; // NOK

}

// (iii) double

void MaxSizeOfDoubleArr() {
	// double arr[129140]; // OK
	// double arr[129141]; // NOK
}

//  struct { char name[20];
//           double percentage;
//      	}

struct node
{
	char name[20];
	double percentage;
};

void MaxSizeOfStructArr() {
	// node arr[32279]; // OK
	// node arr[32280]; // NOK
}

// 7. Write a function pause(), which waits for pressing any key at every tenth invocation. [Hint: use a counter of type static.]

void Pause() {
	map<char, int> counter;
	map<char, int>::iterator it;
	char tmp;

	while (true)
	{
		tmp = cin.get();
		it = counter.find(tmp);
		if (it != counter.end()) {
			it->second++;
			if (it->second == 10)
				break;
		}
		else
			counter.insert(it, pair<char, int>(tmp, 0));
	}
}

// 8. Study any one random number generation algorithm and develop a function to return a pseudo-random number between 0 and N.

void RandomGenerator(int n) {
	// linear congruential generator
	srand(std::time(nullptr));
	int a = rand() % 100;
	cout << "a: " << a << endl;
	int c = rand() % 200;
	cout << "c: " << c << endl;
	int m = n;
	int x0 = rand() % 500;
	cout << "x0: " << x0 << endl;


	int j = rand() % 1000 + rand() % 1000 + rand() % 1000;
	for (int i = 0; i < j; i++)
	{
		x0 = (a * x0 + c) % m;
	}

	cout << "rand: " << x0 << endl;
}

// 9. Write a function to find the largest number from a given integer array.

void LargestInteger(int arr[], int size) {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max)
			max = arr[i];
	}

	cout << "max elemenet is: " << max << endl;
}

// 10. Write a program to find the determinant of N x N matrix.

void SwitchLine(float(&mx)[4][4], int from, int to) {
	int tmp[4];
	
	for (int i = 0; i < 4; i++) {
		tmp[i] = mx[to][i];
		mx[to][i] = mx[from][i];
		mx[from][i] = tmp[i];
	}
}

void DeterminantOfMatrix() {
	
	// int matrix[4][4] = { { 1, 3, 5, 9 },{ 4, 3, 9, 7 },{ 5, 2, 0, 9 },{ 7, 2, 7, 1 } };
	float matrix[4][4] = { {5, 2, 0, 9}, {1, 3, 1, 7}, {4, 3, 9, 7}, {1, 3, 5, 9 }};

	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}*/

	/*if (matrix[0][0] != 1) {
		for (int i = 1; i < 4; i++) {
			if (matrix[i][0] == 1) {
				SwitchLine(matrix, i, 0);
				break;
			}
		}
	}*/

	int dim = sizeof(matrix[0]) / sizeof(float);

	for (int top = 0; top < dim-1; top++) {
		for (int num = top; num < dim-1; num++) {
			float elim = -1 * matrix[num+1][top] / matrix[top][top];
			for (int i = 0; i < dim; i++) {
				matrix[num+1][i] += elim * matrix[top][i];
			}
		}
	}

	/*float top = matrix[0][0];

	float elim1 = -1 * matrix[1][0] / top;
	float elim2 = -1 * matrix[2][0] / top;
	float elim3 = -1 * matrix[3][0] / top;

	for (int i = 0; i < 4; i++) {
		matrix[1][i] += elim1 * matrix[0][i];
		matrix[2][i] += elim2 * matrix[0][i];
		matrix[3][i] += elim3 * matrix[0][i];
	}

	top = matrix[1][1];

	elim2 = -1 * matrix[2][1] / top;
	elim3 = -1 * matrix[3][1] / top;

	for (int i = 1; i < 4; i++) {
		matrix[2][i] += elim2 * matrix[1][i];
		matrix[3][i] += elim3 * matrix[1][i];
	}

	top = matrix[2][2];

	elim3 = -1 * matrix[3][2] / top;

	for (int i = 1; i < 4; i++) {
		matrix[3][i] += elim3 * matrix[2][i];
	}*/

	float determinant = matrix[0][0] * matrix[1][1] * matrix[2][2] * matrix[3][3];

	cout << "determinant: " << determinant << endl;
}

// 11. Write a program to find transpose of a matrix.

void TransposeOFMatrix() {
	int matrix[2][8] = { {1, 2, 3, 4, 5, 6, 7, 8}, {11, 12, 13, 14, 15, 16, 17, 18} };

	int rows = sizeof matrix / sizeof matrix[0];  
	int cols = sizeof matrix[0] / sizeof(int); 

	int** ary = new int*[cols];
	for (int i = 0; i < cols; ++i)
		ary[i] = new int[rows];

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++) {
			ary[j][i] = matrix[i][j];
		}
	}

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << ary[i][j] << " ";
		}
		cout << endl;
	}

}

// 12. Write a function ‘sort’ which accepts an array of integers ‘A’ and number of elements ‘n’. The function sorts the array in ascending order.

void Sort(int A[], int n) {
	
	int tmp;
	for (int j = 0; j < n - 1; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (A[i] > A[i + 1]) {
				tmp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = tmp;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}

}

// 13. Write a program to test whether a given string is a palindrome. 
//     A palindrome is a character string which reads the same both forward and backward. (Malayalam, madam are palindrome, hello is not).

void Palindrome(string str) {
	int length = str.length();
	bool pal = true;
	for (int i = 0; i < length; i++) {
		if (str[i] != str[length - i - 1]) {
			pal = false;
		}
	}

	if (pal) {
		cout << "The given strig is paliondrome";
	}
	else {
		cout << "The given strig is not paliondrome";
	}
}

// 14. Write a program to count number of words in a given string.

void WordCounter(string str) {

	int count = 0;
	char space = ' ';

	for (string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it == space)
			count++;
	}

	cout << count << endl;
}

// 15. Write a program to check the input characters for uppercase, lowercase, number of digits and other characters in a given string.

void CheckInputString() {

	string str;

	getline(cin, str);

	for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
		if (islower(*it)) {
			cout << *it << " is lowercase alphabet!" << endl;
		}
		else if (isupper(*it)) {
			cout << *it << " is uppercase aplhabet!" << endl;
		}
		else if (isdigit(*it)) {
			cout << *it << " is digit!" << endl;
		}
		else if (isspace(*it)) {
			cout << *it << " is space!" << endl;
		}
		else if (iswspace(*it)) {
			cout << *it << " is shitespace!" << endl;
		}
		else {
			cout << *it << " is unknown character!" << endl;
		}
			
	}

}

// 16. Create a structure point which stores x and y coordinates of a point as two float values. 
//	   Write a program to accept three points from the user and decide whether they are collinear or not.

struct  Point{
	int x, y;
};

float distance(Point a, Point b)
{
	float d;
	d = (a.x - b.x)* (a.x - b.x)
		+ (b.y - a.y)* (b.y - a.y);
	d = sqrt(d);
	return(d);
}


void InCollinear() {
	Point a, b, c;
	
	cout << "Give me 6 number: " << endl;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

	if (distance(a, b) + distance(b, c) > distance(c, a)) {
		cout << "The three given point, there is no collinear!" << endl;
	}
	else {
		cout << "The given three point there are collinear!" << endl;
	}

}

// 17. Define a structure ‘Complex’ which stores a complex numbers using two float values. 
//     Create separate functions to perform basic arithmetic operations add, subtract, multiply, divide (+, -, *, /) on two complex numbers.

struct Complex{
	float real, im;
};

Complex Conjugate(Complex a) {
	Complex c;
	c.real = a.real;
	c.im = -1 * a.im;
	return c;
}

Complex add(Complex a, Complex b) {
	Complex c;
	c.real = a.real + b.real;
	c.im = a.im + b.im;

	return c;
}

Complex subtract(Complex a, Complex b) {
	Complex c;
	c.real = a.real - b.real;
	c.im = a.im - b.im;
	return c;
}

Complex multiply(Complex a, Complex b) {
	Complex c;
	c.real = a.real * b.real - a.im * b.im;
	c.im = a.real * b.im + a.im * b.real;
	return c;
}

Complex divide(Complex a, Complex b) {
	Complex con = Conjugate(b);
	Complex numerator = multiply(a, con);
	Complex denominator = multiply(b, con);
	Complex c;
	c.real = numerator.real / denominator.real;
	c.im = numerator.im / denominator.real;

	return c;
}

void ComplexAritmethicOperations() {
	Complex a, b;
	string str;

	cout << "Give me 4 integer for 2 complex number" << endl;
	//cin >> a.real >> a.im >> b.real >> b.im;
	a.real = 1; a.im = 2;
	b.real = 3; b.im = 4;

	cout << "Write the sepected operation: a+b, a-b, a*b or a/b" << endl;
	cin >> str;

	Complex res;
	for (string::iterator it = str.begin(); it != str.end(); ++it) {
		char ch = *it;
		if (ch == '+')
			res = add(a, b);
		else if (ch == '-')
			res = subtract(a, b);
		else if (ch == '*')
			res = multiply(a, b);
		else if (ch == '/')
			res = divide(a, b);
	}
	cout << "Result is: " << res.real << " + " << res.im << "i!" << endl;
}

// 18. Write a program that prompts a user to input the current month, date and year. 
//     Store the data entered in a suitably defined structure and display the date in three different styles say 09/09/2009, 09-Sept-09 or Sept 9, 09.

struct Date{
	string month, date, year;
	map<string, string> mon = { {"01", "Jan"},{ "02", "Feb" },{ "03", "Mar" },{ "04", "Apr" },{ "05", "May" },{ "06", "June" },{ "07", "July" },{ "08", "Aug" },{ "09", "Sept" },{ "10", "Oct" },{ "11", "Nov" },{ "12", "Dec" } };
};

void Type1(Date& d) { // 09/09/2009
	cout << d.month << "/" << d.date << "/" << d.year << endl;
}

void Type2(Date& d) { // 09-Sept-09
	cout << d.date << "-" << d.mon[d.month] << "-" << d.year.substr(2,4) << endl;
}

void Type3(Date& d) { // Sept 9, 09
	cout << d.mon[d.month] << " " << d.date << ", " << d.year.substr(2, 4) << endl;
}

void PrintDate() {
	Date d1;
	cout << "Give me a current date in form witn (01 18 2000):" << endl;
	cin >> d1.month >> d1.date >> d1.year;
	Type1(d1);
	Type2(d1);
	Type3(d1);
}

// 19. Create a structure ‘Student’ which stores name, roll no., marks of three tests (each out of 100) and grand total. 
//     Write a program to accept all the information for n records of the students, calculate their grand total and arrange them in the descending order of their grand total.

struct Student
{
	string name;
	float roll_no, grand_total;
	int tests[3];
};

template < typename RA_SEQUENCE > void sort(RA_SEQUENCE& seq)
{
	std::cout << "unordered: ";
	for (const auto& v : seq) std::cout << v << ' ';
	std::cout << '\n';

	std::sort(std::begin(seq), std::end(seq));

	std::cout << "   sorted: ";
	for (const auto& v : seq) std::cout << v << ' ';
	std::cout << "\n\n";
}	

void StudentCalculator() {
	Student st;
	cout << "give me a name of the student" << endl;
	cin >> st.name;
	cout << "give me the roll number of the student" << endl;
	cin >> st.roll_no;
	cout << "give me the marks of the 3 test" << endl;
	cin >> st.tests[0] >> st.tests[1] >> st.tests[2];
	st.grand_total = (st.tests[0] + st.tests[1] + st.tests[2]) / 3;
	cout << "the ground total is: " << st.grand_total << endl;
	sort(st.tests);
}

// 20. Create a structure ‘employee’ which stores employee name, employee number and employee salary. 

struct Employee{
	string name;
	int number, salary;
};

//     Create a function ‘increment’ which accepts one record of employee and increments its salary in the following way:
//     1. If the salary is less than 5000, then increment by 25%.
//     2. If the salary is greater than 5000 but less than 10000, then increment by 20%.
//     3. Otherwise increment by 10%.

void Increment(Employee& e) {
	if (e.salary < 5000) {
		e.salary += e.salary * 0.25;
	}
	else if (e.salary >= 5000 && e.salary < 10000) {
		e.salary += e.salary * 0.2;
	}
	else if (e.salary >= 10000){
		e.salary += e.salary * 0.1;
	}
	else {
		cout << "Error!" << endl;
	}
}

void EmployeeSalary() {
	Employee e;
	cout << "give me name of the employee: ";
	cin >> e.name;

	cout << "give me number of employee: "; 
	cin >> e.number;

	cout << "give me salary of employee: ";
	cin >> e.salary;

	cout << "increment salary!" << endl;
	Increment(e);
	cout << "new salary of employee: " << e.salary << endl;
}

// 21. Write a program to accept n records of employee from the user and increment their salary using ‘increment’ function. 
//     The program should finally display the complete list of employees.

void Employees() {
	const int count = 10;
	Employee ems[count];

	for (int i = 0; i < count; i++) {
		cout << "give me name of the " << i+1 <<  ". employee: ";
		cin >> ems[i].name;

		cout << "give me number of the " << i + 1 << ". employee: ";
		cin >> ems[i].number;

		cout << "give me salary of the " << i + 1 << ". employee: ";
		cin >> ems[i].salary;
		
		Increment(ems[i]);
	}

	for (int i = 0; i < count; i++) {
		cout << "Name: " << ems[i].name << ", number: " << ems[i].number << ", salary: " << ems[i].salary << endl;
	}

}

// 22. Create a structure ‘node’ which stores an integer (data) and a pointer of the same node type (next). 
//     Write a program to implement a linked list using the following functions:

struct Node
{
	int data = 0;
	Node* next = 0;
};

Node* head = new Node();

//    insert(): to add a new node at the end of the linked list.
void insert(int data) {
	Node* last = head;
	while (true)
	{
		if (head != NULL) {
			if (last->next == NULL) {
				last->next = new Node();
				last->next->data = data;
				break;
			}
			else
				last = last->next;
		}
		else {
			head = new Node();
			head->data = data;
			break;
		}
	}
}

//    del(): to delete the node form the beginning.
void del() {
	Node* tmp;
	if (head != NULL) {
		if (head->next != NULL) {
			tmp = head->next;
			cout << "delete: " << head->data << endl;
			delete head;
			head = tmp;
		}
		else
			head = NULL;
	}
	else
		cout << "the queue is empty!" << endl;
}

//	  display(): to display all the nodes of the linked list.
void display() {
	Node* tmp = head;
	while (true)
	{	
		cout << "data: " << tmp->data << endl;
		if (tmp->next == NULL)
			break;
		else
			tmp = tmp->next;
	}
}

void LinkedList() {
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	display();
	del();
	del();
	del();
	del();
	display();
	insert(7);
	del();
	insert(8);
	del();
	display();
	del();
	del();
	del();
	del();
	insert(1);
	display();
}

// 23. What do you think about what will be displayed by the following section of code?

union {
	char ch;
	float atype;
} cut;

void Question() {
	cut.ch = 'y';
	printf("%f", cut.atype);
}

// 24. Design a type enum for a computer accessory store which sells items like keyboard, mouse, pen drive, etc.

enum Accessory {
	keyborad, mouse, pen_drive, speaker, monitor 
};

// 25. Write a program which runs from command prompt. Command line parameter is the name of the user (say “Raja”). 
//     The program should print string “Good morning Raja”.

void CmpProgramme(int argc, char *argv[]) {
	cout << "Good morning " << argv[1] << endl;
}
