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
    Personnel(QString, QString, QString, QString);
    QString getId();
    QString getNom();
    QString getPrenom();
    QString getGrade();
    void setId(QString);
    void setNom(QString);
    void setPrenom(QString);
    void setGrade(QString);
    bool Ajouter_personnel();
    QSqlQueryModel* Afficher_personnel();
    bool Modifier_personnel(QString, QString);
    bool Supprimer_personnel(QString);
private:
    QString Id, Nom, Prenom, Grade;
};
#endif // PERSONNEL_H
