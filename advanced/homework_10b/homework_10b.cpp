#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>

using namespace std;

unsigned maxSize = 1;

unsigned CountAnagrams(vector<string>& input)
{
	unsigned result = 1;

	for (size_t i = 0; i < input.size(); i++)
	{
		for (size_t j = i + 1; j < input.size(); j++)
		{
			if (set<char>(input[i].begin(), input[i].end()) == set<char>(input[j].begin(), input[j].end()))
			{
				return result + 1;
			}
		}
	}

	return result;
}

void SubsetsUtil (
	vector<string>& input,
	vector<string>& subset,
	size_t index)
{
	for (size_t i = index; i < input.size(); i++) 
	{ 
		subset.push_back(input[i]);

		if (maxSize < subset.size() && subset.size() >= 2)
		{
			if (CountAnagrams(subset) < 2 && subset.size() > maxSize)
			{
				maxSize = subset.size();
			}
		}

		SubsetsUtil(input, subset, i + 1);

		subset.pop_back();
	}

	return;
}

void GenerateSubsets(vector<string>& input)
{
	vector<string> subset;

	int index = 0;
	SubsetsUtil(input, subset, index);
}

int main()
{
	string input = "";
	while (getline(cin, input))
	{
		maxSize = 1;

		stringstream stream(input);
		vector<string> elements;
		string inputString = "";
		while (stream >> inputString)
		{
			elements.push_back(inputString);
		}

		GenerateSubsets(elements);
		cout << maxSize << endl;
	}

	return 0;
}