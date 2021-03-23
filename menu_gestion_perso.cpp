#include "menu_gestion_perso.h"
#include "ui_menu_gestion_perso.h"

Menu_gestion_perso::Menu_gestion_perso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_gestion_perso)
{
    ui->setupUi(this);
}

Menu_gestion_perso::~Menu_gestion_perso()
{
    delete ui;
}

void Menu_gestion_perso::on_pushButton_gerer_personnel_clicked()
{
    //Vue_perso V;
    //V.setModal(true);
    //V.exec();
    hide();
    Vue_personnel = new Vue_perso(this);
    Vue_personnel->show();
}
