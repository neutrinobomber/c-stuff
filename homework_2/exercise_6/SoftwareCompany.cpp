// start SoftwareCompany.cpp
#include <iostream>

#include "SoftwareCompany.h"

SoftwareCompany::SoftwareCompany() : Company(), rent_cost(0)
{
	std::cout << "SoftwareCompany created" << std::endl;
}

SoftwareCompany::SoftwareCompany(
	const Employee * employees,
	unsigned employees_count,
	double overhead_costs,
	double rent_cost) : Company(employees, employees_count, overhead_costs), rent_cost(rent_cost)
{
	std::cout << "SoftwareCompany created" << std::endl;
}

SoftwareCompany::~SoftwareCompany()
{
	std::cout << "SoftwareCompany destroyed" << std::endl;
}

double SoftwareCompany::costs()
{
	return Company::costs() + this->rent_cost;
}

double SoftwareCompany::get_rent_cost() const
{
	return this->rent_cost;
}

void SoftwareCompany::set_rent_cost(double rent_cost)
{
	this->rent_cost = rent_cost;
}

void SoftwareCompany::insert_data(std::ostream & out) const
{
	Company::insert_data(out);
	out << "rent cost: " << this->rent_cost << std::endl;
}
// end SoftwareCompany.cpp