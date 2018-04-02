// start Executive.h
#ifndef EXECUTIVE
#define EXECUTIVE

#include <iostream>

#include "Manager.h"

class Executive : public Manager
{
public:
	Executive();
	Executive(const char * name, unsigned salary, unsigned experience, const char * division);

	virtual void print() const;
};

#endif
// end Executive.h