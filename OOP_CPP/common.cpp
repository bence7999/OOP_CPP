#include <iostream>
#include "common.h"
#include "string"

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

Time::Time()
{
	hr = 0;
	min = 0;
	sec = 0;
}

Time::Time(int h, int m, int s) {
	hr = h;
	min = m;
	sec = s;
}

Time::Time(long h)
{
	long temp;
	sec = h % 60;
	temp = h / 60;
	min = temp % 60;
	hr = temp / 60;
}

Time::~Time()
{
}

void Time::set_time() {
	hr = 0;
	min = 0;
	sec = 0;
}

void Time::set_time(int h, int m, int s) {
	hr = h;
	min = m;
	sec = s;
}

void Time::show_time() {
	std::cout << hr << " : " << min << " : " << sec << std::endl;
}

int compare(Time tx, Time ty) //---3---
{
	int answer = 0;
	long s1, s2;
	s1 = ((tx.hr * 60) + tx.min) * 60 + tx.sec; //---4---
	s2 = ((ty.hr * 60) + ty.min) * 60 + ty.sec; //---5---
	if (s2 == s1) answer = 1;
	return answer;
}

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int d, int m, int y)
{
	this->day = d;
	this->month = m;
	this->year = y;
}

Date::Date(std::string date)
{
	char delim = ':';

	size_t found = date.find(delim);
	std::string day = date.substr(0, found);
	date = date.substr(found + 1);

	found = date.find(delim, found);
	std::string month = date.substr(0, found);
	date = date.substr(found + 1);

	found = date.find(delim, found);
	std::string year = date.substr(0, found);

	this->day = stoi(day);
	this->month = stoi(month);
	this->year = stoi(year);

}

void Date::Init() {
	std::cout << "Interactive constructor" << std::endl;
	std::cout << "Enter day month year : " << std::endl;
	std::cin >> day >> month >> year;
}

void Date::Init(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

Date::~Date()
{
}

void Date::showDate()
{
	std::cout << day << " / " << month << " / " << year << std::endl;
}

Complex::Complex() {
	real = 0;
	imaginary = 0;
}

Complex::Complex(int re, int im) {
	real = re;
	imaginary = im;
}

Complex::~Complex() {

}

void Complex::setRe(int re) {
	real = re;
}

int Complex::getRe() {
	return real;
}

void Complex::setIm(int im) {
	imaginary = im;
}

int Complex::getIm() {
	return imaginary;
}

void Complex::show() {
	std::cout << real << " + " << imaginary << "j " << std::endl;
}

void Complex::init() {
	int re, im;

	std::cout << "give me real path: ";
	std::cin >> re;

	std::cout << "give me imaginary pah: ";
	std::cin >> im;

	real = re;
	imaginary = im;

}

Complex addComplex(Complex a, Complex b) {
	Complex z;
	z.real = (a.real) + (b.real);
	z.imaginary = (a.imaginary) + (b.imaginary);
	return(z);
}

Complex multiComplex(Complex a, Complex b) {
	Complex z;
	z.real = ((a.real)*(b.real)) - ((a.imaginary)*(b.imaginary));
	z.imaginary = ((a.real)*(b.imaginary)) + ((a.imaginary)*(b.real));
	return(z);
}

Complex conjugateComplex(Complex a) {
	Complex tmp;
	tmp.real = a.real;
	tmp.imaginary = -1 * a.imaginary;
	return tmp;
}

Complex subtactComplex(Complex a, Complex b) {
	Complex tmp;
	tmp.real = (a.real) - (b.real);
	tmp.imaginary = (a.imaginary) - (b.imaginary);
	return tmp;
}

Complex divideComplex(Complex a, Complex b) {
	Complex con = conjugateComplex(b);
	Complex numerator = multiComplex(a, con);
	Complex denominator = multiComplex(b, con);
	Complex tmp;
	tmp.real = numerator.real / denominator.real;
	tmp.imaginary = numerator.imaginary / denominator.real;

	return tmp;
}

String::String()
{
	length = 0;
	str[80] = {};
}

String::String(int l, char c[]) {
	this->length = l;
	strcpy_s(this->str, c);
}

String::~String()
{
}

