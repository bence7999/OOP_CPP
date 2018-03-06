#include "ChapterEleven.h"

using namespace std;

namespace ChapterEleven {

	// Write a program to study reading of character in light of flag skipws.

	void Skipws1() {
		char ch1;
		char ch2;
		cout << "<-- - skipws1.cpp--->" << endl;
		cin.setf(ios::skipws);
		cin >> ch1;
		cout << "char ch1 is-- - " << ch1 << endl;
		cin >> ch2;
		cout << "char ch2 is-- - " << ch2 << endl;
		cout << "part 2" << endl;
		cin.unsetf(ios::skipws);
		cin >> ch1;
		cout << "char ch1 is-- - " << ch1 << endl;
		cin >> ch2;
		cout << "char    ch2 is-- - " << ch2 << endl;
	}

	// Write a program to illustrate reading of strings.

	void Read1() {
		char str1[80], str2[80];
		cout << "<-- - read1.cpp--->" << endl;
		cin >> str1;
		cout << str1 << endl;
		cin >> str2;
		cout << str2;
	}

	// Write a program to study function getline().

	void Getline() {
		char st1[80], st2[40];
		cout << "<-- - getline.cpp--->" << endl;
		cin.getline(st1, 25, '0');
		cin.getline(st2, 5, '0');
		cout << st1 << endl << st2 << endl;
	}

	// Write a program to demonstrate that a program which can read unformatted data as well as formatted data.

	typedef char string15[15];
	
	struct Employee
	{
		int type;
		long pay;
		string15 name;
	};

	void read_struct(Employee & emp)
	{
		cin >> emp.type >> emp.name >> emp.pay;
	}

	void Struct1() {
		int i;
		cout << "<-- - struct1.cpp--->" << endl;
		cout << " give data for three employees " << endl;
		Employee emp[3];
		for (i = 0; i < 3; i++) {
			read_struct(emp[i]);
		}
		cout << " " << endl;
		cout << "Category : Name: Pay " << endl;
		for (i = 0; i < 3; i++)
		{
			cout << emp[i].type << " " << emp[i].name << " " << emp[i].pay << endl;
		}
	}

	// Write a program to study methods like fill(), width() and setf().

	void Forout1() {
		int num1 = 17, num2 = 25;
		cout << "<-- - forout1.cpp--->" << endl;
		cout << " 1)";
		cout.width(6); cout.fill('#');
		cout << num1 << num2 << endl;
		cout << " 2)";
		cout.width(6); cout << num1;
		cout.width(6); cout << num2 << endl;
		cout << " 3)";
		cout.fill('$');
		cout.setf(ios::left, ios::adjustfield);
		cout.width(6); cout << num1;
		cout.width(6); cout << num2 << endl;
	}

	// Write a program to illustrate the use of ios flags like showbase, dec, etc.

	void Intw2() {
		int num = 17;
		cout << "<-- - intw2.cpp--->" << endl;
		cout.setf(ios::hex, ios::basefield);
		cout << " 1) num in hex " << num << endl;
		cout.setf(ios::dec, ios::basefield);
		cout << " 2) num in decimal " << num << endl;
		cout.setf(ios::oct, ios::basefield);
		cout << " 3) num in octal " << num << endl;
		cout << "Above output with show base" << endl;
		cout.setf(ios::showbase);
		cout.setf(ios::hex, ios::basefield);
		cout << " 1) num in hex " << num << endl;
		cout.setf(ios::dec, ios::basefield);
		cout << " 2) num in decimal " << num << endl;
		cout.setf(ios::oct, ios::basefield);
		cout << " 3) num in octal " << num << endl;
	}

	// Write a program to illustrate ios flags like scientific, uppercase etc.

	void Floatw2() {
		float distance = 171.234567;
		cout << " <--floatw2.cpp--->" << endl;
		cout.setf(ios::fixed);
		cout << " 1)" << distance << endl;
		cout.precision(3);
		cout << " 2)" << distance << endl;
		cout.setf(ios::scientific, ios::floatfield); //note 1
		cout.setf(ios::showpoint);
		cout << " 3)" << distance << endl;
		cout.precision(8);
		cout << " 4)" << distance << endl;
	}

	// Write a program to demonstrate writing an object in formatted manner

	class Employee_2
	{
	protected:
		int type;
		long pay;
		string15 name;
	public:
		Employee_2()
		{  //cout <<"enter type name and pay in format free manner" <<endl;
			cin >> type >> name >> pay;
		}

		void writeLine()
		{
			cout << setw(8) << type << setw(15) << name << setw(8) << pay << endl;
		}
	};

