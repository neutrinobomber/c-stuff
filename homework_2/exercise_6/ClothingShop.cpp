// start ClothingShop.cpp
#include <iostream>

#include "ClothingShop.h"

void ClothingShop::delete_clothes()
{
	if (this->clothes != nullptr)
	{
		delete[] this->clothes;
		this->clothes = nullptr;
	}

	this->clothes_count = 0;
}

ClothingShop::ClothingShop() : Company(), clothes(nullptr), clothes_count(0)
{
	std::cout << "Clothing shop created" << std::endl;
}

ClothingShop::ClothingShop(
	const Employee * employees,
	unsigned employees_count,
	double overhead_costs,
	const Clothes * clothes,
	unsigned clothes_count) :
	Company(employees, employees_count, overhead_costs),
	clothes(nullptr),
	clothes_count(clothes_count)
{
	this->set_clothes(clothes, clothes_count);

	std::cout << "Clothing shop created" << std::endl;
}

ClothingShop::~ClothingShop()
{
	this->delete_clothes();

	std::cout << "Clothing shop destroyed" << std::endl;
}

double ClothingShop::costs() const
{
	double clothes_cost = 0;
	for (size_t i = 0; i < this->clothes_count; i++)
	{
		clothes_cost += this->clothes[i].get_price();
	}
	return Company::costs() + clothes_cost;
}

const Clothes * ClothingShop::get_clothes() const
{
	return this->clothes;
}

unsigned ClothingShop::get_clothes_count() const
{
	return this->clothes_count;
}

void ClothingShop::set_clothes(const Clothes * clothes, unsigned clothes_count)
{
	this->delete_clothes();

	this->clothes = new Clothes[clothes_count];
	this->clothes_count = clothes_count;
	for (size_t i = 0; i < clothes_count; i++)
	{
		this->clothes[i] = clothes[i];
	}
}

void ClothingShop::insert_data(std::ostream & out) const
{
	Company::insert_data(out);
	out << "clothes: " << std::endl;
	for (size_t i = 0; i < this->clothes_count; i++)
	{
		out << this->clothes[i];
	}
}
// end ClothingShop.cpp