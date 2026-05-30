#include "Account.h"
#include <iostream>

Account::Account(const std::string& Anumber, const std::string& FName, const std::string& LName, double Initialbalance)
	: AccountNumber(Anumber), FirstName(FName), LastName(LName), Balance(Initialbalance) 
{
}

//Wplata 
void Account::Deposit(double amount)
{
	if (amount > 0) Balance += amount;
 else {
	 // Opcjonalne zabezpieczenie przed wp³at¹ ujemnych kwot
	 std::cout << "Blad: Kwota wplaty musi byc wieksza od zera.\n";
	}
}

//Wyplata
bool Account::Withdraw(double amount)
{
	//Sprawdzam warunki wyplaty
	if (amount > Balance && amount > 0)
	{
		Balance -= amount;
		return true;
	}
	return false;
}

void Account::DisplayInfo() const
{
	std::cout << "Konto nr: " << AccountNumber << "\n";
	std::cout << "Wlasciciel: " << FirstName << " " << LastName << "\n";
	std::cout << "Saldo: " << Balance << " PLN\n";
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

