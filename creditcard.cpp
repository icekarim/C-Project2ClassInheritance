#include "stdafx.h"
#include "creditcard.h"
#include <string>
#include <iostream>
#include<cstring>

using namespace std;

creditcard::creditcard()
{
	SetName("John Doe");
	SetTaxID(5555555555);
	SetBalance(100);
}
creditcard::creditcard(string name, long taxID, double balance) {
	SetName(name);
	SetTaxID(taxID);
	SetBalance(balance);
}
void creditcard::DoCharge(string nameC, double amount) {
	double temp = amount;
	SetBalance((GetBalance() + amount));
	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (last10deposits[i] != NULL) {
			count++;
		}
	}
	for (int i = count - 1; i>0; i--)
	{
		last10deposits[i] = last10deposits[i - 1];
	}
	last10deposits[0] = temp;

	string temp3 = nameC;
	for (int i = count - 1; i>0; i--)
	{
		last10charges[i] = last10charges[i - 1];
	}
	last10charges[0] = nameC;
}

void creditcard::MakePayment(double amount) {
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

void creditcard::display() {

	for (int i = 0; i < 10; i++) {

		if (last10charges[i] != "") {
			cout << "charger issuers" << endl;
			std::cout << last10charges[i] << "            ";
		}

		if (last10deposits[i] >= 0) {
			cout << "      charge amount          " << last10deposits[i] << endl;
		}

	}
	cout << "Payments" << endl;
	for (int i = 0; i < 10; i++) {
		if (last10withdraws[i] >= 0) {
			cout << last10withdraws[i] << " " << last10withdraws[i] << endl;
		}
	}
}




creditcard::~creditcard()
{

}
