#include "pch.h"
#include <iostream>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

// 2001 is the maximum number we can calculate with ((1 + sin(0.1*i))*k) + 1
const unsigned maxPrimes = 10000;
bool primes[maxPrimes + 1];
vector<unsigned> primeNumbers;

class PrimeSum
{
private:
	unsigned a;
	unsigned b;
public:
	PrimeSum(unsigned a, unsigned b) : a(a), b(b) {};

	bool operator==(const PrimeSum& other)
	{
		return (this->a == other.a && this->b == other.b) ||
			(this->a == other.b && this->b == other.a);
	}
};

void GeneratePrimes()
{
	fill(begin(primes), end(primes), true);
	primes[0] = false;
	primes[1] = false;

	unsigned current = 0;
	unsigned multiple = 0;
	for (current = 2; current * current <= maxPrimes; current++)
	{
		if (primes[current] == true)
		{
			for (multiple = current * 2; multiple <= maxPrimes; multiple += current)
			{
				primes[multiple] = false;
			}
		}
	}

	for (size_t i = 2; i <= maxPrimes; i++)
	{
		if (primes[i] == true)
		{
			primeNumbers.emplace_back(i);
		}
	}
}

bool HasElement(const vector<PrimeSum>& data, PrimeSum searched)
{
	for (auto element : data)
	{
		if (searched == element)
		{
			return true;
		}
	}

	return false;
}

unsigned CountPrimeAdditions(unsigned number)
{
	vector<PrimeSum> checked;

	for (unsigned firstPrime : primeNumbers)
	{
		for (unsigned secondPrime : primeNumbers)
		{
			if (firstPrime + secondPrime == number)
			{
				PrimeSum sum(firstPrime, secondPrime);
				bool result = HasElement(checked, sum);
				if (result == false)
				{
					checked.emplace_back(sum);
				}
			}
		}
	}

	return checked.size();
}

int main()
{
	GeneratePrimes();

	unsigned number = 0;
	while (cin >> number)
	{
		cout << CountPrimeAdditions(number) << " ";
	}

	return 0;
}
