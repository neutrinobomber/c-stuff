#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int Abs(int num)
{
	if (num < 0)
	{
		return -num;
	}

	return num;
}

int main()
{
	int len = 0;
	cin >> len;

	int* data = new int[len];
	for (size_t i = 0; i < len; i++)
	{
		cin >> data[i];
	}

	int min = data[0];
	int max = data[len - 1];
	for (size_t i = 0; i < len; i++)
	{
		if (data[i] > max)
		{
			max = data[i];
		}

		if (data[i] < min)
		{
			min = data[i];
		}
	}

	int minDist = INT_MAX;
	for (size_t i = 0; i < len; i++)
	{
		int diff = max - min;
		int dist = Abs(diff - data[i]) * Abs(diff - data[i]);

		if (dist < minDist)
		{
			minDist = dist;
		}
	}

	vector<int> minimums;
	for (size_t i = 0; i < len; i++)
	{
		int diff = max - min;
		int dist = Abs(diff - data[i]) * Abs(diff - data[i]);

		if (dist == minDist)
		{
			minimums.push_back(i);
		}
	}

	for (int el : minimums)
	{
		cout << el << " ";
	}

	return 0;
}