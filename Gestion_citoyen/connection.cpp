#include "connection.h"
//test at
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");//inserer le nom de la source de données ODBC
db.setUserName("steve");//inserer nom de l'utilisateur
db.setPassword("azerty");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
