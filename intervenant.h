#ifndef INTERVENANT_H
#define INTERVENANT_H
#include <QString>
#include <QSqlQueryModel>
#include <QDateTimeEdit>
#include <QDate>

class Intervenant
{
public:
    Intervenant();
    Intervenant(int,QString,QString,QString);
    QString getnomI();
    QString getprenomI();
    QString getprof();
    int getId();



    void setnomi(QString);
    void setprenomi(QString);
    void setprof(QString);
    void setId(int);



    bool Ajouter_Inter();
    QSqlQueryModel* Afficher_Inter();
    bool Modifier_Inter(int,QString,QString,QString);
    bool Supprimer_Inter(int);
    QSqlQueryModel* Trouver_Inter(int, QString, QString);

private:
    QString nomI,prenomI,prof;
    int id;
};

#endif // INTERVENANT_H
