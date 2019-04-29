#ifndef SAVINGS_H
#define SAVINGS_H
#include "account.h"
class savings : public account
{
public:
	savings();
	savings(string name, long taxID, double balance);
	~savings();
	void DoWithdraw(double amount);
	void display();
};
#endif

