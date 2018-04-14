#include "ChapterSixteen.h"

using namespace std;

namespace ChapterSixteen {
	
	/// 16.1.3 Constant pointer to constant
	/// 16.1 Using keyword "const"
	// Write a program to demonstrate use of keyword const.

	void Constl() {
		cout << "<-- - constl.cpp--->" << endl;
		// example 1 pointer to constant
		int m = 20, i = 30, j = 40;
		const int *ptr = &i;
		// *ptr =10;
		// Error Cannot modify a const object
		//(ptr)--;
		ptr = &j;
		cout << *ptr << endl;
		// example 2 constant pointer
		int * const p = &i;
		// p++; // error
		// Error Cannot modify a const object
		cout << *p << endl;
		// example 3constant pointer to constant
		const int * const q = &m;
		cout << *q << endl;
		// q++;
		// Error : Cannot modify a const object
		// *q = 3 ;
		// Error : Cannot modify a const object
	}

	/// 16.2.2 "const" With data members
	/// 16.2 Using const with data member
	// Write a program to illustrate the use of const with data member of a class.

	class AA
	{
	public:
		const int num;
		AA();
	};

	void Const99() {
		AA a;
		cout << "<-- - const99.cpp--->" << endl;
		// a.num++; // compilation error
		cout << a.num;
	}

	AA::AA(): num(4) {}

	/// 16.2.3 "const" With methods
	/// 16.3 Using const with a method
	// Write a program to demonstrate the use of const with a method.

	class BB {
	public:
		int marks[3];
		int print() const;
		BB(int a, int b, int c);
	};

	void Const99b() {
		cout << "<-- - const99B--->" << endl;
		BB test(78, 88, 72);
		test.print();
	}

	BB::BB(int a, int b, int c)
	{
		marks[0] = a;
		marks[1] = b;
		marks[2] = c;
	};

	int BB::print() const
	{
		cout << "constant method " << endl;
		cout << "marks are : " << endl;
		//marks[2]= marks[2]+ 20;
		cout << marks[0] << " " << marks[1] << " " << marks[2] << endl;
		return 0;
	};

	/// 16.3 CONDITIONAL COMPILATION
	/// 16.4 Conditional compilation
	// Write a program to demonstrate conditional compilation.

	void Ifdef3() {
		cout << "<-- - ifdef3.cpp--->" << endl;
#ifdef stdout
		printf("stdout defined\n");
#endif
#ifdef __TURBOC__
		printf("turboc defined\n");
#endif
#ifdef __cplusplus
		printf("cplusplus defined\n");
#endif
	}

	/// 16.4 FUNCTIONS WITH VARIABLE ARGUMENTS
	/// 16.5 Variable argument
	// Write a program to demonstrate variable arguments in a function.

	// calculate sum of a 0 terminated list
	void sum(char *msg, ...)
	{
		int total = 0;
		va_list ap;
		int arg;
		va_start(ap, msg);
		while ((arg = va_arg(ap, int)) != 0)
		{
			total = total + arg;
		}
		cout << msg << total << endl;
		va_end(ap);
	}

	void Varg1() {
		cout << "<-- - vargl.cpp--->" << endl;
		sum("The sum of parameters is ", 3, 5, 7, 0);
	}

	/// 16.5 BIT MANIPULATION
	/// 16.6 Bit manipulation I
	// Write a program to develop class BitMan (Bit Manipulation). It should have methods to
	// - set a bit
	// - get a bit
	// - convert object to string of 1s and 0s
	// - show the object Solution: See Program 16.6.

	typedef unsigned char BYTE;
	typedef char STR9[9];

	class BitMan
	{
	private:
		BYTE num;
	public:
		BitMan();
		BitMan(BYTE k);
		void show();
		int getBit(int i);
		void setBit(int i);
		friend void toString(BitMan x, STR9 & str);
	};

	void Bitman2() {
		cout << "<-- - bitman2.cpp--->" << endl;
		BitMan Z(17);
		Z.show();
		cout << "Testing 4th Bit" << endl;
		cout << "4 th bit is " << Z.getBit(4) << endl;
		cout << "seting 6th bit " << endl;
		Z.setBit(6);
		Z.show();
	}

	BitMan::BitMan()
	{
		num = 0;
	}

	void BitMan::show()
	{
		STR9 st;
		cout << "num is " << (int)num << endl;
		toString(*this, st);
		cout << " bit pattern " << st << endl;
	}

	BitMan::BitMan(BYTE k)
	{
		num = k;
	}

