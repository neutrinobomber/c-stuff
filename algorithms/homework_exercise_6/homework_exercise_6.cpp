#include "pch.h"
#include <iostream>
#include <chrono>

using namespace std;

void PrintHanoi(int towers, char from, char to, char through)
{
	cout << "moving disc " << towers << " from " << from << " to " << to << endl;
}

unsigned copies = 0;
void Hanoi(int towers, char a, char b, char c)
{
	copies++;

	if (towers > 1)
	{
		Hanoi(towers - 1, a, c, b);

		cout << towers << " " << a << b << c << endl;

		// PrintHanoi(towers, a, b, c);

		Hanoi(towers - 1, c, b, a);
	}
	else
	{
		cout << towers << " " << a << b << c << endl;

		// PrintHanoi(towers, a, b, c);
	}
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	Hanoi(4, 'A', 'B', 'C');

	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = finish - start;

	cout << "made " << copies << " copies in " << elapsed.count() << " seconds" << endl;

	return 0;
}
