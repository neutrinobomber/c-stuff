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
	if (Func(right, param) * Func(left, param) < 0)
	{
		bool foundMid = false;
		ld mid = 0;
		ld currentDistance = 0;
		ld previousDistance = 0;

		do
		{
			mid = (left + right) / 2;

			if (Func(right, param) * Func(mid, param) > 0)
			{
				right = mid;
			}
			else
			{
				left = mid;
			}

			foundMid = Func(mid, param) == 0;
			previousDistance = currentDistance;
			currentDistance = abs(left - right);
		} while (currentDistance > delta && currentDistance != previousDistance && foundMid == false);

		cout << setprecision(20) << fixed << mid << endl;
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

	while (cin >> a)
	{
		FindRoot(0, 10, delta, a);
	}

	return 0;
}
