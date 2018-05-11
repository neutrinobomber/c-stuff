// start SoftwareCompany.h
#ifndef SOFTWARE_COMPANY
#define SOFTWARE_COMPANY

#include "Company.h"

class SoftwareCompany : public Company
{
private:
	double rent_cost;
public:
	SoftwareCompany();
	SoftwareCompany(
		const Employee * employees,
		unsigned employees_count,
		double overhead_costs,
		double rent_cost);
	virtual ~SoftwareCompany();

	virtual double costs();

	double get_rent_cost() const;

	void set_rent_cost(double rent_cost);

	virtual void insert_data(std::ostream & out) const;
};

#endif
// end SoftwareCompany.h