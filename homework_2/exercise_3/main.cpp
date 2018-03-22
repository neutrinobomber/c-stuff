// start main.cpp
#include <iostream>
#include "HotelRoom.h"

using namespace std;

int main()
{
	const unsigned rooms_count = 2;
	unsigned ids[rooms_count] = { 1, 2 };
	double prices[rooms_count] = { 2.2, 3.4 };

	HotelRoom room1(rooms_count, ids, prices);
	room1.add_reservaton(3, 4.5);
	print_highest_price(room1);

	HotelRoom room2 = room1;
	room2.add_reservaton(4, 5.6);
	print_highest_price(room2);

	room2 = room1;
	room2.add_reservaton(5, 4.6);
	print_highest_price(room2);

	return 0;
}
// end main.cpp