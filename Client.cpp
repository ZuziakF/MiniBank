#include "Client.h"

Client::Client(int id, const std::string& pesel, const std::string& firstname, const std::string& lastname)
	: ClientID(id), PESEL(pesel), FirstName(firstname), LastName(lastname)
{
}
//Dodajemy nowe konto
void Client::AddAccount(const Account& NewAccount)
{
	Accounts.insert({NewAccount.GetAccountNumber(),NewAccount });
}

Account* Client::GetAccount(const std::string& AccountNumber)
{
	auto it = Accounts.find(AccountNumber);
	if (it != Accounts.end()) return &(it->second); //Zwracamy wskaünik na konto

	return nullptr;
}
//Getter dla peselu
std::string Client::GetPesel() const
{
	return PESEL;
}
//Getter dla imienia i nazwiska
std::string Client::GetFullName() const
{
	return FirstName + " " + LastName;
}
