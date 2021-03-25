#include "dialog1.h"
#include "ui_dialog1.h"
#include "dialog2.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}


void Dialog1::on_pushButton_avance_clicked()
{
    Dialog2 D2;
    D2.setModal(true);
    hide();
    D2.exec();
}
