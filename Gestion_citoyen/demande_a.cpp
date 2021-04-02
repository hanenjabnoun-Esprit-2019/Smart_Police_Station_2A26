#include "demande_a.h"
#include <QSqlQuery>
#include<QDebug>
#include<QObject>

demande_a::demande_a()
{
id=0;nom="";objet="";
}
demande_a::demande_a(int id,QString nom,QString objet)
{this->id=id; this->nom=nom; this->objet=objet;}
int demande_a::getid(){return id;}
QString demande_a::getnom(){return nom;}
QString demande_a::getobjet(){return objet;}
void demande_a::setid(int id){this->id=id;}
void demande_a::setnom(QString nom){this->nom=nom;}
void demande_a::setobjet(QString objet){this->objet=objet;}
bool demande_a::ajouter()
{//bool test=false;
    QSqlQuery query;
    QString id_string=QString::number(id);
    query.prepare("INSERT INTO demande_a (identifiant, nom, objet) "
                  "VALUES (:id, :forename, :surname)");
    query.bindValue(0, id_string);
    query.bindValue(1, nom);
    query.bindValue(2, objet);
     return query.exec();


    //return test;
}
bool demande_a::supprimer(int id)
{//bool test=false;
    QSqlQuery query;
    query.prepare("Delete from demande_a where identifiant=:id");
    query.bindValue(0, id);
    return query.exec();


    //return test;



}
QSqlQueryModel* demande_a::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM demande_a");
   // model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   // model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("objet"));


 return model;
}
//
bool demande_a::modifier(int id,QString nom,   QString objet){

    QSqlQuery query;

    query.prepare("UPDATE demande_a SET nom=:nom,objet=:objet WHERE identifiant=:identifiant");
    QString res = QString::number(id);
    query.bindValue(":identifiant", res);
    query.bindValue(":nom", nom);
    query.bindValue(":objet", objet);

    return query.exec();
}
