#include "ChapterFourteeen.h"

using namespace std;

namespace ChapterFourteen {

	/// 14.4.1 Reading and writing text files
	/// 14.1 Reading and writing text files
	// Write a program to read a text file and copy it to another (output) file character by character.

	void Copy1() {
		char ch;
		ifstream f1("input.txt");
		if (!f1)
		{
			cout << "Cannot open input.txt for input" << endl;
			cout << " quitting the program";
			exit(1);
		}
		ofstream f2("output.txt");
		// no checking required
		while (f1.get(ch))
		{
			f2.put(ch);
		}
		f1.close();
		f2.close();
	}

	/// 14.4.2 Reading numeric data from text file
	/// 14.2 Reading data from text file I
	// A bank has stored the amounts of deposits gathered in a day in a text file "textin.dat". 
	// Write the program to read this file and calculate (1) total amount deposited; and (2) average of the deposits. 
	// (It is known that there are 10 deposits. However, program should not assume this fact.)

	void Tread2() {
		int i;
		float deposit, average, sum;
		ifstream f1("textin.dat");
		cout << "<-- - tread2.cpp--->" << endl;
		if (!f1) cout << "Cannot open textin.dat for input" << endl;
		i = 0; sum = 0.0;
		cout << "Reading from file textin.dat " << endl;
		while (f1 >> deposit)
		{
			cout << deposit << endl;
			sum += deposit;
			i++;
		}
		cout << "Number of deposits = " << i << endl;
		average = sum / i;
		cout << "Total deposits gathered = " << sum << endl;
		cout << "average = " << average << endl;
	}

	/// 14.4.3 Writing data to text file
	/// 14.3 Writing to text file
	//  Write a program to find how amount grows with compound interest. Store the output in a file.

	void Fw1() {
		float amount = 1000.0;
		float rate = 0.08;
		ofstream f2;
		f2.open("f2out.txt"); //file created
		f2.precision(2);
		f2.setf(ios::fixed, ios::floatfield);
		f2 << "<-- - fw1.cpp--->" << endl;
		f2 << "Year Amount" << endl;
		for (int i = 1; i<10; i++)
		{
			amount = amount + amount * rate;
			f2 << i << ") " << amount << endl;
		}
		f2.close();
	}

	/// 14.4.4 Reading and writing strings
	/// 14.4 Reading and writing strings
	// Write a program to study reading and writing strings (using text file).

	void Stread() {
		char str1[80];
		cout << "<-- - stread.cpp--->" << endl;
		ifstream f1("input.txt");
		if (!f1)
		{
			cout << "File input.txt does not exists!" << endl;
			cout << "aborting the program … press any key" << endl;
			exit(0);
		}
		ofstream f2("output.txt");
		while (!f1.eof())
		{
			f1 >> str1;
			f2 << str1 << " ";
		}
		f1.close();
		f2.close();
		cout << "program over" << endl;
	}

	/// 14.5.1 Reading and writing binary files: file of Integer
	/// 14.5 File of integers
	//  Write a program to create a file storing squares of first 10 natural numbers. The file should be binary files. Next, the file should be read and contents displayed on the screen.

	void Int1() {
		int i, k;
		cout << "<-- - int1.cpp--->" << endl;
		//creating binary file
		ofstream f2("integer.out", ios::binary);
		for (i = 1; i <= 10; i++)
		{
			k = i * i;
			f2.write((char *)&k, 2);
		}
		f2.close();
		// reading binary file
		ifstream f1("integer.out", ios::binary);
		while ((f1.read((char *)&k, 2)))
		{
			cout << k << endl;
		}
	}

	/// 14.5.2 Binary files for object
	/// 14.6 Binary files: file of object POINT
	//  Write a program to study creation of binary files to store objects. Define a class Point. Define one object of this class. Write it to a file. 
	//  To verify, read back from the file, this object (in a different object variable) and print it.

	class Point
	{
		int xc, yc;
	public:
		Point();
		Point(int i, int j);
		void show();
	};

