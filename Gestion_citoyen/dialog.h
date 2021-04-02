#ifndef DIALOG_H
#define DIALOG_H

#include<demande_a.h>
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
    //void on_pb_ajouter_clicked();

    //void on_pb_supprimer_clicked();

    void on_pb_ajourter_clicked();

    void on_pb_supprimer_clicked();

private:
    Ui::Dialog *ui;
     demande_a E;
};

#endif // DIALOG_H
