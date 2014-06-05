#include "potencia.h"

potencia::potencia(QWidget *parent) :
    QFrame(parent)
{
    this->setFixedHeight(250);
    this->setFixedWidth(700);
    this->setFrameStyle(QFrame::Box);
    this->setWindowTitle("Leitura Da Potência");

    this->lVLayout = new QVBoxLayout();
    this->lHLayout = new QHBoxLayout();
    this->customPlot = new QCustomPlot();
    this->lbHead = new QLabel();
    this->lbSesorAtual = new QLabel();
    this->lbSesoresDisponiveis = new QLabel();
    this->edSensorAtual = new QLCDNumber();
    this->edSensoresDisponiveis = new QLCDNumber();
    //this->btDesligarSensor = new QPushButton();

    //connect(btDesligarSensor, SIGNAL(clicked()),this,SLOT(atualizaValores()));

    this->edSensorAtual->setDigitCount(1);
    this->edSensorAtual->setFixedWidth(30);
    this->edSensorAtual->setFixedHeight(40);
    this->edSensoresDisponiveis->setDigitCount(1);
    this->edSensoresDisponiveis->setFixedWidth(30);
    this->edSensoresDisponiveis->setFixedHeight(40);
    this->edSensorAtual->setSegmentStyle(QLCDNumber::Flat);
    this->edSensoresDisponiveis->setSegmentStyle(QLCDNumber::Flat);

    this->lbHead->setText("Informações:");
    this->lbSesorAtual->setText("Sensor \nAtual:");
    this->lbSesoresDisponiveis->setText("Sensores \nDisponíveis");
    //this->btDesligarSensor->setText("Atualizar");
    //this->btDesligarSensor->setFixedWidth(50);
    this->customPlot->addGraph();

    this->lVLayout->addWidget(lbHead);
    //this->lVLayout->addWidget(btDesligarSensor);
    this->lVLayout->addWidget(lbSesorAtual);
    this->lVLayout->addWidget(edSensorAtual);
    this->lVLayout->addWidget(lbSesoresDisponiveis);
    this->lVLayout->addWidget(edSensoresDisponiveis);

    this->lHLayout->addLayout(lVLayout);
    this->lHLayout->addWidget(customPlot);

    this->setLayout(lHLayout);

}

void potencia::atualizaGrafico(double x,double y) {
    xAxis << x;
    yAxis << y;
    customPlot->graph(0)->setData(xAxis, yAxis);
    customPlot->yAxis->setLabel("Potência");
    customPlot->yAxis->setRange(0, 2);
    customPlot->replot();
}

void potencia::atualizaValores(){
    this->edSensorAtual->display(1);
    this->edSensoresDisponiveis->display(1);
}
