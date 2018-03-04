#include "ChapterEight.h"

using namespace std;

namespace chapterEight {

	// Write a program to concatenate two strings.

	void Concat() {
		char st1[50] = "Hello";
		char st2[50] = "world";
		cout << "<-- - concat.cpp--->" << endl;
		strcat_s(st1, st2);
		cout << st1 << endl;
	}

	//  Write a program to read a sentence (string) into an array and capitalize the first character of every word in the input.

	void Cap1() {
		int i, flag;
		char s1[20], s2[20];
		cout << "<-- - cap1.cpp--->" << endl;
		cout << " give string : ";
		//cin >> s1 ; // cannot read a string with blank
		cin.getline(s1, 20);
		cout << s1 << endl;
		flag = 1;
		for (i = 0; i<strlen(s1); i++)
		{
			if (flag)
				s1[i] = toupper(s1[i]);
			if (s1[i] == ' ') /* blank */ flag = 1;
			else flag = 0;
		}
		cout << "converted to : " << s1 << endl;
	}

	// Write a program to read a string containing a blank using scanf function.

	void String4() {
		char name1[10];
		cout << "<-- - string4.cpp--->" << endl;
		printf("Give a string : ");
		//scanf_s("%[^\n]", name1);
		//printf("\n%s", name1);
	}

	// Write a program to read a string containing a blank using getline() function.

	void Getline1() {
		char str1[40];
		cout << "<-- - getline1.cpp--->" << endl;
		cout << "give input" << endl;
		cin.getline(str1, 20);
		cout << "Output is" << endl;
		cout << str1 << endl;
	}

	// Develop the function "removecr", which removes the last carriage return from a string.

	char nl = 10; // ASCII value 10 represents new line character

	void removecr(char *st);

	void Remove2() {
		int i, j, k;
		char str1[50] = "bhave\n";
		cout << "<-- - remove2.cpp--->" << endl;
		cout << str1 << "over" << endl;
		removecr(str1);
		cout << str1 << "over" << endl;
	}

	void removecr(char *st)
	{
		int k;
		k = strlen(st);
		if ((k>0) && (st[k - 1] == nl)) /* if nl i.e. Newline */
			st[strlen(st) - 1] = 0; /* then it is removed */
		return;
	}

	// Write a program to sort strings. Use C++ keywords as input data.

	char box[48][18] =
	{ "case", "union",  "enum", "public", "register",
		"int" , "continue", "while", "asm", "break",
		"void", "for", "double",  "catch",  "short",
		"new",  "float", "do",    "goto",   "auto",
		"protected", "extern", "try", "private", "class",
		"if",    "char", "this", "unsigned", "delete",
		"struct", "default", "long", "typedef", "throw",
		"volatile", "switch", "inline", "const", "virtual",
		"static", "template", "friend", "return", "operator",
		"sizeof", "signed", "else"
	};

	void sort(char box[][18], int n);

	void String5() {
		char *p;
		int i, j;
		cout << "<-- - string5.cpp--->" << endl;
		sort(box, 48);
		for (i = 0; i<48; i++)
		{
			cout.setf(ios::right);
			cout << setw(2) << (i + 1) << ")";
			cout.setf(ios::left);
			cout << setw(11) << box[i];
			if ((i + 1) % 5 == 0) cout << endl;
		}
		cout << endl;
	}

	void sort(char box[][18], int n)
	{
		int i, j;
		char k[18];
		for (i = 0; i<n; i++)
			for (j = 0; j<n - 1; j++)
			{
				if (strcmp(box[j], box[j + 1])> 0)
				{ // swap
					strcpy_s(k, box[j]);
					strcpy_s(box[j], box[j + 1]);
					strcpy_s(box[j + 1], k);
				}
			}
	};

	// Write a program to study printing of strings with field specifications.

	void String10() {
		char directions[][10] = { "north" , "south" , "east" , "west" };
		cout << "<-- - string10.cpp--->" << endl;
		printf("_.2s\n", directions[0]);
		printf("_.3s\n", directions[1]);
		printf("%-10.7s\n", directions[2]);
		printf("%-10.7s\n", directions[3]);
	}

	// Write a program to study copying strings.

	void Scopy3() {
		int i;
		char name1[15] = "DADA";
		char name2[15] = "SAURV";
		cout << "<-- - scopy3.cpp--->" << endl;
		i = 0;
		while (name1[i] != '\0')
		{
			name2[i] = name1[i];
			i++;
		}
		name2[i] = '\0';
		cout << name1 << endl;
		cout << name2 << endl;
	}