	void Point1() {
		Point pt2; // for reading
		cout << "<-- - point1.cpp--->" << endl;
		// an object will be created
		Point pt1(20, 25);
		pt1.show();
		ofstream f2("point1.bf", ios::binary);
		cout << "File point1.bf has been created" << endl;
		// now we will put object in a file
		f2.write((char *)& pt1, sizeof(Point));
		f2.close();
		// now the same file is opened for input
		ifstream f1("point1.bf");
		cout << "now the same file is opened for reading" << endl;
		f1.read((char *)& pt2, sizeof(Point));
		cout << "now showing the point" << endl;
		pt2.show();
	}

	Point::Point(int i, int j)
	{
		xc = i;
		yc = j;
	}

	Point::Point() //default constructor
	{
		xc = 0;
		yc = 0;
	}

	void Point::show()
	{
		cout << "point is : " << setw(2) << xc;
		cout << ", " << setw(2) << yc << endl;
	}

	/// 14.7.2 Sequentially accessing binary file
	/// 14.7 Sequential access file
	//  Write a program to read a binary sequential file and display the ticket information. The program should also calculate total amount collected.

	class Ticket
	{
	protected:
		int key;
		int tclass; //class is reserved word
		int amount;
		char org[10];
		char dest[10];
		char name[27];
	public:
		void show();
		void show1();
		int getAmount();
		Ticket();
		Ticket(int, int, int, char*, char*, char*);
	};

	void upload_bin() {
		Ticket *lst[7];
		lst[0] = new Ticket(1, 1, 200, "Mumbai", "Pune",    "Pradyumna");
		lst[1] = new Ticket(2, 2, 80,  "Mumbai", "Pune",    "Vivek");
		lst[2] = new Ticket(3, 2, 70,  "Mumbai", "Lonavla", "Fredrix");
		lst[3] = new Ticket(4, 1, 140, "Mumbai", "Lonavla", "Daya");
		lst[4] = new Ticket(5, 2, 70,  "Mumbai", "Pune",    "Abhijit");
		lst[5] = new Ticket(6, 1, 200, "Mumbai", "Pune",    "Salunke");
		lst[6] = new Ticket(7, 3, 70,  "kalyan", "Pune",    "Sarika");

		ofstream f2("rail.TKT", ios::binary);
		cout << "File rail.TKT has been created" << endl;
		// now we will put object in a file
		for (int i = 0; i < 7; i++) {
			f2.write((char *)& *lst[i], sizeof(Ticket));
		}
		f2.close();
	}

	void Seq1() {
		int i;
		upload_bin();
		Ticket t1, *ticket_ptr;
		ticket_ptr = &t1;
		long sum = 0;
		cout << "<-- - seq1.cpp--->" << endl;
		ifstream fin("rail.TKT", ios::binary);
		if (!fin) {
			cout << "Cannot open rail.TKT for input";
			exit(1);
		}
		cout << "Processing input file " << endl;
		i = 0;
		fin.read((char*)ticket_ptr, sizeof(t1));
		while (fin.gcount() == sizeof(t1))
		{
			t1.show();
			i++;
			sum = sum + t1.getAmount();
			fin.read((char*)ticket_ptr, sizeof(t1));
		}
		cout << "processed " << i << " records" << endl;
		cout << "Total Amount = " << sum << endl;
		fin.close();
	}

	Ticket::Ticket() {

	}

	Ticket::Ticket(int k, int c, int a, char* o, char *d, char *n) {
		key = k;
		tclass = c;
		amount = a;
		strcpy_s(org, o);
		strcpy_s(dest, d);
		strcpy_s(name, n);
	}

	void Ticket::show()
	{
		cout << setw(3) << key << setw(3) << tclass
			<< setw(6) << amount << setw(10) << org
			<< setw(10) << dest << setw(27) << name
			<< endl;
	}

	int Ticket::getAmount()
	{
		return amount;
	}

	/// 14.7.3 Direct access files
	/// 14.8 Direct access file (only reading)
	//  Write a program for railway supervisor to read any record directly (random manner) from the file "rail.TKT".

