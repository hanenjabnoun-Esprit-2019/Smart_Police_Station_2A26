#ifndef DEMANDE_A_H
#define DEMANDE_A_H
#include<QString>
#include<QSqlQueryModel>

class demande_a
{
public:
    demande_a();
    demande_a(int,QString,QString);
    int getid();
    QString getnom();
    QString getobjet();
    void setid(int);
    void setnom(QString);
    void setobjet(QString);
    bool ajouter();
   QSqlQueryModel* afficher ();
   bool supprimer(int);
   bool modifier(int,QString , QString);
private:
    int id;
    QString nom, objet;
};

#endif // DEMANDE_A_H
