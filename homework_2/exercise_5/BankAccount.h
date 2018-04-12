// start BankAccount.h
#ifndef BANK_ACCOUNT
#define BANK_ACCOUNT

class BankAccount
{
private:
	const char * holder_name;
	double amount;
	double credit_limit;
public:
	BankAccount();
	BankAccount(const char * holder_name, double amount, double credit_limit);

	const char * get_holder_name() const;
	double get_amount() const;
	double get_credit_limit() const;

	void set_holder_name(const char * new_name);
	void set_amount(double new_amount);
	void set_credit_limit(double new_limit);

	bool operator==(const BankAccount & other) const;
	bool operator!=(const BankAccount & other) const;

	BankAccount & operator+=(double add_sum);
	BankAccount & operator-=(double subtract_sum);
	BankAccount & operator*=(unsigned charge_percent);
};

#endif
// end BankAccount.h