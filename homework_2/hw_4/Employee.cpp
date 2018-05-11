// start Employee.cpp
#include <cstring>

#include "Employee.h"

Employee::Employee() : name(nullptr), salary(0), experience(0) 
{
	this->set_name("\0");
}

Employee::Employee(const char * name, unsigned salary, unsigned experience) :
	name(nullptr),
	salary(salary),
	experience(experience)
{
	this->set_name(name);
}

Employee::Employee(const Employee & other) : name(nullptr)
{
	this->set_name(other.name);

	this->salary = other.salary;
	this->experience = other.experience;
}

void Employee::delete_name()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
}

Employee::~Employee()
{
	this->delete_name();
}

Employee & Employee::operator=(const Employee & other)
{
	if (this != &other)
	{
		this->set_name(other.name);

		this->salary = other.salary;
		this->experience = other.experience;
	}
	return *this;
}

const char * Employee::get_name() const
{
	return this->name;
}

unsigned Employee::get_salary() const
{
	return this->salary;
}

unsigned Employee::get_experience() const
{
	return this->experience;
}

void Employee::set_name(const char * new_name)
{
	this->delete_name();

	this->name = new char[strlen(new_name) + 1];
	strcpy_s(this->name, strlen(new_name) + 1, new_name);
}

void Employee::set_salary(unsigned salary)
{
	this->salary = salary;
}

void Employee::set_experience(unsigned experience)
{
	this->experience = experience;
}
// end Employee.cpp