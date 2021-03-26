#ifndef CRUD_HORAIRE_H
#define CRUD_HORAIRE_H

#include <QDialog>
#include "horaire.h"

namespace Ui {
class Crud_Horaire;
}

class Crud_Horaire : public QDialog
{
    Q_OBJECT

public:
    explicit Crud_Horaire(QWidget *parent = nullptr);
    ~Crud_Horaire();

private slots:
    void on_pushButton_RetourMenuPrincipale_clicked();

    void on_pushButton_AjoutHoraire_clicked();

    void on_pushButton_ModifHoraire_clicked();

    void on_pushButton_SupprHoraire_clicked();

    int on_pushButton_exportpdf_clicked();

private:
    Ui::Crud_Horaire *ui;
    Horaire H;

};

#endif // CRUD_HORAIRE_H
