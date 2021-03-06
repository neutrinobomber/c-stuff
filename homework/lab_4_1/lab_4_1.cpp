#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

void add_symbols(string& input_str, int& number_of_times, char symbol)
{
	for (int i = 1; i <= number_of_times; ++i)
	{
		input_str = symbol + input_str;
	}
}

void first_task()
{
	int side = 0;
	char symbol = '-';
	cout << "side: ";
	cin >> side;
	cout << "symbol: ";
	cin >> symbol;

	for (int i = 1; i <= side; ++i)
	{
		int spaces = side - i;
		int symbols = i > 2 && i < side ? i - 2 : 0;

		string spaces_str = "";
		string symbols_str = "";

		add_symbols(spaces_str, spaces, ' ');
		add_symbols(symbols_str, symbols, symbol);

		if (i < side)
			spaces_str += "*";
		
		spaces_str += symbols_str;

		if (i == side)
			add_symbols(spaces_str, side, '*');
		else if (i > 1)
			spaces_str += "*";

		cout << spaces_str << endl;
	}

	cout << endl;
}

void second_task()
{
	int input = 0, negatives_sum = 0, positives_sum = 0;

	do
	{
		cout << "number: ";
		cin >> input;

		if (input < -1000 || input > 1000)
		{
			cout << "number must be between -1000 and 1000" << endl;
			continue;
		}

		if (input > 0)
			positives_sum += input;
		else if (input < 0)
			negatives_sum += input;
	} while (input != 0);

	cout << "negatives sum: " << negatives_sum << endl;
	cout << "positives sum: " << positives_sum << endl;
}

int main()
{
	first_task();
	second_task();

    return 0;
}