// start Manager.h
#ifndef MANAGER
#define MANAGER

#include "Employee.h"

class Manager : public Employee
{
private:
	char * division;

	void delete_division();

public:
	Manager();
	Manager(const char * name, unsigned salary, unsigned experience, const char * division);
	Manager(const Manager & other);
	~Manager();

	Manager & operator=(const Manager & other);

	const char * get_division() const;

	void set_division(const char * new_division);

	virtual void print() const;
};

#endif
// end Manager.h