#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long ull;
unsigned CountPrimesInInterval(ull start, ull end)
{
	if (start == 0)
	{
		return 0;
	}

	vector<bool> prime(end + 1);
	fill(prime.begin(), prime.end(), true);

	for (ull p = 2; p * p <= end; p++)
	{
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == true)
		{
			// Update all multiples of p 
			for (ull i = p * 2; i <= end; i += p)
			{
				prime[i] = false;
			}
		}
	}

	unsigned count = 0;
	for (ull p = start; p < end; p++)
	{
		if (prime[p])
		{
			count++;
		}
	}

	return count;
}

int main()
{
	ull b = 0;
	vector<ull> inputs { 2, 10 };
	//while (cin >> b)
	//{
	//	inputs.emplace_back(b);
	//}

	if (inputs.size() == 0)
	{
		cout << 0;
	}

	for (auto el : inputs)
	{
		cout << CountPrimesInInterval(el, el * 2) << endl;
	}

	return 0;
}