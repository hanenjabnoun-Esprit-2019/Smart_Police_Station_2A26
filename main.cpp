#include "mainwindow.h"
#include "admin.h"
#include "connection.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection C;
    bool test = C.createConnection();
    MainWindow w;
    Admin Admin;

    if(test){
        w.show();
        //Admin.show();
    }
    return a.exec();
}
