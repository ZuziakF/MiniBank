#pragma once
#include "Account.h"
#include <unordered_map>
#include <string>

class Bank
{
	private:
		std::unordered_map<std::string, Account> Accounts;
		const std::string BankPrefix = "82102052260000";
		long long NextClientNumber = 100000000000;
		std::string GenerateAccountNumber();
	public:
		std::string CreateAccount(const std::string& FirstName, const std::string LastName, double InitialBalance = 0.0);
		void DepositToAccount(const std::string& AccountNumber, double Amount);
		void WithdrawFromAccount(const std::string& AccountNumber, double Amount);
		void DisplayAccountInfo(const std::string& AccountNumber) const;
		double GetBalance(const std::string& AccountNumber) const;
};	

