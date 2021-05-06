#ifndef CRUD_CITOYEN_H
#define CRUD_CITOYEN_H

#include <QDialog>
#include<citoyen.h>

namespace Ui {
class Crud_citoyen;
}

class Crud_citoyen : public QDialog
{
    Q_OBJECT

public:
    explicit Crud_citoyen(QWidget *parent = nullptr);
    ~Crud_citoyen();

private slots:
    void on_pushButton_RetourMenuGestionCit_clicked();

    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pb_mofidier_clicked();

    void on_pb_recherche_clicked();

    void on_pb_export_pdf_clicked();

    //void on_pb_tri_clicked();

private:
    Ui::Crud_citoyen *ui;
    Citoyen E;
};

#endif // CRUD_CITOYEN_H
