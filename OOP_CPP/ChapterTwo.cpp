#include "ChapterTwo.h"

using namespace std;

namespace ChapterTwo {

	/// 2.2.4 Enumerated data type
	// Write a program to demonstrate enumerated data type with the example of planets.

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

	// Write a program to demonstrate anonymous enum.

	enum { Red, Green, Blue };

	void Enum2() {
		int var1;
		cout << "<---enum2.cpp--->" << endl;
		var1 = Green;
		cout << var1 << endl;
		cout << (int)Blue << endl;
	}

	/// 2.2.5 Type reference
	// Write a program to demonstrate type reference.

	void Refer5() {
		int fork = 10;
		int & cutlery = fork; // Note 1: Since cutlery in an alias variable (variable of type reference), it is essential that it is initialized at the time of declaration. Hence, the statement int & cutlery = fork; defines a variable cutlery of type reference to integer and it works as an alias of integer variable fork.
		cout << "<---refer5.cpp--->" << endl;
		cout << "fork = " << fork << endl;
		cout << "cutlery = " << cutlery << endl;
		cutlery++; // Note 2: Now we want to demonstrate that variable cutlery can stand alias to this variable. Hence, we will execute a statement cutlery++; as cutlery is nothing but (alias to) fork, value of fork is incremented.
		cout << "cutlery = " << cutlery << endl;
		cout << "fork = " << fork << endl;
	}

	/// 2.2.6 Type void
	// Write a program to demonstrate “pointer to void”.

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

	/// 2.4 OPERATORS AND EXPRESSIONS
	// Write a program to find the premium to be paid by a person to Life Insurance Corporation for policy of Rs. 100,000. Rule is that if age is >45, premium is Rs. 6,500 otherwise premium is Rs. 5,500. Use ? : operator.

	void Ter1() {
		int pre1 = 6500, pre2 = 5500;
		int prem, age;
		cout << "<---ter1.cpp--->" << endl;
		cout << "give age : "; cin >> age;
		prem = (age >= 45) ? pre1 : pre2;
		cout << "premium = " << prem << endl;
	}

	/// 2.8 C++ IS A BLOCK-STRUCTURED LANGUAGE
	// Write a program to demonstrate block structure.

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

	/// 2.10.1 Input–output with cin and cout
	// Write a program to study manipulators like setw() and endl.

	void Input1() {
		double value_of_pi = 3.1415926536;
		cout << "<---input1.cpp--->" << endl;
		cout << setfill('#');
		cout << setw(15) << setprecision(8) << value_of_pi << endl; // setw(15) - összeen 15 hosszúnak kell lennie, a többi #
		cout << setw(12) << setprecision(4) << value_of_pi << endl;
	}

	/// 2.11.1 if statement
	// A moll in the city declared 10% discounts to males if only they are senior citizens, i.e. age is greater than 60. A flat 20% discount to all females irrespective of age. Write a program to compute the discount.

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
	}

	/// 2.11.2 Switch statement
	// Write a program to demonstrate use of switch statement. Use characters (+, –, *, /) as switch expression. Depending on the character, appropriate mathematical operation should be carried out on two given integers.

	void Switch1() {
		int i = 3, j = 7, k = 0;
		char ch;
		cout << "<---switch1.cpp--->" << endl;
		// specifying input
		cout << "give me a simbol: (+-*/):" << endl;
		ch = _getch();
		switch (ch)
		{
		case '+': k = i + j; break;
		case '-': k = i - j; break;
		case '*': k = i * j; break;
		case '/': k = i / j; break;
		};
		cout << "k= " << k << endl;
	}

	/// 2.12.1 for statement
	// Write a program to find the factorial of a given integer.

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
				product = product * n;
				cout << n << "\t" << product << endl;
			}
			factorial = product;
		}
		cout << "The final answer is " << factorial;
	}

	/// 2.13.1 Sum of series
	// Write a program to calculate sin x for given x in degrees by
	// 1. Using series expansion
	// 2. Using library function sin().

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

	/// 2.13.2 Accuracy of type float is limited!
	// Write a program to demonstrate that accuracy of type float is limited.

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

	/// 2.13.3 Prime number
	// Write a program to find if a given number is a prime number.

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

	///////////////////////////
	////       TASKS       ////
	///////////////////////////

}


// 1. Explain why language supports type double and long when type int and float exists.

// 2. What are the typical uses of type reference?

// 3. Explain the two-step process of automatic type conversion during evaluation of expressions.

// 4. Describe the syntax and state the advantage of typedef facility

