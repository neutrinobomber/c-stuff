// exercise_5.cpp : Defines the entry point for the console application.
//

#include "functions.h"

#include <iostream>

using namespace std;

int main()
{
	const unsigned len = 5;
	int set[len] = { 1, 2, 3, 4, 5 };
	const unsigned sublen = 3;
	int subset[sublen] = { 1, 3, 5 };

	char mask[6] = "10101";
	cout << "power: " << set_power(mask) << endl;

	cout << "set U: ";
	print_arr(set, len);
	cout << "set A: ";
	print_arr(subset, sublen);
	int * set_r = NULL;
	unsigned sz_r = set_diff_power(set, len, subset, sublen);
	set_r = new int[sz_r];
	set_diff(set, len, subset, sublen, set_r);
	print_arr(set_r, sz_r);
    return 0;
}