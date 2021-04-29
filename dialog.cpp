#include "dialog.h"
#include "ui_dialog.h"
#include <QIntValidator>
#include <QTextDocument>
#include <QPdfWriter>
#include <QTableWidget>
#include <QPainter>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_qte->setValidator(new QIntValidator(0, 9999, this));
    ui->le_id_supp->setValidator(new QIntValidator(0, 999999, this));
    ui->le_qtev->setValidator(new QIntValidator(0, 999, this));
    ui->tab_equipement->setModel(E.afficher());
    ui->tab_vehicule->setModel(V.afficher());
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nomE=ui->le_nomE->text();
    int qte=ui->le_qte->text().toInt();
    Equipement E(id,nomE,qte);

    bool test=E.ajouter();

    if (test) {

        // ACTUALISATION DE L'AFFICHAGE
          ui->tab_equipement->setModel(E.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to Exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to Exit."), QMessageBox::Cancel);

}

void Dialog::on_pb_search_eq_clicked()
{
    Equipement E1;
        QString recherche = ui->le_searched_eq->text();
        ui->tab_equipement->setModel(E1.Trouver_eq(recherche));
}

void Dialog::on_pb_exportpdf_eq_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    QString strTitle = "Planning";

    const int rowCount = ui->tab_equipement->model()->rowCount();
    const int columnCount = ui->tab_equipement->model()->columnCount();
    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg(strTitle)
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_equipement->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_equipement->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_equipement->isColumnHidden(column)) {
                QString data = ui->tab_equipement->model()->data(ui->tab_equipement->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
}
    delete document;
}

void Dialog::on_pb_supprimer_clicked()
{
    Equipement E1;
            E1.setid(ui->le_id_supp->text().toInt());
                bool test = E1.supprimer(E1.getid());
                if(test){
                       QMessageBox::information(this, tr("Done"), QString(tr("Suppression réussie")));
                       ui->tab_equipement->setModel(E1.afficher());
                   }
                   else
                       QMessageBox::critical(this, tr("Failed"), QString(tr("Echec de suppresssion")));

}

void Dialog::on_pb_modifier_e_clicked()
{
    int id=ui->le_id_mod->text().toInt();
    QString nomE=ui->le_nomE_mod->text();
    int qte=ui->le_qte_mod->text().toInt();
    Equipement E(id,nomE,qte);

    bool modif = E.modifier_e(id, nomE,qte);
    //QMessageBox msgBox;
    if(modif){

        QMessageBox::information(this, tr("Done"), QString(tr("Modification réussie")));
         ui->tab_equipement->setModel(E.afficher());

    }
    else
        QMessageBox::critical(this, tr("Failed"), QString(tr("Modification échoué")));

}

void Dialog::on_pb_ajouter_v_clicked()
{
    QString mat=ui->le_mat->text();
    QString marq=ui->le_mar->text();
    QString mod=ui->le_mod->text();
    QString etat=ui->le_eta->text();
    int qtev=ui->le_qtev->text().toInt();

    Vehicule V(mat,marq,mod,etat,qtev);

    bool test=V.ajouter();

    if (test) {

        // ACTUALISATION DE L'AFFICHAGE
          ui->tab_vehicule->setModel(V.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to Exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to Exit."), QMessageBox::Cancel);

}

void Dialog::on_pb_search_v_clicked()
{
    Vehicule V1;
            QString recherche = ui->le_searched_v->text();
            ui->tab_vehicule->setModel(V1.Trouver_v(recherche));
}

void Dialog::on_pb_exportpdf_v_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    QString strTitle = "Planning";

    const int rowCount = ui->tab_vehicule->model()->rowCount();
    const int columnCount = ui->tab_vehicule->model()->columnCount();
    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg(strTitle)
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_vehicule->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_vehicule->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_vehicule->isColumnHidden(column)) {
                QString data = ui->tab_vehicule->model()->data(ui->tab_vehicule->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
}
    delete document;
}

void Dialog::on_pb_supprimer_v_clicked()
{
    Vehicule V1;
    V1.setMat(ui->le_mat_supp->text());
        bool test = V1.supprimer(V1.getMat());
        if(test){
               QMessageBox::information(this, tr("Done"), QString(tr("Suppression réussie")));
               ui->tab_vehicule->setModel(V1.afficher());
           }
           else
               QMessageBox::critical(this, tr("Failed"), QString(tr("Echec de suppresssion")));

}

void Dialog::on_pb_modifier_e_2_clicked()
{
    QString marq="",mod="";

         QString mat =ui->le_mat_mod->text();
         QString etat =ui->le_etat_mod->text();
         int qtev=ui->le_qtev_mod->text().toInt();

         Vehicule V1(mat, marq, mod, etat, qtev);
         bool modif = V1.modifier_v(mat, etat,qtev);
         //QMessageBox msgBox;
         if(modif){

             QMessageBox::information(this, tr("Done"), QString(tr("Modification réussie")));
             ui->tab_vehicule->setModel(V1.afficher());

         }
         else
             QMessageBox::critical(this, tr("Failed"), QString(tr("Modification échoué")));


}
