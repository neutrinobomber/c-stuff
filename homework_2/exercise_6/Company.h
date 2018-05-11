// start Company.h
#ifndef COMPANY
#define COMPANY

#include "Employee.h"

class Company
{
private:
	unsigned employees_count;
	Employee * employees;
	double overhead_costs;

	void delete_employees();
public:
	Company();
	Company(const Employee * employees, unsigned employees_count, double overhead_costs);
	virtual ~Company();

	virtual double costs() const;

	unsigned get_employees_count() const;
	const Employee * get_employees() const;
	double get_overhead_costs() const;

	void set_employees(const Employee * employees, unsigned employees_count);
	void set_overhead_costs(double costs);

	virtual void insert_data(std::ostream & out) const;
};

std::ostream & operator<<(std::ostream & out, const Company & other);

#endif
// end Company.h