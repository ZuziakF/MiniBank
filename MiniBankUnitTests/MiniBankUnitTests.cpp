#include "pch.h"
#include "CppUnitTest.h"
#include "../Client.h"
#include "../Account.h"
#include "../Bank.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MiniBankTests
{
    //Testy dla clasy klient
    TEST_CLASS(ClientTests)
    {
    public:

        // Testujemy dlugosc PESELu
        TEST_METHOD(ThrowException_WhenPeselIsTooShort)
        {
            auto CreateClient = [] { Client(1, "12345", "Jan", "Kowalski"); };
            Assert::ExpectException<std::invalid_argument>(CreateClient);
        }

        // Testujrmy dlugosc PESELu
        TEST_METHOD(ThrowException_WhenPeselIsTooLong)
        {
            auto CreateClient = [] { Client(1, "1234567890123", "Jan", "Kowalski"); };
            Assert::ExpectException<std::invalid_argument>(CreateClient);
        }

        //Testujemy cyfry w PESELu
        TEST_METHOD(ThrowException_WhenPeselContainsLetters)
        {
            auto CreateClient = [] { Client(1, "11111A11116", "Jan", "Kowalski"); };
            Assert::ExpectException<std::invalid_argument>(CreateClient);
        }
    };
    //Testy dla klasy account
    TEST_CLASS(AccountTests)
    {
    public:
        //Test dla depozytu
        TEST_METHOD(IncreaseBalance_WhenDepositIsMade)
        {
            Account Account("NUMER_123", AccountType::MAIN, 100.0);
            Account.Deposit(50.0);
            Assert::AreEqual(150.0, Account.GetBalance());
        }
        //Test dla ujemnego depozytu
        TEST_METHOD(ThrowException_WhenDepositIsNegative)
        {
            Account Account("NUMER_123", AccountType::MAIN, 100.0);
            auto BadDeposit = [&Account] { Account.Deposit(-10.0); };
            Assert::ExpectException<std::invalid_argument>(BadDeposit);
        }
        //Test dla ujemnej wplaty
        TEST_METHOD(DecreaseBalance_WhenWithdrawalIsMade)
        {
            Account Account("NUMER_123", AccountType::MAIN, 100.0);
            Account.Withdraw(40.0);
            Assert::AreEqual(60.0, Account.GetBalance());
        }
        //Test dla ujemnej wyplaty
        TEST_METHOD(ThrowException_WhenWithdrawalIsNegative)
        {
            Account Account("NUMER_123", AccountType::MAIN, 100.0);
            auto badWithdraw = [&Account] { Account.Withdraw(-20.0); };
            Assert::ExpectException<std::invalid_argument>(badWithdraw);
        }
        //Test dka przekroczenia bilansu przy wyplacie
        TEST_METHOD(ThrowException_WhenWithdrawalExceedsBalance)
        {
            Account Account("NUMER_123", AccountType::MAIN, 100.0);
            auto Overdraw = [&Account] { Account.Withdraw(200.0); };
            Assert::ExpectException<std::runtime_error>(Overdraw);
        }
    };
    //Testy dla klasy bank
    TEST_CLASS(BankTests)
    {
    public:
        //Test czy rejestracja i otwieranie kont dziala poprawnie
        TEST_METHOD(RegisterClientAndOpenAccount)
        {
            Bank bank;
            bank.RegisterClient("11111111116", "Jan", "Kowalski");
            std::string AccNum = bank.OpenAccountForClient("11111111116", AccountType::MAIN, 250.0);

            Assert::AreEqual(250.0, bank.GetBalance("11111111116", AccNum));
        }
        //Test dla tego samego peselu przy rejestracji
        TEST_METHOD(ThrowException_WhenRegisteringExistingClient)
        {
            Bank bank;
            bank.RegisterClient("11111111116", "Jan", "Kowalski");
            auto RegisterAgain = [&bank] { bank.RegisterClient("11111111116", "Anna", "Nowak"); };

            Assert::ExpectException<std::invalid_argument>(RegisterAgain);
        }
        //Test dla otwarcia konta dla nieistniejacego uztykownika
        TEST_METHOD(ThrowException_WhenOpeningAccountForUnknownClient)
        {
            Bank bank;
            auto OpenAcc = [&bank] { bank.OpenAccountForClient("11111111116", AccountType::MAIN, 100.0); };

            Assert::ExpectException<std::invalid_argument>(OpenAcc);
        }
    };
}