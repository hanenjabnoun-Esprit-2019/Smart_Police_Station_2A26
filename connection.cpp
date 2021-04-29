#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("P_Station");//inserer le nom de la source de données ODBC
db.setUserName("firas");//inserer nom de l'utilisateur
db.setPassword("firas");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

void Connection::closeConnection(){ db.close(); }
