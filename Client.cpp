#include "Client.h"
#include <stdexcept>
#include <cctype>

Client::Client(int id, const std::string& pesel, const std::string& firstname, const std::string& lastname)
{
    //Sprawdzamy poprawnoúÊ PESELu
    if (pesel.length() != 11) {
        throw std::invalid_argument("PESEL musi sk≥adaÊ siÍ z dok≥adnie 11 znakÛw!");
    }

    for (char c : pesel) {
        if (!isdigit(c)) {
            throw std::invalid_argument("PESEL moøe zawieraÊ tylko cyfry!");
        }
    }
    this->PESEL = pesel;
    this->FirstName = firstname;
    this->LastName = lastname;
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
	return " " + FirstName + " " + LastName + " ";
}

//Getter dla kont
const std::unordered_map<std::string, Account>& Client::GetAllAccounts() const
{
	return Accounts;
}