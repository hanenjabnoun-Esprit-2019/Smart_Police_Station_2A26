#ifndef DIALOG_H
#define DIALOG_H
#include "dossierc.h"
#include "intervenant.h"


#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

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
    Ui::Dialog *ui;
    DossierC D;
    Intervenant I;
    DossierC R;

};

#endif // DIALOG_H
