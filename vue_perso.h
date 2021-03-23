#ifndef VUE_PERSO_H
#define VUE_PERSO_H

#include <QWidget>
#include "personnel.h"
#include <QDialog>

namespace Ui {
class Vue_perso;
}

class Vue_perso : public QDialog
{
    Q_OBJECT

public:
    explicit Vue_perso(QWidget *parent = 0);
    ~Vue_perso();

private slots:
    void on_pushButton_AjoutPersonnel_clicked();

    void on_pushButton_SupprPersonnel_clicked();

private:
    Ui::Vue_perso *ui;
    Personnel P;
};

#endif // VUE_PERSO_H
