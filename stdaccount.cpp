#include "stdaccount.h"
#include "ui_stdaccount.h"

StdAccount::StdAccount(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StdAccount)
{
    ui->setupUi(this);

}

StdAccount::~StdAccount()
{
    delete ui;
}

void StdAccount::setName(QString name) {
    ui->comboBox->addItem(name);
}
