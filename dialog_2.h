#ifndef DIALOG_2_H
#define DIALOG_2_H

#include <QDialog>
#include "dossierc.h"
#include "intervenant.h"

namespace Ui {
class Dialog_2;
}

class Dialog_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_2(QWidget *parent = nullptr);
    ~Dialog_2();
signals:
    void PageAccueil();
private slots:

    void on_pb_ajout_clicked();

    void on_pb_dossiersup_clicked();

    void on_pb_mod_clicked();

    void on_pb_ajout2_clicked();

    void on_pb_sup2_clicked();

    void on_pb_mod2_clicked();

    void on_pb_recherched_clicked();

    void on_pb_export_clicked();

    void on_pushButton_RetourMenu_clicked();

private:
    Ui::Dialog_2 *ui;
    DossierC D;
    Intervenant I;
    DossierC R;

};

#endif // DIALOG_2_H
