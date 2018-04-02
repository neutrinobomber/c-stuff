// start main.cpp
#include <iostream>

#include "Employee.h"
#include "Manager.h"
#include "Executive.h"

using namespace std;

int main()
{
	Manager * emps[2];
	emps[0] = new Manager("manager", 1, 2, "div");
	emps[1] = new Executive("exec", 4, 5, "other");
	
	emps[0]->print();
	emps[1]->print();

	return 0;
}
// end main.cpp