#include "MiniBankGUI.h"
#include "../Bank.h"
#include <QString>
#include <QMessageBox>

MiniBankGUI::MiniBankGUI(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MiniBankGUIClass)
{
    ui->setupUi(this);
    bank = new Bank();
    ui->FirstNameInput->setPlaceholderText("Imie");
    ui->LastNameInput->setPlaceholderText("Nazwisko");
    ui->PeselInput->setPlaceholderText("PESEL");
    //Pod³¹czamy elelemty
    connect(ui->RegisterClientBtn, &QPushButton::clicked, this, &MiniBankGUI::onRegisterClientClicked);
    connect(ui->OpenAccountBtn, &QPushButton::clicked, this, &MiniBankGUI::onCreateAccountClicked);
    connect(ui->ClientSelector, &QComboBox::currentIndexChanged, this, &MiniBankGUI::onClientChanged);
    connect(ui->AccountsList, &QListWidget::currentTextChanged, this, &MiniBankGUI::onAccountSelected);
    connect(ui->DepositBtn, &QPushButton::clicked, this, &MiniBankGUI::onDepositClicked);
    connect(ui->WithdrawBtn, &QPushButton::clicked, this, &MiniBankGUI::onWithdrawClicked);
}


//Usuwanie po zamknieciu
MiniBankGUI::~MiniBankGUI()
{
    delete ui;   
    delete bank; 
}
//Tworzenie Konta
void MiniBankGUI::onCreateAccountClicked()
{
    if(ui->ClientSelector->count()==0)
    {
        QMessageBox::warning(this, "B³¹d","Brak klienta do wyboru");
        return;
    }
    std::string Pesel = ui->ClientSelector->currentData().toString().toStdString();
    QString TypeStr = ui->AccountTypeSelector->currentText();
    if (TypeStr != "Glowne" && TypeStr != "Oszczednosciowe") 
    {
        QMessageBox::warning(this, "Blad", "Prosze wybrac poprawny typ konta (Glowne lub Oszczednosciowe)!");
        return;
    }
    AccountType Type = (TypeStr == "Oszczednosciowe") ? AccountType::SAVINGS : AccountType::MAIN;
    double InitialBalance = ui->InitialBalanceInput->value();
    try
    {
        std::string NewAccountNumber = bank->OpenAccountForClient(Pesel, Type, InitialBalance);
        ui->AccountsList->addItem(QString::fromStdString(NewAccountNumber));
        ui->InitialBalanceInput->setValue(0.0);
    }
    catch (const std::exception& e)
    {
        QMessageBox::warning(this, "Nie uda³o siê otworzyæ konta", e.what());
    }

}

//£adowanie kont dla zaznaczonej osoby
void MiniBankGUI::onClientChanged()
{
    ui->AccountsList->clear();
    ui->BalanceLabel->setText("Saldo: brak");
    ui->OwnerLabel->setText("Posiadajacy: brak");

    if (ui->ClientSelector->currentIndex() == -1) return; //W przypadku gdy nie ma kogo wybraæ
    std::string ActivePesel = ui->ClientSelector->currentData().toString().toStdString();
    Client* ActiveClient = bank->GetClient(ActivePesel);

    if (ActiveClient != nullptr) {
        for (const auto& pair : ActiveClient->GetAllAccounts()) {
            ui->AccountsList->addItem(QString::fromStdString(pair.first));
        }
    }
}
//Przy wyborze konta z listy
void MiniBankGUI::onAccountSelected(const QString& AccountNumber)
{
    if (AccountNumber.isEmpty()) 
    {
        ui->BalanceLabel->setText("Saldo: brak");
        ui->OwnerLabel->setText("Posiadajacy: brak");
        return;
    }
    std::string AccNum = AccountNumber.toStdString();
    std::string  ActivePesel = ui->ClientSelector->currentData().toString().toStdString();
    Client* ActiveClient = bank->GetClient(ActivePesel);

    if (ActiveClient != nullptr)
    {
        const auto& Accounts = ActiveClient->GetAllAccounts();
        auto it = Accounts.find(AccNum);
        if (it != Accounts.end())
        {
            double balance = it->second.GetBalance();
            ui->BalanceLabel->setText("Saldo: " + QString::number(balance,'f',2) + "branient->GetFullName()));
        }
    }
}
<<<<<<< Updated upstream
=======

//Przycisk wplac
>>>>>>> Stashed changes
void MiniBankGUI::onDepositClicked()
{
   
    if (ui->AccountsList->currentItem() == nullptr) 
    {
        QMessageBox::warning(this, "Blad", "Wybierz najpierw konto z listy!");
        return;
    }
    std::string accNum = ui->AccountsList->currentItem()->text().toStdString();
    std::string activePesel = ui->ClientSelector->currentData().toString().toStdString();
    double amount = ui->AmountInput->value();
    if (amount <= 0) 
    {
        QMessageBox::warning(this, "Blad", "Kwota wplaty musi byæ wieksza od zera!");
        return;
    }
    try 
    {
      
        bank->Deposit(activePesel, accNum, amount);
        ui->AmountInput->setValue(0.0);
        QMessageBox::information(this, "Sukces", "Wplacono pieniadze na konto.");
        onAccountSelected(QString::fromStdString(accNum));
    }
    catch (const std::exception& e) 
    {
        QMessageBox::critical(this, "Blad transakcji", e.what());
    }
}

//Przycisk wyplac
void MiniBankGUI::onWithdrawClicked()
{
   
    if (ui->AccountsList->currentItem() == nullptr) 
    {
        QMessageBox::warning(this, "Blad", "Wybierz najpierw konto z listy!");
        return;
    }
    std::string AccNum = ui->AccountsList->currentItem()->text().toStdString();
    std::string ActivePesel = ui->ClientSelector->currentData().toString().toStdString();
    double amount = ui->AmountInput->value();
    if (amount <= 0) 
    {
        QMessageBox::warning(this, "Blad", "Kwota wyplaty musi byc wieksza od zera!");
        return;
    }
    try 
    {
        bank->Withdraw(ActivePesel, AccNum, amount);
        ui->AmountInput->setValue(0.0);
        QMessageBox::information(this, "Sukces", "Wyplacono pieniadze.");
        onAccountSelected(QString::fromStdString(AccNum));
    }
    catch (const std::exception& e) 
    {
        QMessageBox::critical(this, "Odmowa", e.what());
    }
}
<<<<<<< Updated upstream
=======

//Rejestrujemy klienta
>>>>>>> Stashed changes
void MiniBankGUI::onRegisterClientClicked()
{
    std::string firstName = ui->FirstNameInput->text().toStdString();
    std::string lastName = ui->LastNameInput->text().toStdString();
    std::string pesel = ui->PeselInput->text().toStdString();
    if (firstName.empty() || lastName.empty() || pesel.empty()) 
    {
        QMessageBox::warning(this, "Blad", "Wypelnij wszystkie pola!");
        return;
    }

    try 
    {
        bank->RegisterClient(pesel, firstName, lastName);
        QString displayName = QString::fromStdString(firstName + " " + lastName);
        QString hiddenPesel = QString::fromStdString(pesel);
        ui->ClientSelector->addItem(displayName, hiddenPesel);
        ui->FirstNameInput->clear();
        ui->LastNameInput->clear();
        ui->PeselInput->clear();
        QMessageBox::information(this, "Sukces", "Zarejestrowano klienta!");
    }
    catch (const std::exception& e) 
    {
        QMessageBox::critical(this, "Blad rejestracji", e.what());
    }
}

