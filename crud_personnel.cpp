#include "crud_personnel.h"
#include "ui_crud_personnel.h"
#include "personnel.h"
#include <QMessageBox>
#include "menu_gestion_personnel.h"

Crud_Personnel::Crud_Personnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Crud_Personnel)
{
    ui->setupUi(this);
    ui->tableView_Personnel->setModel(P.Afficher_personnel());
}

Crud_Personnel::~Crud_Personnel()
{
    delete ui;
}

void Crud_Personnel::on_pushButton_AjoutPerso_clicked()
{
    QString Id = ui->lineEdit_Id->text();
    QString Nom = ui->lineEdit_Nom->text();
    QString Prenom = ui->lineEdit_Prenom->text();
    QString Grade = ui->comboBox_Grade->currentText();
    Personnel p(Id, Nom, Prenom, Grade);
    bool test = p.Ajouter_personnel();
    //QMessageBox msgBox;

    if(test){
        QMessageBox::information(this, tr("Done"), QString(tr("Ajout avec succès")));
        ui->tableView_Personnel->setModel(P.Afficher_personnel());
    }
    else
        QMessageBox::information(this, tr("Failed"), QString(tr("Ajout échoué")));
    //msgBox.exec();
}

void Crud_Personnel::on_pushButton_ModifPersonnel_clicked()
{
    QString Id = ui->lineEdit_IdModif->text();
    QString Nom = " ";
    QString Prenom = " ";
    QString Grade = ui->comboBox_GradeModif->currentText();

    Personnel P(Id, Nom, Prenom, Grade);
    bool modif = P.Modifier_personnel(Id, Grade);
    //QMessageBox msgBox;
    if(modif){
        ui->tableView_Personnel->setModel(P.Afficher_personnel());
        QMessageBox::information(this, tr("Done"), QString(tr("Modification réussie")));
    }
    else
        QMessageBox::information(this, tr("Failed"), QString(tr("Modification échoué")));

    //msgBox.exec();
}

void Crud_Personnel::on_pushButton_SupprPerso_clicked()
{
    Personnel P1;
    P1.setId(ui->lineEdit_IdSuppr->text());
    bool test = P1.Supprimer_personnel(P1.getId());
    //QMessageBox msgBox;

    if(test){
        QMessageBox::information(this, tr("Done"), QString(tr("Suppression réussie")));
        ui->tableView_Personnel->setModel(P.Afficher_personnel());
    }
    else
        QMessageBox::critical(this, tr("Failed"), QString(tr("Echec de suppresssion")));
    //msgBox.exec();
}

void Crud_Personnel::on_pushButton_RetourGestionPerso_clicked()
{
    Menu_Gestion_Personnel MGP;
    MGP.setModal(true);
    hide();
    MGP.exec();
}
