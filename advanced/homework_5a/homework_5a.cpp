#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// F87134
// x^5 - 2x^3 - ax^2 - x - 34 = 0

typedef long double ld;

ld Func(ld x, ld a)
{
	return pow(x, 5) - 2 * pow(x, 3) - a * pow(x, 2) - x - 34;
}

void FindRoot(ld left, ld right, ld delta, ld param)
{
	ld res = 0.0;

	res = Func(left, param) * Func(right, param);
	if (res < (ld)0.0)
	{
		bool foundMid = false;
		ld mid = 0.0;
		ld distance = 0.0;

		do
		{
			mid = (left + right) / (ld)2.0;

			res = Func(right, param) * Func(mid, param);
			if (res < (ld)0.0)
			{
				left = mid;
			}
			else
			{
				right = mid;
			}

			foundMid = Func(mid, param) == (ld)0.0;
			distance = abs(left - right);
		} while (distance > delta && foundMid == false);

		cout << setprecision(20) << mid << endl;
	}
	else
	{
		cout << "NO SOLUTION" << endl;
	}
}

int main()
{
	ld a = 1;
	ld delta = 0.00000000000000000001;
	cout << delta << endl;

	while (cin >> a)
	{
		FindRoot(0, 10, delta, a);
	}

	return 0;
}
