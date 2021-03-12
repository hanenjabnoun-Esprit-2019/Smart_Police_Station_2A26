#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"citoyen.h"
#include<QMessageBox>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->le_numero->setValidator( new QIntValidator(100, 9999999, this));
    ui->tab_citoyen->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
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

void MainWindow::on_pb_supprimer_clicked()
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
