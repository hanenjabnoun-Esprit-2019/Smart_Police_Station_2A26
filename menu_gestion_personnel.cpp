#include "menu_gestion_personnel.h"
#include "ui_menu_gestion_personnel.h"
#include "crud_personnel.h"
#include "crud_horaire.h"
#include "stats.h"
#include "mainwindow.h"
#include "admin.h"

Menu_Gestion_Personnel::Menu_Gestion_Personnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_Gestion_Personnel)
{
    ui->setupUi(this);
}

Menu_Gestion_Personnel::~Menu_Gestion_Personnel()
{
    delete ui;
}

void Menu_Gestion_Personnel::on_pushButton_CrudPerso_clicked()
{
    this->hide();
    Crud_Personnel CP;
    CP.setModal(true);
    CP.exec();
}

void Menu_Gestion_Personnel::on_pushButton_CrudHoraire_clicked()
{
    this->hide();
    Crud_Horaire CH;
    CH.setModal(true);
    CH.exec();
}

void Menu_Gestion_Personnel::on_pushButton_Stats_clicked()
{
    this->hide();
    Stats StatsPerso;
    StatsPerso.setModal(true);
    StatsPerso.exec();
}

void Menu_Gestion_Personnel::on_pushButton_RetourMenuPrincipale_clicked()
{
    /*this->close();
    emit PageAccueil();*/
    this->hide();
    Admin Admin;
    Admin.setModal(true);
    Admin.exec();
}
