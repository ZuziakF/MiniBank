#include "Bank.h"
#include <iostream>
#include <stdexcept>


//Generowanie numeru konta
std::string Bank::GenerateAccountNumber()
{
	std::string NewNumber = BankPrefix + std::to_string(NextClientNumber);
	NextClientNumber++;
	return NewNumber;
}


//Tworzenie konta
std::string Bank::CreateAccount(const std::string& FirstName, const std::string LastName, double InitialBalance)
{
	std::string AccountNumber = GenerateAccountNumber();
	Account NewAccount(AccountNumber, FirstName, LastName, InitialBalance);
	Accounts.insert({AccountNumber,NewAccount});
	std::cout << "Utworzono Konto o numerze: " + AccountNumber;
	return AccountNumber;
}


//Depozyt
void Bank::DepositToAccount(const std::string& AccountNumber, double Amount)
{
	auto it = Accounts.find(AccountNumber);
	if (it == Accounts.end()) throw std::invalid_argument("Nie znaleziono konta o numerze " + AccountNumber);
	it->second.Deposit(Amount);
}


//Wyplata
void Bank::WithdrawFromAccount(const std::string& AccountNumber, double Amount)
{
	auto it = Accounts.find(AccountNumber);
	if (it == Accounts.end()) throw std::invalid_argument("Nie znaleziono konta o numerze " + AccountNumber);

	it->second.Withdraw(Amount);
}

//Pokazywanie informacji o koncie
void Bank::DisplayAccountInfo(const std::string& AccountNumber) const
{
	auto it = Accounts.find(AccountNumber);
	if (it == Accounts.end())  throw std::invalid_argument("Blad: Nie znaleziono konta o numerze " + AccountNumber);

	it->second.DisplayInfo();
	
}
double Bank::GetBalance(const std::string& AccountNumber) const
{
	auto it = Accounts.find(AccountNumber);
	if (it == Accounts.end()) throw std::invalid_argument("Nie znaleziono konta o numerze " + AccountNumber);

	return it->second.GetBalance();
}