	void Direct1() {
		int i; char ch;
		int flag;
		long filePos;
		Ticket t1, *ticketPtr;
		ticketPtr = &t1;
		cout << "<-- - direct1.cpp--->" << endl;
		ifstream finp("rail.TKT", ios::binary);
		if (!finp)
		{
			cout << "Cannot open rail.TKT for input";
			exit(1);
		}
		flag = 1;
		while (flag)
		{
			cout << "give record number between 0 & 6 : ";
			cin >> i;
			if ((i<0) || (i>7))
				cout << "Sorry index outof order" << endl;
			else
			{
				filePos = i * sizeof(Ticket);
				finp.seekg(filePos);
				finp.read((char*)ticketPtr, sizeof(t1));
				ticketPtr->show1();
			}
			cout << "Do you want to continue Y / N ? ";
			ch = _getche();
			cout << endl;   if (toupper(ch) != 'Y') flag = 0;
		}
		finp.close();
	}

	void Ticket::show1()
	{
		cout << " key = " << key << " TCLASS " << tclass << endl;
		cout << "Starting station : " << org << endl;
		cout << "Travel Up to : " << dest << endl;
		cout << "passenger name : " << name << endl;
	}

	/// 14.8 DIRECT ACCESS FILES: SIMULTANEOUS READ WRITE
	/// 14.9 Direct access file - simultaneous read write
	//  Write a seat reservation program using random access file. Consider reservation of coach C1 on any one particular day. Assume that it has 10 seats numbered 1 to 10. Assume following situation:
	// - A passenger comes to booking counter.
	// - He demands a particular seat(number)
	// - Computer checks if seat is available.
	// - If so issues ticket with requested seat number.
	// - If seat is already booked, tourist must request another seat.

	class Seat
	{
	protected:
		int seatno;
		int available;
		int ticket_no;
	public:
		void update(int y, int z);
		int isAvailable();
		void show();
	};

	void Seat::update(int y, int z)
	{
		available = y;
		ticket_no = z;
	}

	int Seat::isAvailable()
	{
		int temp = 0;
		if (available == 1) temp = 1; ;
		return temp;
	}

	void Seat::show()
	{
		cout << setw(5) << seatno << " ";
		if (available) cout << setw(10) << "vacant " << endl;
		else cout << setw(10) << "booked "
			<< setw(10) << ticket_no << endl;
	}

	void Queen2() {
		int i, k, pos;//,k,num;
		int request = 0;
		int data[] = { 3, 5, 6, 3, 4 };
		int ticket_number = 501;
		int nbytes;
		Seat temp;
		cout << "<-- - queen2.cpp--->" << endl;
		nbytes = sizeof(Seat);
		fstream frand("dqc1.dat", ios::binary | ios::in | ios::out);
		if (!frand) {
			cout << "error error error " << endl;
			exit(0);
		}
		// live transaction starts 10 in number
		while (request < 5)
		{
			k = data[request++];
			cout << "Requested seat number : " << k << endl;
			pos = k - 1; //one means zero!
			frand.seekg(nbytes * pos); //…1
			frand.read((char *)&temp, nbytes);
			// temp.show();
			if (temp.isAvailable()) // seat available
			{
				temp.update(0, ticket_number);
				frand.seekp(nbytes * pos); // …2 very important
				frand.write((char *)&temp, nbytes); // to file
				cout << "Seat reserved ";
				cout << "Ticket number " << ticket_number << endl;
				// temp.show();
				ticket_number++;
			}
			else
				cout << " sorry this seat is booked" << endl;
			_getch();
		}
		frand.close();
		// printing summary
		ifstream frand1("dqc1.dat", ios::binary | ios::in);
		cout << "Printing summary " << endl;
		cout << "seat no status ticket_no" << endl;
		// frand1.seekg(nbytes * 0 );
		for (i = 1; i <= 10; i++)
		{
			frand1.read((char *)&temp, nbytes);
			temp.show();
		}
		frand1.close();
	}

	/// 14.10 Errors and error handling in file operation
	/// 14.10 Errors in file handling
	//  Write a program to demonstrate file errors.

	void Ferror1() {
		char ch;
		cout << "<-- - ferror1.cpp--->" << endl;
		ifstream f1;
		cout << "opening NON existent file " << endl;
		f1.open("Absent.txt");
		cout << "result is : ";
		if (f1.good()) cout << "good"; else cout << "----";
		if (f1.bad()) cout << ": bad"; else cout << "----";
		if (f1.fail()) cout << " : fail" << endl; else cout << "----" << endl;
		ch = 'B';
		cout << "now reading from non opened file" << endl;
		f1.get(ch);
		cout << "character is->" << ch << "<-" << endl;
		if (f1.good()) cout << "good"; else cout << "----";
		if (f1.bad()) cout << ": bad"; else cout << "----";
		if (f1.fail()) cout << " : fail" << endl; else cout << "----" << endl;
		f1.close();
	}

