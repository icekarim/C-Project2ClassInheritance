#pragma once
#include <cstring>
#include <iostream>
#ifndef ACCOUNT_H
#define ACCOUNT_H
using namespace std;
class account
{
public:
	account();
	account(string, long, double);
	~account();
	void SetName(string);
	void SetBalance(double);
	void SetTaxID(long);
	string GetName();
	long GetTaxID();
	double GetBalance();
	void Display();
	void MakeDeposit(double);

private:
	string name;
	long taxID;
	double balance;
protected:
	double last10withdraws[10];
	double last10deposits[10];
	int numdeposits;
	int numwithdraws;

};
#endif
