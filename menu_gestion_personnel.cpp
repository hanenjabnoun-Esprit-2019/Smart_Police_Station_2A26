#include "menu_gestion_personnel.h"
#include "ui_menu_gestion_personnel.h"
#include "crud_personnel.h"
#include "crud_horaire.h"

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
    Crud_Personnel CP;
    CP.setModal(true);
    hide();
    CP.exec();
}

void Menu_Gestion_Personnel::on_pushButton_RetourMenuPrincipale_clicked()
{

}

void Menu_Gestion_Personnel::on_pushButton_CrudHoraire_clicked()
{
    Crud_Horaire CH;
    CH.setModal(true);
    hide();
    CH.exec();
}
