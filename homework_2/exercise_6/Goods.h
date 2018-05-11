// start Goods.h
#ifndef GOODS
#define GOODS

class Goods
{
private:
	char * name;
	unsigned price;

	void delete_name();
public:
	Goods();
	Goods(const char * name, unsigned price);
	virtual ~Goods();

	const char * get_name() const;
	unsigned get_price() const;

	void set_name(const char * name);
	void set_price(unsigned price);

	virtual void insert_data(std::ostream & out) const;
};

std::ostream & operator<<(std::ostream & out, const Goods & other);

#endif
// end Goods.h