#include "detenu.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Detenu::Detenu()
{
    id=""; nomE=""; prenom=""; num_cell=0; photo="";

}

Detenu::Detenu(QString id,QString nomE,QString prenom,int num_cell,QString photo){
    this->id=id; this->nomE=nomE;this->prenom=prenom; this->num_cell=num_cell;this->photo=photo;
}
QString Detenu::getid(){
    return id;
}
QString Detenu::getnomE(){
    return nomE;
}
QString Detenu::getPrenom(){
    return prenom;
}
int Detenu::getNum_Cell(){
    return num_cell;
}
QString Detenu::getPhoto(){
    return photo;
}

void Detenu::setid(QString id){
 this->id=id;
}
void Detenu::setnomE(QString nomE){
  this->nomE=nomE;
}
void Detenu::setPrenom(QString prenom){
  this->prenom=prenom;
}
void Detenu::setNum_cell(int num_cell){
  this->num_cell=num_cell;
}
void Detenu::setPhoto(QString photo){
  this->photo=photo;
}

bool Detenu::ajouter(){

    QSqlQuery query;

    query.prepare("INSERT INTO DETENU (id , nom, prenome, num_cell) "
                  "VALUES (:id, :nom, :prenom, :num_cell )");
    query.bindValue(0, id);
    query.bindValue(1, nomE);
    query.bindValue(2, prenom);
    query.bindValue(3, num_cell);

    return query.exec();
}

QSqlQueryModel* Detenu::afficher(){
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM DETENU");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de detenu"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom de detenu"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero de cellule"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Photo"));
    return model;
}

bool Detenu::supprimer(QString id){

    QSqlQuery query;
   // QString id_str=QString::number(id);

    query.prepare("Delete from DETENU WHERE id=:id");
    query.bindValue(":id", id);

    return query.exec();
}

bool Detenu::modifier(QString id,QString nomE,QString prenom,int num_cell){

    QSqlQuery query;
            query.prepare("UPDATE detenu SET id=:id, nom=:nomE , prenome=:prenom , num_cell=:num_cell WHERE id=:id");
            query.bindValue(":id", id);
            query.bindValue(":nomE", nomE);
            query.bindValue(":prenom", prenom);
            query.bindValue(":num_cell", num_cell);
            return query.exec();

}

QSqlQueryModel* Detenu::Trouver_d(QString recherche){
    QSqlQueryModel* trouve = new QSqlQueryModel();

    trouve->setQuery("SELECT * FROM detenu WHERE id LIKE '"+recherche+"%' OR nom LIKE '"+recherche+"%' OR prenome LIKE '"+recherche+"%' OR num_cell LIKE '"+recherche+"%' ");

    trouve->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    trouve->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de detenu"));
    trouve->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom de detenu"));
    trouve->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero de cellule"));



    return trouve;
}


