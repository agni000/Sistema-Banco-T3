#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newclient.h"
#include "client.h"
#include <QInputDialog>
#include <QMessageBox>
#include <stdlib.h>
#include <QPixmap>
#include <QDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), newclientUI(nullptr),
    stdAccUI(nullptr)/*, logo(":images/logo.png")*/
{
    ui->setupUi(this);
    // ui->logoLabel->setPixmap(logo);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete newclientUI;
    delete stdAccUI;
}

void MainWindow::on_pushButton_CadCliente_clicked()
{
    newclientUI = new NewClient(this);
    if (newclientUI->exec() == QDialog::Accepted) {
        Client newClient(newclientUI->getName(), newclientUI->getAddress(), newclientUI->getJob(), newclientUI->getIncome());
        clientList.push_back(newClient);
    }

}

void MainWindow::on_pushButton_CadContaCorr_clicked()
{
    if (clientList.empty()) {
        QMessageBox::warning(this, "Erro", "Nenhum cliente cadastrado.");
        return;
    }

    QStringList clientNames;
    for (size_t i = 0; i < clientList.size(); ++i) {
        clientNames << QString::fromStdString(clientList[i].GetInformation());
    }

    bool ok;
    QString selectedClient = QInputDialog::getItem(this, tr("Cadastrar Conta Bancária"), tr("Selecione o Cliente:"), clientNames, 0, false, &ok);
    if (!ok || selectedClient.isEmpty()) return;

    float initialBalance = QInputDialog::getDouble(this, tr("Cadastrar Conta Bancária"), tr("Saldo Inicial:"), 0, 0, 1e9, 2, &ok);
    if (!ok) return;

    Client *clientPtr = NULL;
    for (size_t i = 0; i < clientList.size(); ++i) {
        if (QString::fromStdString(clientList[i].GetInformation()) == selectedClient) {
            clientPtr = &clientList[i];
            break;
        }
    }

    ContaCorrente *newAccount = NULL;
    newAccount = new ContaCorrente(clientPtr, initialBalance);
    accountList.push_back(newAccount);
    QMessageBox::information(this, "Sucesso", "Conta Corrente adicionada com sucesso.");
}

void MainWindow::on_pushButton_CadContaEsp_clicked() {
    if (clientList.empty()) {
        QMessageBox::warning(this, "Erro", "Nenhum cliente cadastrado.");
        return;
    }

    QStringList clientNames;
    for (size_t i = 0; i < clientList.size(); ++i) {
        clientNames << QString::fromStdString(clientList[i].GetInformation());
    }

    bool ok;
    QString selectedClient = QInputDialog::getItem(this, tr("Cadastrar Conta Bancária"), tr("Selecione o Cliente:"), clientNames, 0, false, &ok);
    if (!ok || selectedClient.isEmpty()) return;

    float initialBalance = QInputDialog::getDouble(this, tr("Cadastrar Conta Bancária"), tr("Saldo Inicial:"), 0, 0, 1e9, 2, &ok);
    if (!ok) return;

    float limit = QInputDialog::getDouble(this, tr("Cadastrar Conta Bancária"), tr("Limite:"), 0, 0, 1e9, 2, &ok);
    if (!ok) return;

    Client *clientPtr = NULL;
    for (size_t i = 0; i < clientList.size(); ++i) {
        if (QString::fromStdString(clientList[i].GetInformation()) == selectedClient) {
            clientPtr = &clientList[i];
            break;
        }
    }

    ContaEspecial *newAccount = NULL;
    newAccount = new ContaEspecial(clientPtr, initialBalance, limit);
    accountList.push_back(newAccount);

    QMessageBox::information(this, "Sucesso", "Conta Especial adicionada com sucesso.");
}

void MainWindow::on_pushButton_CadContaMast_clicked()
{
    if (clientList.empty()) {
        QMessageBox::warning(this, "Erro", "Nenhum cliente cadastrado.");
        return;
    }

    QStringList clientNames;
    for (size_t i = 0; i < clientList.size(); ++i) {
        clientNames << QString::fromStdString(clientList[i].GetInformation());
    }

    bool ok;
    QString selectedClient = QInputDialog::getItem(this, tr("Cadastrar Conta Bancária"), tr("Selecione o Cliente:"), clientNames, 0, false, &ok);
    if (!ok || selectedClient.isEmpty()) return;

    float initialBalance = QInputDialog::getDouble(this, tr("Cadastrar Conta Bancária"), tr("Saldo Inicial:"), 0, 0, 1e9, 2, &ok);
    if (!ok) return;

    float limit = QInputDialog::getDouble(this, tr("Cadastrar Conta Bancária"), tr("Limite:"), 0, 0, 1e9, 2, &ok);
    if (!ok) return;

    float bitcoin = QInputDialog::getDouble(this, tr("Cadastrar Conta Bancária"), tr("Bitcoins:"), 0, 0, 1e9, 2, &ok);
    if (!ok) return;

    Client *clientPtr = NULL;
    for (size_t i = 0; i < clientList.size(); ++i) {
        if (QString::fromStdString(clientList[i].GetInformation()) == selectedClient) {
            clientPtr = &clientList[i];
            break;
        }
    }

    ContaMaster *newAccount = NULL;
    newAccount = new ContaMaster(clientPtr, initialBalance, limit, bitcoin);
    accountList.push_back(newAccount);

    QMessageBox::information(this, "Sucesso", "Conta Master adicionada com sucesso.");
}

