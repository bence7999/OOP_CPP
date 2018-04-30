#include <iostream>
#include <string>

using namespace std;

typedef char str20[20];

class Planet
{
private:
	int num;
	str20 name;
public:
	void init(int n, str20 namex);
	Planet();
	char * display();
};

void Planet::init(int n, str20 namex)
{
	num = n;
	strcpy_s(name, namex);
}

Planet::Planet()
{}

char * Planet::display()
{
	return name;
}

Planet planet[12];

void init_planet()
{
	planet[0].init(0, "Sun");
	planet[1].init(1, "Moon");
	planet[2].init(2, "Mars");
	planet[3].init(3, "Mercury");
	planet[4].init(4, "Jupiter");
	planet[5].init(5, "Venus");
	planet[6].init(6, "Saturn");
	planet[7].init(7, "Dragon\'s head");
	planet[8].init(8, "Dragon\'s tail");
	planet[9].init(9, "Hershel");
	planet[10].init(10, "Neptune");
	planet[11].init(11, "Pluto");
}

class Sign
{
private:
	int num;
	str20 name;
public:
	void init(int n, str20 namex);
	Sign();
	char * display();
};

char * Sign::display()
{
	return name;
}

void Sign::init(int n, str20 namex)
{
	num = n;
	strcpy_s(name, namex);
}

Sign::Sign()
{}

Sign x[12];

void init_sign()
{
	x[0].init(1, "Aries");
	x[1].init(2, "Taurus");
	x[2].init(3, "Gemini"),
	x[3].init(4, "Cancer"),
	x[4].init(5, "Leo"),
	x[5].init(6, "Virgo"),
	x[6].init(7, "Libra"),
	x[7].init(8, "Scorpio"),
	x[8].init(9, "Sagittarius"),
	x[9].init(10, "Capricorn"),
	x[10].init(11, "Aquarius"),
	x[11].init(12, "Pisces");
	return;
}

// This array specifies the planet number for a given sign
int lord[12] = { 2,5,3,1,0,3,5,2,4,6,6,4 };

int valid1to12(int n)
{
	int ans = 1; // valid
	if (n < 1) ans = 0;
	if (n > 12) ans = 0;
	return ans;
}