	int BitMan::getBit(int i)
	{
		BYTE mask = 1;
		int retval = 0;
		if ((i>0) && (i<8)) mask = mask << i;
		else { cout << " error"; exit(1); };
		if ((mask & num) > 0) retval = 1;
		return retval;
	}

	void toString(BitMan x, STR9 & str)
	{
		int i;
		int k = x.num;
		str[8] = '\0';
		for (i = 7; i >= 0; i--)
		{
			str[i] = (k % 2) ? '1' : '0';
			k = k / 2;
		}
	}

	void BitMan::setBit(int i)
	{
		BYTE mask = 1;
		if ((i>0) && (i<8)) mask = mask << i;
		else { cout << " error"; exit(1); };
		num = mask | num;
	}

	/// 16.5.2 Getting group of bits
	/// 16.7 Masking technique
	// Write a program to add method pickBits to class Bitman. This method should select specified number of bits (nbits) from a given position (pos).

	class BitMan2
	{
	private:
		BYTE num;
	public:
		BitMan2();
		BitMan2(BYTE k);
		void show();
		int getBit(int i);
		void setBit(int i);
		friend void toString(BitMan2 x, STR9 & str);
		BYTE pickBits(int numbits, int pos);
	};

	void Bitman4() {
		cout << "<bitman4.cpp>" << endl;
		BYTE answer;
		BitMan2 Z(3l);
		Z.show();
		answer = Z.pickBits(2, 3);
		cout << " 2bits from 3rd " << (int)answer << endl;;
	}

	BitMan2::BitMan2()
	{
		num = 0;
	}

	void BitMan2::show()
	{
		STR9 st;
		cout << "num is " << (int)num;
		toString(*this, st);
		cout << " bit pattern : " << st << endl;
	}

	BitMan2::BitMan2(BYTE k)
	{
		num = k;
	}

	int BitMan2::getBit(int i)
	{
		BYTE mask = 1;
		int retval = 0;
		if ((i>0) && (i<8)) mask = mask << i;
		else { cout << " error"; exit(1); };
		if ((mask & num) > 0) retval = 1;
		return retval;
	}

	void toString(BitMan2 x, STR9 & str)
	{
		int i;
		int k = x.num;
		str[8] = '\0';
		for (i = 7; i >= 0; i--)
		{
			str[i] = (k % 2) ? 'l' : 's0';
			k = k / 2;
		}
	}

	void BitMan2::setBit(int i)
	{
		BYTE mask = 1;
		if ((i>0) && (i<8)) mask = mask << i;
		else { cout << " error"; exit(1); };
		num = mask | num;
	}

	BYTE BitMan2::pickBits(int numbits, int pos)
	{ // check numbits 7 or less
	  // check pos 0 to 7
	  // pos + 1 – numbits should be greate than 0
		BYTE temp;
		BitMan2 mask(0);
		int i;
		for (i = 0; i<numbits; i++)
			mask.setBit(pos - i);
		cout << " showing mask" << endl;
		mask.show(); //helps in debugging
		temp = this->num & mask.num;
		// cout<<"---"<< int(temp ) <<endl,//for debugging
		temp = temp >> (pos + 1 - numbits);
		return temp;
	}

	/// 16.5.3 A case study – ios flags
	/// 16.8 Setting ios flags
	// Write a program to study setting of ios flags.

	const int MAXBIT = 16;

	class BitMan1
	{
	private:
		unsigned long mask[MAXBIT];
		long num;
		void initMask();
		char str[MAXBIT + 1];
	public:
		BitMan1();
		BitMan1(long N);
		void show1(char *p);
		int getBit(int i);
		void defStr();
	};

	void Bitman9T() {
		cout << "<-- - bitman9T.cpp--->" << endl;
		cout << "commentflag last l6 bitsoutput" << endl;
		BitMan1 Zl(cout.flags());
		Zl.show1("Default flag ");
		cout << " : " << setw(8) << 25.4 << endl;
		cout.setf(ios::left, ios::adjustfield);
		BitMan1 Z2(cout.flags());
		Z2.show1("left flag");
		cout << " : " << setw(8) << 25.4 << endl;
		cout.setf(ios::scientific, ios::floatfield);
		BitMan1 Z3(cout.flags());
		Z3.show1("scientific ");
		cout << " : " << setw(8) << 25.4 << endl;
		cout.unsetf(ios::scientific);
		BitMan1 Z4(cout.flags());
		Z4.show1("unsetf sci..");
		cout << " : " << setw(8) << 25.4 << endl;
		cout.setf(ios::right, ios::adjustfield);
		BitMan1 Z5(cout.flags());
		Z5.show1("set right");
		cout << " : " << setw(8) << 25.4 << endl;
	}

