#ifndef CHECKING_H
#define CHECKING_H
#include "account.h"
class checking: public account
{
public:
	checking();
	checking(string name, long taxID, double balance);
	~checking();
	void WriteCheck(int checknum, double amount);
	void Display();
private:
	int last10checks[10];
};
#endif

