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
     int ret=A.connect_arduino();
     switch (ret) {
     case (0): qDebug()<<"Arduino est disponible et connectée"<<A.getarduino_port_name();
         break;
     case (1): qDebug()<<"Arduino est disponible mais elle n'est pas connectée"<<A.getarduino_port_name();
         break;
     case (-1): qDebug()<<"Arduino n'est pas disponible";
         break;
     }
     QObject::connect(A.getserial(), SIGNAL(readyRead()),this,SLOT(update_label()));
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

void Crud_demande::update_label()
{
    data=A.read_from_arduino();
        if(data=="1")
//{
            ui->label_7->setText("RED ON"); // si les données reçues de arduino via la liaison série sont égales à 1
            //qDebug()<<"Personne detectée";}
        // alors afficher ON

        else if (data=="0")

            ui->label_7->setText("GREEN ON");   // si les données reçues de arduino via la liaison série sont égales à 0
         //alors afficher ON
        else if (data=="2")

            ui->label_7->setText("YELLOW ON");   // si les données reçues de arduino via la liaison série sont égales à 0
         //alors afficher ON
}
