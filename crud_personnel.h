#ifndef CRUD_PERSONNEL_H
#define CRUD_PERSONNEL_H

#include <QDialog>
#include "personnel.h"

namespace Ui {
class Crud_Personnel;
}

class Crud_Personnel : public QDialog
{
    Q_OBJECT

public:
    explicit Crud_Personnel(QWidget *parent = nullptr);
    ~Crud_Personnel();

private slots:
    void on_pushButton_AjoutPerso_clicked();

    void on_pushButton_ModifPersonnel_clicked();

    void on_pushButton_SupprPerso_clicked();

    void on_pushButton_RetourGestionPerso_clicked();

    void on_pushButton_Recherche_clicked();

    void on_pushButton_tri_clicked();

private:
    Ui::Crud_Personnel *ui;
    Personnel P;
    Personnel R;
    Personnel T;
};

#endif // CRUD_PERSONNEL_H
