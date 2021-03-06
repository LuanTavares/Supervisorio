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
#include <QtSerialPort/QSerialPortInfo>


class FormPrincipal :public QMainWindow
{
    Q_OBJECT
    public:
    FormPrincipal(QSerialPortInfo port);
    ~FormPrincipal();

    QSerialPort portaSelecionada;
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
    QTimer * atualizaSensores;
    QTimer * atualizaTela;

signals:
    void atualizaTemperatura(double x, double y);
    void atualizaPotencia(double x, double y);
    void atualizaRotacao(double x, double y);
    void atualizaTensao(double x, double y);

public slots:
    void leDados();
};
