#include "mainwindow.h"
#include"dialog.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "menu_gestion_citoyen.h"
#include "crud_citoyen.h"
#include "crud_demande.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test=c.createconnect();
    Menu_gestion_citoyen MGC;
    // MainWindow w;
   // Crud_citoyen CC;
    //Crud_demande CD;

    if(test)
    {
        MGC.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
