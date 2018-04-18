#pragma once

#include "CStudent.h"

class CSchool
{
private:
	char * name;
	size_t students_count;
	CStudent * students;
public:
	CSchool();
	CSchool(const char * name, size_t students_count, const CStudent * student);
	std::ostream& inserter(std::ostream & out) const;
};

std::ostream& operator << (std::ostream &, const CSchool &);