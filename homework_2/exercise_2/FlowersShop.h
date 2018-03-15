// start FlowersShop.h
#ifndef FLOWERS_SHOP
#define FLOWERS_SHOP

class FlowersShop
{
private:
	float single_price;
	unsigned flowers_count;

public:
	FlowersShop();
	FlowersShop(unsigned flowers_count);
	FlowersShop(float single_price);
	FlowersShop(unsigned flowers_count, float single_price);

	void increase_flowers(unsigned count);
	void decrease_flowers(unsigned count);

	void increase_single_price(float price);
	void decrease_single_price(float price);

	void print() const;
	double calculate_profit() const;

	FlowersShop simulating_price_decrease() const;
};

#endif
// end FlowersShop.h