// start main.cpp
#include <iostream>

#include "BankAccount.h"

using namespace std;

int main()
{
	BankAccount acc;
	BankAccount acc2("holder", 10, 20);

	acc *= 2;
	cout << acc2.get_amount() << endl;

	cout << acc2.get_holder_name() << endl;
	cout << (acc2 == acc) << endl;

	acc2 = acc;

	cout << acc2.get_holder_name() << endl;
	cout << (acc2 == acc) << endl;
}
// end main.cpp