#ifndef DIAL2_H
#define DIAL2_H

#include <QDialog>
#include "detenu.h"
#include "cellule.h"

namespace Ui {
class Dial2;
}

class Dial2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dial2(QWidget *parent = nullptr);
    ~Dial2();
signals:
    void PageAccueil();
private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();

    //void on_pb_ajouter_v_clicked();

    void on_pb_ajouter_c_clicked();

    void on_pb_supprimer_c_clicked();

    void on_btn_image_clicked();

    void on_pb_modifier_clicked();

    void on_modif_cel_clicked();

    void on_pb_rech_det_clicked();

    void on_pb_exportpdf_d_clicked();

    void on_pb_export_c_clicked();

    void on_pb_rech_cel_clicked();

    //void on_pushButton_clicked();

    void on_pushButton_RetourMenu_clicked();

private:
    Ui::Dial2 *ui;
    Detenu D;
    Cellule C;
};

#endif // DIAL2_H
