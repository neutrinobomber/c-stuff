#pragma once

#include <iostream>

class CountVar
{
private:
	double value;
	unsigned int cnt_ass;
	unsigned int cnt_exp;
	char * name;
	std::ostream & out;

	void set_name(const char * name);
public:
	CountVar(double value, const char * name, std::ostream & out);
	virtual ~CountVar();

	operator double();
	CountVar& operator=(double);
	CountVar& operator=(const CountVar&);
	const CountVar operator+(const CountVar &);
	const CountVar operator-(const CountVar &);
	const CountVar operator*(const CountVar &);
	const CountVar operator/(const CountVar &);
};