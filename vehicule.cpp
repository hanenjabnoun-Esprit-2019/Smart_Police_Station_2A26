#include "vehicule.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

    Vehicule::Vehicule() {
    mat="";  marq="";  mod=""; etat=""; qtev=0;
    }

    Vehicule::Vehicule(QString mat,QString marq,QString mod,QString etat,int qtev){
    this->mat=mat; this->marq=marq; this->mod=mod; this->etat=etat; this->qtev=qtev;
}
    QString Vehicule::getMat(){
        return mat;
    }
    QString Vehicule::getMar(){
        return marq;
    }
    QString Vehicule::getMod(){
        return mod;
    }
    QString Vehicule::getEta(){
        return etat;
    }
    int Vehicule::getQtev(){
        return qtev;
    }
    void Vehicule::setMat(QString mat){
        this->mat=mat;
    }
    void Vehicule::setMar(QString marq){
        this->marq=marq;
    }
    void Vehicule::setMod(QString mod){
        this->mod=mod;
    }
    void Vehicule::setEta(QString etat){
        this->etat=etat;
    }

    void Vehicule::setQtev(int qtev){
        this->qtev=qtev;
    }

    bool Vehicule::ajouter(){

        QSqlQuery query;
             query.prepare("INSERT INTO vehicule (mat, marq, mod, etat, qtev) "
                           "VALUES (:mat, :marq, :mod, :etat, :qtev)");
             query.bindValue(0, mat);
             query.bindValue(1, marq);
             query.bindValue(2, mod);
             query.bindValue(3, etat);
             query.bindValue(4, qtev);
        return query.exec();
    }

    QSqlQueryModel* Vehicule::afficher(){
        QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("SELECT* FROM vehicule");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Marque"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Modèle"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Quantité"));

        return model;
    }
    bool Vehicule::supprimer(QString mat){
        QSqlQuery query;
       // QString id_str=QString::number(id);

        query.prepare("Delete from Vehicule WHERE mat=:mat");
        query.bindValue(":mat", mat);

        return query.exec();
  }

    bool Vehicule::modifier_v(QString mat,QString etat,int qtev){
        QSqlQuery query;
        query.prepare("UPDATE vehicule SET etat=:etat, qtev=:qtev WHERE mat=:mat");
        query.bindValue(":mat", mat);
        query.bindValue(":etat", etat);
        query.bindValue(":qtev", qtev);
        return query.exec();
    }

    QSqlQueryModel* Vehicule::Trouver_v(QString recherche){
        QSqlQueryModel* trouve = new QSqlQueryModel();

        trouve->setQuery("SELECT * FROM vehicule WHERE MAT LIKE '"+recherche+"%' OR MARQ LIKE '"+recherche+"%' OR MOD LIKE '"+recherche+"%' OR ETAT LIKE '"+recherche+"%' OR QTEV LIKE '"+recherche+"%' ");

        trouve->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule"));
        trouve->setHeaderData(1, Qt::Horizontal, QObject::tr("Marque"));
        trouve->setHeaderData(2, Qt::Horizontal, QObject::tr("Modèle"));
        trouve->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
        trouve->setHeaderData(4, Qt::Horizontal, QObject::tr("Quantité"));


        return trouve;
    }

