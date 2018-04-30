#include <iostream>
#include "graphics.h"

using namespace std;

extern void put_image(int x, int y, void *duck, int z);

class CURSOR
{
private:
	int xcor, ycor;
public:
	void * ptr;
	void init();
	void show();
	void down();
	void up();
	void left();
	void right();
	void friend set_cor(int &xpos, int & ypos, CURSOR A);
	void set_cor(int x, int y);
};
void CURSOR::set_cor(int x, int y)
{
	xcor = x;
	ycor = y;
};
void CURSOR::show()
{
	putimage(xcor*SIZE, ycor*SIZE, ptr, XOR_PUT);
}
void CURSOR::down()
{
	show();
	if (ycor < no_rows - 1) ycor++;
	else beep();
	show(); // = hide cursor
}
void CURSOR::up()
{
	show();
	if (ycor > 0) ycor--;
	else beep();
	show();
};
void CURSOR::left()
{
	show();
	if (xcor > 0) xcor--;
	else beep();
	show();
};
void CURSOR::right()
{
	show();
	if (xcor < no_cols - 1) xcor++;
	else beep();
	show();
};
void CURSOR::init()
{
	ptr = cursorA;
	// memcpy(ptr,cursorA,Dsize) ;
	xcor = 0; ycor = 0;
}
void set_cor(int &xpos, int & ypos, CURSOR A)
{
	xpos = A.xcor;
	ypos = A.ycor;
};