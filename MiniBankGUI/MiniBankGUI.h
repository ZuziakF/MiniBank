#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MiniBankGUI.h"

class Bank;
class MiniBankGUI : public QMainWindow
{
    Q_OBJECT

public:
    MiniBankGUI(QWidget *parent = nullptr);
    ~MiniBankGUI();
private slots:
    void onDepositClicked();
    void onWithdrawClicked();
    void onCreateAccountClicked();
    void onAccountSelected(const QString& AccountNumber);
    void onRegisterClientClicked();
    void onClientChanged();
private:
    Ui::MiniBankGUIClass* ui;
    Bank* bank;
    
};

