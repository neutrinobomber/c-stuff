// start Manager.cpp
#include <cstring>
#include <iostream>

#include "Manager.h"

Manager::Manager() : Employee(), division(nullptr)
{
	this->set_division("\0");
}

Manager::Manager(const char * name, unsigned salary, unsigned experience, const char * division) :
	Employee(name, salary, experience),
	division(nullptr)
{
	this->set_division(division);
}

Manager::Manager(const Manager & other) : Employee(other), division(nullptr)
{
	this->set_division(other.division);
}

Manager::~Manager()
{
	this->delete_division();
}

void Manager::delete_division()
{
	if (this->division != nullptr)
	{
		delete[] this->division;
		this->division = nullptr;
	}
}

Manager & Manager::operator=(const Manager & other)
{
	Employee::operator=(other);

	if (this != &other)
	{
		this->set_division(other.division);
	}
	return *this;
}

const char * Manager::get_division() const
{
	return this->division;
}

void Manager::set_division(const char * new_division)
{
	this->delete_division();

	this->division = new char[strlen(new_division) + 1];
	strcpy_s(this->division, strlen(new_division) + 1, new_division);
}

void Manager::print() const
{
	std::cout << "name: " << this->get_name()
		<< " division: " << this->get_division()
		<< " salary: " << this->get_salary() << std::endl;
}
// end Manager.cpp