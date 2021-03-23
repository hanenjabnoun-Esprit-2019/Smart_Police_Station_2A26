#include "horaire.h"
#include "personnel.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QDateTime>

Horaire::Horaire()
{
 reference =0;
 debut = QDateTime(QDate(0, 0, 0), QTime(0, 0, 0));
 fin = QDateTime(QDate(0, 0, 0), QTime(0, 0, 0));
}

Horaire::Horaire(int reference, QDateTime debut, QDateTime fin){
    this->reference=reference;
    this->debut=debut;
    this->fin=fin;
}
int Horaire::getRef(){
    return reference;
}
QDateTime Horaire::getDebut(){
    return debut;
}
QDateTime Horaire::getFin(){
    return fin;
}
void Horaire::setRef(int reference){
    this->reference=reference;
}
void Horaire::setDebut(QDateTime debut){
    this->debut=debut;
}
void Horaire::setFin(QDateTime fin){
    this->fin=fin;
}
//ajout
bool Horaire::Ajouter_horaire(){
    //bool test = false;
    QSqlQuery query1;
          query1.prepare("INSERT INTO horaire (reference, debut, fin) "
                        "VALUES (:reference, :debut, :fin)");
          query1.bindValue(":reference", reference);
          query1.bindValue(":debut", debut);
          query1.bindValue(":fin", fin);

        return query1.exec();
}
//affichage
QSqlQueryModel* Horaire::Afficher_horaire(){
    QSqlQueryModel* model1 = new QSqlQueryModel();

    model1->setQuery("SELECT * FROM horaire");
    model1->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Début"));
    model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Fin"));

    return model1;
}
//suppression
bool Horaire::Supprimer_horaire(int reference){
    QSqlQuery query1;
          query1.prepare("DELETE FROM horaire WHERE reference=:reference");
          query1.bindValue(0, reference);

          return query1.exec();
}
