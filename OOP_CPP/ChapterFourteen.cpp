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
}