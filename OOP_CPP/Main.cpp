#include <iostream>
#include <string>
#include "ChapterTwo.h"


void Exit();

int main() {

	Prime1();

	Exit();
	return 0;
}

void Exit() {
	bool exit = true;
	std::string str;
	while (exit)
	{
		std::cout << "\nDo you want exit: (y/n)";
		std::cin.clear();
		getline(std::cin, str);
		const char *cstr = str.c_str();
		if (*cstr == 'y')
			exit = false;
	}
}