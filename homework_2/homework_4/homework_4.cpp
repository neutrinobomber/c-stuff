// start main.cpp
#include "Company.h"

#include <iostream>
using namespace std;

int main()
{
	Company first("first", 10);
	Company second("second", 5);

	cout << first + second << endl;
	cout << first - 1 << endl;
	cout << first * 80 << endl;

    return 0;
}
// end main.cpp