#include "ChapterEighteen.h"

using namespace std;

namespace ChapterEighteen {

	/// 18.4 WORKING OF EXCEPTION HANDLING MECHANISM
	/// 18.1 Exception
	// Write a program to demonstrate simple exception handling.

	void Excep3() {
		int i = 3, j = 0, k = 3;
		cout << "<-- - excep3.cpp--->" << endl;

		try
		{
			if (j == 0) throw 4;
			k = i / j;
			cout << k << endl;
		}
		catch (int k)
		{
			cout << "exception caught" << endl;
		};
		cout << "val of k = " << k << endl;
	}

	/// 18.5 CATCHING ALL EXCEPTIONS
	/// 18.2 Catch with ellipsis
	// Write a program to demonstrate the use of catch with ellipsis.

	void Excep4() {
		int i = 3, j = 0, k = 3;
		cout << "<-- - excep4.cpp--->" << endl;
		try
		{
			if (j == 0) throw 2.44;
			k = i / j;
			cout << k << endl;
		}
		catch (int k)
		{
			cout << " integer exception caught" << endl;
		}
		catch (...)
		{
			cout << " general exception caught" << endl;
		};
		cout << "val of k = " << k << endl;
	}

	/// 18.6 OBJECT AS EXCEPTION
	/// 18.3 Object as exception
	// Write a program to demonstrate throwing an object as exception.

	class myException
	{
	public:
		int key;
		myException() { key = 4; };
		void show()
		{
			cout << "key is " << key << endl;
		};
	};

	void Excep5() {
		int i = 3, j = 0, k = 3;
		cout << "<-- - excep5.cpp-- - >" << endl;
		try
		{
			if (j == 0) throw new myException();
			k = i / j;
			cout << k << endl;
		}
		catch (myException *ex1)
		{
			cout << "myException caught" << endl;
			ex1->show();
		}
		catch (...)
		{
			cout << " general exception caught" << endl;
		};
		cout << "val of k = " << k << endl;
	}

	/// 18.8 EXCEPTION SPECIFICATION
	/// 18.4 Exception specification
	// Write a program to demonstrate that a function can specify which exceptions may be thrown during its exception.

	class myException2 : public exception
	{
	public:
		char* what()
		{
			return "File Not Found Exception";
		};
	};

	void file_open(ifstream &f1, char * str1) throw (myException2 *)
	{
		cout << "file_open starts" << endl;
		f1.open(str1);
		//throw 3; // note 1
		if (!f1) throw new myException2;
		else cout << "file opened Successfully" << endl;
	}

	void Excep7C() {
		ifstream f1;
		cout << "<-- - excep7C.cpp--->" << endl;
		try
		{
			file_open(f1, "XYZT.txt");
			cout << "try block ends" << endl;
		}
		catch (myException2 *ex1)
		{
			cout << "myException caught" << endl;
			cout << ex1->what() << endl;
		}
		catch (...)
		{
			cout << " general exception caught" << endl;
		};
		cout << "reached the end of program" << endl;
	}

	///////////////////////////
	////       TASKS       ////
	///////////////////////////
	
	// 1. What is an exception? How is an exception handled in C++?

	// 2. Can we place two or more catch blocks together to catch and handle multiple types of exceptions thrown by a try block? If your answer is yes, describe the syntax.

	// 3. Is it possible to recover from an error using catch block? Give reasons.

	// 4. What is the use of catch block with ellipsis as parameter?

	// 5. Why catch clause with ellipsis is always the last catch clause?

	// 6. Can a function specify what exception it may throw? What will happen if exception of some different type eventually gets thrown?

	// 7. What do you understand by the term “stack unwinding”?

	// 8. Why throw statement is always a part of an “if statement”?

	// 9. What happens when an exception is thrown from outside the try block?

	// 10. Write a program that illustrates the application of multiple catch statements.

	class MostSpecificException : public exception
	{
	public:
		char* what()
		{
			return "This is a most specified exception!";
		};
	};

	class LessSpecificException : public exception
	{
	public:
		char* what()
		{
			return "This is a less specified exception!";
		};
	};