	// Develop two suitable constructors for class STRING.

	class STRING
	{
	private:
		int len;
		char a[80];
	public:
		STRING(char * p);// constructor1
		STRING(); // constructor 2
		void show();
	};

	void String1() {
		cout << "<-- - string1.cpp--->" << endl;
		char * name = "Long Live C++";
		STRING str1(name);
		str1.show();
		STRING str2;
		str2.show();
	}

	STRING::STRING(char * p)
	{
		int i;
		i = 0;
		while ((p[i] != '\0') && (i<80))
		{
			a[i] = p[i];
			i++;
		}
		len = i;
	}

	void STRING::show()
	{
		int i;
		cout << "string with " << len << " characters : " << endl;
		cout << "--->";
		for (i = 0; i<len; i++)
			cout << a[i];
		cout << "<-- - ";
		cout << endl;
	}

	STRING::STRING()
	{
		len = 0;
	}

	// Write a program to illustrate Interactive constructor for class STRING.

	class STRING_2
	{
	private:
		int len;
		char a[80];
	public:
		STRING_2(char * p);
		STRING_2();
		void show();
		int length();
		friend ostream& operator<<(ostream &, STRING_2 st);
		STRING_2 operator+(STRING_2 st2);// st1 is object itself
	};

	void String2() {
		cout << "<-- - string2.cpp--->" << endl;
		STRING_2 str;
		// interactive constructor gets called
		str.show();
		cout << str.length() << endl;
	}

	STRING_2::STRING_2(char * p)
	{
		int i;
		i = 0;
		while ((p[i] != '\0') && (i<80))
		{
			a[i] = p[i];
			i++;
		}
		len = i;
	}

	void STRING_2::show()
	{
		int i;
		cout << "--->";
		for (i = 0; i<len; i++)
			cout << a[i];
		cout << "<-- - ";
		cout << endl;
	}

	int STRING_2::length()
	{
		return len;
	}

	STRING_2::STRING_2()
	{
		int i, flag = 1;
		char ch;
		cout << "Interactive Construction" << endl;
		cout << "give string : ";
		i = 0;
		while (flag && (i<80))
		{
			ch = getchar();
			if (isprint(ch))
			{
				a[i] = ch;
				i++;
			}
			else flag = 0;
		}
		cout << endl << "reading over" << endl;
		len = i;
	}

	// Write a program to overload "<<" operator for class STRING.

	void String3() {
		cout << "<-- - string3.cpp--->" << endl;
		STRING_2 str1("Programming with C++");
		cout << str1 << endl;
		cout << "no of chars are "
			<< str1.length() << endl;
	}

	ostream & operator<< (ostream & temp, STRING_2 st)
	{
		int i;
		for (i = 0; i<st.len; i++)
			temp << st.a[i];
		return temp;
	}

	// Write a program to overload "+" operator to concatenate two strings.

	void String11() {
		cout << "<-- - string11.cpp--->" << endl;
		STRING_2 str1("Bhave");
		STRING_2 str2("Patekar");
		cout << "See concatenation in action" << endl;
		cout << str1 + str2;
	}

	STRING_2 STRING_2::operator+(STRING_2 st2)// st1 is object itself
	{
		STRING_2 addedup(""); //empty string
							// believes that total characters << 250
		int i;
		for (i = 0; i<len; i++)
			addedup.a[i] = a[i];
		addedup.len = len;
		for (i = 0; i<st2.len; i++)
			addedup.a[i + len] = st2.a[i];
		addedup.len = len + st2.len;
		return addedup;
	}

	///////////////////////////
	////       TASKS       ////
	/////////////////////////// 

	// 1. Write a program to sort an array of strings in ascending order of string length.

	void sorts(string s[], int max);

	void ArrayOfString() {
		const int max = 13;
		string lista[max] = {"admirevanity", "countyan", "mutualyas", "roused", "of", "a", "thrownam", "warmly", "merely", "resultdepart", "supply", "required", "honoured"};

		sorts(lista, max);

		for (int i = 0; i < max; i++) {
			cout << lista[i] << endl;
		}
	}

	void sorts(string b[], int max) {
		int i, j;
		string temp;

		for (i = 0; i < max - 1; i++) {
			for (j = 0; j<max - 1; j++)
			{
				if (b[j].length() > b[j + 1].length())
				{
					temp = b[j];
					b[j] = b[j + 1];
					b[j + 1] = temp;
				}
			}
		}

	}

