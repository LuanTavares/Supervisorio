#pragma once
#include "temperatura.h"
#include "potencia.h"
#include "tensao.h"
#include "rotacao.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QMainWindow>
#include <QImage>
#include <QDebug>
#include <QtSerialPort/QSerialPort>

class FormPrincipal :public QMainWindow
{
    Q_OBJECT
    public:
    FormPrincipal(QSerialPort *port);
    ~FormPrincipal();


    QImage * image;
    temperatura *formTemperatura;
    potencia *formPotencia;
    tensao *formTensao;
    rotacao *formRotacao;
    double rtTemperatura;
    double rtPotencia;
    double rtTensao;
    double rtRotacao;

    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);

private:
};
