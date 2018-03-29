#include "stdafx.h"

#include <iostream>

using namespace std;

class Company
{
private:
	char * name;
	unsigned employees_count;

	void delete_name();

public:
	Company();
	Company(const char * const name, unsigned employees_count);
	Company(const Company &other);
		
	~Company();

	const char * const get_name() const;
	unsigned get_employees_count() const;

	void set_name(const char * const new_name);
	void set_employees_count(unsigned new_count);

	Company operator+(const Company &other) const;
	Company operator-(unsigned decrease_employees_count) const;
	Company operator*(unsigned more_employees_percent) const;
	Company & operator=(const Company & other);

	friend std::ostream & operator<<(std::ostream & out, const Company & other);
};

int main()
{
	Company first("1", 10);
	Company second("2", 5);

	Company third = first + second;
	cout << third << endl;

    return 0;
}

void Company::delete_name()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
}

Company::Company() : name(nullptr), employees_count(0) {}

Company::Company(const char * const name, unsigned employees_count) : 
	name(new char[strlen(name) + 1]),
	employees_count(employees_count)
{
	strcpy_s(this->name, strlen(name) + 1, name);
	cout << this->name << endl;
}

Company::Company(const Company & other)
{
	if (other.name != nullptr)
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
		this->employees_count = other.employees_count;
	}
	else
	{
		this->name = nullptr;
		this->employees_count = 0;
	}
}

Company::~Company()
{
	this->delete_name();
}

const char * const Company::get_name() const
{
	return this->name;
}

unsigned Company::get_employees_count() const
{
	return this->employees_count;
}

void Company::set_name(const char * const new_name)
{
	this->delete_name();
	this->name = new char[strlen(new_name) + 1];
	strcpy_s(this->name, strlen(new_name) + 1, new_name);
}

void Company::set_employees_count(unsigned new_count)
{
	this->employees_count = new_count;
}

Company Company::operator+(const Company & other) const
{
	unsigned new_len = strlen(this->name) + strlen(other.name) + 1;
	char * new_name = new char[new_len];
	strcpy_s(new_name, new_len, this->name);
	strcat_s(new_name, new_len, other.name);	

	Company new_company(new_name, this->employees_count + other.employees_count);
	
	delete[] new_name;
	new_name = nullptr;

	return new_company;
}

Company Company::operator-(unsigned decrease_num) const
{
	return Company(this->name, this->employees_count - decrease_num);
}

Company Company::operator*(unsigned increase_percent) const
{
	return Company(this->name, unsigned((increase_percent / 100) * this->employees_count));
}

Company & Company::operator=(const Company & other)
{
	if (this != &other) 
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
		this->employees_count = other.employees_count;
	}
	return *this;

}

std::ostream & operator<<(std::ostream & out, const Company & other)
{
	out << "company name: " << other.name << endl 
		<< "number of employees: " << other.employees_count << endl;
	return out;
}
