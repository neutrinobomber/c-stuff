// start HotelRoom.h
#ifndef HOTEL_ROOM
#define HOTEL_ROOM

class HotelRoom
{
private:
	unsigned *room_ids;
	double *prices;
	unsigned reservations_count;

	void clean_data();
public:
	HotelRoom();
	HotelRoom(unsigned reservations_count, unsigned *ids, double *prices);
	HotelRoom(HotelRoom &other);
	~HotelRoom();

	HotelRoom& operator=(const HotelRoom &other);

	void add_reservaton(unsigned id, double price);
	double get_highest_price() const;
};

void print_highest_price(const HotelRoom &room);

#endif
// end HotelRoom.h