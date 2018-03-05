#include <iostream>
#include <string>
#include "ChapterTwo.h"
#include "ChapterThree.h"
#include "ChapterFive.h"
#include "ChapterSix.h"
#include "ChapterSeven.h"
#include "ChapterEight.h"
#include "ChapterNine.h"
#include "ChapterTen.h"
#include "ChapterEleven.h"

void Exit();

int main(int argc, char *argv[]) {

	ChapterTen::PointInLine();
	
	Exit(); 
	return 0;
}

void Exit() {
	bool exit = true;
	std::string str;
	while (exit)
	{
		std::cin.clear();
		std::cout << "\nDo you want exit: (y/n)";
		getline(std::cin, str);
		const char *cstr = str.c_str();
		if (*cstr == 'y')
			exit = false;
	}
}