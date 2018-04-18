#include "CSchool.h"

CSchool::CSchool() : name(nullptr), students_count(0), students(nullptr) {}

CSchool::CSchool(const char * name, size_t students_count, const CStudent * students) :
	name(new char[strlen(name) + 1]),
	students_count(students_count),
	students(new CStudent[students_count])
{
	strcpy_s(this->name, strlen(name) + 1, name);

	for (size_t i = 0; i < this->students_count; i++)
	{
		this->students[i] = students[i];
	}
}

std::ostream & CSchool::inserter(std::ostream& out) const
{
	for (size_t i = 0; i < this->students_count; i++)
	{
		out << this->students[i] << std::endl;
	}
	return out;
}

std::ostream & operator<<(std::ostream & left, const CSchool & right)
{
	return right.inserter(left);
}