#ifndef HORAIRE_H
#define HORAIRE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDateTimeEdit>
#include <QDate>

class Horaire
{
public:
    Horaire();
    Horaire(QString, QDateTime, QDateTime, QString, QString);
    //
    QString getRef();
    QDateTime getDebut();
    QDateTime getFin();
    QString getMission();
    QString getAgent();
    //
    void setRef(QString);
    void setDebut(QDateTime);
    void setFin(QDateTime);
    void setMission(QString);
    void setAgent(QString);
    //
    bool Ajouter_horaire();
    bool Supprimer_horaire(QString);
    bool Modifier_Horaire(QString, QDateTime, QDateTime, QString, QString);
    QSqlQueryModel* Afficher_horaire();
    QSqlQueryModel* Affecter_agent();
private:
    QString reference;
    QDateTime debut, fin;
    QString mission, agent;

};

#endif // HORAIRE_H
