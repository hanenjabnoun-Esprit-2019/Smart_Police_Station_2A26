#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //init mgp
    admin = new Admin();
    login = new Login_Admin();
    crime = new Dial2();
    affaire = new Dialog_2();
    ressource = new Dialog22();
    //
    connect(login, &Login_Admin::PageAccueil, this, &MainWindow::show);

    connect(crime, &Dial2::PageAccueil, this, &MainWindow::show);

     connect(affaire, &Dialog_2::PageAccueil, this, &MainWindow::show);

     connect(ressource, &Dialog22::PageAccueil, this, &MainWindow::show);

     connect(admin, &Admin::PageAccueil, this, &MainWindow::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_EspaceAdmin_clicked()
{
    login->show();
    this->close();
}

void MainWindow::on_pushButton_GestionCrime_clicked()
{
    crime->show();
    this->close();
}

void MainWindow::on_pushButton_GestionAffaires_clicked()
{
    affaire->show();
    this->close();
}

void MainWindow::on_pushButton_GestionRessources_clicked()
{
    ressource->show();
    this->close();
}
