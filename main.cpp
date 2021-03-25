#include "mainwindow.h"
#include "menu_gestion_personnel.h"
#include <QMessageBox>
#include "connection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection C;
    bool test=C.createConnection();
    Menu_Gestion_Personnel GP;
    //Vue_perso v;
    MainWindow w;

    if(test){
        GP.show();
    //qDebug() <<"Connexion réussie 00";
       // QMessageBox::information(nullptr, QObject::tr("database is open"), QObject::tr("connexion successfull:\n""click ok to exit"), QMessageBox::Ok);
    }
        //qDebug() <<"Erreur";
       // QMessageBox::critical(nullptr, QObject::tr("database is not open"), QObject::tr("connexion failed:\n""click cancel to exit"), QMessageBox::Cancel);
    return a.exec();
}
