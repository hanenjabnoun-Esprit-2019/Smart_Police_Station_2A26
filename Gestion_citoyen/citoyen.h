#ifndef CITOYEN_H
#define CITOYEN_H
#include<QString>
#include<QSqlQueryModel>
class Citoyen
{
public:
    Citoyen();
    Citoyen(int,QString,QString);
    int getnumero();
    QString getnom();
    QString getprenom();
    void setnumero(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
   QSqlQueryModel* afficher ();
   bool supprimer(int);
   bool modifier(int, QString, QString);
private:
    int numero;
    QString nom, prenom;
};

#endif // CITOYEN_H
