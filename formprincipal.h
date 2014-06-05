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
<<<<<<< HEAD
#include <QtSerialPort/QSerialPortInfo>
=======
>>>>>>> 01105cfe5582c578cf763d9555d103b739c31d21

class FormPrincipal :public QMainWindow
{
    Q_OBJECT
    public:
<<<<<<< HEAD
    FormPrincipal(QSerialPortInfo port);
    ~FormPrincipal();

    QSerialPort portaSelecionada;
=======
    FormPrincipal(QSerialPort *port);
    ~FormPrincipal();


>>>>>>> 01105cfe5582c578cf763d9555d103b739c31d21
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
