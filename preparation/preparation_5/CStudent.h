#pragma once

#include <iostream>

class CStudent
{
private:
	double sum_grades() const;
	char * name;
	size_t subjects_count;
	double * grades;

	void set_name(const char * name);
	void set_grades(const double * grades, size_t len);
public:
	CStudent();
	CStudent(const char * name, size_t subjects_count);
	CStudent(const CStudent & other);
	virtual ~CStudent();

	void add_grade(double value);
	void change_grade(double value, size_t);

	CStudent& operator=(const CStudent & other);
	double operator()() const;
	bool operator> (const CStudent & other) const;
	double operator[](size_t) const;
	double& operator[](size_t);

	std::ostream & inserter(std::ostream & out) const;
};

std::ostream & operator << (std::ostream & out, const CStudent & other);