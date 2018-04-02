// start Executive.cpp
#include <iostream>

#include "Executive.h"
#include "Manager.h"

Executive::Executive() : Manager() {}

Executive::Executive(const char * name, unsigned salary, unsigned experience, const char * division) :
	Manager(name, salary, experience, division) {}

void Executive::print() const
{
	std::cout << "Executive ";
	Manager::print();
}
// end Executive.cpp