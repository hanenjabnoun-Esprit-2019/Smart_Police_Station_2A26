#include "dialog.h"
#include "ui_dialog.h"
#include"demande_a.h"
#include<QMessageBox>
#include<QIntValidator>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(100, 99, this));
     ui->tab_demande_a->setModel(E.afficher());
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pb_ajourter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
     QString objet=ui->le_objet->text();
   demande_a E(id,nom,objet);
    bool test=E.ajouter();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajourter avec succes.");
    ui->tab_demande_a->setModel(E.afficher());
     }
   else
       msgBox.setText("echec de l'ajout.");
      msgBox.exec();
}

void Dialog::on_pb_supprimer_clicked()
{
    demande_a E1;
    E1.setid(ui->le_id_sup->text().toInt());
    bool test=E1.supprimer(E1.getid());
    QMessageBox msgBox;

   if(test)
       {msgBox.setText("supprimer avec succes.");
    ui->tab_demande_a->setModel(E.afficher());
     }
    else
        msgBox.setText("echec de la suppresion.");
        msgBox.exec();
}
