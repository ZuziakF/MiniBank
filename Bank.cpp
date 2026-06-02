#include "Bank.h"
#include <iostream>
#include <stdexcept>


//Generowanie numeru konta
std::string Bank::GenerateAccountNumber()
{
	std::string NewNumber = BankPrefix + std::to_string(NextAccountNumber);
	NextAccountNumber++;
	return NewNumber;
}

//Rejestrujemy klienta
void Bank::RegisterClient(const std::string& pesel, const std::string& firstname, const std::string& lastname)
{
	if (Clients.find(pesel) != Clients.end())
		throw std::invalid_argument("Klient o podanym numerze PESEL ju¿ istnieje");
	Client NewClient(NextClientID, pesel, firstname, lastname);
	Clients.insert({ pesel,NewClient });
	NextClientID++;
}

//Otwieramy konto
std::string Bank::OpenAccountForClient(const std::string& pesel, AccountType type, double initialbalance)
{
	//Szukamy klienta
	auto it = Clients.find(pesel);
	if(it == Clients.end()) throw std::invalid_argument("Nie znaleziono klienta o podanym numerze PESEL.");
	//Otwieramy nowe konto
	std::string NewAccountNumber = GenerateAccountNumber();
	Account NewAccount(NewAccountNumber, type, initialbalance);
	it->second.AddAccount(NewAccount);
	std::string typeName = (type == AccountType::MAIN) ? "Glowne" : "Oszczednosciowe";
	return NewAccountNumber;
}

void Bank::Deposit(const std::string& pesel, const std::string& accountnumber, double amount)
{
	//Szukamy klienta
	auto it = Clients.find(pesel);
	if(it==Clients.end()) throw std::invalid_argument("Nie znaleziono klienta.");
	//Wykonujemy depozyt
	Account* Acc = it->second.GetAccount(accountnumber);
	if (!Acc) throw std::invalid_argument("Nie znaleziono konta u tego klienta.");
	Acc->Deposit(amount);
}	

void Bank::Withdraw(const std::string& pesel, const std::string& accountnumber, double amount)
{
	//Szukamy klienta
	auto it = Clients.find(pesel);
	if (it == Clients.end()) throw std::invalid_argument("Nie znaleziono klienta.");
	//Wykonujemy wyplate
	Account* Acc = it->second.GetAccount(accountnumber);
	if (!Acc) throw std::invalid_argument("Nie znaleziono konta u tego klienta.");
	Acc->Withdraw(amount);
}
//Informacja o saldzie
double Bank::GetBalance(const std::string& pesel, const std::string& accountnumber)
{
	auto it = Clients.find(pesel);
	if (it == Clients.end()) throw std::invalid_argument("Nie znaleziono klienta.");

	Account* Acc = it->second.GetAccount(accountnumber);
	if (!Acc) throw std::invalid_argument("Nie znaleziono konta u tego klienta.");
	return Acc->GetBalance();
}

//Wyciagamy konkretnego klienta aby mieæ jego konta
Client* Bank::GetClient(const std::string& pesel)
{
	auto it = Clients.find(pesel);
	if (it != Clients.end()) {
		return &(it->second);
	}
	return nullptr;
}


