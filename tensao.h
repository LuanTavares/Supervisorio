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
class tensao : public QFrame
{
    Q_OBJECT
public:
    tensao(QWidget *parent = 0);
    ~tensao();
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
    //FormPrincipal form;

private:
    double maiorTensao;

signals:

public slots:
    void atualizaGrafico(double x, double y);
    void atualizaValores();
};
