// start main.cpp
#include <iostream>
#include "Money.h"
using namespace std;

int main()
{
	Money first(10, 1);
	Money second(1, 10);
	cout << first / second << endl;
	return 0;
}
// end main.cpp