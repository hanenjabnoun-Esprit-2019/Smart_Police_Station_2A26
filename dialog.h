#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "equipement.h"
#include "vehicule.h"

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
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();

    void on_pb_ajouter_v_clicked();

    void on_pb_supprimer_v_clicked();

    void on_pb_modifier_e_2_clicked();

    void on_pb_modifier_e_clicked();

    void on_pb_exportpdf_clicked();

    void on_pb_search_eq_clicked();

    void on_pb_exportpdf_eq_clicked();

    void on_pb_search_v_clicked();

    void on_pb_exportpdf_v_clicked();

    void on_tab_equipement_activated(const QModelIndex &index);

private:
    Ui::Dialog *ui;
    Equipement E;
    Vehicule V;
};

#endif // DIALOG_H