	BitMan1::BitMan1()
	{
		num = 0;
		initMask();
		defStr();
	}

	void BitMan1::show1(char *p)
	{ // cout << " num is " << num << endl;
		cout << p << str;//<< endl;
	}

	BitMan1::BitMan1(long N)
	{
		int i;
		num = N;
		initMask();
		defStr();
	}

	void BitMan1::initMask()
	{
		int i;
		mask[0] = 1;
		for (i = 1; i<MAXBIT; i++)
		{
			mask[i] = mask[i - 1] * 2;
		}
	}

	int BitMan1::getBit(int i)
	{
		int retval = 0;
		if ((i >= 0) && (i<MAXBIT))
		{
			if (num & mask[i]) retval = 1;
		}
		else {
			cout << " error";
			exit(1);
		}
		return retval;
	}

	void BitMan1::defStr()
	{
		str[MAXBIT] = '\0'; // terminating null
		for (int i = 0; i<MAXBIT; i++)
			if (getBit(i) == 0) str[MAXBIT - 1 - i] = '0';
		else
			str[MAXBIT - 1 - i] = '1';
	}

	/// 16.9.4 Data encryption by bit manipulation
	/// 16.9 Data encryption by bit manipulation
	// Write a program to encrypt a given string.

	void Encriptl() {
		char ch;
		int i;
		char *name = "Bhavepatekar";
		char mask = char(8);
		cout << "<-- - encryptl.cpp--->" << endl;
		for (ch = 'a'; ch <= 'z'; ch++)
			cout << ch; cout << endl;
		for (ch = 'a'; ch <= 'z'; ch++)
		{
			cout << char(ch ^ mask);
		}
		cout << endl;
		for (i = 0; i<strlen(name); i++)
			cout << name[i];
		cout << endl;
		for (i = 0; i<strlen(name); i++)
			cout << char(name[i] ^ mask);
	}

	/// 16.6 SCOPE RESOLUTION OPERATOR AS UNARY OPERATOR
	/// 16.10 Scope resolution operator
	// A college conducts tests with maximum marks 100. A global variable MAX is defined with value 100. A particular teacher conducts test with maximum marks 50. 
	// He also wants variable name MAX to store value 50 inside a block. Write a program to illustrate this situation. Solution: A global variable MAX can be referred as "::MAX".

	int MAX = 100;

	void Sro1() {
		cout << "<-- - sro1.cpp--->" << endl;
		// note new block below
		{ int MAX = 50;
		cout << "MAX = " << MAX << endl;
		cout << "global MAX = " << MAX << endl;
		}
	}

	/// 16.7 POINTERS TO MEMBERS
	/// 16.11 Pointers to members
	// Write a program to demonstrate pointers to members.

	class Date
	{
	private:
		int day, month;
	public:
		int year;
		Date(int d, int m, int y);
		void show();
	};

	void Ptomeml() {
		Date date1(1, 1, 2009), *date2;
		date2 = new Date(5, 5, 2011);
		int Date::* ptr1 = &Date::year;
		void (Date::* ptr2)();
		ptr2 = &Date::show;
		cout << "<-- - ptomem1.cpp--->" << endl;
		date1.year = 2010;
		// Using pointer to data member
		cout << "Now we are in Year " << date1.*ptr1 << " AD" << endl;
		// using pointer to method
		(date2->*ptr2)();
	}

