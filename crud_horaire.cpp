#include "crud_horaire.h"
#include "ui_crud_horaire.h"
#include "menu_gestion_personnel.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include <QPrintDialog>

Crud_Horaire::Crud_Horaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Crud_Horaire)
{
    ui->setupUi(this);
    ui->tableView_AfficheHor->setModel(H.Afficher_horaire());
    ui->comboBox_Agent->setModel(H.Affecter_agent());
    //ui->tableWidget_AfficherHor->setItem( , ,H.Afficher_horaire());
}

Crud_Horaire::~Crud_Horaire()
{
    delete ui;
}

void Crud_Horaire::on_pushButton_RetourMenuPrincipale_clicked()
{
    Menu_Gestion_Personnel MGP;
    MGP.setModal(true);
    hide();
    MGP.exec();
}

void Crud_Horaire::on_pushButton_AjoutHoraire_clicked()
{
    QString reference = ui->lineEdit_RefHoraire->text();
    QDateTime debut = ui->dateTimeEdit_Debut->dateTime();
    QDateTime fin = ui->dateTimeEdit_Fin->dateTime();
    QString mission = ui->comboBox_Mission->currentText();
    /*QString agent = ui->comboBox_Agent->currentText();
    Horaire H(reference, debut, fin, mission, agent);
    bool ajout = H.Ajouter_horaire();

    if(ajout){
        QMessageBox::information(this, tr("Done"), QString(tr("Ajout avec succès")));
        //ui->tableView_Horaire->setModel(H.Afficher_horaire());
    }
    else
        QMessageBox::information(this, tr("Failed"), QString(tr("Ajout échoué")));*/
}

void Crud_Horaire::on_pushButton_ModifHoraire_clicked()
{
    QString reference = ui->lineEdit_RefHorModif->text();
    QDateTime debut = ui->dateTimeEdit_DebutHorModif->dateTime();
    QDateTime fin = ui->dateTimeEdit_FinHorModif->dateTime();
    QString mission = ui->comboBox_MissionHorModif->currentText();
    //QString agent = ui->lineEdit_AgentHorModif->text();

    //Horaire H(reference, debut, fin, mission, agent);
    //bool modif = H.Modifier_Horaire(reference, debut, fin, mission, agent);

    /*if(modif){
        //ui->tableView_Horaire->setModel(H.Afficher_horaire());
        QMessageBox::information(this, tr("Done"), QString(tr("Modification réussie")));
    }
    else
        QMessageBox::information(this, tr("Failed"), QString(tr("Modification échoué")));
*/
}

void Crud_Horaire::on_pushButton_SupprHoraire_clicked()
{
    Horaire H1;
    H1.setRef(ui->lineEdit_Ref_HoraireSuppr->text());
    bool suppr = H1.Supprimer_horaire(H1.getRef());

    if(suppr){
        QMessageBox::information(this, tr("Done"), QString(tr("Suppression réussie")));
        //ui->tableView_Horaire->setModel(H.Afficher_horaire());
    }
    else
        QMessageBox::critical(this, tr("Failed"), QString(tr("Echec de suppresssion")));
}

void Crud_Horaire::on_pushButton_exportpdf_clicked()
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

    const int rowCount = ui->tableView_AfficheHor->model()->rowCount();
    const int columnCount = ui->tableView_AfficheHor->model()->columnCount();
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
        if (!ui->tableView_AfficheHor->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_AfficheHor->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_AfficheHor->isColumnHidden(column)) {
                QString data = ui->tableView_AfficheHor->model()->data(ui->tableView_AfficheHor->model()->index(row, column)).toString().simplified();
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
