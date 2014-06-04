#pragma once
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QLCDNumber>
#include <QTimer>
#include "qcustomplot.h"
class temperatura : public QFrame
{
    Q_OBJECT
public:
    temperatura(QWidget *parent = 0);
    QCustomPlot *customPlot;
    QLabel * lbHead;
    QLabel * lbSesoresDisponiveis;
    QLabel * lbSesorAtual;
    QLCDNumber * edSensoresDisponiveis;
    QLCDNumber * edSensorAtual;
    QPushButton * btDesligarSensores;
    QRadioButton * rbDesligarLeitura;
    QTimer * timerAtualizaSensores;

    QVBoxLayout *lVLayout;
    QHBoxLayout *lHLayout;
    QVector <double> xAxis;
    QVector <double> yAxis;

    
signals:
    
public slots:
    void atualizaGrafico(double x, double y);
    void atualizaValores();
};

