#pragma once
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QList>
#include "formprincipal.h"
class Serial {

    QT_USE_NAMESPACE

public:
    Serial();
    ~Serial();
    QList <QString> listaPortas();
    void selecionaPorta(int porta);

private:
    QSerialPort portaSelecionada;
    QList <QString> listaDePortas;
    FormPrincipal *principal;
    QList <QSerialPortInfo> listaDePortasSeriais;

signals:
    void fechaTela();

};
