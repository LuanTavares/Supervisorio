#include "Serial.h"
#include <iostream>

Serial::Serial() {

}

Serial::~Serial() {

}

QList<QString> Serial::listaPortas() {
    int i = 0;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QString dialogStr = info.portName();
        listaDePortasSeriais.insert(i,info);
        listaDePortas.insert(i,dialogStr);
        i++;
    }
    return listaDePortas;
}

void Serial::selecionaPorta(int porta) {
    portaSelecionada.setPort(listaDePortasSeriais.at(porta));
    if (portaSelecionada.open(QIODevice::ReadWrite)) {
        QString dialogStr = listaDePortas.at(porta);
        principal = new FormPrincipal(&portaSelecionada);

        principal->show();
        portaSelecionada.close();
    }
}
