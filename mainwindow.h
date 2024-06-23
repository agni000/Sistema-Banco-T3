#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QMovie>
#include "newclient.h"
#include "newclient.h"
#include "client.h"
#include "account.h"
#include "stdaccount.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();

private slots:

    void on_pushButton_CadCliente_clicked();
    void on_pushButton_CadContaCorr_clicked();
    void on_pushButton_CadContaEsp_clicked();
    void on_pushButton_Operacoes_clicked();
    void on_pushButton_RelatoriosClient_clicked();
    void on_pushButton_RelatoriosCont_clicked();
    void on_pushButton_CadContaMast_clicked();

private:
    Ui::MainWindow *ui;
    NewClient *newclientUI;
    StdAccount *stdAccUI;
    QPixmap logo;
    QMovie background;
    vector<Client> clientList;
    vector<ContaCorrente*> accountList;
};

#endif // MAINWINDOW_H
