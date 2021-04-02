#ifndef MENU_GESTION_CITOYEN_H
#define MENU_GESTION_CITOYEN_H

#include <QDialog>

namespace Ui {
class Menu_gestion_citoyen;
}

class Menu_gestion_citoyen : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_gestion_citoyen(QWidget *parent = nullptr);
    ~Menu_gestion_citoyen();

private slots:

    void on_pb_citoyen_clicked();

    void on_pb_demande_ad_clicked();

private:
    Ui::Menu_gestion_citoyen *ui;
};

#endif // MENU_GESTION_CITOYEN_H
