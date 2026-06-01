#include "Account.h"
#include <iostream>

Account::Account(const std::string& Anumber,AccountType Type, double Initialbalance)
	: AccountNumber(Anumber),Type(Type), Balance(Initialbalance)
{
}

//Wplata 
void Account::Deposit(double amount)
{
	if (amount <= 0) throw std::invalid_argument("Kwota wplaty musi byc wieksza od zera.");
	
	Balance += amount;
}

//Wyplata
void Account::Withdraw(double amount)
{
	if (amount <= 0) throw std::invalid_argument("Kwota wyplaty musi byc wieksza od zera.");
	if (Balance < amount) throw std::runtime_error("Brak wystarczajacych srodkow na koncie.");
	Balance -= amount;
}

//Getter dla numeru konta
std::string Account::GetAccountNumber() const
{
	return AccountNumber;
}

//Getter dla salda konta
double Account::GetBalance() const
{
	return Balance;
}

//Getter dla typu konta
AccountType Account::GetType() const
{
	return Type;
}
