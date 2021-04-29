#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>
#include <QSqlQueryModel>
class Equipement
{
public:
    Equipement();
    Equipement(int,QString,int);
    int getid();
    QString getnomE();
    int getqte();
    void setid(int);
    void setnomE(QString);
    void setqte(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier_e(int id,QString nomE,int qte);
    QSqlQueryModel* Trouver_eq(QString recherche);
private:
    int id;
    QString nomE;
    int qte;

};

#endif // EQUIPEMENT_H
