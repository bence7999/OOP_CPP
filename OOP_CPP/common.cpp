#include "common.h"

Investment::Investment()
{
	deposit = 0;
	rate = 0;
	time = 0;
}

Investment::Investment(int d, int r, int t)
{
	deposit = d;
	rate = r;
	time = t;
}

Investment::~Investment()
{
}

void Investment::setDeposit(int d) {
	deposit = d;
}

int Investment::getDeposit() {
	return deposit;
}

void Investment::setRate(int r) {
	rate = r;
}

int Investment::getRate() {
	return rate;
}

void Investment::setTime(int t) {
	time = t;
}

int Investment::getTime() {
	return time;
}

double getInterest(Investment i) {

	double interest_unit = i.getDeposit() * ((double)i.getRate() / 100);
	double interest = interest_unit * i.getTime();

	return interest;
}