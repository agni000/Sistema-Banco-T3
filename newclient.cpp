#include "newclient.h"
#include "ui_newclient.h"
#include <QMessageBox>

NewClient::NewClient(QWidget *parent) : QDialog(parent), ui(new Ui::NewClient), newlogo(":images/bank.png")
{
    ui->setupUi(this);
    ui->bankLabel->setPixmap(newlogo);
}

NewClient::~NewClient()
{
    delete ui;
}

std::string NewClient::getName() const {
    return ui->lineName->text().toStdString();
}

std::string NewClient::getAddress() const {
    return ui->lineAddress->text().toStdString();
}

std::string NewClient::getJob() const {
    return ui->lineJob->text().toStdString();
}

float NewClient::getIncome() const {
    return ui->lineIncome->text().toFloat();
}

void NewClient::on_cadastrarButton_clicked()
{
    if (!ui->lineName->text().isEmpty()) {
        QMessageBox::information(this, "Sucesso!", "Cliente Cadastrado!");
        accept();
    } else {
        QMessageBox::information(this, "Erro!", "Cliente sem nome!");
        reject();
    }
}


void NewClient::on_cancelarButton_clicked()
{
    reject();
}

