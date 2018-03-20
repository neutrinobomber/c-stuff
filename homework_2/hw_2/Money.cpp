// start Money.cpp
#include "Money.h"

Money Money::operator+(const Money &other) const
{
	unsigned st = this->st + other.st;
	unsigned lv = this->lv + other.lv;
	while (st >= 100)
	{
		lv++;
		st -= 100;
	}
	return Money(lv, st);
}

Money Money::operator-(const Money &other) const
{
	return Money(this->st - other.st, this->lv - other.lv);
}

Money Money::operator*(const Money &other) const
{
	unsigned lv = this->lv * other.lv;
	unsigned st = this->st * other.st;
	while (st >= 100)
	{
		lv++;
		st -= 100;
	}
	return Money(lv, st);
}

Money Money::operator/(const Money &other) const
{
	return Money((unsigned)(this->lv / other.lv), unsigned(this->st / other.st));
}

bool Money::operator>(const Money &other) const
{
	if (this->lv > other.lv)
		return true;

	if (this->st > other.st)
		return true;

	return false;
}

bool Money::operator<(const Money &other) const
{
	if (this->lv < other.lv)
		return true;

	if (this->st < other.st)
		return true;

	return false;
}

bool Money::operator==(const Money &other) const
{
	return this->lv == other.lv && this->st == other.st;
}

bool Money::operator!=(const Money &other) const
{
	return this->lv != other.lv || this->st != other.st;
}

std::istream& operator>>(std::istream &in, Money &val)
{
	std::cout << "lv: ";
	in >> val.lv;
	std::cout << "st: ";
	in >> val.st;
	return in;
}

std::ostream& operator<<(std::ostream &out, const Money &val)
{
	out << "lv: " << val.lv << " st: " << val.st << std::endl;
	return out;
}

double operator%(const double n, const Money &other)
{
	unsigned lv = other.lv;
	unsigned st = other.st;
	while (lv > 0)
	{
		st += 100;
		lv--;
	}
	return n / st * 100;
}
// end Money.cpp