	void MultipleCatch() {

		try
		{
			int a = 1;

			if (a == 5)
				throw new MostSpecificException;
			else if (a == 3)
				throw new LessSpecificException;
			else if (a == 1)
				throw new exception;
		}
		catch (MostSpecificException *e)
		{
			cout << "MostSpecificException caught" << endl;
			cout << e->what() << endl;
		}
		catch (LessSpecificException *e)
		{
			cout << "LessSpecificException caught" << endl;
			cout << e->what() << endl;
		}
		catch (exception *e)
		{
			cout << "Standard Exception caught" << endl;
			cout << e->what() << endl;
		}
		catch (...)
		{
			cout << " general exception caught" << endl;
		}
		cout << "end of program!" << endl;
	}

	// 11. Develop a class TextFile to open text files for reading or writing. For input files, if file is not found, throw an exception “FileNotFound”. For output files, if file exists throw “FileExists” exception.

	class FileExists;
	class FileNotFound;

	class TextFile
	{
	public:
		TextFile(string);
		~TextFile();
		void read();
		void write();
		void rename(string);
		bool fcheck();
	private:
		string name;
		const string extension = "txt";
	};

	TextFile::TextFile(string fileName)
	{
		name = fileName;
	}

	TextFile::~TextFile()
	{
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

	void TextFile::rename(string new_name) {
		name = new_name;
	}

	bool TextFile::fcheck() {
		ifstream ifile(name);
		return (bool)ifile;
	}

	class FileNotFound : public exception
	{
	public:
		char* what()
		{
			return "File not found";
		};
	};

	class FileExists : public exception
	{
	public:
		char* what()
		{
			return "File found";
		};
	};

	void FileException() {
		TextFile *tf = new TextFile("test");
		try
		{
			if (tf->fcheck())
				throw new FileExists;
			else
				throw new FileNotFound;
		}
		catch (FileNotFound *e)
		{
			cout << e->what() << endl;
		}
		catch (FileExists *e)
		{
			cout << e->what() << endl;
		}
		catch (...)
		{
			cout << " general exception caught" << endl;
		}
	}

	// 12. Develop class complex. Overload operator ‘/’ for division. It should throw “DivideByZero” exception in appropriate situation.

	class DivideByZero
	{
	public:
		char* what()
		{
			return "DivideByZero";
		};
	};

	class Complex
	{
	public:
		Complex(int, int);
		Complex();
		~Complex();
		void show();
		Complex operator/(Complex);
	private:
		float real, imaginary;
	};

	Complex::Complex(int re, int im)
	{
		real = re;
		imaginary = im;
	}

	Complex::Complex()
	{
		real = 0;
		imaginary = 0;
	}

	Complex::~Complex()
	{
	}

	Complex Complex::operator/(Complex c) {
		Complex tmp;
		float quotient = c.real * c.real + c.imaginary * c.imaginary;
		float real = this->real*c.real + this->imaginary*c.imaginary;
		float imaginary = -1 * this->real*c.imaginary + this->imaginary*c.real;
		try
		{
			if (real != 0)
				tmp.real = real / quotient;
			else
				throw new DivideByZero;
			
			if (imaginary != 0)
				tmp.imaginary = imaginary / quotient;
			else 
				throw new DivideByZero;

			return tmp;
		}
		catch (DivideByZero *e)
		{
			cout << e->what() << endl;
		}
		catch (const std::exception&)
		{
			cout << " general exception caught" << endl;
		}
		exit(0);
	}

	void Complex::show() {
		cout << this->real << " + " << this->imaginary << "i" << endl;
	}

	void ComplexTest() {
		Complex c1(3, 2);
		Complex c2(4, -3);

		c1.show();
		c2.show();

		Complex c3 = c1 / c2;
		c3.show();


	}

	// 13. Write a program to demonstrate that a catch block is responsible for destroying all the objects created inside try block, before exception is thrown.

	void TestOfDestroying() {
		try
		{
			Complex a(1, 1);

		}
		catch (int k)
		{
			//a.show();
		}
	}

	// 14. Design simple class BankAccount. If amount to be withdrawn is greater than balance, throw “InsufficentBalance” exception.

	class InsufficentBalance
	{
	public:
		char* what()
		{
			return "InsufficentBalance";
		};
	};

	class BankAccount
	{
	public:
		BankAccount();
		~BankAccount();

	private:

	};

	BankAccount::BankAccount()
	{
	}

	BankAccount::~BankAccount()
	{
	}

}