	/// 14.11 Destructor releases resource
	// Write a problem to demonstrate that a file is a resource.

	class Process
	{
		int procNo;
	public:
		ofstream f1;
		Process(int n)
		{
			cout << "constructor called - acquiring resource" << endl;
			procNo = n;
			f1.open("output.txt");
			if (!f1)
			{
				cout << "Cannot open input.txt for input" << endl;
				cout << " quitting the program";
				exit(1);
			}
			char ch = 'M';
			f1.put(ch);
			// cout<<"f1::ch is :" << ch <<endl;
		};
		~Process()
		{
			cout << "Destructor called : releasing resource " << endl;
			f1.close();
		};
		void show()
		{
			cout << procNo << endl;
		}
		;
	};

	void Error2() {
		char ch;
		cout << "<-- - error2.cpp--->" << endl;
		Process myPro(1); // opens file
						  //myPro.Process::~Process() ; // note 1 call to destructor
		cout << "now opening file again" << endl;
		ifstream f2("output.txt");
		if (!f2)
		{
			cout << "Cannot open f2 = output.txt for input" << endl;
			cout << " quitting the program";
			exit(1);
		}
		cout << "result is : ";
		if (myPro.f1.good()) cout << "good"; else cout << "----";
		if (myPro.f1.bad()) cout << ": bad"; else cout << "----";
		if (myPro.f1.fail()) cout << ": fail" << endl; else cout << "----" << endl;
		ch = 'B';
		cout << "now reading file" << endl;
		f2.get(ch);
		cout << "character is->" << ch << "<-" << endl;
		if (f2.good()) cout << "result is good" << endl;
		if (f2.bad()) cout << "result is bad" << endl;
		if (f2.fail()) cout << "result is fail" << endl;
		myPro.f1.close();
		f2.close();
	}

	/// 14.12.1 Encrypt a file
	/// 14.12 File encryption
	//	Read a text file and encrypt it.

	void Encrypt() {
		char x, y;
		cout << "<-- - encrypt.cpp--->" << endl;
		ifstream f1("encr_inp.TXT");
		ofstream f2("encr_out.TXT");
		if (!f1)
		{
			cout << "Cannot open encr_inp.TXT for input";
			exit(0);
		}
		if (!f2)
		{
			cout << "Cannot open encr_out.TXT for output";
			exit(0);
		}
		while (f1.get(x))
		{
			y = ~x;
			f2.put(y);
			_putch(y);
		}
		f1.close();
		f2.close();
		_getch();
	}

	/// 14.12.2 Splitting and joining a large file
	/// 14.13 File splitting
	// Write a program to split a large file in to one MB fragments.

	#define LIMIT 10

	void Split() {
		int not_over = 1, step = 0;
		const long OneM = 1024000;
		long count = 0;
		char fname[20];
		char temp[2];
		int k;
		char * onames[LIMIT] = { "a.0", "a.1", "a.2", "a.3", "a.4", "a.5", "a.6", "a.7", "a.8", "a.9" };
		cout << "<-- - split.cpp--->" << endl;
		cout << "give file name to split : ";
		cin >> fname;
		ifstream finp(fname, ios::binary);
		if (!finp) {
			cout << "Cannot open specified file for input";
			exit(0);
		}
		cout << "Splitting file " << fname << endl;
		while (not_over && (step < LIMIT))
		{
			ofstream fout(onames[step], ios::binary);
			count = 0;
			while (count < OneM)
			{
				if ((k = finp.get()) == EOF) break;
				fout.put(k);
				count++;
			}
			cout << " count = " << count << endl; // for debugging
			if (finp.eof()) not_over = 0;
			fout.close();
			step = step + 1; //next file
		}
	}

	/// 14.14 File joining
	// Write a program to join the fragments and reconstruct the original file.

