#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
	ull pointsCount = 1;
	while (cin >> pointsCount)
	{
		vector<ll> points;
		ll point = 0;
		for (ull i = 0; i < pointsCount; i++)
		{
			cin >> point;
			points.push_back(point);
		}

		ull minCount = 0;
		ull maxCount = 0;

		for (ull currentIdx = 1; currentIdx < points.size() - 1; currentIdx++)
		{
			ll currentPoint = points[currentIdx];
			ll previousPoint = points[currentIdx - 1];
			ll nextPoint = points[currentIdx + 1];

			if (currentPoint < previousPoint && currentPoint < nextPoint)
			{
				minCount++;
			}
			else if (currentPoint > previousPoint && currentPoint > nextPoint)
			{
				maxCount++;
			}
		}

		cout << minCount << " " << maxCount << endl;
	}

	return 0;
}
