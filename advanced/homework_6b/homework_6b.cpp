#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool CustomCompare(const string& first, const string& second)
{
	return first.size() < second.size();
}

int main()
{
	int count = 0;
	while (cin >> count)
	{
		vector<string> elements;
		int n = count - 1;

		while (count > 0)
		{
			string element;
			cin >> element;
			elements.push_back(element);

			count--;
		}

		sort(elements.begin(), elements.end(), CustomCompare);
		
		int midIdx = n / 2;
		int nextIdx = midIdx + 1;
		string mid = elements[midIdx];
		string next = elements[nextIdx];

		if (mid == next)
		{
			cout << mid << endl;
		}
		else
		{
			cout << "---" << endl;
		}
	}

	return 0;
}