	Date::Date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}

	void Date::show()
	{
		cout << "Date is " << day << " : "
			<< month << " : " << year << endl;
	}

	///////////////////////////
	////       TASKS       ////
	///////////////////////////

	// 1. What are the differences between pointers to constants and constant pointers? Give examples.

	// 2. What is the use of declaring an object as constant?

	// 3. What is the use of declaring a data member as constant? How is such member initialized?

	// 4. What advantage one gets of declaring a method of a class as constant?

	// 5. Study any one standard encryption algorithm on your own.

	string crypt(const string message, bool encrypt) {
		srand(time(0));
		static int secret = rand() % 32000;
		string output;
		int i = 0, a = 0, b = 1, c = 0;
		for (i = 0; i < message.size(); ++i) {
			if (encrypt) {
				output += ((int)message[i]) + (secret + c);
			}
			else {
				output += ((int)message[i]) - (secret + c);
			}

			c = a + b;
			a = b;
			b = c;
		}
		
		return output;
	}

	void TestOwnEncript() {
		string message("Lorem ipsum dolor sit amet consectetur");
		string output(crypt(message, false));
		string result(crypt(output, true));

		cout << message << endl << endl << output << endl << endl << result << endl;
	}

	// 6. Write a program to print a given long integer in hexadecimal and octal number system. (Hint:- Use bit manipulation technique to separate group of bits).

	typedef char unit[33];

	void Print4Byte(char* str) {
		for (int i = 0; i < 32; i++) {
			if (i % 8 == 0)
				cout << " ";
			cout << str[i];
		}
		cout << endl;
	}

	void PrintHexa(int* hexa) {
		cout << " ";
		for (int i = 0; i < 9; i++) {
			if (hexa[i] == 0)
				break;
			else {
				cout << uppercase << hex << hexa[i];
			}
		}
		cout << endl;
	}

	int* toHexa(long n) {
		int a[9] = {-1};
		int i = 0;
		int dec = n;
		while (dec != 0)
		{
			a[i] = dec % 16;
			dec = dec / 16;
			i++;
		}
		return a;
	}

	int toOcta(long n) {
		int dec = n;
		int rem, i = 1, octalNumber = 0;
		while (dec != 0)
		{
			rem = dec % 8;
			dec /= 8;
			octalNumber += rem * i;
			i *= 10;
		}
		return octalNumber;
	}

	char* toBin(long n) {
		int i;
		int k = n;
		unit str;
		str[32] = '/0';
		for (i = 31; i >= 0; i--)
		{
			str[i] = (k % 2) ? '1' : '0';
			k = k / 2;
		}
		return str;
	}

	void IntToHexAndOctal() {
		unit tmp;
		long num = 1234567;
		char* bin = toBin(num);
		for (int i = 0; i < 33; i++)
			tmp[i] = bin[i];
		Print4Byte(tmp);
		int lst[9];
		int* ret = toHexa(77);
		for (int i = 0; i < 9; i++)
			lst[i] = ret[i];
		PrintHexa(lst);
		cout << " " << dec << toOcta(77) << endl;
	}

	// 7. Write a program to print a bit pattern of a float value. (Hint:- Use technique of Program 16.6 bitman2.cpp. Also use a suitable union to convert float to array of bytes.)

	typedef char BYTE2[8];
	typedef char TWOBYTE[16];
	typedef char THREEBYTE[24];
	typedef char FOURBYTE[32];

	char* getNumSectionInBin(float num) {
		BYTE2 byte;
		int intpart = (int)num;
		for (int i = 0; i < 8; i++)
		{
			byte[i] = intpart % 2;
			intpart /= 2;
		}
		return byte;
	}

	char* getFracSectionInBin(float frac) {
		TWOBYTE twobyte;
		float sum = 0;
		for (int i = 1; i < 17; i++) {
			double power = 1 / pow(2, i);
			if (sum + power < frac) {
				twobyte[i-1] = 1;
				sum += power;
			}
			else {
				twobyte[i-1] = 0;
			}
		}
		return twobyte;
	}

	int getBinaryPoint(BYTE2 b) {
		int offset = 0;
		for (int i = 7; i >= 0; i--) {
			if (b[i] == 1)
				break;
			else
				offset++;
		}
		return 7 - offset;
	}

	char* getExponent(int binPoint) {
		int p = 127 + binPoint;
		char* ret = getNumSectionInBin((float)p);
		BYTE2 exp;
		for (int i = 0; i < 8; i++) {
			exp[i] = ret[i];
		}
		return exp;
	}

	void BitOffloat() {
		FOURBYTE binary;
		float intpart, fractpart;
		char sign = 0;

		float a = 1.4;

		if (a < 0)
			sign = 1;

		binary[0] = sign;

		fractpart = modf(a, &intpart);

		char* ret = getNumSectionInBin(intpart);
		BYTE2 num;
		for (int i = 0; i < 8; i++) {
			num[i] = ret[i];
		}

		int binPoint = getBinaryPoint(num);

		char* ret2 = getFracSectionInBin(fractpart);
		TWOBYTE frac;
		for (int i = 0; i < 16; i++) {
			frac[i] = ret2[i];
		}

		char* ret3 = getExponent(binPoint);
		BYTE2 exponenet;
		for (int i = 0; i < 8; i++) {
			exponenet[i] = ret3[i];
		}
		for (int i = 1; i < 9; i++)
			binary[i] = exponenet[7 - (i - 1)];

		THREEBYTE threeb;
		for (int i = 0; i < 8; i++)
			threeb[i] = num[7 - i];
		for (int i = 0; i < 16; i++)
			threeb[8 + i] = frac[15 - i];

		int offs = 0;
		for (int i = 7; i >= 0; i--) {
			if (num[i] == 1)
				break;
			else
			{
				offs++;
			}
		}

		offs++; // elim leading 1

		for (int i = offs; i < 24; i++) {
			binary[9+i-offs] = threeb[i];
		}

	}

}