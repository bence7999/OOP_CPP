
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
	~Time();
	void set_time(int, int, int);
	void show_time();
	friend int compare(Time tx, Time ty); //---1---
private:
	int hr, min, sec;
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
	friend Complex addComplex(Complex a, Complex b);
	friend Complex multiComplex(Complex a, Complex b);

private:
	int real, imaginary;
};


