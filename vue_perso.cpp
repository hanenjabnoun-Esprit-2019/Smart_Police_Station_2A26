#include "vue_perso.h"
#include "ui_vue_perso.h"
#include "personnel.h"
#include <QMessageBox>

Vue_perso::Vue_perso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vue_perso)
{
    ui->setupUi(this);
    ui->tableView_Personnel->setModel(P.Afficher_personnel());
}

Vue_perso::~Vue_perso()
{
    delete ui;
}

void Vue_perso::on_pushButton_AjoutPersonnel_clicked()
{
    QString Id = ui->lineEdit_Id->text();
    QString Nom = ui->lineEdit_Nom->text();
    QString Prenom = ui->lineEdit_Prenom->text();
    QString Grade = ui->comboBox_Grade->currentText();
    Personnel p(Id, Nom, Prenom, Grade);
    bool test = p.Ajouter_personnel();
    QMessageBox msgBox;

    if(test){
        msgBox.setText("Ajout réussi");
        ui->tableView_Personnel->setModel(P.Afficher_personnel());
    }
    else
        msgBox.setText("Echec");
    msgBox.exec();
}


void Vue_perso::on_pushButton_SupprPersonnel_clicked()
{
    Personnel P1;
    P1.setId(ui->lineEdit_SupprPerso->text());
    bool test = P1.Supprimer_personnel(P1.getId());
    QMessageBox msgBox;

    if(test){
        msgBox.setText("Suppression réussi");
        ui->tableView_Personnel->setModel(P.Afficher_personnel());
    }
    else
        msgBox.setText("Echec");
    msgBox.exec();
}
