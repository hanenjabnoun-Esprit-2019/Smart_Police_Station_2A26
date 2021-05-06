#include "crud_citoyen.h"
#include "ui_crud_citoyen.h"
#include "menu_gestion_citoyen.h"
#include"citoyen.h"
#include<QMessageBox>
#include<QIntValidator>
#include<QTextDocument>
#include<QPrintDialog>
#include<QTextStream>
#include<QPrinter>


Crud_citoyen::Crud_citoyen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Crud_citoyen)
{
    ui->setupUi(this);
    ui->le_numero->setValidator( new QIntValidator(100, 9999999, this));
     ui->tab_citoyen->setModel(E.afficher());
}

Crud_citoyen::~Crud_citoyen()
{
    delete ui;
}

void Crud_citoyen::on_pushButton_RetourMenuGestionCit_clicked()
{
    Menu_gestion_citoyen MGC;
    MGC.setModal(true);
    hide();
    MGC.exec();
}

void Crud_citoyen::on_pb_ajouter_clicked()
{
    int numero=ui->le_numero->text().toInt();
    QString nom=ui->le_nom->text();
     QString prenom=ui->le_prenom->text();
    Citoyen E(numero,nom,prenom);
    bool test=E.ajouter();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajourter avec succes.");
    ui->tab_citoyen->setModel(E.afficher());
     }
   else
       msgBox.setText("echec de l'ajout.");
      msgBox.exec();
}

void Crud_citoyen::on_pushButton_clicked()
{
    Citoyen E1;
    E1.setnumero(ui->le_numero_sup->text().toInt());
    bool test=E1.supprimer(E1.getnumero());
    QMessageBox msgBox;

   if(test)
       {msgBox.setText("supprimer avec succes.");
    ui->tab_citoyen->setModel(E.afficher());
     }
    else
        msgBox.setText("echec de la suppresion.");
        msgBox.exec();
}

void Crud_citoyen::on_pb_mofidier_clicked()
{
       int numero = ui->Le_numero->text().toInt();
       QString nom = ui->le_nom_2->text();
       QString prenom = ui->le_prenom_2->text();

       Citoyen C(numero, nom, prenom);

       bool modif = C.modifier(numero, nom, prenom);

       //QMessageBox msgBox;

       if(modif){

           ui->tab_citoyen->setModel(C.afficher());

           QMessageBox::information(this, tr("Done"), QString(tr("Modification réussie")));

       }

       else

           QMessageBox::information(this, tr("Failed"), QString(tr("Modification échoué")));



       //msgBox.exec();
}

void Crud_citoyen::on_pb_recherche_clicked()
{
     QString numero = ui->la_recherche->text();
     ui->tab_citoyen->setModel(E.rechercher(numero));

}

void Crud_citoyen::on_pb_export_pdf_clicked()
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

        const int rowCount = ui->tab_citoyen->model()->rowCount();
        const int columnCount = ui->tab_citoyen->model()->columnCount();
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
            if (!ui->tab_citoyen->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tab_citoyen->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tab_citoyen->isColumnHidden(column)) {
                    QString data = ui->tab_citoyen->model()->data(ui->tab_citoyen->model()->index(row, column)).toString().simplified();
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

void Crud_citoyen::on_pb_tri_clicked()
{
        ui->tab_citoyen->setModel(E.tri ());
}
