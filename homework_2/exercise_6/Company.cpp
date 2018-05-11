// start Company.cpp
#include <iostream>

#include "Company.h"

void Company::delete_employees()
{
	if (this->employees != nullptr)
	{
		delete[] this->employees;
		this->employees = nullptr;

		this->employees_count = 0;
	}
}

Company::Company() : employees(nullptr), employees_count(0), overhead_costs(0)
{
	std::cout << "Company created" << std::endl;
}

Company::Company(const Employee * employees, unsigned employees_count, double overhead_costs)
	: employees(nullptr), employees_count(employees_count), overhead_costs(overhead_costs)
{
	this->set_employees(employees, employees_count);

	std::cout << "Company created" << std::endl;
}

Company::~Company()
{
	this->delete_employees();

	std::cout << "Company destroyed" << std::endl;
}

double Company::costs() const
{
	double salaries = 0;
	if (this->employees_count > 0)
	{
		for (size_t i = 0; i < this->employees_count; i++)
		{
			salaries += this->employees[i].get_salary();
		}
	}

	return salaries + this->overhead_costs;
}

unsigned Company::get_employees_count() const
{
	return this->employees_count;
}

const Employee * Company::get_employees() const
{
	return this->employees;
}

double Company::get_overhead_costs() const
{
	return this->overhead_costs;
}

void Company::set_employees(const Employee * employees, unsigned employees_count)
{
	this->delete_employees();

	this->employees = new Employee[employees_count];
	this->employees_count = employees_count;

	for (size_t i = 0; i < employees_count; i++)
	{
		this->employees[i] = employees[i];
	}
}

void Company::set_overhead_costs(double costs)
{
	this->overhead_costs = costs;
}

void Company::insert_data(std::ostream & out) const
{
	out << "employees count: " << this->employees_count << std::endl
		<< "employees: " << std::endl;
	for (size_t i = 0; i < this->employees_count; i++)
	{
		out << this->employees[i];
	}
	out << "overhead costs: " << this->overhead_costs << std::endl;
}

std::ostream & operator<<(std::ostream & out, const Company & other)
{
	other.insert_data(out);
	return out;
}
// end Company.cpp