	void Fjoin1() {
		int not_over = 1, step = 0;
		long count = 0, master = 0;
		int k;
		char fname[20];
		char * onames[LIMIT] = { "a.0", "a.1", "a.2", "a.3", "a.4",	"a.5", "a.6", "a.7", "a.8", "a.9" };
		cout << "<-- - fjoin1.cpp--->" << endl;
		cout << "give file name : ";
		cin >> fname;
		ofstream fout(fname, ios::binary);
		if (!fout)
		{
			cout << "Cannot create specified file for output";
			exit(0);
		}
		cout << "All sub files would be joined" << endl;
		cout << "and would be in " << fname << endl;
		cout << "copying starts" << endl;
		while (not_over && (step < LIMIT))
		{
			ifstream fin(onames[step], ios::binary);
			if (!fin)
			{
				cout << "Cannot open specified file for input" << endl;
				not_over = 0;
				break;
			}
			count = 0;
			while (!fin.eof())
			{
				if ((k = fin.get()) == EOF) break;
				fout.put(k);
				master++;
				count++;
			}
			cout << "step : " << step;
			cout << " count : " << count << endl;
			fin.close();
			step = step + 1; //next file to be opened
		}
		cout << " Final file size in bytes : " << master << endl;
		fout.close();
	}

	///////////////////////////
	////       TASKS       ////
	///////////////////////////

	// 1. What are the various methods of classifying files ?

	// 2. What are the advantages of binary file ?

	// 3. What are the advantages of text files ?

	// 4. What are the advantages of Random Access Files ?

	// 5. What are the operations on files ? Illustrate with examples.

	// 6. Describe various classes available for file operations.

	// 7. How do we check for errors upon opening a file and output the correct error message ?

	// 8. Write a program to read bio - data from the console and write to a file. Filename should be accepted from command line.

	void ReadAndWriteBio() {
		string filname;

		cout << "give me the name of the output file: ";
		cin >> filname;

		ofstream f;
		f.open(filname);

		cout << "give me bio - data, to wirte to file: (q is end of data)" << endl;

		string tmp;
		while (true)
		{
			getline(cin, tmp);
			if (tmp == "q")
				break;
			f << tmp << endl;
		}
		f.close();
	}

	// 9. Create a class “TextFile” for handling text files.

	class TextFile
	{
	public:
		TextFile();
		TextFile(string);
		~TextFile();
		void read();
		void write();
		void rename(string);
	private:
		string name;
		const string extension = "txt";
	};

	TextFile::TextFile()
	{
	}

	TextFile::TextFile(string n) {
		name = n;
	}

	TextFile::~TextFile()
	{
	}

	void TextFile::rename(string new_name) {
		name = new_name;
	}

	void TextFile::read() {
		char str[80];
		ifstream f(name + "." + extension);
		if (!f) {
			cout << "Cannot open " << name << "." << extension << " for input" << endl;
			cout << " quitting the program";
			exit(1);
		}
		while (!f.eof())
		{
			f >> str;
			cout << str;
		}
		f.close();
	}

	void TextFile::write() {
		string str;
		ofstream f;
		f.open(name + "." + extension);
		while (true)
		{
			getline(cin, str);
			if (str == "q")
				break;
			f << str << endl;
		}
		f.close();
	}

	void TestOfTextFile() {
		TextFile *tf = new TextFile("sample");
		tf->write();
		tf->read();
	}

	// 10. Write a program to read your name roll number, address, physics, chemistry, and maths marks from keyboard and place it in file.

	void NameAndEtcToFile() {
		string name, address, tmp;
		int roll_num, phy, chem, mat;

		cout << "give me your name: ";
		getline(cin, name);
		cin.clear();
		cout << name << endl;
		cout << "give me your roll number: ";
		cin >> roll_num;
		getline(cin, tmp);
		cin.clear();
		cout << roll_num << endl;
		cout << "give me your address: ";
		getline(cin, address);
		cin.clear();
		cout << address << endl;
		cout << "give me your physics, chemistry and math marks one by one: " << endl;
		cin >> phy >> chem >> mat;

		ofstream f("data.txt");
		f << "Name of student: " << name << endl << "Roll number: " << roll_num << endl << "Address: " << address << endl;
		f << "Subjets: " << endl << "physics: " << phy << endl << "chemistry: " << chem << endl << "maths: " << mat << endl;
	}

	// 11. Write a function named fcheck() that checks whether a file exists. The function should be passed a file name. If the file exists, the function should return a value of 1, otherwise a value 0.

