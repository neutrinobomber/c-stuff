// start Employee.cpp
#include <cstring>
#include <iostream>

#include "Employee.h"

Employee::Employee() : name(nullptr), salary(0)
{
	this->set_name("no name");

	std::cout << "Employee created" << std::endl;
}

Employee::Employee(const char * name, double salary) : name(nullptr), salary(salary)
{
	this->set_name(name);

	std::cout << "Employee created" << std::endl;
}

Employee::~Employee()
{
	this->delete_name();

	std::cout << "Employee destroyed" << std::endl;
}

void Employee::delete_name()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
}

void Employee::set_name(const char * name)
{
	this->delete_name();

	unsigned len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

const char * Employee::get_name() const
{
	return this->name;
}

double Employee::get_salary() const
{
	return this->salary;
}

void Employee::set_salary(double salary)
{
	this->salary = salary;
}

void Employee::insert_data(std::ostream & out) const
{
	out << "employee name: " << this->name << std::endl
		<< "employee salary: " << this->salary << std::endl;
}

std::ostream & operator<<(std::ostream & out, const Employee & other)
{
	other.insert_data(out);
	return out;
}
// end Employee.cpp