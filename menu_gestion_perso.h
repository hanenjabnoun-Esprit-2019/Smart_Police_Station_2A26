#ifndef MENU_GESTION_PERSO_H
#define MENU_GESTION_PERSO_H

#include <QWidget>
#include <QDialog>
#include "vue_perso.h"

namespace Ui {
class Menu_gestion_perso;
}

class Menu_gestion_perso : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_gestion_perso(QWidget *parent = 0);
    ~Menu_gestion_perso();

private slots:
    void on_pushButton_gerer_personnel_clicked();

private:
    Ui::Menu_gestion_perso *ui;
    Vue_perso *Vue_personnel;
};

#endif // MENU_GESTION_PERSO_H
