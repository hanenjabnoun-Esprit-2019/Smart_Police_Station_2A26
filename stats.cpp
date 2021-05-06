#include "stats.h"
#include "ui_stats.h"
#include "personnel.h"
#include "menu_gestion_personnel.h"
//#include "qcustomplot.h"

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);
    Stats::StatsPerso();
}

Stats::~Stats()
{
    delete ui;

}

void Stats::StatsPerso(){
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->StatsPerso->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *hommes = new QCPBars(ui->StatsPerso->xAxis, ui->StatsPerso->yAxis);
    QCPBars *femmes = new QCPBars(ui->StatsPerso->xAxis, ui->StatsPerso->yAxis);
    // gives more crisp, pixel aligned bar borders
    hommes->setAntialiased(false);
    femmes->setAntialiased(false);

     hommes->setStackingGap(1);
     femmes->setStackingGap(1);

    // set names and colors:
    hommes->setName("Personnel masculin en mission");
    hommes->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    hommes->setBrush(QColor(111, 9, 176));
    femmes->setName("Personnel féminin en mission");
    femmes->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    femmes->setBrush(QColor(250, 170, 20));

    // stack bars on top of each other:
    femmes->moveAbove(hommes);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12 ;
    labels << "Janvier" << "Février" << "Mars" << "Avril" << "Mai" << "Juin" << "Juillet" << "Août" << "Septembre" << "Octobre" << "Novembre" << "Décembre";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->StatsPerso->xAxis->setTicker(textTicker);
    ui->StatsPerso->xAxis->setTickLabelRotation(60);
    ui->StatsPerso->xAxis->setSubTicks(false);
    ui->StatsPerso->xAxis->setTickLength(0, 4);
    ui->StatsPerso->xAxis->setRange(0, 12.5);
    ui->StatsPerso->xAxis->setBasePen(QPen(Qt::white));
    ui->StatsPerso->xAxis->setTickPen(QPen(Qt::white));
    ui->StatsPerso->xAxis->grid()->setVisible(true);
    ui->StatsPerso->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->StatsPerso->xAxis->setTickLabelColor(Qt::white);
    ui->StatsPerso->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->StatsPerso->yAxis->setRange(0, 15);
    ui->StatsPerso->yAxis->setPadding(5); // a bit more space to the left border
    ui->StatsPerso->yAxis->setLabel("Statistiques du personnel\n en mission");
    ui->StatsPerso->yAxis->setBasePen(QPen(Qt::white));
    ui->StatsPerso->yAxis->setTickPen(QPen(Qt::white));
    ui->StatsPerso->yAxis->setSubTickPen(QPen(Qt::white));
    ui->StatsPerso->yAxis->grid()->setSubGridVisible(true);
    ui->StatsPerso->yAxis->setTickLabelColor(Qt::white);
    ui->StatsPerso->yAxis->setLabelColor(Qt::white);
    ui->StatsPerso->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->StatsPerso->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> hommesData, femmesData;
    hommesData  << compteJanvier() << compteFevrier() << compteMars() << compteAvril() << compteMai() << compteJuin() << compteJuillet() << compteAout() << compteSeptembre() << compteOctobre() << compteNovembre() << compteDecembre();

    hommes->setData(ticks, hommesData);
    femmes->setData(ticks, femmesData);

    // setup legend:
    ui->StatsPerso->legend->setVisible(true);
    ui->StatsPerso->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->StatsPerso->legend->setBrush(QColor(255, 255, 255, 100));
    ui->StatsPerso->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->StatsPerso->legend->setFont(legendFont);
    ui->StatsPerso->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void Stats::on_pushButton_RetourGestionPerso_clicked()
{
    this->hide();
    Menu_Gestion_Personnel MGP;
    MGP.setModal(true);
    MGP.exec();
}
