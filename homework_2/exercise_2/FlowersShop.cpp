// start FlowersShop.cpp
#include <iostream>

#include "FlowersShop.h"

FlowersShop::FlowersShop() :
	single_price(0),
	flowers_count(0) {}

FlowersShop::FlowersShop(unsigned flowers_count) :
	single_price(0),
	flowers_count(flowers_count) {}

FlowersShop::FlowersShop(float single_price) :
	single_price(single_price),
	flowers_count(0) {}

FlowersShop::FlowersShop(unsigned flowers_count, float single_price) :
	single_price(single_price),
	flowers_count(flowers_count) {}

void FlowersShop::increase_flowers(unsigned count)
{
	this->flowers_count += count;
}

void FlowersShop::decrease_flowers(unsigned count)
{
	if (count <= this->flowers_count)
	{
		this->flowers_count -= count;
	}
}

void FlowersShop::increase_single_price(float price)
{
	this->single_price += price;
}

void FlowersShop::decrease_single_price(float price)
{
	if (price <= this->single_price)
	{
		this->single_price -= price;
	}
}

void FlowersShop::print() const
{
	std::cout << "number of flowers in the shop: " << this->flowers_count << std::endl
		<< "price of a single flower: " << this->single_price << std::endl;
}

double FlowersShop::calculate_profit() const
{
	return this->single_price * this->flowers_count;
}

FlowersShop FlowersShop::simulating_price_decrease() const
{
	return FlowersShop(this->flowers_count, 0.2f * this->single_price);
}
// end FlowersShop.cpp