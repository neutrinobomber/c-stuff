// start BankAccount.cpp
#include <cstring>

#include "BankAccount.h"

BankAccount::BankAccount() : holder_name("none"), amount(0), credit_limit(0)
{
}

BankAccount::BankAccount(const char * holder_name, double amount, double credit_limit)
	: holder_name(holder_name)
{
	if (amount > 0)
	{
		this->amount = amount;
	}
	else
	{
		this->amount = 0;
	}

	if (credit_limit > 0)
	{
		this->credit_limit = credit_limit;
	}
	else
	{
		this->credit_limit = 0;
	}
}

const char * BankAccount::get_holder_name() const
{
	return this->holder_name;
}

double BankAccount::get_amount() const
{
	return this->amount;
}

double BankAccount::get_credit_limit() const
{
	return this->credit_limit;
}

void BankAccount::set_holder_name(const char * new_name)
{
	this->holder_name = new_name;
}

void BankAccount::set_amount(double new_amount)
{
	if (new_amount > 0)
	{
		this->amount = new_amount;
	}
}

void BankAccount::set_credit_limit(double new_limit)
{
	if (new_limit > 0)
	{
		this->credit_limit = new_limit;
	}
}

bool BankAccount::operator==(const BankAccount & other) const
{
	if (this == &other) 
	{
		return true;
	}

	return strcmp(this->holder_name, other.holder_name) == 0 &&
		this->amount == other.amount && this->credit_limit == other.credit_limit;
}

bool BankAccount::operator!=(const BankAccount & other) const
{
	return !this->operator==(other);
}

BankAccount & BankAccount::operator+=(double add_sum)
{
	if (add_sum > 0)
	{
		this->amount += add_sum;
	}

	return *this;
}

BankAccount & BankAccount::operator-=(double subtract_sum)
{
	if (subtract_sum > 0)
	{
		this->amount -= subtract_sum;
	}

	return *this;
}

BankAccount & BankAccount::operator*=(unsigned charge_percent)
{
	double increase = this->amount * (double)(charge_percent / 100);
	this->amount += increase;
	return *this;
}
// end BankAccount.cpp