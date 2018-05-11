// start Clothes.cpp
#include <iostream>

#include "Clothes.h"

Clothes::Clothes() : Goods("Clothes", 0), size(0)
{
	std::cout << "Clothes created" << std::endl;
}

Clothes::Clothes(unsigned size) : Goods("Clothes", 0), size(size)
{
	std::cout << "Clothes created" << std::endl;
}

Clothes::~Clothes()
{
	std::cout << "Clothes destroyed" << std::endl;
}

unsigned Clothes::get_size() const
{
	return this->size;
}

void Clothes::set_size(unsigned size)
{
	this->size = size;
}

void Clothes::insert_data(std::ostream & out) const
{
	Goods::insert_data(out);
	out << "clothes size: " << this->size << std::endl;
}
// end Clothes.cpp