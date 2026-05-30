#include <iostream>
#include <string>
#include <limits> // Do czyszczenia bufora konsoli
#include "Bank.h"

void ClearInput() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int main()
{
	Bank MyBank;
	bool Running = true;
	int Choice;

	while (Running) 
	{
		//Wybor opcji
		std::cout << "\nWybierz operacje:\n";
		std::cout << "1. Utworz nowe konto\n";
		std::cout << "2. Wplac srodki\n";
		std::cout << "3. Wyplac srodki\n";
		std::cout << "4. Wyswietl informacje o koncie\n";
		std::cout << "5. Wyjscie\n";
		std::cout << "Twoj wybor: ";

		if (!(std::cin >> Choice)) {
			std::cout << "Nieprawidlowy wybor. \n";
			ClearInput();
			continue;
		}
		std::string AccNumber, FirstName, LastName;
		double Amount;


		switch (Choice) 
		{
		//Zakladanie nowego konta
		case 1:
			std::cout << "Podaj imie: ";
			std::cin >> FirstName;
			std::cout << "Podaj nazwisko ";
			std::cin >> LastName;

			try 
			{
				MyBank.CreateAccount(FirstName, LastName);
			} 
			catch (const std::exception& e)
			{
				std::cout << "Blad: " << e.what() << "\n";
			}
			break;


		//Wplata
		case 2:
			std::cout << "Podaj numer konta: ";
			std::cin >> AccNumber;
			std::cout << "Podaj kwote do wplaty: ";
			if (!(std::cin >> Amount))
			{
				std::cout << "Nieprawidlowa kwota.\n";
				ClearInput();
				break;
			}
			try
			{
				MyBank.DepositToAccount(AccNumber, Amount);
				std::cout << "Wplata zakonczona!\n";
			}
			catch (const std::exception& e) 
			{
				std::cout << e.what() << "\n";
			}


		//Wyplata
		case 3:
			std::cout << "Podaj numer konta: ";
			std::cin >> AccNumber;
			std::cout << "Podaj kwote do wplaty: ";
			if (!(std::cin >> Amount))
			{
				std::cout << "Nieprawidlowa kwota.\n";
				ClearInput();
				break;
			}
			try
			{
				MyBank.WithdrawFromAccount(AccNumber, Amount);
				std::cout << "Wyplata zakonczona!\n";
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << "\n";
			}


		//Wyswietlanie informacji
		case 4:
			std::cout << "Podaj numer konta: ";
			std::cin >> AccNumber;
			try
			{
				MyBank.DisplayAccountInfo(AccNumber);
			}
			catch (const std::exception& e)
			{
				std::cout<< e.what() << "\n";
			}
			break;


		//Wyjscie
		case 5:
			std::cout << "Dziekujemy za skrozystanie z banku. Do uslyszenia!";
			Running = false;
			break;
		default:
			std::cout << "Nieznana opcja. Wybierz cyfre od 1 do 5.";
			break;
		}
	}
	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
