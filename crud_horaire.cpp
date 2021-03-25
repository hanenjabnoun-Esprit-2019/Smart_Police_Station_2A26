#include "crud_horaire.h"
#include "ui_crud_horaire.h"
#include "menu_gestion_personnel.h"
#include <QMessageBox>

Crud_Horaire::Crud_Horaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Crud_Horaire)
{
    ui->setupUi(this);
    ui->tableView_Horaire->setModel(H.Afficher_horaire());
}

Crud_Horaire::~Crud_Horaire()
{
    delete ui;
}

void Crud_Horaire::on_pushButton_RetourMenuPrincipale_clicked()
{
    Menu_Gestion_Personnel MGP;
    MGP.setModal(true);
    hide();
    MGP.exec();
}

void Crud_Horaire::on_pushButton_AjoutHoraire_clicked()
{

}

void Crud_Horaire::on_pushButton_ModifHoraire_clicked()
{

}

void Crud_Horaire::on_pushButton_SupprHoraire_clicked()
{
    Horaire H1;
    H1.setRef(ui->lineEdit_Ref_HoraireSuppr->text());
    bool suppr = H1.Supprimer_horaire(H1.getRef());

    if(suppr){
        QMessageBox::information(this, tr("Done"), QString(tr("Suppression réussie")));
        ui->tableView_Horaire->setModel(H.Afficher_horaire());
    }
    else
        QMessageBox::critical(this, tr("Failed"), QString(tr("Echec de suppresssion")));
}
