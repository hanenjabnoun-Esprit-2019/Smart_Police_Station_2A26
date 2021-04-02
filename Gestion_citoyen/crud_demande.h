#ifndef CRUD_DEMANDE_H
#define CRUD_DEMANDE_H

#include <QDialog>
#include<demande_a.h>

namespace Ui {
class Crud_demande;
}

class Crud_demande : public QDialog
{
    Q_OBJECT

public:
    explicit Crud_demande(QWidget *parent = nullptr);
    ~Crud_demande();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_retour_MenuGestion_Citoyen_clicked();

private:
    Ui::Crud_demande *ui;
     demande_a E;
};

#endif // CRUD_DEMANDE_H
