#include "personnel.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QDateTime>

Personnel::Personnel()
{
 Id = " ";
 Nom = " ";
 Prenom = " ";
 Grade = " ";
}

Personnel::Personnel(QString Id, QString Nom, QString Prenom, QString Grade){
    this->Id=Id;
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->Grade=Grade;
}
QString Personnel::getId(){
    return Id;
}
QString Personnel::getNom(){
    return Nom;
}
QString Personnel::getPrenom(){
    return Prenom;
}
QString Personnel::getGrade(){
    return Grade;
}
void Personnel::setId(QString Id){
    this->Id=Id;
}
void Personnel::setNom(QString Nom){
    this->Nom=Nom;
}
void Personnel::setPrenom(QString Prenom){
    this->Prenom=Prenom;
}
void Personnel::setGrade(QString Grade){
    this->Grade=Grade;
}
//ajout
bool Personnel::Ajouter_personnel(){
    //bool test = false;
    QSqlQuery query;
          query.prepare("INSERT INTO personnel (id, nom, prenom, grade) "
                        "VALUES (:id, :nom, :prenom, :grade)");
          query.bindValue(":id", Id);
          query.bindValue(":nom", Nom);
          query.bindValue(":prenom", Prenom);
          query.bindValue(":grade", Grade);

        return query.exec();
}
//affichage
QSqlQueryModel* Personnel::Afficher_personnel(){
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM personnel");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Grade"));

    return model;
}
//suppression
bool Personnel::Supprimer_personnel(QString Id){
    QSqlQuery query;
          query.prepare("DELETE FROM personnel WHERE Id=:Id");
          query.bindValue(0, Id);

          return query.exec();
}
//
//
//
//
//
