#ifndef DETENU_H
#define DETENU_H

#include <QString>
#include <QSqlQueryModel>
class Detenu
{
public:
    Detenu();
    Detenu(QString,QString,QString,int,QString);
    QString getid();
    QString getnomE();
    QString getPrenom();
    int getNum_Cell();
    QString getPhoto();

    void setid(QString);
    void setnomE(QString);
    void setPrenom(QString);
    void setNum_cell(int);
    void setPhoto(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString id);
    bool modifier(QString id,QString nomE,QString prenom,int num_cell);
    QSqlQueryModel* Trouver_d(QString recherche);
private:
    QString id;
    QString nomE;
    QString prenom;
    int num_cell;
    QString photo;
};

#endif // DETENU_H