	bool fcheck(string fname) {
		ifstream ifile(fname);
		return (bool)ifile;
	}

	void TestCheck() {
		string f1 = "input.txt";
		string f2 = "point1.bf";
		string f3 = "err.err";

		cout << fcheck(f1) << endl;
		cout << fcheck(f2) << endl;
		cout << fcheck(f3) << endl;
	}

	// 12. a) Write a program to store the following numbers into a file named “result.dat” 16.25, 18.96, 22.34, 18.94, 17.42, 22.63

	const string float_f= "result.dat";

	void WriteFloat() {
		const int len = 6;
		float arr[len] = { 16.25, 18.96, 22.34, 18.94, 17.42, 22.63 };
		ofstream f;
		f.open(float_f);
		f.precision(2);
		f.setf(ios::fixed, ios::floatfield);
		for (int i = 0; i < len; i++) {
			f << arr[i] << endl;
		}
		f.close();
	}

	//     b) Write a program to read the data from “result.dat” and display the data. Additionally, the program should calculate the number of items and average of data.

	void ReadFloat() {
		ifstream f(float_f);
		float num, sum = 0;
		int item = 0;
		if (!f)
		{
			cout << "Cannot open input.txt for input" << endl;
			cout << " quitting the program";
			exit(1);
		}
		while (f >> num)
		{
			cout << num << endl;
			sum += num;
			item++;
		}
		cout << "number of items: " << item << ", average: " << sum / item << endl;
	}

	void CheckFloat() {
		WriteFloat();
		ReadFloat();
	}

	// 13. Write a program that counts and prints the total number of characters(bytes) in a given file.The program should ask the user to enter the file name.

	void PrintSize() {
		string fname;
		int sum = 0;
		cout << "give me the name of the file: ";
		cin >> fname;
		if (!fcheck(fname)) {
			cout << "Cannot open input.txt for input" << endl;
			cout << " quitting the program";
			exit(1);
		}
		ifstream f(fname);
		char ch;
		while (f.get(ch)) {
			sum++;
		}
		cout << "total number of characters in the given file: " << sum << endl;
		f.close();
	}

	// 14. Write a program that reads a text file and displays ‘n’ characters starting from any position in a file. 
	//     The program should accept three user entered items : the name of the file, the offset of the first character to be read, and the number of the characters to be read.

	void PrintNCharacters(string fname, int offset, int numOfItems) {
		if (!fcheck(fname)) {
			cout << "Cannot open input.txt for input" << endl;
			cout << " quitting the program";
			exit(1);
		}
		ifstream f(fname);
		char ch;
		f.seekg(offset);
		while (f.get(ch) && numOfItems > 0) {
			cout << ch;
			numOfItems--;
		}
	}

	void TestCharOffset() {
		PrintNCharacters("input.txt", 4, 15);
	}

	// 15. Assume that a data file is a large text file. Write a program that will read integer n, and display nth line on the screen.
	//     The above action should be in a loop. A negative number should terminate the loop.

	void ReadNthLine(int n) {
		string fname = "test.txt";
		if (!fcheck(fname)) {
			cout << "Cannot open input.txt for input" << endl;
			cout << " quitting the program";
			exit(1);
		}
		string tmp;
		ifstream f(fname);
		for (int i = 0; i < n; ++i)
			getline(f, tmp);

		getline(f, tmp);
		cout << tmp << endl;
	}

	void TestReadLine() {
		ReadNthLine(5);
		ReadNthLine(13);
		ReadNthLine(20);
		ReadNthLine(2);
	}

	// 16. Write a C++ program “displ.cpp” to display the contents of a random file beginning with the location you specify on the command line.

	void getDir(const char* d, vector<string> & f)
	{
		FILE* pipe = NULL;
		string pCmd = "dir /B /S " + string(d);
		char buf[256];

		if (NULL == (pipe = _popen(pCmd.c_str(), "rt")))
		{
			cout << "Shit" << endl;
			return;
		}
		while (!feof(pipe))
		{
			if (fgets(buf, 256, pipe) != NULL)
			{
				f.push_back(string(buf));
			}

		}
		_pclose(pipe);
	}