// 5. Write a note on selecting an appropriate control structure for a particular task.

// 6. Explain what is meant by term block. Comment on the scope of variables declared in a block.

// 7. Read five real numbers (float) and find its average.

float AverageOfFloats() {
	float sum = 0;
	float loc;
	
	for (int i = 0; i < 5; i++) {
		cin >> loc;
		sum += loc;
	}

	return sum / 5;
}

// 8. Write a program to accept a character from the user in variable ch and display its ASCII value.

void WriteASCII() {
	char ch = cin.get();

	cout << (int)ch << endl;
}

// 9. Find the diameter, circumference and area of circle with given radius.

void Circle() {
	float r;
	float pi = 3.14159265359;
	
	cin >> r;

	float d = 2 * r;
	float c = 2 * r * pi;
	float a = r * r * pi;

	cout << "diameter: " << d << " circumference: " << c << " area: " << a << endl;
}

// 10. Estimate the time needed for a stone to fall from height of 3000 m. Assume g = 9.8 m/s2.

void Estimation() {
	// h = 0,5 * g * t^2

	float g = 9.81;
	float h = 3000;

	float t = sqrt((2 * h) / g);

	cout << "Required time is: " << t << endl;

}

// 11. Find the distance between two points (20, 20) and (40, 50).

void Distance() {
	// d=sqrt((x2​−x1​)^2+(y2​−y1​)^2)

	int x1 = 20, y1 = 20, x2 = 40, y2 = 50;
	float d = sqrt(pow(x2 - x1,2)+ pow(y2 - y1, 2));

	cout << "Distance is: " << d << endl;
}

// 12. If a straight line passes through points (1, 4) and (12, 56) decide if given point (x1, y1) lies on this straight line or not.

void LiesOnLine() {
	// m = (y2 - y1) / (x2 - x1)
	// e => y - y0 = m * (x - x0)

	int x1 = 1, y1 = 4, x2 = 12, y2 = 56;

	float m = (y2 - y1) / (x2 - x1);

	int x, y;

	cout << "Give x and y: " << endl;
	cin >> x >> y;

	if ((y - y1) == m*(x - x1))
		cout << "The given point lies on the line!";
	else
		cout << "The gien point does not lie on the line!";
}

// 13. Find if a given point lies inside a given circle or not.

void InsideCircle() {
	int r = 5;
	int x = 2, y = 3;
	int x0, y0;

	cout << "Give x and y: " << endl;
	cin >> x0 >> y0;

	float d = sqrt(pow(x - x0, 2) + pow(y - y0, 2));

	if (d < r)
		cout << "The given point is inside the circe!";
	else
		cout << "The given point in not inside the circle!";
}

// 14. Write a program to accept an integer “num” from user. Check whether the given integer is even or odd and display appropriate message

void EvenOrOdd() {
	int i;
	
	cout << "Give an integer: " << endl;
	cin >> i;

	if (i % 2 == 0)
		cout << i << " is even!";
	else
		cout << i << " is odd!";
}

// 15. Find the amount returned after 10 years if Rs. 5,000 are deposited for 10 years. Assume interest rate of 12%. Interest is compounded quarterly.

void CalculateInterest() {
	float amount = 5000;
	float time = 10;
	float rate = 12;

	float interest = amount * (rate / 100) * time;

	cout << "The interest is: " << interest;
}

// 16. Find the largest of given five integers.

void LargestNumber() {
	cout << "Give me 5 number: " << endl;

	int largest = 0;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		if (num > largest)
			largest = num;
	}

	cout << "The given largestnumber is: " << largest;
}

// 17. A professor took Rs. 30 lakh loan from HDFC for a term of 20 years. 
//	   If payment is in equal instalments at the end of every year, find the yearly instalment. 
//     If professor returns Rs 5 lakh at the end of fifth year as addition payment, find the reduction in instalments in remaining years. Assume rate of interest as 11%.

void CalculateInterest2() {
	float amount = 30;
	float time = 20;
	float rate = 11;
	int redemption = 5;

	float equal_instalments = amount * (rate / 100) * time;

	cout << "Without redemption at the and of 20 years the interest is: " << equal_instalments << endl;

	float redeemed_instalments = 0;

	for (int i = 0; i < time; i++) {
		redeemed_instalments += amount * (rate / 100);
		if (i % redemption == 0)
			amount -= redemption;
	}

	cout << "With redemption at the and of 20 years the interest is: " << redeemed_instalments << endl;
}

// 18. Find roots of a given quadratic equation.

