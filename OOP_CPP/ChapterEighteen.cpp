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


}