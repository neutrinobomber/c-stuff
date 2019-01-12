#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>

using namespace std;

string RemoveDuplicates(const string& input)
{
	string result = "";

	auto res = set<char>(input.begin(), input.end());
	for (auto el : res)
	{
		result += el;
	}

	return result;
}

unsigned CountNotAnagrams(vector<string>& input)
{
	if (input.size() == 1)
	{
		return 1;
	}

	set<string> notInAnagram;
	for (auto el : input)
	{
		string cleaned = RemoveDuplicates(el);
		notInAnagram.insert(cleaned);
	}

	return notInAnagram.size();
}

int main()
{
	string input = "";
	while (getline(cin, input))
	{
		stringstream stream(input);
		vector<string> elements;
		string inputString = "";
		while (stream >> inputString)
		{
			elements.push_back(inputString);
		}
		
		cout << CountNotAnagrams(elements) << endl;
	}

	return 0;
}