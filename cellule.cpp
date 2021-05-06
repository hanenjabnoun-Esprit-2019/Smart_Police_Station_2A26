#include "cellule.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Cellule::Cellule::Cellule()
{
    num_cell=0;num_det=0;
}

Cellule::Cellule(int num_cell,int num_det){
    this->num_cell=num_cell;
    this->num_det=num_det;
}
    int Cellule::getNcel(){
        return num_cell;
    }

    int Cellule::getNdet(){
        return num_det;
    }
    void Cellule::setNcel(int num_cell){
        this->num_cell=num_cell;
    }
    void Cellule::setNdet(int num_det){
        this->num_det=num_det;
    }
    bool Cellule::ajouter(){

        QString ncel_str=QString::number(num_cell);
        QString ndet_str=QString::number(num_det);
        QSqlQuery query;

        query.prepare("INSERT INTO cellule (num_cell , num_det) "
                      "VALUES (:num_cell, :num_det)");
        query.bindValue(0, num_cell);
        query.bindValue(1, num_det);

        return query.exec();
    }

    QSqlQueryModel* Cellule::afficher(){
        QSqlQueryModel* model = new QSqlQueryModel();

           model->setQuery("SELECT* FROM CELLULE");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero Cellule"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre de detenus"));
           return model;
    }
    bool Cellule::supprimer(int num_cell){

        QSqlQuery query;
       // QString id_str=QString::number(id);

        query.prepare("Delete from cellule WHERE num_cell=:num_cell");
        query.bindValue(":num_cell", num_cell);

        return query.exec();
    }

 bool Cellule::modifier(int num_cell,int num_det){

        QSqlQuery query;
                query.prepare("UPDATE cellule SET num_cell=:num_cell, num_det=:num_det WHERE num_cell=:num_cell");
                query.bindValue(":num_cell", num_cell);
                query.bindValue(":num_det", num_det);
                return query.exec();

    }

 QSqlQueryModel* Cellule::Trouver_c(QString recherche){
     QSqlQueryModel* trouve = new QSqlQueryModel();

     trouve->setQuery("SELECT * FROM cellule WHERE num_cell LIKE '"+recherche+"%' OR num_det LIKE '"+recherche+"%' ");

     trouve->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero Cellule"));
     trouve->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre de detenus"));

     return trouve;
 }



