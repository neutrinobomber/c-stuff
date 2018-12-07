#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

void find_lis(vector<unsigned> &input, vector<unsigned> &result)
{
	vector<unsigned> lis(input.size());
	unsigned u = 0;
	unsigned v = 0;

	if (input.empty())
	{
		return;
	}

	result.push_back(0);

	for (size_t i = 1; i < input.size(); i++)
	{
		if (input[result.back()] <= input[i])
		{
			lis[i] = result.back();
			result.push_back(i);
			continue;
		}
   
		for (u = 0, v = result.size() - 1; u < v;)
		{
			unsigned mid = (u + v) / 2;
			if (input[result[mid]] < input[i])
			{
				u = mid + 1;
			}
			else
			{
				v = mid;
			}
		}

		if (input[i] < input[result[u]])
		{
			if (u > 0)
			{
				lis[i] = result[u - 1];
			}
			result[u] = i;
		}
	}

	for (u = result.size(), v = result.back(); u--; v = lis[v])
	{
		result[u] = v;
	}
}

int main()
{
	unsigned len = 0;
	while (cin >> len)
	{
		vector<unsigned> elements;
		unsigned currentElement = 0;
		for (size_t i = 0; i < len; i++)
		{
			cin >> currentElement;
			elements.push_back(currentElement);
		}

		vector<unsigned> res;
		find_lis(elements, res);
		cout << res.size() << endl;
	}

	return 0;
}