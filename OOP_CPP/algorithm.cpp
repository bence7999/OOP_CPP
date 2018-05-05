#include "algorithm.h"

int LowestCommonMultiple(int n1, int n2) {
	int minMultiple;
	minMultiple = (n1>n2) ? n1 : n2;

	while (true)
	{
		if (minMultiple % n1 == 0 && minMultiple % n2 == 0)
		{
			return minMultiple;
			break;
		}
		++minMultiple;
	}
}

int GreatestCommonDivisor(int m, int n) {
	if (n == 0) return m;
	else if (n > m) GreatestCommonDivisor(n, m);
	else GreatestCommonDivisor(n, m%n);
}