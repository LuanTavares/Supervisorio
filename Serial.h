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
<<<<<<< HEAD
    bool getTela();
=======

>>>>>>> 01105cfe5582c578cf763d9555d103b739c31d21
private:
    QSerialPort portaSelecionada;
    QList <QString> listaDePortas;
    FormPrincipal *principal;
    QList <QSerialPortInfo> listaDePortasSeriais;
<<<<<<< HEAD
    bool mostraTela;
=======
>>>>>>> 01105cfe5582c578cf763d9555d103b739c31d21

signals:
    void fechaTela();

};
