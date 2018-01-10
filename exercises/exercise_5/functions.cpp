#include "functions.h"

#include <iostream>

using std::cout;
using std::endl;

void print_arr(int *arr, unsigned len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

unsigned set_power(char *mask)
{
	unsigned counter = 0;
	for (unsigned i = 0; mask[i] != '\0'; i++)
		if (mask[i] == '1')
			counter++;
	return counter;
}

unsigned set_diff_power(int *set_a, unsigned size_a, int *set_b, unsigned size_b)
{
	unsigned cnt = 0, i, j;
	for (i = 0; i < size_a; i++)
	{
		for (j = 0; j < size_b; j++)
			if (set_a[i] == set_b[j])
				break;
		if (j == size_b)
			cnt++;
	}
	return cnt;
}

void set_diff(int *set_a, unsigned size_a, int *set_b, unsigned size_b, int *set_r)
{
	unsigned k = 0, i, j;
	for (i = 0; i < size_a; i++)
	{
		for (j = 0; j < size_b; j++)
			if (set_a[i] == set_b[j])
				break;
		if (j == size_b)
			set_r[k++] = set_a[i];
	}
}