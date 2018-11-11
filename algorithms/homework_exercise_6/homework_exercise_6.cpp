#include "pch.h"
#include <iostream>
#include <chrono>

using namespace std;

void PrintHanoi(int towers, char from, char to, char through)
{
	cout << "moving disc " << towers << " from " << from << " to " << to << endl;
}

unsigned copies = 0;
void Hanoi(int towers, char from, char to, char through)
{
	copies++;

	if (towers > 1)
	{
		Hanoi(towers - 1, from, through, to);

		PrintHanoi(towers, from, to, through);

		Hanoi(towers - 1, through, to, from);
	}
	else
	{
		PrintHanoi(towers, from, to, through);
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
