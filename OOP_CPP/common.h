
class Bank
{
public:
	Bank();
	Bank(int, int, int);
	~Bank();

	void setAmount(int);
	int getAmount();
	void setIntervall(int);
	int getIntervall();
	void setRate(int);
	int getRate();

protected:
	int amount;
	int intervall;
	int rate;
};

class Investment: public Bank
{
public:
	Investment();
	Investment(int, int, int);
	~Investment();
	friend double getInterest(Investment);
};

double getInterest(Investment);

class Loan: public Bank
{
public:
	Loan();
	Loan(int, int, int);
	~Loan();
	friend double getInstalment(Loan);
	friend double getRedemption(Loan);
};

class Time
{
public:
	Time();
	Time(int, int, int);
	Time(long);
	~Time();
	void set_time();
	void set_time(int, int, int);
	void show_time();
	friend int compare(Time tx, Time ty); //---1---
private:
	int hr, min, sec;
};

class Date
{
public:
	Date();
	Date(int, int, int);
	Date(std::string);
	~Date();
	void Init();
	void Init(int, int, int y = 2003);
	void showDate();
private:
	int day, month, year;
};

class Complex
{
public:
	Complex();
	Complex(int, int);
	~Complex();
	void setRe(int);
	int getRe();
	void setIm(int);
	int getIm();
	void show();
	void init();
	friend Complex addComplex(Complex, Complex);
	friend Complex multiComplex(Complex, Complex);
	friend Complex conjugateComplex(Complex);
	friend Complex subtactComplex(Complex, Complex);
	friend Complex divideComplex(Complex, Complex);

private:
	int real, imaginary;
};

class String
{
public:
	String();
	String(int, char[]);
	~String();

private:
	int length;
	char str[80];
};




