#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef unsigned long ul;

void PrintRotate(const string& data, ul rotations)
{
	ul index = rotations % data.size();
	ul prints = data.size() > 10 ? 10 : data.size();
	while (prints--)
	{
		cout << data[index++ % data.size()];
	}
}

int main()
{
	string data = " ";
	while (cin >> data)
	{
		string rotationsStr = "";

		while (cin >> rotationsStr)
		{
			istringstream stream(rotationsStr);
			ul rotations = 0;

			if (stream >> rotations)
			{
				PrintRotate(data, rotations);
				cout << endl;
			}
			else
			{
				data = rotationsStr;
				continue;
			}
		}
	}

	return 0;
}