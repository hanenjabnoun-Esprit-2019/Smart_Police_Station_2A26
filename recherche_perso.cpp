#include "recherche_perso.h"
#include "ui_recherche_perso.h"

Recherche_Perso::Recherche_Perso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recherche_Perso)
{
    ui->setupUi(this);
}

Recherche_Perso::~Recherche_Perso()
{
    delete ui;
}
