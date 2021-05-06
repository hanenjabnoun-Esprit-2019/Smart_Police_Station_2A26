#ifndef CELLULE_H
#define CELLULE_H

#include <QString>
#include <QSqlQueryModel>
class Cellule
{
public:
    Cellule();
    Cellule(int,int);
        int getNcel();
        int getNdet();
        void setNcel(int);
        void setNdet(int);
        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int num_cel);
        bool modifier(int num_cell,int num_det);
        QSqlQueryModel* Trouver_c(QString recherche);
private:
        int num_cell;
        int num_det;
};

#endif // CELLULE_H

