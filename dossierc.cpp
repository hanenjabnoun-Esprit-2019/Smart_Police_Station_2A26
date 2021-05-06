#include "dossierc.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QDateTime>
#include <QSqlQueryModel>
#include <QObject>

DossierC::DossierC()
{
 id = 0;
 nomc = " ";
 prenomc = " ";
 description = " ";
}

DossierC::DossierC(int id, QString nomc, QString prenomc, QString description){
    this->id = id;
    this->nomc = nomc;
    this->prenomc = prenomc;
    this->description = description;

}
int DossierC::getId(){
    return id;
}
QString DossierC::getNomc(){
    return nomc;
}
QString DossierC::getPrenomc(){
    return prenomc;
}
QString DossierC::getDesc(){
    return description;
}

void DossierC::setId(int id){
    this->id = id;
}
void DossierC::setNomc(QString nomc){
    this->nomc = nomc;
}
void DossierC::setPrenomc(QString prenomc){
    this->prenomc = prenomc;
}
void DossierC::setDesc(QString description){
    this->description = description;
}
bool DossierC::Ajouter_dossier()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
          query.prepare("INSERT INTO DOSSIERS_CRIMINELS (ID_D, NOMC, PRENOMC,DESCRIPTION) "
                        "VALUES (:id, :nomc, :prenomc, :description)");
          query.bindValue(":id",id_string );
          query.bindValue(":nomc",nomc );
          query.bindValue(":prenomc",prenomc );
          query.bindValue(":description",description );
         return query.exec();
}
QSqlQueryModel* DossierC::Afficher_dossier()
{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT ID_D, NOMC,PRENOMC,DESCRIPTION FROM DOSSIERS_CRIMINELS");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));

    return model;
}

bool DossierC::Supprimer_dossier(int)
{
    QSqlQuery query;
          query.prepare("Delete from DOSSIERS_CRIMINELS where ID_D=:id");
          query.bindValue(0,id );

         return query.exec();
}
bool DossierC::Modifier_dossier(int id,QString nomc,QString prenomc,QString description){
    QSqlQuery query;
    query.prepare("UPDATE DOSSIERS_CRIMINELS SET NOMC=:nomc, PRENOMC=:prenomc, DESCRIPTION=:description WHERE ID_D=:id");
    query.bindValue(":id", id);
    query.bindValue(":nomc", nomc);
    query.bindValue(":prenomc", prenomc);
    query.bindValue(":description", description);
    return query.exec();
}
QSqlQueryModel* DossierC::Trouver_dossier(QString recherche){
    QSqlQueryModel* trouve = new QSqlQueryModel();

    trouve->setQuery("SELECT * FROM DOSSIERS_CRIMINELS WHERE ID_D LIKE '"+recherche+"%' OR NOMC LIKE '"+recherche+"%' OR PRENOMC LIKE '"+recherche+"%' OR DESCRIPTION LIKE '"+recherche+"%' ");

    trouve->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    trouve->setHeaderData(1, Qt::Horizontal, QObject::tr("Identifiant"));
    trouve->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    trouve->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));


    return trouve;
}
