#include "intervenant.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QDateTime>
#include <QSqlQueryModel>
#include <QObject>

Intervenant::Intervenant()
{
 id = 0;
 nomI = " ";
 prenomI = " ";
 prof = " ";
}

Intervenant::Intervenant(int id,QString nomI,QString prenomI,QString prof )
{
    this->id = id;
    this->nomI = nomI;
    this->prenomI = prenomI;
    this->prof = prof;
}
int Intervenant::getId(){
    return id;
}
QString Intervenant::getnomI(){
    return nomI;
}
QString Intervenant::getprenomI(){
    return prenomI;
}
QString Intervenant::getprof(){
    return prof;
}

void Intervenant::setId(int id){
    this->id = id;
}
void Intervenant::setnomi(QString nomI){
    this->nomI = nomI;
}
void Intervenant::setprenomi(QString prenomI){
    this->prenomI = prenomI;
}
void Intervenant::setprof(QString prof){
    this->prof = prof;
}
bool Intervenant::Ajouter_Inter()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
          query.prepare("INSERT INTO INTERVENANTS (ID_I, NOM_I, PRENOM_I,PROF_I) "
                        "VALUES (:id, :nomI, :prenomI, :prof)");
          query.bindValue(":id",id_string );
          query.bindValue(":nomI",nomI );
          query.bindValue(":prenomI",prenomI );
          query.bindValue(":prof",prof );
         return query.exec();
}
QSqlQueryModel* Intervenant::Afficher_Inter()
{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT ID_I, NOM_I,PRENOM_I,PROF_I FROM INTERVENANTS");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Profession"));

    return model;
}

bool Intervenant::Supprimer_Inter(int)
{
    QSqlQuery query;
          query.prepare("Delete from INTERVENANTS where ID_I=:id");
          query.bindValue(0,id );

         return query.exec();
}
bool Intervenant::Modifier_Inter(int id,QString nomI,QString prenomI,QString prof){
    QSqlQuery query;
    query.prepare("UPDATE INTERVENANTS SET NOM_I=:nomI, PRENOM_I=:prenomI, PROF_I=:prof WHERE ID_I=:id");
    query.bindValue(":id", id);
    query.bindValue(":nomI", nomI);
    query.bindValue(":prenomI", prenomI);
    query.bindValue(":prof", prof);
    return query.exec();
}
