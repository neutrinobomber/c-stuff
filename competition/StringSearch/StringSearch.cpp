#include "pch.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<char> elements;
vector<char> currentVariation;
vector<vector<char>> variations;

void CalculateVariations(size_t index)
{
	if (index >= currentVariation.size())
	{
		variations.emplace_back(currentVariation);
	}
	else
	{
		for (size_t i = 0; i < elements.size(); i++)
		{
			currentVariation[index] = elements[i];
			CalculateVariations(index + 1);
		}
	}
}

void SetUpData()
{
	currentVariation.resize(elements.size() - 1);
}

void ResetData()
{
	elements.clear();
	currentVariation.clear();
	variations.clear();
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		istringstream is{ line };
		string expression;
		cin >> expression;
		unsigned order = 0;
		cin >> order;

		for (auto letter : expression)
		{
			elements.emplace_back(letter);
		}

		SetUpData();
		CalculateVariations(0);
		ResetData();
	}

	return 0;
}
