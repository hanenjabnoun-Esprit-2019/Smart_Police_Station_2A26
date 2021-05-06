#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "login_admin.h"
#include "connection.h"
#include "admin.h"
#include "dial2.h"
#include "dialog_2.h"
#include "dialog22.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_EspaceAdmin_clicked();

    void on_pushButton_GestionCrime_clicked();

    void on_pushButton_GestionAffaires_clicked();

    void on_pushButton_GestionRessources_clicked();

private:
    Ui::MainWindow *ui;
    Admin *admin;
    Login_Admin *login;
    Dial2 *crime;
    Dialog_2 *affaire;
    Dialog22 *ressource;
};
#endif // MAINWINDOW_H
