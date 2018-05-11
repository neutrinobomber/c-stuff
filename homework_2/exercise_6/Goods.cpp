// start Goods.cpp
#include <cstring>
#include <iostream>

#include "Goods.h"

void Goods::delete_name()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
}

Goods::Goods() : name(nullptr), price(0)
{
	this->set_name("none");

	std::cout << "Goods created" << std::endl;
}

Goods::Goods(const char * name, unsigned price) : name(nullptr), price(price)
{
	this->set_name(name);

	std::cout << "Goods created" << std::endl;
}

Goods::~Goods()
{
	this->delete_name();

	std::cout << "Goods destroyed" << std::endl;
}

const char * Goods::get_name() const
{
	return this->name;
}

unsigned Goods::get_price() const
{
	return this->price;
}

void Goods::set_name(const char * name)
{
	this->delete_name();

	unsigned len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

void Goods::set_price(unsigned price)
{
	this->price = price;
}

void Goods::insert_data(std::ostream & out) const
{
	out << "goods name: " << this->name << std::endl
		<< "goods price: " << this->price << std::endl;
}

std::ostream & operator<<(std::ostream & out, const Goods & obj)
{
	obj.insert_data(out);
	return out;
}
// end Goods.cpp