#include <cassert>

#include "CStudent.h"

void CStudent::set_name(const char * name)
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void CStudent::set_grades(const double * grades, size_t len)
{
	if (this->grades != nullptr)
	{
		delete[] this->grades;
	}

	this->grades = new double[len];
	for (size_t i = 0; i < len; i++)
	{
		this->grades[i] = grades[i];
	}
}

CStudent::CStudent() : name(nullptr), subjects_count(0), grades(nullptr)
{
	this->set_name("NoName");
}

CStudent::CStudent(const char * name, size_t subjects_count) :
	name(nullptr),
	subjects_count(subjects_count),
	grades(new double[subjects_count])
{
	this->set_name(name);

	for (size_t i = 0; i < subjects_count; i++)
	{
		this->grades[i] = 0.;
	}
}

CStudent::CStudent(const CStudent & other) :
	name(nullptr),
	subjects_count(other.subjects_count),
	grades(nullptr)
{
	this->set_name(other.name);
	this->set_grades(other.grades, other.subjects_count);
}

void CStudent::add_grade(double value)
{
	assert(value >= 2. && value <= 6.);

	if (!(value >= 2. && value <= 6.))
	{
		std::cout << "Not valid grade" << std::endl;
	}

	if (this->subjects_count > 0)
	{
		this->subjects_count++;
		double * tmp = new double[this->subjects_count];
		for (size_t i = 0; i < this->subjects_count - 1; i++)
		{
			tmp[i] = this->grades[i];
		}
		tmp[this->subjects_count - 1] = value;

		if (this->grades != nullptr)
		{
			delete[] this->grades;
		}
		this->grades = tmp;
	}
	else
	{
		this->subjects_count = 1;
		this->grades[0] = value;
	}
}

void CStudent::change_grade(double value, size_t ind)
{
	assert(ind >= 0. && ind < this->subjects_count);
	assert(value >= 2. && value <= 6.);
	(*this)[ind] = value;
	//this->operator[](ind) = g;
}

CStudent & CStudent::operator=(const CStudent & other)
{
	if (this != &other)
	{
		this->set_name(other.name);
		this->set_grades(other.grades, other.subjects_count);
		this->subjects_count = other.subjects_count;
	}
	return *this;
}

CStudent::~CStudent()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}
	if (this->grades != nullptr)
	{
		delete[] this->grades;
	}
}

double CStudent::operator()() const
{
	return this->sum_grades() / this->subjects_count;
}

bool CStudent::operator>(const CStudent & other) const
{
	return (*this)() > other();
	//return this->operator()>rhs.operator();
}

double CStudent::operator[](size_t ind) const
{
	assert(ind >= 0 && ind < this->subjects_count);
	return this->grades[ind];
}

double& CStudent::operator[](size_t ind)
{
	assert(ind >= 0 && ind < this->subjects_count);
	return this->grades[ind];
}

std::ostream & CStudent::inserter(std::ostream & out) const
{
	out << "Students\'s name:" << this->name << std::endl;
	for (size_t i = 0; i < this->subjects_count; i++)
	{
		out << "grade[" << i + 1 << "]="
			<< this->grades[i] << std::endl;
	}
	return out;
}

double CStudent::sum_grades() const
{
	double sum = 0.;
	for (size_t i = 0; i < this->subjects_count; i++)
	{
		sum += this->grades[i];
	}
	return sum;
}

std::ostream & operator << (std::ostream & left, const CStudent & right)
{
	return right.inserter(left);
}