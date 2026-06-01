#pragma once
#include <string>

enum class AccountType 
{
	MAIN,
	SAVINGS
};
class Account
{
private:
	std::string AccountNumber;
	AccountType Type;
	// U¿ywamy double na potrzeby symulacji (normalnie u¿ylibyœmy np. int dla groszy poniewa¿ typy zmiennoprzecinkowe maj¹ problem z precyzj¹ w u³amkach)
	double Balance;

public:
	Account(const std::string& accountNumber, AccountType type, double initialBalance = 0.0);
	void Deposit(double amount);
	void Withdraw(double amount);
	std::string GetAccountNumber() const;
	double GetBalance() const;
	AccountType GetType() const;


};