void QuadraticEquation() {
	// ax^2+bx+c = 0 -> a != 0
	// D = b^2-4ac
	// x = (-b +- sqrt(D))/2a

	float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;
	cout << "Enter coefficients a, b and c: ";
	cin >> a >> b >> c;
	discriminant = b*b - 4 * a*c;

	if (discriminant > 0) {
		x1 = (-b + sqrt(discriminant)) / (2 * a);
		x2 = (-b - sqrt(discriminant)) / (2 * a);
		cout << "Roots are real and different." << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}

	else if (discriminant == 0) {
		cout << "Roots are real and same." << endl;
		x1 = (-b + sqrt(discriminant)) / (2 * a);
		cout << "x1 = x2 =" << x1 << endl;
	}

	else {
		realPart = -b / (2 * a);
		imaginaryPart = sqrt(-discriminant) / (2 * a);
		cout << "Roots are complex and different." << endl;
		cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
		cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
	}

}

// 19. Write a program to accept three sides of a triangle in a, b and c. Check whether the triangle is constructible or not. 
//     If yes, then find whether the triangle is equilateral, isosceles or scalene.

bool _liesOnLine(int x1, int y1, int x2, int y2, int x, int y) {
	float m = (y2 - y1) / (x2 - x1);
	if ((y - y1) == m*(x - x1))
		return true;
	else
		return false;
}

float _distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void ConstructibleTriangle() {
	int x1, y1, x2, y2, x3, y3;

	cout << "Give me 3 pair point for triangle: " << endl;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	if (_liesOnLine(x1, y1, x2, y2, x3, y3)) {
		cout << "The triangle is not constructible!" << endl;
		return;
	}
	else
		cout << "The triangle is constructible!" << endl;
	
	float d1 = _distance(x1, y1, x2, y2);
	cout << "d1: " << d1 << endl;
	float d2 = _distance(x2, y2, x3, y3);
	cout << "d2: " << d2 << endl;
	float d3 = _distance(x3, y3, x1, y1);
	cout << "d3: " << d3 << endl;

	if ((d1 == d2) && (d1 == d3))
		cout << "This is a equilateral triangle!" << endl;
	else if (((d1 == d2) && (d1 != d3)) || ((d2 == d3) && (d2 != d1)) || ((d3 == d1) && (d3 != d1)))
		cout << "This is a isosceles triangle!" << endl;
	else if ((d1 != d2) && (d2 != d3) && (d3 != d1))
		cout << "This is a scalene triangle!" << endl;
}

// 20. Find LCM of given two integers.

void LowestCommonMultiple() {
	int n1, n2, minMultiple;

	cout << "Give 2 number: " << endl;
	cin >> n1 >> n2;

	minMultiple = (n1>n2) ? n1 : n2;

	while (true)
	{
		if (minMultiple%n1 == 0 && minMultiple%n2 == 0)
		{
			cout << "The LCM of is: " <<  minMultiple << endl;
			break;
		}
		++minMultiple;
	}
}

// 21. Find the largest integer value n, such that its factorial can be correctly stored in variable of type “long”.

int factorial(int n){

	float result = 1;
	int i = 0;

	if (n <= 1)
		return 1;

	for (i = 2; i <= n; i++){
		result = result * i;
	}
	return result;
}

void StoredFactorial() {
	cout << "Maximum of long int: " << LONG_MAX << endl;
	
	int num = 0;

	while (true)
	{
		if (factorial(num) < LONG_MAX) {
			num++;
		}
		else {
			break;
		}
	}
	cout << "the largest integer value n, such that its factorial can be correctly stored in variable of type 'long': " << num << endl;
}

// 22. Find the cosine of a given angle using series expansion formula.

void SerielExpansionOfCos() {
	// cos x = ((-1)^k / (2*k+1)!) *x^(2*k+1)

	cout << "Give me a angle: ";
	double x;
	cin >> x;

	float k;
	double sum = 0;
	float a = 0, b = 0, c = 0;

	for (k = 0; k < 10; k++) {
		//cout << "k: " << k << endl;
		a = pow(-1, k);
		//cout << "a: " << a << endl;
		b = pow(x, (2 * k));
		//cout << "b: " << b << endl;
		c = factorial(2 * k);
		//cout << "c: " << c << endl << endl;
		sum += ( a * b / c );
	}

	cout << "cos(" << x << ") is: " << sum << endl;
}

// 23. Find first 50 prime numbers.

bool primeCheck(int n) {
	int i, flag = 1;
	for (i = 2; i <n; i++){
		if ((n%i) == 0){
			flag = 0; // sets not prime
			break;
		}
	}
	if (flag == 1) return true;
	else return false;
}

