#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 10;

class Mat10
{
protected:
	int X[MAX][MAX];
	int N;
public:
	friend void multiply(Mat10 A, Mat10 B, Mat10 &C);
	void show();
	Mat10();
	Mat10(int dimN);
	void init(int box[], int num); // initialisation
	void set(int i, int j, int val);
	int get(int i, int j);
	int getN();
	int is_diagonal(); // 1 true 0 false
};

void Mat10::init(int box[], int lim)
{
	int i, j;
	for (i = 0; i< lim; i++)
		for (j = 0; j< lim; j++)
			set(i, j, box[j + i * lim]);
}

Mat10::Mat10(int dimN)
{
	int i, j, val;
	N = dimN; //actual dimension
	for (i = 0; i< N; i++)
		for (j = 0; j< N; j++)
		{
			cout << " specify mat[" << i << "][" << j << "] : ";
			cin >> val;
			set(i, j, val); ;
		}
}

void Mat10::show()
{
	int i, j, lim;
	lim = getN();
	cout << "Matrix is " << endl;
	for (i = 0; i < lim; i++)
	{
		for (j = 0; j < lim; j++)
		{
			cout << setw(6) << X[i][j];
		}
		cout << endl;
	}
}

Mat10::Mat10()
{
	N = 3;
}

void Mat10::set(int i, int j, int val)
{
	X[i][j] = val;
}

int Mat10::get(int i, int j)
{
	return X[i][j];
}

int Mat10::getN()
{
	return N;
}

int Mat10::is_diagonal()
{
	int i, j;
	int answer = 1;// true;
	for (i = 0; i<N; i++)
		for (j = 0; j<N; j++)
			if ((i != j) && (get(i, j) != 0)) answer = 0; //false
	return answer;
}