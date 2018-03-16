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
#include "ChapterTwelve.h"
#include "ChapterThirteen.h"
#include "ChapterFourteeen.h"
#include "ChapterFifteen.h"
#include "ChapterSixteen.h"

void Exit();

int main(int argc, char *argv[]) {

	ChapterFourteen::Fjoin1();
	
	Exit(); 
	return 0;
}

void Exit() {
	std::string str;
	while (true)
	{
		std::cin.clear();
		std::cout << "\nDo you want exit: (y/n)";
		getline(std::cin, str);
		const char *cstr = str.c_str();
		if (*cstr == 'y')
			break;
	}
}