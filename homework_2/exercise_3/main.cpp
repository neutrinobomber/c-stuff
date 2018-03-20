#include <iostream>

using namespace std;

class HotelRoom
{
private:
	unsigned *room_ids;
	unsigned *prices;
	unsigned reservations_count;

	void clean_data();
public:
	HotelRoom();
	HotelRoom(unsigned reservations_count, unsigned *room_ids, unsigned *prices);
	HotelRoom(HotelRoom &other);
	~HotelRoom();

	HotelRoom& operator=(const HotelRoom &other);

	void add_reservaton(unsigned room_id, unsigned price);
	unsigned get_highest_price();
};

HotelRoom::HotelRoom() : 
	reservations_count(0), 
	room_ids(NULL),
	prices(NULL)
{}

HotelRoom::HotelRoom(unsigned reservations_count, unsigned *room_ids, unsigned *prices) :
	reservations_count(reservations_count),
	room_ids(new unsigned[reservations_count]),
	prices(new unsigned[reservations_count])
{
	for (size_t i = 0; i < this->reservations_count; i++)
	{
		this->room_ids[i] = room_ids[i];
		this->prices[i] = prices[i];
	}
}

HotelRoom::HotelRoom(HotelRoom &other)
{
	if (other.reservations_count > 0)
	{
		this->reservations_count = other.reservations_count;
		for (size_t i = 0; i < this->reservations_count; i++)
		{
			this->room_ids[i] = other.room_ids[i];
			this->prices[i] = other.prices[i];
		}
	}
	else
	{
		this->reservations_count = 0;
		this->prices = NULL;
		this->room_ids = NULL;
	}
}

void HotelRoom::clean_data()
{
	if (this->prices != NULL)
	{
		delete[] this->prices;
		this->prices = NULL;
	}

	if (this->room_ids != NULL)
	{
		delete[] this->room_ids;
		this->room_ids = NULL;
	}
}

HotelRoom::~HotelRoom()
{
	this->clean_data();
}

HotelRoom& HotelRoom::operator=(const HotelRoom &other)
{
	if (this == &other)
	{
		return *this;
	}

	this->clean_data();
	if (other.reservations_count > 0)
	{
		this->reservations_count = other.reservations_count;
		this->prices = new unsigned[this->reservations_count];
		this->room_ids = new unsigned[this->reservations_count];
		for (size_t i = 0; i < this->reservations_count; i++)
		{
			this->room_ids[i] = other.room_ids[i];
			this->prices[i] = other.prices[i];
		}
	}

	return *this;
}

void HotelRoom::add_reservaton(unsigned room_id, unsigned price)
{
	this->reservations_count++;

	unsigned *new_prices = new unsigned[this->reservations_count];
	unsigned *new_room_ids = new unsigned[this->reservations_count];
	for (size_t i = 0; i < this->reservations_count - 1; i++)
	{
		new_room_ids[i] = this->room_ids[i];
		new_prices[i] = this->prices[i];
	}

	this->clean_data();
	this->prices = new_prices;
	this->room_ids = new_room_ids;
}

unsigned HotelRoom::get_highest_price()
{
	if (this->reservations_count == 0)
	{
		return 0;
	}

	unsigned max_price = this->prices[0];
	for (size_t i = 1; i < this->reservations_count; i++)
	{
		if (this->prices[i] > max_price)
		{
			max_price = this->prices[i];
		}
	}
	return max_price;
}

int main()
{
	return 0;
}