#include "common.h"

Bank::Bank()
{
	amount = 0;
	intervall = 0;
	rate = 0;
}

Bank::Bank(int a, int i, int r)
{
	amount = a;
	intervall = i;
	rate = r;
}

Bank::~Bank()
{
}

void Bank::setAmount(int a) {
	amount = a;
}

int Bank::getAmount() {
	return amount;
}

void Bank::setIntervall(int i) {
	intervall = i;
}

int Bank::getIntervall() {
	return intervall;
}

void Bank::setRate(int r) {
	rate = r;
}

int Bank::getRate() {
	return rate;
}

Investment::Investment() : Bank()
{
}

Investment::Investment(int a, int i, int r) : Bank(a, i, r)
{
}

Investment::~Investment()
{
}

double getInterest(Investment i) {
	
	double interest_unit = i.amount * ((double)i.rate / 100);
	double interest = interest_unit * i.intervall;

	return interest;
}

Loan::Loan() : Bank()
{
}

Loan::Loan(int a, int i, int r) : Bank(a, i, r)
{
}

Loan::~Loan()
{
}

double getInstalment(Loan l) {

	double instalment = (double)l.amount / (double)l.intervall;

	return instalment;
}

double getRedemption(Loan l) {

	double extra_cost = l.amount * (double)l.rate;
	double full_cost = l.amount * extra_cost;
	double redemptio = full_cost / l.intervall;

	return redemptio;
}