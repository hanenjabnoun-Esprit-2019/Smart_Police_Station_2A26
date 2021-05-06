#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQueryModel>
#include <QDateTimeEdit>
#include <QDate>
class Personnel
{
public:
    Personnel();
    Personnel(QString, QString, QString, QString, QString);
    QString getId();
    QString getNom();
    QString getPrenom();
    QString getSexe();
    QString getGrade();

    void setId(QString);
    void setNom(QString);
    void setPrenom(QString);
    void setGrade(QString);
    void setSexe(QString);

    bool Ajouter_personnel();
    QSqlQueryModel* Afficher_personnel();
    bool Modifier_personnel(QString, QString);
    bool Supprimer_personnel(QString);
    QSqlQueryModel* Trouver_personnel(QString);
    QSqlQueryModel* Tri();

private:
    QString Id, Nom, Prenom,Sexe, Grade;
};

int connectAdmin(QString, QString);
int compteJanvier();
int compteFevrier();
int compteMars();
int compteAvril();
int compteMai();
int compteJuin();
int compteJuillet();
int compteAout();
int compteSeptembre();
int compteOctobre();
int compteNovembre();
int compteDecembre();
#endif // PERSONNEL_H
