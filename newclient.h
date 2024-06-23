#ifndef NEWCLIENT_H
#define NEWCLIENT_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class NewClient;
}

class NewClient : public QDialog
{
    Q_OBJECT

public:
    explicit NewClient(QWidget *parent = nullptr);
    ~NewClient();
    std::string getName() const;
    std::string getAddress() const;
    std::string getJob() const;
    float getIncome() const;

private slots:
    void on_cadastrarButton_clicked();
    void on_cancelarButton_clicked();

private:
    Ui::NewClient *ui;
    QPixmap newlogo;
};

#endif // NEWCLIENT_H
