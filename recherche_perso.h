#ifndef RECHERCHE_PERSO_H
#define RECHERCHE_PERSO_H

#include <QDialog>

namespace Ui {
class Recherche_Perso;
}

class Recherche_Perso : public QDialog
{
    Q_OBJECT

public:
    explicit Recherche_Perso(QWidget *parent = nullptr);
    ~Recherche_Perso();

private:
    Ui::Recherche_Perso *ui;
};

#endif // RECHERCHE_PERSO_H
