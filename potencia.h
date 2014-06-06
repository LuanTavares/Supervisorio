#pragma once
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QLCDNumber>
#include <QFrame>
#include <QTimer>
#include "qcustomplot.h"
class potencia : public QFrame
{
    Q_OBJECT
public:
    potencia(QWidget *parent = 0);
    ~potencia();
    QCustomPlot *customPlot;
    QLabel * lbHead;
    QLabel * lbSesoresDisponiveis;
    QLabel * lbSesorAtual;
    QLCDNumber * edSensoresDisponiveis;
    QLCDNumber * edSensorAtual;
    QPushButton * btDesligarSensor;
    QRadioButton * rbDesligarLeitura;
    QTimer * timerAtualizaSensores;

    QVBoxLayout *lVLayout;
    QHBoxLayout *lHLayout;
    QVector <double> xAxis;
    QVector <double> yAxis;
    //FormPrincipal form;
private:
    double maiorPotencia;

signals:

public slots:
    void atualizaGrafico(double x, double y);
    void atualizaValores();
};