	void Displ(int argc, char* argv[]) {
		time_t* t = new time_t;
		srand(std::time(t));

		vector<string> files;

		getDir(argv[1], files);

		//cout << files.size() << endl;

		//cout << "Printing Dir" << endl;
		//ector<string>::const_iterator it = files.begin();

		int random_variable = rand();
		int file_num = random_variable % 25;
		string fname = files[file_num];
		fname.erase(fname.find_last_not_of(" \n\r\t") + 1);
		if (!fcheck(fname)) {
			cout << "Cannot open input.txt for input" << endl;
			cout << " quitting the program";
			exit(1);
		}
		string str;
		ifstream f(fname);
		while (!f.eof())
		{
			f >> str;
			cout << str;
		}
		f.close();

		/*while (it != files.end())
		{
			cout << *it << endl << endl;
			it++;
		}*/
	}

	// 17. Write a program to create a data file containing the following information:

	class DataFile
	{
	public:
		DataFile();
		DataFile(int, int, int, string);
		~DataFile();

	private:
		int Sr_no, Merit_no, total_marks;
		string name;
	};

	DataFile::DataFile()
	{
		Sr_no = 0;
		Merit_no = 0;
		total_marks = 0;
		name = "";
	}

	DataFile::DataFile(int sr, int merit, int total, string n) {
		Sr_no = sr;
		Merit_no = merit;
		total_marks = total;
		name = n;
	}

	DataFile::~DataFile()
	{
	}

	void StoreDataFile() {
		DataFile* df[3];
		df[0] = new DataFile(1, 03, 92, "Sunil");
		df[1] = new DataFile(2, 02, 98, "Anil");
		df[2] = new DataFile(3, 01, 99, "Mahesh");

		ofstream f("DataFile.data", ios::binary);
		for (int i = 0; i < 3; i++) {
			f.write((char *)& df[i], sizeof(DataFile));
		}
		f.close();
	}

	// 18. Write a program to generate directory of doctors in Mumbai city. The entries must be name of the doctor, telephone number of doctor, and his specialization. Generate suitable array. 
	//     The member elements should be accessed by pointer type operator.

	class Doctor
	{
	public:
		Doctor();
		Doctor(string, string, int);
		~Doctor();

	private:
		string name, specialization;
		long telephon;
		string place = "Mumbai";
	};

	Doctor::Doctor()
	{
		name = ""; 
		specialization = "";
		telephon = 0;
	}

	Doctor::Doctor(string n, string s, int t) {
		name = n;
		specialization = s;
		telephon = t;
	}

	Doctor::~Doctor()
	{
	}

	void DoctorDirectory() {
		const int max = 100;
		Doctor* Directory[max];
	}

	// 19. Write a program to encrypt and decrypt text files such that encrypted file contains only printable characters. Assume that input also consists of only printable characters.

	void EncryptText(string &fname) {
		if (!fcheck(fname)) {
			cout << "Cannot open input.txt for input" << endl;
			cout << " quitting the program";
			exit(1);
		}
		ifstream f(fname);
		ofstream f2("enc_t.txt");
		char x, y;
		while (f.get(x))
		{
			y = ~x;
			f2.put(y);
		}
		f.close();
		f2.close();
	}

	void DescriptText(string &fname) {
		if (!fcheck(fname)) {
			cout << "Cannot open input.txt for input" << endl;
			cout << " quitting the program";
			exit(1);
		}
		ifstream f(fname);
		char x, y;
		while (f.get(x))
		{
			y = ~x;
			cout << y;
		}
		f.close();
	}

	void CheckEncDescText() {
		string fname = "sample.txt";
		EncryptText(fname);
		string dfname = "enc_t.txt";
		DescriptText(dfname);
	}

	// 20. Write an interactive, file-oriented program that will maintain a list of names, address and telephone numbers in alphabetic order. 
	//     Process the information associated with each name as a separate record. Represent each record as a structure. Include a menu that will allow the user to select any of the following features.
	//     1. Add a new record
	//     2. Delete a record
	//     3. Modify an existing record
	//     4. Retrieve and display an entire record for a given name
	//     5. Generate a complete list of all names, addresses, and telephone numbers

	struct MemberData
	{
		string name;
		string address;
		long telephone;
	};

