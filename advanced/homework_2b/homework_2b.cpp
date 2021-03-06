#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

// map used for caching results
map<ull, bool> primeTable;
bool IsPrime(ull number)
{
	if (primeTable.find(number) != primeTable.end())
	{
		return primeTable[number];
	}

	bool result = false;
	if (number < 2)
	{
		primeTable.insert(pair<ull, bool>(number, result));
		return result;
	}

	ull i = 2;
	while (i * i <= number) 
	{
		if (number % i == 0)
		{
			primeTable.insert(pair<ull, bool>(number, result));
			return result;
		}

		++i;
	}

	result = true;
	primeTable.insert(pair<ull, bool>(number, result));
	return result;
}

unsigned CountPrimes(ull k, unsigned n)
{	
	unsigned count = 0;
	ull number = 0;

	unsigned i = 0;
	for (i = 1; i <= n; i++)
	{
		number = static_cast<ull>(((1 + sin(0.1 * i)) * k) + 1);
		cout << number << endl;

		if (IsPrime(number))
		{
			count++;
		}
	}

	return count;
}

int main()
{
	ull k = 0;
	unsigned n = 0;

	while (cin >> k >> n)
	{
		cout << CountPrimes(k, n) << endl;
	}

	return 0;
}