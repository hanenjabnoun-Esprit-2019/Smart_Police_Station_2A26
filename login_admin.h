#ifndef LOGIN_ADMIN_H
#define LOGIN_ADMIN_H

#include <QDialog>
#include "arduino.h"

namespace Ui {
class Login_Admin;
}

class Login_Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Login_Admin(QWidget *parent = nullptr);
    ~Login_Admin();

signals:
    void PageAccueil();
private slots:
    void on_pushButton_retourMenu_clicked();

    void on_pushButton_loginAdmin_clicked();

    void update_label();

private:
    Ui::Login_Admin *ui;
    arduino A;
    QByteArray data;
};

#endif // LOGIN_ADMIN_H
