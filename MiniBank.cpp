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
    Bank myBank;

    try {
        std::cout << "--- TEST 1: Rejestracja i otwieranie kont ---\n";

        // 1. Rejestrujemy klienta
        myBank.RegisterClient("90010112345", "Jan", "Kowalski");

        // 2. Otwieramy mu dwa różne konta i zapisujemy ich numery
        std::string mainAcc = myBank.OpenAccountForClient("90010112345", AccountType::MAIN, 1000.0);
        std::string savingsAcc = myBank.OpenAccountForClient("90010112345", AccountType::SAVINGS, 5000.0);

        std::cout << "\n--- TEST 2: Operacje finansowe ---\n";

        // 3. Wpłacamy 500 na główne
        std::cout << "Wplacam 500 na konto glowne...\n";
        myBank.Deposit("90010112345", mainAcc, 500.0);

        // 4. Wypłacamy 200 z oszczędnościowego
        std::cout << "Wyplacam 200 z konta oszczednosciowego...\n";
        myBank.Withdraw("90010112345", savingsAcc, 200.0);

        // 5. Sprawdzamy salda
        std::cout << "Saldo konta glownego: " << myBank.GetBalance("90010112345", mainAcc) << " PLN\n";
        std::cout << "Saldo konta oszczednosciowego: " << myBank.GetBalance("90010112345", savingsAcc) << " PLN\n";

        std::cout << "\n--- TEST 3: Zabezpieczenia i wyjatki ---\n";

        // 6. Próbujemy wypłacić więcej niż mamy (to powinno wywołać błąd i przejść do catch)
        std::cout << "Probuje wyplacic 100 000 PLN z konta glownego...\n";
        myBank.Withdraw("90010112345", mainAcc, 100000.0);

        // Jeśli błąd zadziała, ten napis nigdy się nie wyświetli:
        std::cout << "To sie nie powinno wyswietlic!\n";

    }
    catch (const std::exception& e) {
        // Tutaj wpadają wszystkie nasze błędy (np. brak środków, zły pesel)
        std::cerr << "ZLAPANO BLAD: " << e.what() << "\n";
    }

    std::cout << "\nKoniec testow.\n";
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
