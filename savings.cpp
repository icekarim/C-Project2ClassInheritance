#include "stdafx.h"
#include "savings.h"


savings::savings()
{
	SetName("John Doe");
	SetTaxID(5555555555);
	SetBalance(100);
}
savings::savings(string name, long taxID, double balance) {
	SetName(name);
	SetTaxID(taxID);
	SetBalance(balance);
}
void savings::DoWithdraw(double amount) {
	SetBalance((GetBalance() - amount));
	double temp = amount;
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
}

void savings::display() {
	
	for (int i = 0; i < 10; i++) {
		if (last10withdraws[i] >= 0) {
			cout << "withdraws" <<  endl;
			cout << last10withdraws[i] << "           ";
		}
			if (last10deposits[i] >= 0) {
				cout << "      deposits           " << last10deposits[i] << endl;
			}
		
	}
}

savings::~savings()
{
}
