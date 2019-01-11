#include "pch.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	srand(87134 % 100);

	string input;
	while (getline(cin, input))
	{
		stringstream stream(input);

		unsigned m = 0;
		unsigned n = 0;
		unsigned k = 0;

		stream >> m >> n >> k;

		vector<unsigned> numbers;
		for (size_t i = 0; i < m; i++)
		{
			numbers.emplace_back(rand() % k);
		}
		sort(numbers.begin(), numbers.end());

		cout << numbers[n - 1] << endl;
	}

	return 0;
}