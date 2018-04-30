#include <iostream>
#include<conio.h>
#include<dos.h>

using namespace std;

enum keytype
{
	FUNCT, ORDINARY, RETURN, UP, DOWN,
	LEFT, RIGHT, HOME, PGUP,
	END, PGDN, INS, DEL, BS,
	ESCAPE, CTRLK, OTHERS
};

void getkey(keytype & key, char & x)
{
	x = _getch();
	if (x == 0) /* extended key */
	{
		x = _getch();
		switch (x)
		{
		case 59: case 60: case 61: case 62: case 63:
		case 64: case 65: case 66: case 67:
		case 68: key = FUNCT; break;
		case 72: key = UP; break;
		case 75: key = LEFT; break;
		case 77: key = RIGHT; break;
		case 80: key = DOWN; break;
		case 71: key = HOME; break; /* home*/
		case 73: key = PGUP; break; /* Pg Up */
		case 79: key = END; break; /* End*/
		case 81: key = PGDN; break; /* PgDn*/
		case 82:key = INS; break;
		case 83:key = DEL; break;
		default: key = OTHERS; break;
		}; // end of case
	}
	else // ordinary key
	{
		key = ORDINARY;
		switch (x)
		{
		case 27: key = ESCAPE; break;
		case 13: key = RETURN; break;
		case  8: key = BS; break;
		case 11: key = CTRLK; break; // for ^k is build here
		};
	};
}

/* getkey */