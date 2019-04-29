#include "stdafx.h"
#include "account.h"
#include <iostream>
#include <cstring>
using namespace std;

account::account()
{
	name = "john doe";
	taxID = 5555555555;
	balance = 100;
}
account::account(string newName, long newID, double newBal)
{
	SetName(newName);
	SetTaxID(newID);
	SetBalance(newBal);
}
void account::SetName(string newName)
{
	this->name = newName;
}
void account::SetBalance(double newBalance)
{
		this->balance = newBalance;
}
void account::SetTaxID(long newID) {
	if (newID >= 1) {
		this->taxID = newID;
	}
	else {
		cout << "Not a Valid ID" << endl;
	}
}
string account::GetName() {
	return name;
}
long account::GetTaxID() {
	return taxID;
}
double account::GetBalance() {
	return balance;
}
void account::Display() {
	cout << "Name: ";
	GetName();
	cout << "Tax ID: " << GetTaxID()<< endl;
	cout << "Balance: " << GetBalance() << endl;
}
void account::MakeDeposit(double newB) {
	double temp = newB;
	SetBalance((GetBalance() + newB));
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
}

account::~account()
{
}
