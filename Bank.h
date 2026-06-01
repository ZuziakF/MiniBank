#pragma once
#include "Client.h"
#include <unordered_map>
#include <string>


class Bank
{
//Struktura klasy bank
private:
	std::unordered_map<std::string, Client> Clients;
	const std::string BankPrefix = "82102052260000";
	long long NextAccountNumber = 100000000000;
	int NextClientID = 1;
	std::string GenerateAccountNumber();
public: 
	void RegisterClient(const std::string& pesel, const std::string& firstname, const std::string& lastname);
	std::string OpenAccountForClient(const std::string& pesel, AccountType type, double initialbalance = 0.0);
	void Deposit(const std::string& pesel, const std::string& accountnumber, double amount);
	void Withdraw(const std::string& pesel, const std::string& accountnumber, double amount);
	double GetBalance(const std::string& pesel, const std::string& accountnumber);
};


