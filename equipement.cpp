#include "equipement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Equipement::Equipement()
{
    id=0; nomE=" "; qte=0;

}

Equipement::Equipement(int id,QString nomE,int qte){
    this->id=id; this->nomE=nomE; this->qte=qte;
}
int Equipement::getid(){
    return id;
}
QString Equipement::getnomE(){
    return nomE;
}
int Equipement::getqte(){
    return qte;
}

void Equipement::setid(int id){
 this->id=id;
}
void Equipement::setnomE(QString nomE){
  this->nomE=nomE;
}
void Equipement::setqte(int qte){
  this->qte=qte;
}
bool Equipement::ajouter(){

    QString id_string=QString::number(id);
    QString qte_string=QString::number(qte);
    QSqlQuery query;

    query.prepare("INSERT INTO equipement (id , nome, qte) "
                  "VALUES (:id, :nome, :qte)");
    query.bindValue(0, id_string);
    query.bindValue(1, nomE);
    query.bindValue(2, qte_string);

    return query.exec();
}

QSqlQueryModel* Equipement::afficher(){
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT* FROM equipement");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Equipement"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantité"));

    return model;
}

bool Equipement::supprimer(int id){

    QSqlQuery query;
   // QString id_str=QString::number(id);

    query.prepare("Delete from equipement WHERE id=:id");
    query.bindValue(":id", id);

    return query.exec();
}

bool Equipement::modifier_e(int id,QString nomE,int qte){
    QSqlQuery query;
    query.prepare("UPDATE equipement SET nomE=:nomE, qte=:qte WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":nomE", nomE);
    query.bindValue(":qte", qte);
    return query.exec();
}

QSqlQueryModel* Equipement::Trouver_eq(QString recherche){
    QSqlQueryModel* trouve = new QSqlQueryModel();

    trouve->setQuery("SELECT * FROM equipement WHERE ID LIKE '"+recherche+"%' OR NOME LIKE '"+recherche+"%' OR QTE LIKE '"+recherche+"%' ");

    trouve->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    trouve->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Equipement"));
    trouve->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantité"));


    return trouve;
}
