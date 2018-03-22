// start HotelRoom.cpp
#include <iostream>
#include "HotelRoom.h"

HotelRoom::HotelRoom() :
	reservations_count(0),
	room_ids(nullptr),
	prices(nullptr)
{}

HotelRoom::HotelRoom(unsigned reservations_count, unsigned *ids, double *prices) :
	reservations_count(reservations_count),
	room_ids(new unsigned[reservations_count]),
	prices(new double[reservations_count])
{
	for (size_t i = 0; i < this->reservations_count; i++)
	{
		this->room_ids[i] = ids[i];
		this->prices[i] = prices[i];
	}
}

HotelRoom::HotelRoom(HotelRoom &other)
{
	if (other.reservations_count > 0)
	{
		this->reservations_count = other.reservations_count;
		this->room_ids = new unsigned[reservations_count];
		this->prices = new double[reservations_count];
		for (size_t i = 0; i < this->reservations_count; i++)
		{
			this->room_ids[i] = other.room_ids[i];
			this->prices[i] = other.prices[i];
		}
	}
}

void HotelRoom::clean_data()
{
	if (this->prices != nullptr)
	{
		delete[] this->prices;
		this->prices = nullptr;
	}

	if (this->room_ids != nullptr)
	{
		delete[] this->room_ids;
		this->room_ids = nullptr;
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
		this->prices = new double[this->reservations_count];
		this->room_ids = new unsigned[this->reservations_count];
		for (size_t i = 0; i < this->reservations_count; i++)
		{
			this->room_ids[i] = other.room_ids[i];
			this->prices[i] = other.prices[i];
		}
	}

	return *this;
}

void HotelRoom::add_reservaton(unsigned id, double price)
{
	this->reservations_count++;

	double *new_prices = new double[this->reservations_count];
	unsigned *new_room_ids = new unsigned[this->reservations_count];
	for (size_t i = 0; i < this->reservations_count - 1; i++)
	{
		new_room_ids[i] = this->room_ids[i];
		new_prices[i] = this->prices[i];
	}
	new_prices[this->reservations_count - 1] = price;
	new_room_ids[this->reservations_count - 1] = id;

	this->clean_data();
	this->prices = new_prices;
	this->room_ids = new_room_ids;
}

double HotelRoom::get_highest_price() const
{
	if (this->reservations_count == 0)
	{
		return 0;
	}

	double max_price = this->prices[0];
	for (size_t i = 1; i < this->reservations_count; i++)
	{
		if (this->prices[i] > max_price)
		{
			max_price = this->prices[i];
		}
	}
	return max_price;
}

void print_highest_price(const HotelRoom &room)
{
	std::cout << "highest price: " << room.get_highest_price() << std::endl;
}
// end HotelRoom.cpp