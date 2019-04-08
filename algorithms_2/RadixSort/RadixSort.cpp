#include <iostream>

using namespace std;

int Max(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void CountSort(int arr[], int len, int exp)
{
	int* output = new int[len]; 
	int count[10] = { 0 };

	// Store count of occurrences in count[] 
	for (int i = 0; i < len; i++)
	{
		count[(arr[i] / exp) % 10]++;
	}

	// Change count[i] so that count[i] now contains actual 
	//  position of this digit in output[] 
	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	// Build the output array 
	for (int i = len - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (int i = 0; i < len; i++)
	{
		arr[i] = output[i];
	}

	delete[] output;
}

// The main function to that sorts arr[] of size n using  
// Radix Sort 
void RadixSort(int arr[], int len)
{
	// Find the maximum number to know number of digits 
	int max = Max(arr, len);

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		CountSort(arr, len, exp);
	}
}

int main()
{
	const int len = 5;
	int arr[len] = { 5, 100, 4, 2, 200 };

	RadixSort(arr, len);

	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}