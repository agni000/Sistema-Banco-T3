#include <string.h>
#include "mainwindow.h"
#include "newaccount.h"
#include "ui_newaccount.h"
#include "client.h"

NewAccount::NewAccount(QWidget *parent) : QMainWindow(parent), ui(new Ui::NewAccount), newClient("", "", "", 0)
{
    ui->setupUi(this);
}

NewAccount::~NewAccount()
{
    delete ui;
}

void NewAccount::on_cadastrarButton_clicked()
{
    QString name = ui->nomeLabel->text();
    std::string namestr = name.toStdString();

    newClient.update(name, "", "", 1500);

    // QString address = QInputDialog::getText(this, tr("Cadastrar Cliente"), tr("Endereço:"), QLineEdit::Normal, "", &ok);
    // if (!ok || address.isEmpty()) return;

    // QString job = QInputDialog::getText(this, tr("Cadastrar Cliente"), tr("Profissão:"), QLineEdit::Normal, "", &ok);
    // if (!ok || job.isEmpty()) return;

    // float income = QInputDialog::getDouble(this, tr("Cadastrar Cliente"), tr("Renda:"), 0, 0, 1e9, 2, &ok);
    // if (!ok) return;

    // Client newClient(name.toStdString(), address.toStdString(), job.toStdString(), income);
    // clientList.push_back(newClient);

    // QMessageBox::information(this, "Sucesso", "Cliente adicionado com sucesso.");
}

