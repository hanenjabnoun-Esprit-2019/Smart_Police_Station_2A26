#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
signals:
    void PageAccueil();

private slots:
    void on_pushButton_gestionAffaires_clicked();

    void on_pushButton_gestionRessources_clicked();

    void on_pushButton_gestionPersonnel_clicked();

    void on_pushButton_gestionCitoyen_clicked();

    void on_pushButton_gestionCrimes_clicked();

    void on_pushButton_retourMenu_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
