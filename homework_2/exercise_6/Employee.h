// start Employee.h
#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
private:
	char * name;
	double salary;

	void delete_name();
public:
	Employee();
	Employee(const char * name, double salary);
	virtual ~Employee();

	const char * get_name() const;
	double get_salary() const;

	void set_name(const char * name);
	void set_salary(double salary);

	virtual void insert_data(std::ostream & out) const;
};

std::ostream & operator<<(std::ostream & out, const Employee & other);

#endif
// end Employee.h