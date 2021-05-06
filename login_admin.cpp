#include "login_admin.h"
#include "ui_login_admin.h"
#include "admin.h"
#include "personnel.h"
#include <QMessageBox>
#include "QSqlQuery"


Login_Admin::Login_Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login_Admin)
{
    ui->setupUi(this);
    int ret=A.connect_arduino();
    switch (ret) {
    case (0): qDebug()<<"Arduino est disponible et connectée"<<A.getarduino_port_name();
        break;
    case (1): qDebug()<<"Arduino est disponible mais elle n'est pas connectée"<<A.getarduino_port_name();
        break;
    case (-1): qDebug()<<"Arduino n'est pas disponible";
        break;
    }
    QObject::connect(A.getserial(), SIGNAL(readyRead()),this,SLOT(update_label()));
}

Login_Admin::~Login_Admin()
{
    delete ui;
}

void Login_Admin::on_pushButton_retourMenu_clicked()
{
    this->close();
    emit PageAccueil();
}

void Login_Admin::on_pushButton_loginAdmin_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    //if(connectAdmin(username, password)==1){
    this->hide();
    Admin Admin;
    Admin.setModal(true);
    Admin.exec();
    //}
    if(connectAdmin(username, password)>1)
        ui->label_Messagelog->setText("nom d'utilisateur ou mot de passe incorrect");
    if(connectAdmin(username, password)<1)
        ui->label_Messagelog->setText("nom d'utilisateur ou mot de passe incorrect");
}


void Login_Admin::update_label()
{
data=A.read_from_arduino();
    if(data=="1"){
        ui->label_Messagelog->setText("Connection par carte réussie"); // si les données reçues de arduino via la liaison série sont égales à 1
        this->hide();
        Admin Admin;
        Admin.setModal(true);
        Admin.exec();
        qDebug()<<"Admin connecté";
    }
    // alors afficher

    else if (data=="0")
        ui->label_Messagelog->setText("Connection par carte échouée");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher
}
