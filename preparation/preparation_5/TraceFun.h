#pragma once

#include <iostream>

class TraceFun
{
private:
	char * name;
	std::ostream * out;
public:
	TraceFun();
	TraceFun(const char * func_name, std::ostream & out);
	TraceFun(const TraceFun & other);
	virtual ~TraceFun();

	TraceFun& operator=(const TraceFun & other);

	void set_func_name(const char * func_name);
	void set_out(std::ostream * out);

	const char * get_fun_name() const;
	const std::ostream * get_out() const;
};