	void Rwobj1() {
		cout << "<-- - rwobj1.cpp--->" << endl;
		cout << "enter type name and pay in format free manner" << endl;
		Employee_2 emp[3]; // note 1
		cout << "*** Objects of class Employee***" << endl;
		cout << "Category : Name: Pay " << endl;
		for (int i = 0; i<3; i++)
			emp[i].writeLine();
	}

	// Write a program to demonstrate the use of manipulators in reading.

	void Manip1A() {
		int marks1, marks2;
		cout << "<-- - manip1A.cpp--->" << endl;
		cout << "enter marks in hex format : ";
		cin >> hex >> marks1;
		cout << "marks1 = " << marks1 << endl;
		cout << "enter marks in hex format : ";
		cin >> marks2;
		cout << "marks2 = " << marks2 << endl;
	}

	// Write a program to illustrate various manipulators like dec, hex, oct, setbase, setfill and setiosflags.

	void Manip2() {
		int marks;
		marks = 23;
		cout << "<-- - manip2.cpp--->" << endl;
		cout << " 1)" << hex << "marks in hex : " << marks << endl;
		cout << " 2)" << dec << "marks in decimal : " << marks << endl;
		cout << " 3)" << oct << "marks in octal : " << marks << endl;
		cout << " 4)" << setbase(16) << "marks in base 16 :" << marks << endl;
		cout << " 5)" << setbase(0) << "marks in default base :" << marks << endl;
		cout << " 6)" << setbase(8) << "marks in base 8 :" << marks << endl;
		cout << " 7)" << setw(10) << setfill('#') << marks << endl;
		cout << " 8)" << setw(10) << setiosflags(ios::left) << marks << endl;
		cout << " 9)" << marks << endl;
	}

	// Write a program to illustrate manipulators like setw, setprecision, setiosflags and resetiosflags.

	void Manip3() {
		float distance = 12.3456789;
		cout << "<-- - manip3.cpp--->" << endl;
		cout << "Printing values of variable distance" << endl;
		cout << " 1)" << distance << "--->default precision" << endl;
		cout << " 2)" << setprecision(2) << setiosflags(ios::fixed) << distance << "--->precision 2" << endl;
		cout << " 3)" << setw(20) << distance << "--->width 20" << endl;
		cout << " 4)" << setiosflags(ios::left) << setw(20) << distance << "--->width 20 Justification left" << endl;
		cout << " 5)" << resetiosflags(ios::left) << setw(20) << distance << "--->width 20 Justification right" << endl;
		cout << " 6)" << setprecision(10) << distance << "--->precision 20" << endl;
	}

	// Write a program to calculate sine of x using series expansion and calculate the percentage error. Show the output in unformatted and formatted manner.

	void Manip4() {
		int i;
		float sum = 0, term = 1;
		float x, x1, x2, error;
		cout << "<-- - manip4.cpp--->" << endl;
		cout.setf(ios::showpoint);
		cout << "unformatted output" << endl;
		cout << "Give x between 0 to 90 degrees:";
		cin >> x;
		cout << " term calculated error " << endl;
		cout << " number value %" << endl;
		x1 = x * 3.14159 / 180.0; // x in radian
		sum = term = x1; i = 1;
		cout << i << " " << sum << endl;
		while (i < 12)
		{
			i = i + 2;
			term = -1 * term * x1 * x1 / i / (i - 1);
			sum = sum + term;
			error = (sum - sin(x1)) * 100.0 / sin(x1); //percentage error
			cout << i << " " << sum << " " << error << endl;
		}
		cout << " formatted output " << endl;
		cout << " term calculated error " << endl;
		cout << " number value %" << endl;
		x2 = x * 3.14159 / 180.0; // x2 in radian
		sum = term = x2; i = 1;
		cout.precision(4);
		cout.setf(ios::fixed, ios::floatfield);
		cout << setw(3) << i << setw(15) << sum << endl;
		while (i<12)
		{
			i = i + 2;
			term = -1 * term * x2 * x2 / i / (i - 1);
			sum = sum + term;
			error = (sum - sin(x2)) * 100.0 / sin(x2); //percentage error
			cout << setw(3) << i << setw(15) << sum << setw(15) << error << endl;
		}
	}

	// Write a program to define a manipulator "standard". It should help in setting suitable flags for printing floating point number as amount.

	ostream & Standard(ostream & dummy)
	{
		dummy.precision(2);
		dummy.width(15);
		dummy.setf(ios::showpoint);
		dummy.setf(ios::fixed);
		return dummy;
	}

	void Manip5() {
		float money1 = 123.4567, money2 = 45.30;
		cout << "<-- - manip5.cpp--->" << endl;
		cout << "money1 = " << money1 << endl;
		cout << "money2 = " << money2 << endl;
		cout << "money1 = " << Standard << money1 << endl;
		cout << "money2 = " << Standard << money2;
	}

