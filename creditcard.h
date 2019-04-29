#ifndef CREDITCARD_H
#define CREDITCARD_H
#include "account.h"
class creditcard: public account
{
public:
	creditcard();
	creditcard(string name, long taxID, double balance);
	~creditcard();
	void DoCharge(string name, double amount);
	void MakePayment(double amount);
	void display();

private:
	long cardnumber;
	string last10charges[10];
};
#endif

