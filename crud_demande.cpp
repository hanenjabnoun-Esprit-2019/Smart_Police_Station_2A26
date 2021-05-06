#include "crud_demande.h"
#include "ui_crud_demande.h"
#include "menu_gestion_citoyen.h"
#include"demande_a.h"
#include<QMessageBox>
#include<QIntValidator>

Crud_demande::Crud_demande(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Crud_demande)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(100, 99, this));
     ui->tab_demande_a->setModel(E.afficher());
}

Crud_demande::~Crud_demande()
{
    delete ui;
}

void Crud_demande::on_pb_ajouter_clicked()
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

void Crud_demande::on_pb_supprimer_clicked()
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

void Crud_demande::on_pb_modifier_clicked()
{
    int id = ui->le_id_2->text().toInt();
    QString nom = ui->le_nom_2->text();
    QString objet = ui->le_objet_2->text();

    demande_a C(id ,nom , objet);

    bool modif = C.modifier(id,nom, objet);

    //QMessageBox msgBox;

    if(modif){

        ui->tab_demande_a->setModel(C.afficher());

        QMessageBox::information(this, tr("Done"), QString(tr("Modification réussie")));


    }

    else

        QMessageBox::information(this, tr("Failed"), QString(tr("Modification échoué")));



    //msgBox.exec();
}

void Crud_demande::on_retour_MenuGestion_Citoyen_clicked()
{
    Menu_gestion_citoyen MGC;
    MGC.setModal(true);
    hide();
    MGC.exec();
}

void Crud_demande::on_pb_recherche_clicked()
{
    QString id = ui->la_recherche->text();
    ui->tab_demande_a->setModel(E.rechercher(id));
}
