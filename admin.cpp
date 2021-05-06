#include "admin.h"
#include "ui_admin.h"
#include "dialog.h"
#include "dialog2.h"
#include "dial.h"
#include "menu_gestion_personnel.h"
#include "menu_gestion_citoyen.h"
#include "login_admin.h"
#include "mainwindow.h"

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    //connect(Acceuil, &MainWindow::AdminPage, this, &Admin::show);
   // connect(ads, &Admin::Accueil, this, &MainWindow::show);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_gestionAffaires_clicked()
{
    this->hide();
    Dialog GestionAff;
    GestionAff.setModal(true);
    GestionAff.exec();
}

void Admin::on_pushButton_gestionRessources_clicked()
{
    this->hide();
    Dialog2 GestionRess;
    GestionRess.setModal(true);
    GestionRess.exec();
}

void Admin::on_pushButton_gestionPersonnel_clicked()
{
    this->hide();
    Menu_Gestion_Personnel MGP;
    MGP.setModal(true);
    MGP.exec();
}

void Admin::on_pushButton_gestionCitoyen_clicked()
{
    this->hide();
    Menu_gestion_citoyen Mgc;
    Mgc.setModal(true);
    Mgc.exec();
}

void Admin::on_pushButton_gestionCrimes_clicked()
{
    this->hide();
    Dial Crimes;
    Crimes.setModal(true);
    Crimes.exec();
}

void Admin::on_pushButton_retourMenu_clicked()
{
    this->hide();
    //emit PageAccueil();
    Login_Admin Log;
    Log.setModal(true);
    Log.exec();
}
