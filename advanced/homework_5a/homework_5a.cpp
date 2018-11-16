#include "pch.h"
#include <iostream>

using namespace std;

// F87134
// x^5 - 2x^3 - ax^2 - x - 34 = 0

long double Func(long double x, long double a)
{
	return pow(x, 5) - 2 * pow(x, 3) - a * pow(x, 2) - x - 34;
}

void FindRootBinary(long double left, long double right, long double delta, long double param)
{
	if (Func(left, param) * Func(right, param) < 0)
	{
		bool foundMid = false;
		long double mid = 0;
		long double distance = 0;

		do
		{
			mid = (left + right) / 2.;

			if (Func(right, param) * Func(mid, param) < 0)
			{
				left = mid;
			}
			else
			{
				right = mid;
			}

			foundMid = Func(mid, param) == 0.;
			distance = fabs(left - right);
		} while (!(distance <= delta || foundMid == true));

		cout << mid << endl;
	}
	else
	{
		cout << "NO SOLUTION" << endl;
	}
}

int main()
{
	long double a = 1;
	FindRootBinary(0, 10, pow<long double, long double>(10, -20), a);

	return 0;
}
