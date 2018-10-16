#include "pch.h"
#include <iostream>

using namespace std;

int result = 0;
int depth = 0;
void GCD(int a, int b)
{
	if (a % b > 0)
	{
		depth++;
		cout << "depth: " << depth << endl 
			<< "    a: " << a << endl
			<< "    b: " << b << endl;

		GCD(b, a % b);

		depth--;
		cout << "depth: " << depth << endl
			<< "    a: " << a << endl
			<< "    b: " << b << endl;
	}
	else
	{
		result = b;
	}
}

int main()
{
	GCD(54, 100);
	cout << "result: " << result << endl;
}