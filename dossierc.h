#ifndef DOSSIERC_H
#define DOSSIERC_H

#include <QString>
#include <QSqlQueryModel>
#include <QDateTimeEdit>
#include <QDate>

class DossierC
{
public:
    DossierC();
    DossierC(int,QString, QString, QString);
    QString getNomc();
    QString getPrenomc();
    QString getDesc();
    int getId();



    void setNomc(QString);
    void setPrenomc(QString);
    void setDesc(QString);
    void setId(int);



    bool Ajouter_dossier();
    QSqlQueryModel* Afficher_dossier();
    bool Modifier_dossier(int,QString,QString,QString);
    bool Supprimer_dossier(int);
    QSqlQueryModel* Trouver_dossier(QString);

private:
    QString nomc,prenomc,description;
    int id;

};

#endif // DOSSIERC_H
