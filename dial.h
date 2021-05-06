#ifndef DIAL_H
#define DIAL_H

#include "detenu.h"
#include "cellule.h"
#include <QDialog>

namespace Ui {
class Dial;
}

class Dial : public QDialog
{
    Q_OBJECT

public:
    explicit Dial(QWidget *parent = nullptr);
    ~Dial();

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
    Ui::Dial *ui;
    Detenu D;
    Cellule C;
};

#endif // DIAL_H
