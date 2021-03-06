// start main.cpp
#include <iostream>
#include <ctime>

#include "FlowersShop.h"

using namespace std;

void call_print1(FlowersShop shop)
{
	shop.print();
}

void call_print2(const FlowersShop &shop)
{
	shop.print();
}

int main()
{
	FlowersShop shop1(10, 1.3f);
	shop1.print();
	FlowersShop shop2 = shop1.simulating_price_decrease();
	shop2.print();

	FlowersShop shops[10];
	// set random values to the shops, because at the moment everything is 0
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		shops[i].increase_single_price(rand() % 100 + 1);
		shops[i].increase_flowers(rand() % 100 + 1);
	}

	// find shop with highest profit
	unsigned biggest_profit_idx = 0;
	for (int i = 0; i < 10; i++)
	{
		if (shops[i].calculate_profit() > shops[biggest_profit_idx].calculate_profit())
		{
			biggest_profit_idx = i;
		}
	}

	cout << endl << "most profitable flowers shop: " << endl;
	shops[biggest_profit_idx].print();

	return 0;
}
// end main.cpp