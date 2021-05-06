#ifndef DIALOG22_H
#define DIALOG22_H

#include <QDialog>
#include "equipement.h"
#include "vehicule.h"

namespace Ui {
class Dialog22;
}

class Dialog22 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog22(QWidget *parent = nullptr);
    ~Dialog22();
signals:
    void PageAccueil();
private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();

    void on_pb_ajouter_v_clicked();

    void on_pb_supprimer_v_clicked();

    void on_pb_modifier_e_2_clicked();

    void on_pb_modifier_e_clicked();

    //void on_pb_exportpdf_clicked();

    void on_pb_search_eq_clicked();

    void on_pb_exportpdf_eq_clicked();

    void on_pb_search_v_clicked();

    void on_pb_exportpdf_v_clicked();

    //void on_tab_equipement_activated(const QModelIndex &index);
    void on_pushButton_RetourMenu_clicked();

private:
    Ui::Dialog22 *ui;
    Equipement E;
    Vehicule V;

};

#endif // DIALOG22_H
