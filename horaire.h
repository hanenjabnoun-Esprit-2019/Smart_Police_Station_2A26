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
    Horaire(int, QDateTime, QDateTime);
    int getRef();
    QDateTime getDebut();
    QDateTime getFin();
    void setRef(int);
    void setDebut(QDateTime);
    void setFin(QDateTime);
    bool Ajouter_horaire();
    bool Supprimer_horaire(int);
    QSqlQueryModel* Afficher_horaire();
private:
    int reference;
    QDateTime debut, fin;

};

#endif // HORAIRE_H
