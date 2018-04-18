#include "TraceFun.h"

TraceFun::TraceFun() : name(nullptr), out(&std::cout)
{
	this->set_func_name("\0");

	*this->out << this->name << " starts here!" << std::endl;
}

TraceFun::TraceFun(const char * name, std::ostream & out) : name(nullptr), out(&out)
{
	this->set_func_name(name);

	*this->out << this->name << " starts here!" << std::endl;
}

TraceFun::TraceFun(const TraceFun & other) : name(nullptr), out(other.out)
{
	this->set_func_name(other.name);

	*this->out << this->name << " starts here!" << std::endl;
}

TraceFun::~TraceFun()
{
	*this->out << this->name << " ends here!" << std::endl;

	if (this->name != nullptr)
	{
		delete[] this->name;
	}
}

TraceFun & TraceFun::operator=(const TraceFun & other)
{
	if (this != &other)
	{
		this->set_func_name(other.name);
		this->out = other.out;
	}

	return *this;
}

void TraceFun::set_func_name(const char * name)
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void TraceFun::set_out(std::ostream * out)
{
	this->out = out;
}

const char * TraceFun::get_fun_name() const
{
	return this->name;
}

const std::ostream * TraceFun::get_out() const
{
	return this->out;
}