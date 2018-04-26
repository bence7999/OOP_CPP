#include "ChapterTwenty.h"

using namespace std;

namespace ChapterTwenty {

	/// 20.2.1 Formatting the source code
	/// 20.1 No formatting for source code
	// 

	void NoFormatted() {
		int marks = 55; cout << "<-- - ifthen1.cpp--->" << endl; if (marks >= 50) if (marks >= 60) 	cout << "First class" << endl; else cout << "Second class" << endl;
		else if (marks >= 40) cout << "Pass class" << endl; else cout << "Fails" << endl;
	}

	///
	/// 20.2 Formatted source code
	//

	void Formatted() {
		int marks = 55;
		cout << "<-- - ifthen1.cpp--->" << endl;
		if (marks >= 50)
			if (marks >= 60) 
				cout << "First class" << endl;
			else 
				cout << "Second class" << endl;
		else if (marks >= 40) 
			cout << "Pass class" << endl;
		else 
			cout << "Fails" << endl;
	}

	///////////////////////////
	////       TASKS       ////
	/////////////////////////// 

	// 1. Study your own various indentation styles such as ANSI, K&R, etc.

	// 2. Describe any two external characteristics of a good program.

	// 3. Describe any four internal characteristics of a good program.

	// 4. Write a short note on coding discipline.

}