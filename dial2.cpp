#include "dial2.h"
#include "ui_dial2.h"
#include "detenu.h"
#include <QIntValidator>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QMessageBox>
#include <QFileDialog>

Dial2::Dial2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dial2)
{
    ui->setupUi(this);
    ui->tab_detenu->setModel(D.afficher());
    ui->tab_cellule->setModel(C.afficher());
}

Dial2::~Dial2()
{
    delete ui;
}


void Dial2::on_pb_ajouter_clicked()
{
    QString id=ui->le_id->text();
    QString nomE=ui->le_nomE->text();
    QString Prenom=ui->le_Prenom->text();
    int num_cell=ui->le_num_cell->text().toInt();
    QString photo=ui->lbl_image->text();
    Detenu D(id,nomE,Prenom,num_cell,photo);

    bool test=D.ajouter();

    if (test) {

        // ACTUALISATION DE L'AFFICHAGE
          ui->tab_detenu->setModel(D.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to Exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to Exit."), QMessageBox::Cancel);

}

void Dial2::on_btn_image_clicked()
{
    Detenu D2;
    QString imagename = QFileDialog::getOpenFileName(this, tr("choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
        if(QString::compare(imagename,QString())!=0)
        {

             QImage image;
             bool test = image.load(imagename);
                if(test){
                    image= image.scaledToWidth(ui->lbl_image->width(), Qt::SmoothTransformation);
                    ui->lbl_image->setPixmap(QPixmap::fromImage(image));
                    D2.setPhoto(imagename);
                    QMessageBox::information(this, tr("Done"), QString(tr("importation avec succés")));
                    ui->tab_detenu->setModel(D2.afficher());
                }

           }
           else
               QMessageBox::critical(this, tr("Failed"), QString(tr("Echec d'importation!")));

}

void Dial2::on_pb_rech_det_clicked()
{
    Detenu D2;
       QString recherche = ui->le_search_d->text();
       ui->tab_detenu->setModel(D2.Trouver_d(recherche));
}

void Dial2::on_pb_exportpdf_d_clicked()
{
    QString strStream;
               QTextStream out(&strStream);
               QString strTitle = "Planning";

               const int rowCount = ui->tab_detenu->model()->rowCount();
               const int columnCount = ui->tab_detenu->model()->columnCount();
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
                   if (!ui->tab_detenu->isColumnHidden(column))
                       out << QString("<th>%1</th>").arg(ui->tab_detenu->model()->headerData(column, Qt::Horizontal).toString());
               out << "</tr></thead>\n";

               // data table
               for (int row = 0; row < rowCount; row++) {
                   out << "<tr>";
                   for (int column = 0; column < columnCount; column++) {
                       if (!ui->tab_detenu->isColumnHidden(column)) {
                           QString data = ui->tab_detenu->model()->data(ui->tab_detenu->model()->index(row, column)).toString().simplified();
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

void Dial2::on_pb_supprimer_clicked()
{
    Detenu D1;
    D1.setid(ui->le_id_supp->text());
        bool test = D1.supprimer(D1.getid());
        if(test){
               QMessageBox::information(this, tr("Done"), QString(tr("Suppression réussie")));
               ui->tab_detenu->setModel(D1.afficher());
           }
           else
               QMessageBox::critical(this, tr("Failed"), QString(tr("Echec de suppresssion")));


}

void Dial2::on_pb_modifier_clicked()
{
    QString photo="";

                QString id =ui->id_mod->text();
                QString nomE =ui->nom_mod->text();
                QString prenom =ui->prenom_mod->text();
                int num_cell=ui->num_cell_mod->text().toInt();

                Detenu D1(id, nomE, prenom, num_cell,photo);
                bool modif = D1.modifier(id, nomE,prenom,num_cell);
                //QMessageBox msgBox;
                if(modif){

                    QMessageBox::information(this, tr("Done"), QString(tr("Modification réussie")));
                    ui->tab_detenu->setModel(D1.afficher());

                }
                else
                    QMessageBox::critical(this, tr("Failed"), QString(tr("Modification échoué")));

}

void Dial2::on_pb_ajouter_c_clicked()
{
    int num_cell=ui->le_ncel->text().toInt();
       int num_det=ui->le_ndet->text().toInt();
           Cellule C(num_cell,num_det);

           bool test=C.ajouter();

           if (test) {

               // ACTUALISATION DE L'AFFICHAGE
                 ui->tab_cellule->setModel(C.afficher());

               QMessageBox::information(nullptr,QObject::tr("OK"),
                                        QObject::tr("Ajout effectué\n"
                                                    "Click Cancel to Exit."), QMessageBox::Cancel);
           }
           else
               QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                     QObject::tr("Ajout non effectué.\n"
                                                 "Click Cancel to Exit."), QMessageBox::Cancel);

}

void Dial2::on_pb_rech_cel_clicked()
{
    Cellule C1;
       QString recherche = ui->le_search_c->text();
       ui->tab_cellule->setModel(C1.Trouver_c(recherche));
}

void Dial2::on_pb_export_c_clicked()
{
    QString strStream;
                   QTextStream out(&strStream);
                   QString strTitle = "Planning";

                   const int rowCount = ui->tab_cellule->model()->rowCount();
                   const int columnCount = ui->tab_cellule->model()->columnCount();
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
                       if (!ui->tab_cellule->isColumnHidden(column))
                           out << QString("<th>%1</th>").arg(ui->tab_cellule->model()->headerData(column, Qt::Horizontal).toString());
                   out << "</tr></thead>\n";

                   // data table
                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!ui->tab_cellule->isColumnHidden(column)) {
                               QString data = ui->tab_cellule->model()->data(ui->tab_cellule->model()->index(row, column)).toString().simplified();
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

void Dial2::on_pb_supprimer_c_clicked()
{
    Cellule C1;
       C1.setNcel(ui->le_cell_supp->text().toInt());
           bool test = C1.supprimer(C1.getNcel());
           if(test){
                  QMessageBox::information(this, tr("Done"), QString(tr("Suppression réussie")));
                  ui->tab_cellule->setModel(C1.afficher());
              }
              else
                  QMessageBox::critical(this, tr("Failed"), QString(tr("Echec de suppresssion")));

}

void Dial2::on_modif_cel_clicked()
{


    int num_cell=ui->ncel_mod->text().toInt();
    int num_det=ui->ndet_mod->text().toInt();

    Cellule C1(num_cell, num_det);
    bool modif = C1.modifier(num_cell, num_det);
    //QMessageBox msgBox;
    if(modif){

        QMessageBox::information(this, tr("Done"), QString(tr("Modification réussie")));
        ui->tab_cellule->setModel(C1.afficher());

    }
    else
        QMessageBox::critical(this, tr("Failed"), QString(tr("Modification échoué")));

}

void Dial2::on_pushButton_RetourMenu_clicked()
{
    this->close();
    emit PageAccueil();
}
