// start Clothes.h
#ifndef CLOTHES
#define CLOTHES

#include "Goods.h"

class Clothes : public Goods
{
private:
	unsigned size;
public:
	Clothes();
	Clothes(unsigned size);
	virtual ~Clothes();

	unsigned get_size() const;

	void set_size(unsigned size);

	virtual void insert_data(std::ostream & out) const;
};

#endif
// end Clothes.h