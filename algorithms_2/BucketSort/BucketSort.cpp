#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float Max(float arr[], int len)
{
	float max = arr[0];

	for (size_t i = 1; i < len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

float Min(float arr[], int len)
{
	float min = arr[0];

	for (size_t i = 1; i < len; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	return min;
}

float Abs(float num)
{
	if (num < 0)
	{
		return -num;
	}

	return num;
}

void BucketSort(float arr[], int len)
{
	float absMin = Abs(Min(arr, len));
	for (size_t i = 0; i < len; i++)
	{
		arr[i] += absMin;
	}

	vector<float>* b = new vector<float>[len];

	for (size_t i = 0; i < len; i++)
	{
		int bi = (len * arr[i]) / (Max(arr, len) + 1);
		b[bi].push_back(arr[i]);
	}

	for (size_t i = 0; i < len; i++)
	{
		sort(b[i].begin(), b[i].end());
	}

	int index = 0;
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 0; j < b[i].size(); j++)
		{
			arr[index++] = b[i][j];
		}
	}

	for (size_t i = 0; i < len; i++)
	{
		arr[i] -= absMin;
	}
}

int main()
{
	const int len = 5;
	float arr[len] = { 5, -4, 3, -2, 1 };

	BucketSort(arr, len);

	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
		 
	return 0;
}