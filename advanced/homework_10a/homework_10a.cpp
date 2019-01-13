#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

#define FN 87134

int main()
{
	string input;
	while (getline(cin, input))
	{
		stringstream stream(input);

		unsigned m = 0;
		unsigned n = 0;
		unsigned k = 0;

		stream >> m >> n >> k;

		srand(FN % 100);
		vector<int> numbers;
		for (size_t i = 1; i <= m; i++)
		{
			numbers.push_back(rand() % k);
		}
		sort(numbers.begin(), numbers.end());

		cout << numbers[n - 1] << endl;
	}

	return 0;
}