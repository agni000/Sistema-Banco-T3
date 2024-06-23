#ifndef NEWACCOUNT_H
#define NEWACCOUNT_H

#include "client.h"
#include <QMainWindow>

namespace Ui {
class NewAccount;
}

class NewAccount : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewAccount(QWidget *parent = nullptr);
    ~NewAccount();
public slots:
    void on_cadastrarButton_clicked();
    Client getClient() {return newClient;};

private:
    Ui::NewAccount *ui;
    Client newClient;
};

#endif // NEWACCOUNT_H
