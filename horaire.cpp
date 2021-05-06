#include "horaire.h"
#include "personnel.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QDateTime>
#include <QTableView>
#include "connection.h"

Horaire::Horaire()
{
 reference = " ";
 debut = QDateTime(QDate(0, 0, 0), QTime(0, 0, 0));
 fin = QDateTime(QDate(0, 0, 0), QTime(0, 0, 0));
 mission = " ";
 agent = " ";
}

Horaire::Horaire(QString reference, QDateTime debut, QDateTime fin, QString mission, QString agent){
    this->reference = reference;
    this->debut = debut;
    this->fin = fin;
    this->mission = mission;
    this->agent = agent;
}
QString Horaire::getRef(){
    return reference;
}
QDateTime Horaire::getDebut(){
    return debut;
}
QDateTime Horaire::getFin(){
    return fin;
}
QString Horaire::getMission(){
    return mission;
}
QString Horaire::getAgent(){
    return agent;
}
void Horaire::setRef(QString reference){
    this->reference = reference;
}
void Horaire::setDebut(QDateTime debut){
    this->debut = debut;
}
void Horaire::setFin(QDateTime fin){
    this->fin = fin;
}
void Horaire::setMission(QString mission){
    this->mission = mission;
}
void Horaire::setAgent(QString agent){
    this->agent = agent;
}
//ajout
bool Horaire::Ajouter_horaire(){
    //bool test = false;
    QSqlQuery query1;
          query1.prepare("INSERT INTO horaire (reference, debut, fin, mission, agent) "
                        "VALUES (:reference, :debut, :fin, :mission, :agent)");
          query1.bindValue(":reference", reference);
          query1.bindValue(":debut", debut);
          query1.bindValue(":fin", fin);
          query1.bindValue(":mission", mission);
          query1.bindValue(":agent", agent);

        return query1.exec();
}
//affichage
QSqlQueryModel* Horaire::Afficher_horaire(){
    QSqlQueryModel* model1 = new QSqlQueryModel();

    model1->setQuery("SELECT * FROM horaire");

    model1->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Début"));
    model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Fin"));
    model1->setHeaderData(3, Qt::Horizontal, QObject::tr("Mission"));
    model1->setHeaderData(4, Qt::Horizontal, QObject::tr("Agent"));

    /*QTableView *view = new QTableView;
    view->setModel(model1);
          view->show();*/

    return model1;
}
//modification
bool Horaire::Modifier_Horaire(QString reference, QDateTime debut, QDateTime fin, QString mission, QString agent){
    QSqlQuery query;
    query.prepare("UPDATE horaire SET debut=:debut, fin=:fin, mission=:mission, agent=:agent WHERE reference=:reference");
    query.bindValue(":reference", reference);
    query.bindValue(":debut", debut);
    query.bindValue(":fin", fin);
    query.bindValue(":mission", mission);
    query.bindValue(":agent", agent);

    return query.exec();
}
//suppression
bool Horaire::Supprimer_horaire(QString reference){
    QSqlQuery query1;
          query1.prepare("DELETE FROM horaire WHERE reference=:reference");
          query1.bindValue(0, reference);

          return query1.exec();
}
//affectation
QSqlQueryModel * Horaire::Affecter_agent(){
    QSqlQueryModel* agent = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("SELECT id FROM personnel");
    qry->exec();
    agent->setQuery(*qry);
    //qDebug() <<(agent->rowCount());
    return agent;
}
