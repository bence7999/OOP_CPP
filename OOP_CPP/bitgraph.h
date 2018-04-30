#include <iostream>
#include "graphics.h"

using namespace std;

void * cursorA;
void * blank;

void pause()
{
	char ch;
	sound(1000);
	delay(200);
	nosound();
	ch = getch();
	if (ch == 27)
		exit(0);
};
//PART II
unsigned int size1, size2;
void * cube;
void draw_cube(int x, int y, int z)
{
	int i, j;
	for (i = x; i<x + z; i++)
		for (j = y; j<y + z; j++)
			putpixel(i, j, BLUE);
};
void grab_image(int x, int y, void *ABC)
{
	getimage(x, y, x + SIZE, y + SIZE, ABC);
}
void grab_image2(int x, int y, void *ABC)
{
	getimage(x, y, x + SIZE - 2, y + SIZE - 2, ABC);
}
void put_image(int x, int y, void * ABC, int z)
{ // z= XOR_PUT; // dummy statement no effect
	putimage(x + 1, y + 1, ABC, z);
};
void graph_init()
{
	int x = 100, y = 100, i, j;
	/* calculate the size of the image */
	size1 = imagesize(x, y, x + SIZE, y + SIZE);
	size2 = imagesize(x, y, x + SIZE - 2, y + SIZE - 2);
	/* allocate memory to hold the image */
	cube = malloc(size1);
	blank = malloc(size2);
	cursorA = malloc(size2);
	clearviewport();
	grab_image2(10, 10, blank); // define blank
	line(1, 1, SIZE - 1, SIZE - 1);
	line(SIZE - 1, 1, 1, SIZE - 1);
	grab_image(0, 0, cursorA); // define cursor
	draw_cube(x, y, SIZE);
	grab_image(x, y, cube); // define cube
	moveto(200, 200);
	outtext(“ end init”); // for debugging
						  //    pause(); // for debugging
	clearviewport();
	//  draw grill
	for (i = 0; i <= no_rows; i++)
		line(0, i*SIZE, SIZE*no_cols, i*SIZE);
	for (j = 0; j <= no_rows; j++)
		line(j*SIZE, 0, j*SIZE, SIZE*no_cols);
};