#ifndef MENU_GESTION_PERSONNEL_H
#define MENU_GESTION_PERSONNEL_H

#include <QDialog>

namespace Ui {
class Menu_Gestion_Personnel;
}

class Menu_Gestion_Personnel : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_Gestion_Personnel(QWidget *parent = nullptr);
    ~Menu_Gestion_Personnel();

/*signals:
    void PageAccueil();*/
private slots:
    void on_pushButton_CrudPerso_clicked();

    void on_pushButton_RetourMenuPrincipale_clicked();

    void on_pushButton_CrudHoraire_clicked();

    void on_pushButton_Stats_clicked();

private:
    Ui::Menu_Gestion_Personnel *ui;
};

#endif // MENU_GESTION_PERSONNEL_H
