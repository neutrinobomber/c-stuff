#include "CountVar.h"

void CountVar::set_name(const char * name)
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

CountVar::CountVar(double value, const char * name, std::ostream& out)
	: value(value), name(nullptr), out(out)
{
	this->set_name(name);

	this->cnt_exp = 0;
	this->cnt_ass = 0;
}

CountVar::operator double()
{
	this->cnt_exp++;

	return value;
}

CountVar& CountVar::operator=(double other)
{
	this->value = other;
	this->cnt_ass++;

	return *this;
}

CountVar& CountVar::operator=(const CountVar& other)
{
	this->value = other.value;
	this->cnt_ass++;

	return *this;
}

CountVar::~CountVar()
{
	this->out << this->name << std::endl << " counter 1: " << this->cnt_exp
		<< std::endl << " counter 2: " << this->cnt_ass << std::endl;

	if (this->name != nullptr)
	{
		delete[] this->name;
	}
}

const CountVar CountVar::operator+(const CountVar & other)
{
	this->cnt_exp++;

	return CountVar(this->value + other.value, this->name, this->out);
}

const CountVar CountVar::operator-(const CountVar & other)
{
	this->cnt_exp++;

	return CountVar(this->value - other.value, this->name, this->out);
}

const CountVar CountVar::operator*(const CountVar & other)
{
	this->cnt_exp++;

	return CountVar(this->value * other.value, "Obj*", this->out);
}

const CountVar CountVar::operator/(const CountVar & other)
{
	this->cnt_exp++;

	if (other.value != 0)
	{
		return CountVar(this->value / other.value, this->name, this->out);
	}
	else
	{
		return CountVar(this->value, this->name, this->out);
	}
}