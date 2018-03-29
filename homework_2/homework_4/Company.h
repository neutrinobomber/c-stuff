// start Company.h
#ifndef COMPANY
#define COMPANY

#include <iostream>

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
	Company operator*(double more_employees_percent) const;
	Company & operator=(const Company & other);

	friend std::ostream & operator<<(std::ostream & out, const Company & other);
};

#endif
// end Company.h