	// Write a program to illustrate ios flags good, bad and fail.

	void Flag1() {
		int m = 25;
		cout << "<-- - flag1.cpp--->" << endl;
		cout << "give value of m" << endl;
		cin >> m;
		cout << m << endl;
		if (cin.bad()) cout << "bad" << endl;
		else cout << "NOT bad" << endl;
		if (cin.good()) cout << "good" << endl;
		else cout << "NOT good" << endl;
		if (cin.fail()) cout << "fail" << endl;
		else cout << "Not fail" << endl;
	}

	///////////////////////////
	////       TASKS       ////
	/////////////////////////// 

	// 1. List C++ predefined streams and explain their significance.

	// 2. Explain stream classes and stream class hierarchy for input/output.

	// 3. Explain why C++ I/O is considered better than I/O in C language.

	// 4. Discuss advantages and disadvantages of format-free input/output.

	// 5. What is the advantage of formatted output?

	// 6. Why does disk-based input/output needs buffers?

	// 7. What are manipulators? List the various predefined manipulators supported by C++ streams.

	// 8. What are custom manipulators? Write a custom manipulator for inserting six blanks in the output.

	// 9. Design a single manipulator format to provide the following output specifications for printing float values:
	//    1. 10 columns width.

	ostream & Own1(ostream & str) {
		str.width(10);
		return str;
	}

	void TryOwn1() {
		float flt = 123.4567;
		cout << Own1 << flt << endl;
	}

	//    2. Right-justified.

	ostream & Own2(ostream & str) {
		str.setf(ios::right);
		return str;
	}

	void TryOwn2() {
		float flt = 123.4567;
		cout << Own2 << setw(20) << flt << endl;
	}

	//    3. Two digits precision.

	ostream & Own3(ostream & str) {
		str.precision(2);
		return str;
	}

	void TryOwn3() {
		float flt = 123.4567;
		cout << Own3 << flt << endl;
	}

	//    4. Filling of unused places with *.

	ostream & Own4(ostream & str) {
		str.fill('*');
		return str;
	}

	void TryOwn4() {
		float flt = 123.4567;
		cout << Own4 << setw(20) << flt << endl;
	}

	//    5. Trailing zeroes shown.

	ostream & Own5(ostream & str) {
		str.setf(ios::showpoint);
		str.setf(ios::fixed);
		return str;
	}

	void TryOwn5() {
		float flt = 123.4567;
		cout << Own5 << flt << endl;
	}

	void AllInAll() {
		float flt = 123.4567;
		cout << Own1 << Own2 << Own3 << Own4 << Own5 << flt << endl;
	}

	// 10. Write a function void getkey( key_type &akey, char &ch) ; to read a key from a keyboard. 
	//     The key_type is an enum with values ESCAPE, ORDINARY, FUNCTION and so on. Variable ch should return the actual corresponding character. (Hint – use conio.h)

	enum key_type{
		ESCAPE = 'e', ORDINARY = 'o', FUNCTION = 'f'
	};

	void getkey(key_type &akey, char &ch) {
		cout << "jee" << akey << ch << endl;
	}

	void readFromKB() {
		char ch;
		ch = getchar();
		cout << ch << endl;

		key_type kt;
		

		switch (ch){
		case ESCAPE:
			kt = ESCAPE;
			getkey(kt, ch);
		case ORDINARY:
			kt = ORDINARY;
			getkey(kt, ch);
		case FUNCTION:
			kt = FUNCTION;
			getkey(kt, ch);
			break;
		default:
			break;
		}
		
	}

	// 11. Write a function to print any given [N,N] matrix with elements of type float. Fix a ceiling on N considering that a typical display has only 80 columns.

	void PrintMatrix() {
		const int max = 6;
		float matrix[max][max] = {	{1.1, 1.2, 1.3, 1.4, 1.5, 1.6}, 
									{2.1, 2.2, 2.3, 2.4, 2.5, 2.6}, 
									{3.1, 3.2, 3.3, 3.4, 3.5, 3.6}, 
									{4.1, 4.2, 4.3, 4.4, 4.5, 4.6},
									{5.1, 5.2, 5.3, 5.4, 5.5, 5.6},
									{6.1, 6.2, 6.3, 6.4, 6.5, 6.6} };

		for (int i = 0; i < max; i++) {
			cout.width(80);
			for (int j = 0; j < max; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}

	}

	// 12. Write an interactive function to show as well as modify values of all ios flags.

	void ShowAndModify() {

	}

	// 13. Write a program to bring up a pop up input box similar to the one available in Visual Basic. (Hint – use conio.h)

	void InputBoxPopUp() {

	}

}