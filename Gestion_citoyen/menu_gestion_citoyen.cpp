#include "menu_gestion_citoyen.h"
#include "ui_menu_gestion_citoyen.h"
#include "crud_citoyen.h"
#include<QMessageBox>
#include<QIntValidator>
#include"crud_demande.h"

Menu_gestion_citoyen::Menu_gestion_citoyen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_gestion_citoyen)
{
    ui->setupUi(this);
}

Menu_gestion_citoyen::~Menu_gestion_citoyen()
{
    delete ui;
}

void Menu_gestion_citoyen::on_pb_citoyen_clicked()
{
   Crud_citoyen E;
    E.setModal(true);
    hide();
    E.exec();
}

void Menu_gestion_citoyen::on_pb_demande_ad_clicked()
{
    Crud_demande E;
     E.setModal(true);
     hide();
     E.exec();
}
