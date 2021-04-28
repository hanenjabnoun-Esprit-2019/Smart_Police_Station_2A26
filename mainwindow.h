#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "detenu.h"
#include "cellule.h"
#include <QFileDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();

    void on_pb_ajouter_v_clicked();

    void on_pb_ajouter_c_clicked();

    void on_pb_supprimer_c_clicked();

    void on_btn_image_clicked();

    void on_pb_modifier_clicked();

    void on_modif_cel_clicked();

    void on_pb_rech_det_clicked();

    void on_pb_exportpdf_d_clicked();

    void on_pb_export_c_clicked();

    void on_pb_rech_cel_clicked();

private:
    Ui::MainWindow *ui;
    Detenu D;
    Cellule C;
};

#endif // MAINWINDOW_H
