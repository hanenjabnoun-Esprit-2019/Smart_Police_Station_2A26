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
 Sexe = " ";
 Grade = " ";
}

Personnel::Personnel(QString Id, QString Nom, QString Prenom, QString Sexe, QString Grade){
    this->Id = Id;
    this->Nom = Nom;
    this->Prenom = Prenom;
    this->Sexe = Sexe;
    this->Grade = Grade;
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
QString Personnel::getSexe(){
    return Sexe;
}
QString Personnel::getGrade(){
    return Grade;
}
void Personnel::setId(QString Id){
    this->Id = Id;
}
void Personnel::setNom(QString Nom){
    this->Nom = Nom;
}
void Personnel::setPrenom(QString Prenom){
    this->Prenom = Prenom;
}
void Personnel::setSexe(QString Sexe){
    this->Sexe = Sexe;
}
void Personnel::setGrade(QString Grade){
    this->Grade = Grade;
}
//ajout
bool Personnel::Ajouter_personnel(){
    //bool test = false;
    QSqlQuery query;
          query.prepare("INSERT INTO personnel (id, nom, prenom, sexe, grade) "
                        "VALUES (:id, :nom, :prenom, :sexe, :grade)");
          query.bindValue(":id", Id);
          query.bindValue(":nom", Nom);
          query.bindValue(":prenom", Prenom);
          query.bindValue(":sexe", Sexe);
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
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Grade"));

    return model;
}
//modification
bool Personnel::Modifier_personnel(QString Id, QString Grade){
    QSqlQuery query;
    query.prepare("UPDATE personnel SET Grade=:Grade WHERE Id=:Id");
    query.bindValue(":Id", Id);
    query.bindValue(":Grade", Grade);
    return query.exec();
}
//suppression
bool Personnel::Supprimer_personnel(QString Id){
    QSqlQuery query;
          query.prepare("DELETE FROM personnel WHERE Id=:Id");
          query.bindValue(0, Id);

          return query.exec();
}
//recherche
QSqlQueryModel* Personnel::Trouver_personnel(QString recherche){
    QSqlQueryModel* trouve = new QSqlQueryModel();

    trouve->setQuery("SELECT * FROM personnel WHERE Id LIKE '"+recherche+"%' OR Nom LIKE '"+recherche+"%' OR Prenom LIKE '"+recherche+"%' OR Grade LIKE '"+recherche+"%' ");

    trouve->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    trouve->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    trouve->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    trouve->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
    trouve->setHeaderData(4, Qt::Horizontal, QObject::tr("Grade"));

    return trouve;
}
//Tri
QSqlQueryModel* Personnel::Tri(){
    QSqlQueryModel* ordre = new QSqlQueryModel();

    ordre->setQuery("SELECT * FROM personnel ORDER BY nom");
    ordre->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    ordre->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    ordre->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    ordre->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
    ordre->setHeaderData(4, Qt::Horizontal, QObject::tr("Grade"));

    return ordre;
}

//connect admin
int connectAdmin(QString username, QString password){
    QString grade = "Admin";

    QSqlQuery log;

    if(log.exec("SELECT * from personnel WHERE id LIKE '"+password+"' AND nom LIKE '"+username+"' AND grade LIKE '"+grade+"'")){
        int count=0;
        while(log.next()){
            count++;
        }
        return count;
    }
    return 0;
}
