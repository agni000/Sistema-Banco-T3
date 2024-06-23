#ifndef STDACCOUNT_H
#define STDACCOUNT_H

#include <QDialog>

namespace Ui {
class StdAccount;
}

class StdAccount : public QDialog
{
    Q_OBJECT

public:
    explicit StdAccount(QWidget *parent = nullptr);
    ~StdAccount();
    void setName(QString name);
private:
    Ui::StdAccount *ui;

};

#endif // STDACCOUNT_H
