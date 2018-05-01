

class Investment
{
public:
	Investment();
	Investment(int, int, int);
	~Investment();
	void setDeposit(int);
	int getDeposit();
	void setRate(int);
	int getRate();
	void setTime(int);
	int getTime();

private:
	int deposit;
	int rate;
	int time;
};

double getInterest(Investment);
