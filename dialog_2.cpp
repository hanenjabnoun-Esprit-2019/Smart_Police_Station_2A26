#include "dialog_2.h"
#include "ui_dialog_2.h"
#include "dossierc.h"
#include "intervenant.h"
#include <QMessageBox>
#include <QtWidgets>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>



Dialog_2::Dialog_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_2)
{
    ui->setupUi(this);
    ui->tabdossier->setModel(D.Afficher_dossier());
    ui->tabinter->setModel(I.Afficher_Inter());
}

Dialog_2::~Dialog_2()
{
    delete ui;
}


void Dialog_2::on_pb_ajout_clicked()
{
    int id=ui->lineEditId->text().toInt();
    QString nom=ui->lineEditNom->text();
    QString prenom=ui->lineEditPrenom->text();
    QString description=ui->le_desc->text();
 DossierC D (id,nom,prenom,description);

 bool test=D.Ajouter_dossier();

 if(test)
 {
     QMessageBox::information(nullptr, QObject::tr("OK"),
                 QObject::tr("Ajout effectué.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tabdossier->setModel(D.Afficher_dossier());
 }
 else
     QMessageBox::critical(nullptr, QObject::tr("not OK"),
                 QObject::tr("Ajout echoué.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);



}

void Dialog_2::on_pb_dossiersup_clicked()
{
    DossierC D1; D1.setId(ui->le_dossiersup->text().toInt());
    bool test = D1.Supprimer_dossier(D1.getId());
    if(test){
           QMessageBox::information(this, tr("Done"), QString(tr("Suppression réussie")));
           ui->tabdossier->setModel(D1.Afficher_dossier());
       }
       else
           QMessageBox::critical(this, tr("Failed"), QString(tr("Echec de suppresssion")));
       //msgBox.exec();

}

void Dialog_2::on_pb_mod_clicked()
{
        int id=ui->le_idmod->text().toInt();
        QString nom =ui->le_newnom->text();
        QString prenom =ui->le_newprenom->text();
        QString description =ui->le_newdesc->text();


        DossierC D(id, nom, prenom, description);
        bool modif = D.Modifier_dossier(id, nom,prenom,description);
        //QMessageBox msgBox;
        if(modif){
            ui->tabdossier->setModel(D.Afficher_dossier());
            QMessageBox::information(this, tr("Done"), QString(tr("Modification réussie")));
        }
        else
            QMessageBox::information(this, tr("Failed"), QString(tr("Modification échoué")));

        //msgBox.exec();
}

void Dialog_2::on_pb_ajout2_clicked()
{
    int id=ui->le_idajout2->text().toInt();
    QString nom=ui->le_nomajout2->text();
    QString prenom=ui->le_prenomajout2->text();
    QString prof=ui->le_profajout2->text();
 Intervenant I (id,nom,prenom,prof);

 bool test=I.Ajouter_Inter();

 if(test)
 {
     QMessageBox::information(nullptr, QObject::tr("OK"),
                 QObject::tr("Ajout effectué.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tabinter->setModel(I.Afficher_Inter());
 }
 else
     QMessageBox::critical(nullptr, QObject::tr("not OK"),
                 QObject::tr("Ajout echoué.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog_2::on_pb_sup2_clicked()
{
    Intervenant I1; I1.setId(ui->le_idsup2->text().toInt());
    bool test = I1.Supprimer_Inter(I1.getId());
    if(test){
           QMessageBox::information(this, tr("Done"), QString(tr("Suppression réussie")));
           ui->tabinter->setModel(I1.Afficher_Inter());
       }
       else
           QMessageBox::critical(this, tr("Failed"), QString(tr("Echec de suppresssion")));
       //msgBox.exec();
}

void Dialog_2::on_pb_mod2_clicked()
{
    int id=ui->le_idmod2->text().toInt();
    QString nom =ui->le_nommod2->text();
    QString prenom =ui->le_prenommod2->text();
    QString prof =ui->le_profmod2->text();


    Intervenant I(id, nom, prenom, prof);
    bool modif = I.Modifier_Inter(id, nom,prenom,prof);
    //QMessageBox msgBox;
    if(modif){
        ui->tabinter->setModel(I.Afficher_Inter());
        QMessageBox::information(this, tr("Done"), QString(tr("Modification réussie")));
    }
    else
        QMessageBox::information(this, tr("Failed"), QString(tr("Modification échoué")));

    //msgBox.exec();
}

void Dialog_2::on_pb_recherched_clicked()
{
        QString recherche = ui->le_recherced->text();
        ui->tabdossier->setModel(R.Trouver_dossier(recherche));
}

void Dialog_2::on_pb_export_clicked()
{
    /* QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("/foobar/nonwritable.pdf");
        QPainter painter;
        if (! painter.begin(&printer)) { // failed to open file
            qWarning("failed to open file, is it writable?");
            return 1;
        }
        painter.drawText(10, 10, "Planing du personnel");
       // painter.drawTextItem(10, 40, ui->tableView_Horaire->column);
        if (! printer.newPage()) {
            qWarning("failed in flushing page to disk, disk full?");
            return 1;
        }
        painter.drawText(10, 10, "Test 2");
        painter.end();
        return 0;
        */
        QString strStream;
        QTextStream out(&strStream);
        QString strTitle = "Planning";

        const int rowCount = ui->tabdossier->model()->rowCount();
        const int columnCount = ui->tabdossier->model()->columnCount();
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
            if (!ui->tabdossier->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabdossier->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabdossier->isColumnHidden(column)) {
                    QString data = ui->tabdossier->model()->data(ui->tabdossier->model()->index(row, column)).toString().simplified();
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

void Dialog_2::on_pushButton_RetourMenu_clicked()
{
    this->close();
    emit PageAccueil();
}
