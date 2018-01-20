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

const int max = 10;
void sort(int b[], int max);

void Bubble1() {
	int i;
	int a[max] = { 26,11,67,89,34,92,43,9,88,54 };
	cout << "<-- - bubble1.cpp--->" << endl;
	cout << "Before sorting" << endl;
	for (i = 0; i<max; i++)
		cout << setw(6) << a[i];
	cout << endl;
	sort(a, max); //array passed as reference
	cout << "After sorting" << endl;
	for (i = 0; i<max; i++)
		cout << setw(6) << a[i];
	cout << endl;
}

void sort(int b[], int max){
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
	QuadraticEquation();
}

// 6. 