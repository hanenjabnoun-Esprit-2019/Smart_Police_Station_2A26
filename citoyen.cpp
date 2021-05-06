#include "citoyen.h"
#include <QSqlQuery>
#include<QDebug>
#include<QObject>
Citoyen::Citoyen()
{
numero=0;nom="";prenom="";
}

Citoyen::Citoyen(int numero,QString nom,QString prenom)
{this->numero=numero; this->nom=nom; this->prenom=prenom;}
int Citoyen::getnumero(){return numero;}
QString Citoyen::getnom(){return nom;}
QString Citoyen::getprenom(){return prenom;}
void Citoyen::setnumero(int numero){this->numero=numero;}
void Citoyen::setnom(QString nom){this->nom=nom;}
void Citoyen::setprenom(QString prenom){this->prenom=prenom;}
bool Citoyen::ajouter()
{//bool test=false;
    QSqlQuery query;
    QString numero_string=QString::number(numero);
    query.prepare("INSERT INTO citoyen (numero, nom, prenom) "
                  "VALUES (:id, :forename, :surname)");
    query.bindValue(0, numero_string);
    query.bindValue(1, nom);
    query.bindValue(2, prenom);
     return query.exec();


    //return test;
}
bool Citoyen::supprimer(int numero)
{//bool test=false;
    QSqlQuery query;
    query.prepare("Delete from citoyen where numero=:numero");
    query.bindValue(0, numero);
    return query.exec();


    //return test;



}
QSqlQueryModel* Citoyen::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM citoyen ORDER BY numero ");
   // model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero"));
   // model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));


 return model;
}
//
bool Citoyen::modifier(int numero, QString nom, QString prenom){

    QSqlQuery query;

    query.prepare("UPDATE citoyen SET nom=:nom,prenom=:prenom WHERE numero=:numero");
    QString res = QString::number(numero);
    query.bindValue(":numero", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    return query.exec();
}

QSqlQueryModel *Citoyen::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from citoyen where numero  LIKE '"+rech+"%'" );
    return model;
}

//QSqlQueryModel *Citoyen::tri()
//{
  // QSqlQueryModel * model= new QSqlQueryModel();

  // model->setQuery("select * from citoyen ORDER BY numero DESC");


  // model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
 //  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
 //  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));


  //     return model;
//}
