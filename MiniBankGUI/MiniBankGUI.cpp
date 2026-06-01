#include "MiniBankGUI.h"
#include "../Bank.h"
#include <QString>
#include <QMessageBox>

MiniBankGUI::MiniBankGUI(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    bank = new Bank();

    connect(ui.Depositbtn, &QPushButton::clicked, this, &MiniBankGUI::onDepositClicked);
    connect(ui.WithdrawBtn, &QPushButton::clicked, this, &MiniBankGUI::onWithdrawClicked);
    connect(ui.CreateAccountBtn, &QPushButton::clicked, this, &MiniBankGUI::onCreateAccountClicked);
    connect(ui.AccountSelector, &QComboBox::currentTextChanged, this, &MiniBankGUI::onAccountSelected);

    ui.BalanceLabel->setText("Brak aktywnego konta. \nUtworz konto, aby zaczac.");
}
MiniBankGUI::~MiniBankGUI()
{
    delete bank;
}

void MiniBankGUI::onCreateAccountClicked()
{
    std::string FirstName = ui.FirstNameInput->text().toStdString();
    std::string LastName = ui.LastNameInput->text().toStdString();

    if (FirstName.empty() || LastName.empty()) {
        QMessageBox::warning(this, "B³¹d", "WprowadŸ imiê i nazwisko!");
        return;
    }
    
    // Tworzymy konto
    CurrentAccount = bank->CreateAccount(FirstName, LastName, 0.0);
    QString qFirstName = QString::fromStdString(FirstName);
    QString qLastName = QString::fromStdString(LastName);
    QString FirstLetter = qLastName.left(1).toUpper(); 
    //Robimy to dla lepszego pogladu na konto (np Kamil N.)
    QString displayText = QString::fromStdString(CurrentAccount) + " - " + qFirstName + " " + FirstLetter + ".";
    ui.AccountSelector->addItem(displayText, QString::fromStdString(CurrentAccount));
    ui.AccountSelector->setCurrentText(displayText);
    ui.FirstNameInput->clear();
    ui.LastNameInput->clear();
    QMessageBox::information(this, "Sukces", "Utworzono nowe konto dla: " + QString::fromStdString(FirstName + " " + LastName));

 
}

void MiniBankGUI::onAccountSelected(const QString&)
{
    QString AccountNum = ui.AccountSelector->currentData().toString();
    if (AccountNum.isEmpty()) return;
    CurrentAccount = AccountNum.toStdString();
    try {
        double CurrentBalance = bank->GetBalance(CurrentAccount);
        ui.BalanceLabel->setText("Konto: " + AccountNum + "\nSaldo: " + QString::number(CurrentBalance) + " PLN");
    }
    catch (const std::exception& e) {
        ui.BalanceLabel->setText("B³¹d: " + QString(e.what()));
    }
}

void MiniBankGUI::onDepositClicked()
{
    if (CurrentAccount.empty()) {
        QMessageBox::warning(this, "B³¹d", "Najpierw utwórz konto!");
        return;
    }

    try {
        double Amount = ui.AmountInput->text().toDouble();
        bank->DepositToAccount(CurrentAccount, Amount);
        double CurrentBalance = bank->GetBalance(CurrentAccount);
        ui.BalanceLabel->setText("Konto: " + QString::fromStdString(CurrentAccount) + "\nSaldo: " + QString::number(CurrentBalance) + " PLN");
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "B³¹d operacji", e.what());
    }
}

void MiniBankGUI::onWithdrawClicked()
{
    if (CurrentAccount.empty()) {
        QMessageBox::warning(this, "B³¹d", "Najpierw utwórz konto!");
        return;
    }

    try {
        double Amount = ui.AmountInput->text().toDouble();
        bank->WithdrawFromAccount(CurrentAccount, Amount);
        double CurrentBalance = bank->GetBalance(CurrentAccount);
        ui.BalanceLabel->setText("Konto: " + QString::fromStdString(CurrentAccount) + "\nSaldo: " + QString::number(CurrentBalance) + " PLN");
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "B³¹d operacji", e.what());
    }
}