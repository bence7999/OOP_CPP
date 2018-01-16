#include "ChapterTwo.h"

using namespace std;

enum Planets { Sun, Moon, Mars, Mercury, Jupiter, Venus, Saturn };

void Enum1() {
	Planets p1, p2;
	cout << "<---enum1.cpp--->" << endl;
	p1 = Sun; 
	p2 = Moon;
	//p2 = 3 ; // warning!
	p2 = Planets(4); // type casting safe
	cout << (int)p1 << endl;
	cout << "p2 is " << (int)p2 << endl;
	p2 = (Planets)3;
	cout << "p2 is " << (int)p2 << endl;
}

enum { Red, Green, Blue };

void Enum2() {
	int var1;
	cout << "<---enum2.cpp--->" << endl;
	var1 = Green;
	cout << var1 << endl;
	cout << (int)Blue << endl;
}

void Refer5() {
	int fork = 10;
	int & cutlery = fork; // Note 1
	cout << "<---refer5.cpp--->" << endl;
	cout << "fork = " << fork << endl;
	cout << "cutlery = " << cutlery << endl;
	cutlery++; // Note 2
	cout << "cutlery = " << cutlery << endl;
	cout << "fork = " << fork << endl;
}

void Pvoid1() {
	void *p;
	int i = 58;
	cout << "<---pvoid1.cpp--->" << endl;
	p = &i;
	cout << "address of i is : " << &i << endl;
	cout << "p points to address : " << p << endl;
	cout << " integer i is : " << i << endl;
	cout << "value pointed by p is : " << *(int *)p << endl;
}

void Ter1() {
	int pre1 = 6500, pre2 = 5500;
	int prem, age;
	cout << "<---ter1.cpp--->" << endl;
	cout << "give age : "; cin >> age;
	prem = (age >= 45) ? pre1 : pre2;
	cout << "premium = " << prem << endl;
}

void Block2() {
	int marks = 65;
	cout << "<---block2.cpp--->" << endl;
	cout << "marks=" << marks << endl;
	// note the block below
	{   
		int k = 30;
		cout << "k = " << k << endl;
		int j = 30; // note2
	}
	// cout << "k = " << k << endl; // Undefined symbol 'k'
	cout << "marks=" << marks << endl;
}

void Input1() {
	double value_of_pi = 3.1415926536;
	cout << "<---input1.cpp--->" << endl;
	cout << setfill('#');
	cout << setw(15) << setprecision(8) << value_of_pi << endl; // setw(15) - összeen 15 hosszúnak kell lennie, a többi #
	cout << setw(12) << setprecision(4) << value_of_pi << endl;
}

// Discount 10% male only if senior citizen age > 60
// Discount 20% for female
void Ifthen3A() {
	int sex = 1; // {0 female 1 male}
	int age = 25;//
	int discount = 0;
	cout << "<---ifthen3A.cpp--->" << endl;
	if (sex == 1)
		if (age > 60)
			discount = 10;
		else discount = 20;
	cout << "discount " << discount << endl;
	_getch();
}

void Switch1() {
	int i = 3, j = 7, k = 0;
	char ch;
	cout << "<---switch1.cpp--->" << endl;
	// specifying input
	//ch = cin.get();
	ch = _getch();
	switch (ch)
	{
	case '+': k = i + j; break;
	case '-': k = i - j; break;
	case '*': k = i*j; break;
	case '/': k = i / j; break;
	};
	cout << "k= " << k << endl;
}

void Fact2() {
	long factorial, n, product;
	int number = 10;
	if (number == 1)
		factorial = 1;
	else
	{
		cout << "<---fact2.cpp--->" << endl;
		product = 1;
		for (n = 2; n <= number; n++)
		{
			product = product*n;
			cout << n << "\t" << product << endl;
		}
		factorial = product;
	}
	cout << "The final answer is " << factorial;
}

void Sinx() {
	int i;
	float sum = 0, term = 1;
	float x, y;
	cout << "---sinx.cpp--->" << endl;
	cout << "Give X between 0 to 90 degrees : ";
	cin >> y;
	x = y * 3.14159 / 180.0; // x in radian
	sum = term = x; i = 1;
	while (i<15)
	{
		i = i + 2;
		term = -1 * term * x * x / i / (i - 1);
		sum = sum + term;
	}
	cout << "The value of sine " << y << " Degrees" << endl;
	cout << "By the series method : " << sum << endl;
	cout << "By using library function sin : " << sin(x) << endl;
}

void Accuracy() {
	cout << "<---accuracy.cpp--->" << endl;
	long n;
	float i, j;
	i = .000001;
	j = 0.0;
	for (n = 0; n<1000000L; n++)
		j = j + i; cout.precision(10);
	cout.width(20);
	cout.setf(ios::showpoint);
	cout << "0.000001 * 1000000 is : " << j << endl;
}

void Prime1() {
	int i, n;
	int flag = 1; // assume prime
	cout << "<-- - prime1.cpp--->" << endl;
	cout << "give a number to test : ";
	cin >> n; // n must be 2 or more
	for (i = 2; i <n; i++)
	{
		if ((n%i) == 0)
		{
			flag = 0; // sets not prime
			break;
		}
	}
	if (flag == 1) cout << "n is prime" << endl;
	else cout << "n is not prime";
}


