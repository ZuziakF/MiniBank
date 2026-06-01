#pragma once
#include <string>
class Account
{
private:
	//clientID
	std::string AccountNumber;
	std::string FirstName;
	std::string LastName;
	// U¿ywamy double na potrzeby symulacji (normalnie u¿ylibyœmy np. int dla groszy poniewa¿ typy zmiennoprzecinkowe maj¹ problem z precyzj¹ w u³amkach)
	double Balance;

public:
	Account(const std::string& accountNumber, const std::string& firstName, const std::string& lastName, double initialBalance = 0.0);
	void Deposit(double amount);
	void Withdraw(double amount);
	void DisplayInfo() const;
	std::string GetAccountNumber() const;
	double GetBalance() const;


};

