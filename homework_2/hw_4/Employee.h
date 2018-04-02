// start Employee.h
#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
private:
	char * name;
	unsigned salary;
	unsigned experience;

	void delete_name();

public:
	Employee();
	Employee(const char * name, unsigned salary, unsigned experience);
	Employee(const Employee & other);
	virtual ~Employee();

	Employee & operator=(const Employee & other);

	const char * get_name() const;
	unsigned get_salary() const;
	unsigned get_experience() const;

	void set_name(const char * new_name);
	void set_salary(unsigned salary);
	void set_experience(unsigned experience);
};

#endif
// end Employee.h