// start ClothingShop.h
#ifndef CLOTHING_SHOP
#define CLOTHING_SHOP

#include "Company.h"
#include "Clothes.h"

class ClothingShop : public Company
{
private:
	Clothes * clothes;
	unsigned clothes_count;

	void delete_clothes();
public:
	ClothingShop();
	ClothingShop(
		const Employee * employees,
		unsigned employees_count,
		double overhead_costs,
		const Clothes * clothes,
		unsigned clothes_count);
	virtual ~ClothingShop();

	virtual double costs() const;

	const Clothes * get_clothes() const;
	unsigned get_clothes_count() const;

	void set_clothes(const Clothes * clothes, unsigned clothes_count);

	virtual void insert_data(std::ostream & out) const;
};

#endif
// end ClothingShop.h