void PrimeNumbers() {
	int prime[50];
	int n = 2, count = 0;

	while (true)
	{
		if (primeCheck(n)) {
			prime[count] = n;
			count++;
		}

		if(count == 50) break;

		n++;
	}

	for (int i = 0; i < 50; i++) {
		cout << prime[i] << endl;
	}
}

// 24. Write a program to print fixed deposit table. Assume period as 1–5 years. 
//     Assume compound interest rates as 5%, 6%, 6.5%, 7% and 7.5%. Assume deposit amount as Rs. 1,000.

float interestCalculator(int amount, float rate, int time) {
	return amount * (rate / 100) * time;
}

void DepositTable() {
	float r1 = 5, r2 = 6, r3 = 6.5, r4 = 7, r5 = 7.5;
	int loan = 1000;
	int period = 5;

	for (int i = 1; i < period+1; i++) {
		cout << "If the loan is: " << loan << " and a rate is: " << r1 << " the time period is: " << i << " year, then the deposit is: " << interestCalculator(loan, r1, i) << endl;
		cout << "If the loan is: " << loan << " and a rate is: " << r2 << " the time period is: " << i << " year, then the deposit is: " << interestCalculator(loan, r2, i) << endl;
		cout << "If the loan is: " << loan << " and a rate is: " << r3 << " the time period is: " << i << " year, then the deposit is: " << interestCalculator(loan, r3, i) << endl;
		cout << "If the loan is: " << loan << " and a rate is: " << r4 << " the time period is: " << i << " year, then the deposit is: " << interestCalculator(loan, r4, i) << endl;
		cout << "If the loan is: " << loan << " and a rate is: " << r5 << " the time period is: " << i << " year, then the deposit is: " << interestCalculator(loan, r5, i) << endl;
		cout << "<============================================================================================>" << endl;
	}

}

// 25. Write a program to accept an integer n from the user and find the sum and average of first n natural numbers.

void SumOfNaturalNumbers() {
	// natural numbers === non-negative integers

	cout << "Give me an integers: ";
	int n; cin >> n; n = abs(n);
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += i;
	}

	cout << "Sum of " << n << " natural numbers is: " << sum << endl;
}

// 26. Find all the divisors (prime as well as non-prime) of a given integer.

void Divisor() {
	cout << "Give me an integer: ";
	int n; cin >> n;

	for (int i = 1; i < n; i++) {
		if (n % i == 0)
			cout << i << " is divisor of: " << n << endl;
	}
}

// 27. Given a positive integer between 1 and 9999, find the number of digits needed to express it in binary form.

void ExpressInBinaryForm() {
	cout << "Give me an integer between 1 and 9999: ";
	int n; cin >> n;

	int i = 0;
	while (true)
	{
		//cout << pow(2, i) << endl;
		if (pow(2, i) > n)
			break;
		i++;
	}
	cout << i << "pc digits needed to express" << endl;
}

// 28. Reverse the digits of a given integer.

void ReverseDigits() {
	cout << "Give me an integer: ";

	int i; cin >> i;

	string str = to_string(i);
	reverse(str.begin(), str.end());
	i = stoi(str);
	cout << i << endl;
}

// 29. Find the sum of all digits of an integer.

void SumOfDigits() {
	cout << "Give me an integer: ";
	int n; cin >> n;
	int sum = 0;

	string str = to_string(n);
	string::iterator it = str.begin();
	for (it; it != str.end(); ++it) {
		//cout << *it << endl;
		sum += (int)*it - 48;
	}
	cout << "The sum is: " << sum;
}

// 30. Write a program to accept an integer n and find its binary equivalent, e.g. if n = 13 then b = 1101.

void BinaryEquivalent() {
	cout << "Give me an integer: ";
	int n; cin >> n;

	string binary = bitset<16>(n).to_string();

	cout << binary << endl;
}

// 31. Write a program to accept number of lines (n) from the user and display the following pattern on the screen. 
//     (The pattern is shown for n = 4 and should vary according to the value of n.)

void DisplayPattern() {
	cout << "Give me an integer: ";
	int n; cin >> n;
	int p = 1;
	bool asc = true;
	for (int i = 1; i < n+1; i++) {
		for (int j = 0; j < (2 * i - 1); j++) {
			cout << p << " ";
			if (p == i) asc = false;
			if (asc) p++;
			else p--;
		}
		p = 1; asc = true;
		cout << endl;
	}
}