	// 2. Write a program to remove duplicates from an unsorted array of strings.

	void RemoveDupplicated() {
		const int maxx = 13;
		string lista[maxx] = { "honoured", "of", "mutualyas", "roused", "of", "a", "merely", "warmly", "merely", "required", "supply", "required", "honoured" };
		int max = maxx;
		for (int i = 0; i < max; ++i)
			for (int j = i + 1; j < max;)
			{
				if (lista[i] == lista[j])
				{
					for (int k = j; k < max - 1; ++k)
						lista[k] = lista[k + 1];

					--max;
				}
				else
					++j;
			}
		for (int i = 0; i < max; i++) {
			cout << lista[i] << endl;
		}
	}

	// 3. Overload Unary operator ‘++’ such that all characters are changed to its uppercase equivalents.

	string operator++(string);

	string operator++(string, int);

	void ToUppercase() {
		string a = "alma";
		string b = "This is a sentence!";
		cout << ++a << " " << ++b << endl;
		cout << a++ << " " << b++ << endl;
	}

	string operator++(string s) {
		int len = s.length();
		string tmp = "";
		for (int i = 0; i < len; i++) {
			tmp += toupper(s[i]);
		}
		return tmp;
	}

	string operator++(string s, int) {
		int len = s.length();
		string tmp = "";
		for (int i = 0; i < len; i++) {
			tmp += toupper(s[i]);
		}
		return tmp;
	}

	// 4. Overload Unary operator ‘--’ such that all the characters are changed to its lowercase equivalents.

	string operator--(string);

	string operator--(string, int);

	void ToLower() {
		string a = "ALMA";
		string b = "THIS IS A SENTENCE!";
		cout << --a << " " << --b << endl;
		cout << a-- << " " << b-- << endl;
	}

	string operator--(string s) {
		int len = s.length();
		string tmp = "";
		for (int i = 0; i < len; i++) {
			tmp += tolower(s[i]);
		}
		return tmp;
	}

	string operator--(string s, int) {
		int len = s.length();
		string tmp = "";
		for (int i = 0; i < len; i++) {
			tmp += tolower(s[i]);
		}
		return tmp;
	}

	// 5. Develop method charAt (int n). It should return the nth character from the string.

	char charAt(string, int);

	void GetNthChar() {
		string a = "alma";	
		cout << charAt(a, 2) << endl;
	}

	char charAt(string s, int n) {
		return s[n];
	}

	// 6. Write a method to check whether any white space character is present in the string.

	bool ContainWhitespace(string);

	void IsInWhitespace() {
		string s = "This is a long \n sentence!";
		string s2 = "alma";
		cout << ContainWhitespace(s2) << endl;
	}

	bool ContainWhitespace(string s) {
		string::iterator it;
		for (it = s.begin(); it != s.end(); ++it) {
			if (iswspace(*it)) {
				return true;
			}
		}
		return false;
	}

	// 7. Write a function test to check if newline (‘\n’) character is part of a string.

	bool ContainNewLine(string);

	void CheckNewLine() {
		string s = "This is a long \n sentence!";
		string s2 = "alma";
		cout << ContainNewLine(s2) << endl;
	}

	bool ContainNewLine(string s) {
		string::iterator it;
		for (it = s.begin(); it != s.end(); ++it) {
			if (*it == '\n') {
				return true;
			}
		}
		return false;
	}

	// 8. Write a method toString() to convert string object to ordinary string (C-string).

	class String_5
	{
	public:
		String_5();
		String_5(char *);
		~String_5();
		char* toString();
	private:
		int len;
		char a[80];
	};

	String_5::String_5(){
		len = 0;
	}

	String_5::String_5(char * p) {
		int i;
		i = 0;
		while ((p[i] != '\0') && (i<80))
		{
			a[i] = p[i];
			i++;
		}
		len = i;
	}

	String_5::~String_5() {}

	void StringToString() {
		String_5 s = "alma";
		char* ret = s.toString();
		for (char* p = ret; *p != '\0'; ++p)
			cout << *p;
	}

	char* String_5::toString() {
		//for (int i = 0; i < this->len; i++) {
		//	p[i] = this->a[i];
		//}
		//p[this->len] = '\0';
		//for (char* p = this->a; p != this->a + this->len; ++p) {
		//	cout << *p << endl;
		//}

		return this->a;
	}

}