	MemberData* addNewRecord() {
		string name, address, tmp;
		float telephone;
		getline(cin, tmp);
		cout << "\nAdd new record:\n  give me a name: ";
		getline(cin, name);
		cout << "  give me an address: ";
		getline(cin, address);
		cout << "  give me a telephone number: ";
		cin >> telephone;
		cout << endl;

		MemberData* new_data = new MemberData();
		new_data->name = name;
		new_data->address = address;
		new_data->telephone = telephone;
		return new_data;
	}

	void deleteRecord(MemberData* md[]) {

	}

	void modifyRecord(MemberData* md[], int &size) {
		string tmp;
		cout << "give me a value of a member from the element what you want to modify: ";
		cin >> tmp;
		MemberData* local[100];
		int tmp_size = 0;
		for (int i = 0; i < size; i++) {
			if (md[i]->name.find(tmp) != string::npos) {
				local[tmp_size] = md[i];
				tmp_size++;
				continue;
			}
			else if (md[i]->address.find(tmp) != string::npos) {
				local[tmp_size] = md[i];
				tmp_size++;
				continue;
			}
			else if (to_string(md[i]->telephone).find(tmp) != string::npos) {
				local[tmp_size] = md[i];
				tmp_size++;
				continue;
			}
		}
		int index = -1;
		if (tmp_size > 1) {
			for (int i = 0; i < tmp_size; i++) {
				cout << 1 << ". Name: " << local[i]->name << ", Address: " << local[i]->address << ", telephone number: " << local[i]->telephone << endl;
			}
			cout << "give me the index of requuired element: ";
			cin >> index;
			while (true)
			{
				if (index > tmp_size) {
					cout << "index error, try again: ";
					cin >> index;
				}
				else {
					break;
				}
			}
			
		}
		int memb = -1;
		cout << "what member what you want to modify:\n  1. name, 2. address, 3. telephone number, 0. end of modify\nnum:";
		cin >> memb;
		string str;
		long lng;
		switch (memb)
		{
		case 1:
			cout << "give me the new name:";
			getline(cin, str);
			local[index]->name = str;
			break;
		case 2:
			cout << "give me the new name:";
			getline(cin, str);
			local[index]->address = str;
			break;
		case 3:
			cout << "give me the new phone number:";
			cin >> lng;
			local[index]->telephone = lng;
			break;
		default:
			cout << "wrong number!";
			break;
		}

	}

	void reseveRecord(MemberData* md[]) {
		string tmp;
		cout << "give me a name, what you want to disply: ";
		getline(cin, tmp);
	}

	void dispalyAllList(MemberData* md[], int& size) {
		if (size <= 0) {
			cout << "the contact list is empty!" << endl << endl;
			return;
		}
		for (int i = 0; i < size; i++) {
			cout << i+1 << ". Name: " << md[i]->name << ", address: " << md[i]->address << ", phone number: " << md[i]->telephone << "!" << endl;
		}
		cout << "end of contact list!" << endl << endl;
	}

	void FileOrentedProgram() {
		const int max = 100;
		int size = 0;
		MemberData* contact[max];
		bool exit = true;
		int next = -1;
		string introduction = "For new record press 1\nFor delete record press 2\nFor modify record press 3\nFor retrieve and disply an etire by name press 4\nFor generate a complete list for all data press 5\nFor exit press 0\n\n" ;
		
		while (exit)
		{
			cout << introduction << endl << "cmd: ";
			cin >> next;
			switch (next)
			{
			case 0:
				exit = false;
				break;
			case 1:
				if (size < max) {
					contact[size] = addNewRecord();
					size++;
				}
				else {
					cout << "the list is full!" << endl;
				}
				break;
			case 2:
				deleteRecord(contact);
				break; 
			case 3:
				modifyRecord(contact, size);
				break; 
			case 4:
				reseveRecord(contact);
				break;
			case 5:
				dispalyAllList(contact, size);
				break;
			default:
				cout << "Wrong number, try again!" << endl << endl;
				break;
			}
		}
		
	}

	// 21. Modify the programs split.cpp and fjoin1.cpp with following specifications.
	//     1. The files split will be in separate sub-directory.
	//     2. A file “info.txt” stores necessary information.
	//     3. This information should be used while joining files.



	// 22. Consider two large data files both containing values from 1 to 1000000. The first one is a text file while other is a binary file. 
	//     Use class BPtimer to compare times to read these files. (Hint – First write a pilot program to create these data files.)

}