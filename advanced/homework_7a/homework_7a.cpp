#include "pch.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int firstSum = 0;
int secondSum = 0;
int minRes = 0;
void findMinRec(const vector<unsigned>& arr, int i, int sumCalculated, int sumTotal)
{
	if (i == 0)
	{
		int res = abs((sumTotal - sumCalculated) - sumCalculated);
		if (res < minRes)
		{
			minRes = res;
			firstSum = sumTotal - sumCalculated;
			secondSum = sumCalculated;

			if (firstSum > secondSum)
			{
				swap(firstSum, secondSum);
			}
		}

		return;
	}

	findMinRec(arr, i - 1, sumCalculated + arr[i - 1], sumTotal);
	findMinRec(arr, i - 1, sumCalculated, sumTotal);
}

void findMin(const vector<unsigned>& arr)
{
	int sumTotal = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sumTotal += arr[i];
	}

	minRes = sumTotal;
	findMinRec(arr, arr.size(), 0, sumTotal);
}

int main()
{
	string input;
	while (getline(cin, input))
	{
		istringstream stream(input);

		vector<unsigned> chests;
		unsigned currentChest = 0;
		while (stream >> currentChest)
		{
			chests.push_back(currentChest);
		}

		findMin(chests);
		cout << firstSum << " " << secondSum << endl;
	}

	return 0;
}