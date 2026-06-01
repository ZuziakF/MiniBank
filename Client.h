#pragma once
#include <string>
#include <unordered_map>
#include "Account.h"
class Client
{
private:
	int ClientID;
	std::string PESEL;
	std::string FirstName;
	std::string LastName;
	std::unordered_map<std::string, Account> Accounts;
public:
	Client(int id, const std::string& pesel, const std::string& firstname, const std::string& lastname);
	void AddAccount(const Account& NewAccount);
	Account* GetAccount(const std::string& AccountNumber);
	std::string GetPesel() const;
	std::string GetFullName() const;
};

