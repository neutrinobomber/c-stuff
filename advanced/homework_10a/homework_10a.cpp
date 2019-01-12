#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>

#define FN 87134

int main()
{
	srand(FN % 100);

	std::string input;
	while (std::getline(std::cin, input))
	{
		std::stringstream stream(input);

		unsigned m = 0;
		unsigned n = 0;
		unsigned k = 0;

		stream >> m >> n >> k;

		std::vector<int> numbers;
		for (size_t i = 1; i <= m; i++)
		{
			numbers.push_back(rand() % k);
		}
		sort(numbers.begin(), numbers.end());
		std::cout << numbers[n - 1] << std::endl;
	}

	return 0;
}