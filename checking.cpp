#include "stdafx.h"
#include "checking.h"


checking::checking()
{
	SetName("John Doe");
	SetTaxID(5555555555);
	SetBalance(100);
}
checking::checking(string name, long taxID, double balance) {
	SetName(name);
	SetTaxID(taxID);
	SetBalance(balance);
}
void checking::WriteCheck(int checknum, double amount) {
	double temp = amount;
	SetBalance((GetBalance() - amount));
	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (last10withdraws[i] != NULL) {
			count++;
		}
	}
	for (int i = count - 1; i>0; i--)
	{
		last10withdraws[i] = last10withdraws[i - 1];
	}
	last10withdraws[0] = temp;

	temp = checknum;
	int count2 = 0;
	for (int i = 0; i < 10; i++) {
		if (last10checks[i] != NULL) {
			count2++;
		}
	}
	for (int i = count - 1; i>0; i--)
	{
		last10checks[i] = last10checks[i - 1];
	}
	last10checks[0] = temp;
}
void checking::Display() {
	cout << "Recent Checks" << endl;
	for (int i = 0; i < 10; i++) {
		if (last10checks[i] >= 0) {
			cout << last10checks[i] << " " << last10withdraws[i] << endl;
		}
	}
}


checking::~checking()
{
}
