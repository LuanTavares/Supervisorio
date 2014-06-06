#include "tensao.h"

tensao::tensao(QWidget *parent) :
    QFrame(parent)
{
    this->setFixedHeight(250);
    this->setFixedWidth(700);
    this->setFrameStyle(QFrame::Box);
    this->setWindowTitle("Leitura Da Tensão");

    this->lVLayout              = new QVBoxLayout();
    this->lHLayout              = new QHBoxLayout();
    this->customPlot            = new QCustomPlot();
    this->lbHead                = new QLabel();
    this->lbSesorAtual          = new QLabel();
    this->lbSesoresDisponiveis  = new QLabel();
    this->edSensorAtual         = new QLCDNumber();
    this->edSensoresDisponiveis = new QLCDNumber();
    this->btDesligarSensores           = new QPushButton();

    connect(btDesligarSensores, SIGNAL(clicked()),this,SLOT(atualizaValores()));

    this->edSensorAtual->setDigitCount(1);
    this->edSensorAtual->setFixedWidth(30);
    this->edSensorAtual->setFixedHeight(40);
    this->edSensoresDisponiveis->setFixedHeight(40);
    this->edSensorAtual->setSegmentStyle(QLCDNumber::Flat);
    this->edSensoresDisponiveis->setSegmentStyle(QLCDNumber::Flat);

    this->lbHead->setText("Informações:");
    this->lbSesorAtual->setText("Sensor \nAtual:");
    this->btDesligarSensores->setText("Atualizar");
    this->btDesligarSensores->setFixedWidth(50);
    this->customPlot->addGraph();

    this->lVLayout->addWidget(lbHead);
    this->lVLayout->addWidget(btDesligarSensores);
    this->lVLayout->addWidget(lbSesorAtual);
    this->lVLayout->addWidget(edSensorAtual);

    this->lHLayout->addLayout(lVLayout);
    this->lHLayout->addWidget(customPlot);

    this->setLayout(lHLayout);

}

void tensao::atualizaGrafico(double x,double y) {
    if(x > maiorTensao)
        maiorTensao= x;

    if(yAxis.isEmpty())
        yAxis << y;
    else
        yAxis << (y+(yAxis.last()));
    xAxis << x;



    customPlot->graph(0)->setData(xAxis, yAxis);
    customPlot->yAxis->setLabel("Tensão ");
    customPlot->yAxis->setRange(0, maiorTensao);
    customPlot->xAxis->setRange(0,yAxis.last());
    customPlot->xAxis->setLabel("Tempo (s)");
    customPlot->replot();
}

void tensao::atualizaValores(){
    this->edSensorAtual->display(1);
    this->edSensoresDisponiveis->display(1);
}

tensao::~tensao(){
    yAxis.clear();
    xAxis.clear();
}
