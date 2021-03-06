#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "precompiled.h"

// Forward declare to break circular dependency.
class RPC;
class Settings;

using json = nlohmann::json;

// Struct used to hold destination info when sending a Tx. 
struct ToFields {
    QString addr;
    double  amount;
    QString txtMemo;
    QString encodedMemo;
};

// Struct used to represent a Transaction. 
struct Tx {
    QString         fromAddr;
    QList<ToFields> toAddrs;
    double          fee;
};

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow*     ui;

    QLabel*             statusLabel;
    QLabel*             statusIcon;
    QLabel*             loadingLabel;

private:    
    void setupSendTab();
    void setupTransactionsTab();
    void setupRecieveTab();
    void setupBalancesTab();

	void setupSettingsModal();
	void setupStatusBar();

	void removeExtraAddresses();
	void setDefaultPayFrom();

    Tx      createTxFromSendPage();
    bool    confirmTx(Tx tx, ToFields devFee);
    void    fillTxJsonParams(json& params, Tx tx);

	void cancelButton();
	void sendButton();
	void inputComboTextChanged(const QString& text);
	void addAddressSection();
	void maxAmountChecked(int checked);

    void addressChanged(int number, const QString& text);
    void amountChanged (int numer, const QString& text);

    void addNewZaddr(bool sapling);
    std::function<void(bool)> addZAddrsToComboList(bool sapling);

    void memoButtonClicked(int number);
    void setMemoEnabled(int number, bool enabled);

    QString doSendTxValidations(Tx tx);

    void donate();
    void importPrivKeys();

    RPC*                rpc;

    QMovie*             loadingMovie;
};

#endif // MAINWINDOW_H
