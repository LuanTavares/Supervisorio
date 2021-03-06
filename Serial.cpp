#include "Serial.h"
#include <iostream>

Serial::Serial() {
    mostraTela = false;
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
        portaSelecionada.close();
        principal = new FormPrincipal(listaDePortasSeriais.at(porta));
        mostraTela = true;
        principal->show();
    } else {
        std::cout << "Não foi possível abrir a porta "<< listaDePortas.at(porta).data() << std::endl;
    }
}

bool Serial::getTela() {
    return mostraTela;
}

