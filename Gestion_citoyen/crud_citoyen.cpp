#include "crud_citoyen.h"
#include "ui_crud_citoyen.h"
#include "menu_gestion_citoyen.h"
#include"citoyen.h"
#include<QMessageBox>
#include<QIntValidator>


Crud_citoyen::Crud_citoyen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Crud_citoyen)
{
    ui->setupUi(this);
    ui->le_numero->setValidator( new QIntValidator(100, 9999999, this));
     ui->tab_citoyen->setModel(E.afficher());
}

Crud_citoyen::~Crud_citoyen()
{
    delete ui;
}

void Crud_citoyen::on_pushButton_RetourMenuGestionCit_clicked()
{
    Menu_gestion_citoyen MGC;
    MGC.setModal(true);
    hide();
    MGC.exec();
}

void Crud_citoyen::on_pb_ajouter_clicked()
{
    int numero=ui->le_numero->text().toInt();
    QString nom=ui->le_nom->text();
     QString prenom=ui->le_prenom->text();
    Citoyen E(numero,nom,prenom);
    bool test=E.ajouter();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajourter avec succes.");
    ui->tab_citoyen->setModel(E.afficher());
     }
   else
       msgBox.setText("echec de l'ajout.");
      msgBox.exec();
}

void Crud_citoyen::on_pushButton_clicked()
{
    Citoyen E1;
    E1.setnumero(ui->le_numero_sup->text().toInt());
    bool test=E1.supprimer(E1.getnumero());
    QMessageBox msgBox;

   if(test)
       {msgBox.setText("supprimer avec succes.");
    ui->tab_citoyen->setModel(E.afficher());
     }
    else
        msgBox.setText("echec de la suppresion.");
        msgBox.exec();
}

void Crud_citoyen::on_pb_mofidier_clicked()
{
       int numero = ui->Le_numero->text().toInt();
       QString nom = ui->le_nom_2->text();
       QString prenom = ui->le_prenom_2->text();

       Citoyen C(numero, nom, prenom);

       bool modif = C.modifier(numero, nom, prenom);

       //QMessageBox msgBox;

       if(modif){

           ui->tab_citoyen->setModel(C.afficher());

           QMessageBox::information(this, tr("Done"), QString(tr("Modification réussie")));

       }

       else

           QMessageBox::information(this, tr("Failed"), QString(tr("Modification échoué")));



       //msgBox.exec();
}
