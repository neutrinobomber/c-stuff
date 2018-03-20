// start Money.h
#ifndef MONEY
#define MONEY

#include <iostream>

class Money
{
private:
	unsigned lv;
	unsigned st;
public:
	Money(unsigned lv = 0, unsigned st = 0) : lv(lv), st(st) {};

	Money operator+(const Money &other) const;
	Money operator-(const Money &other) const;
	Money operator*(const Money &other) const;
	Money operator/(const Money &other) const;

	friend double operator%(const double n, const Money &other);

	bool operator>(const Money &other) const;
	bool operator<(const Money &other) const;
	bool operator==(const Money &other) const;
	bool operator!=(const Money &other) const;

	friend std::istream& operator>>(std::istream &in, Money &val);
	friend std::ostream& operator<<(std::ostream &out, const Money &val);
};

#endif
// end Money.h