#include <iostream>
#include <string>

using namespace std;

typedef char str20[20];

class Attb
{
private:
	int hnum;
	str20 name;
public:
	Attb(int i, str20 str1);
	char * display();
	int get_num();
	friend int init_attributes();
};

Attb::Attb(int i, str20 str1)
{
	hnum = i;
	strcpy_s(name, str1);
}

char * Attb::display()
{
	return name;
}

int Attb::get_num()
{
	return hnum;
}

Attb *attributes[30];

int init_attributes()
{
	attributes[0] = new Attb(1, "Self");
	attributes[1] = new Attb(1, "Personality");
	attributes[2] = new Attb(2, "Finances");
	attributes[3] = new Attb(3, "Brother");
	attributes[4] = new Attb(3, "Sister");
	attributes[5] = new Attb(4, "House");
	attributes[6] = new Attb(4, "Mother");
	attributes[7] = new Attb(4, "Conveyance");
	attributes[8] = new Attb(5, "Children");
	attributes[9] = new Attb(5, "Education");
	attributes[10] = new Attb(6, "Health");
	attributes[11] = new Attb(6, "Service_matters");
	attributes[12] = new Attb(7, "Spouse");
	attributes[13] = new Attb(7, "Marriage");
	attributes[14] = new Attb(8, "Obstacles");
	attributes[15] = new Attb(8, "Longevity");
	attributes[16] = new Attb(9, "Luck");
	attributes[17] = new Attb(9, "Religion");
	attributes[18] = new Attb(10, "Profession");
	attributes[19] = new Attb(11, "Gains");
	attributes[20] = new Attb(12, "Expenses");
	attributes[21] = new Attb(12, "Other_world");
	return 22;
}