void MainWindow::on_pushButton_Operacoes_clicked()
{
    if (accountList.empty()) {
        QMessageBox::warning(this, "Erro", "Nenhuma conta cadastrada.");
        return;
    }

    QStringList accountInfos;
    for (size_t i = 0; i < accountList.size(); ++i) {
        accountInfos << QString::fromStdString(accountList[i]->GetClientInfo());
    }

    bool ok;
    QString operation = QInputDialog::getItem(this, tr("Operações"), tr("Selecione a Operação:"), {"Depósito", "Saque", "Transferência"}, 0, false, &ok);
    if (!ok || operation.isEmpty()) return;

    QString selectedAccount = QInputDialog::getItem(this, tr("Operações"), tr("Selecione a Conta:"), accountInfos, 0, false, &ok);
    if (!ok || selectedAccount.isEmpty()) return;

    ContaCorrente *accountPtr = NULL;
    for (size_t i = 0; i < accountList.size(); ++i) {
        if (QString::fromStdString(accountList[i]->GetClientInfo()) == selectedAccount) {
            accountPtr = accountList[i];
            break;
        }
    }

    if (operation == "Depósito") {
        float value = QInputDialog::getDouble(this, tr("Depósito"), tr("Valor:"), 0, 0, 1e9, 2, &ok);
        if (!ok) return;
        accountPtr->Deposit(value);
        QMessageBox::information(this, "Sucesso", "Depósito realizado com sucesso.");
    } else if (operation == "Saque") {
        float value = QInputDialog::getDouble(this, tr("Saque"), tr("Valor:"), 0, 0, 1e9, 2, &ok);
        if (!ok) return;
        if (accountPtr->Withdraw(value)) {
            QMessageBox::information(this, "Sucesso", "Saque realizado com sucesso.");
        } else {
            QMessageBox::warning(this, "Erro", "Saldo insuficiente.");
        }
    } else if (operation == "Transferência") {
        QString selectedTargetAccount = QInputDialog::getItem(this, tr("Transferência"), tr("Selecione a Conta de Destino:"), accountInfos, 0, false, &ok);
        if (!ok || selectedTargetAccount.isEmpty()) return;

        ContaCorrente *targetAccountPtr = NULL;
        for (size_t i = 0; i < accountList.size(); ++i) {
            if (QString::fromStdString(accountList[i]->GetClientInfo()) == selectedTargetAccount) {
                targetAccountPtr = accountList[i];
                break;
            }
        }

        float value = QInputDialog::getDouble(this, tr("Transferência"), tr("Valor:"), 0, 0, 1e9, 2, &ok);
        if (!ok) return;

        if (accountPtr->Transfer(*targetAccountPtr, value)) {
            QMessageBox::information(this, "Sucesso", "Transferência realizada com sucesso.");
        } else {
            QMessageBox::warning(this, "Erro", "Saldo insuficiente.");
        }
    }
}


void MainWindow::on_pushButton_RelatoriosClient_clicked()
{
    if (clientList.empty()) {
        QMessageBox::information(this, "Relatórios", "Nenhum cliente cadastrado.");
    } else {
        QString report;
        for (size_t i = 0; i < clientList.size(); ++i) {
            report += QString::fromStdString(clientList[i].GetInformation()) + "\n";
        }
        QMessageBox::information(this, "Relatório de Clientes", report);
    }
}


void MainWindow::on_pushButton_RelatoriosCont_clicked()
{
    qDebug() << accountList.size();

    if (accountList.empty()) {
        QMessageBox::information(this, "Relatórios", "Nenhuma conta cadastrada.");
    } else {
        QString report;
        for (size_t i = 0; i < accountList.size(); ++i) {
            report += QString::fromStdString(accountList[i]->getAllInfo()) + "\n";
        }
        QMessageBox::information(this, "Relatório de Contas", report);
    }
}
