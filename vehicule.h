#ifndef VEHICULE_H
#define VEHICULE_H
#include <QString>
#include <QSqlQueryModel>

class Vehicule
{
public:
    Vehicule();
    Vehicule(QString,QString,QString,QString,int);
    QString getMat();
    QString getMar();
    QString getMod();
    QString getEta();
    int getQtev();
    void setMat(QString);
    void setMar(QString);
    void setMod(QString);
    void setEta(QString);
    void setQtev(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString mat);
    bool modifier_v(QString mat,QString etat,int qtev);
    QSqlQueryModel* Trouver_v(QString recherche);

private:
    QString mat;
    QString marq;
    QString mod;
    QString etat;
    int qtev;


};

#endif // VEHICULE_H
