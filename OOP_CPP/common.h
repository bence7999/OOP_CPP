

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

