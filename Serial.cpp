#include "Serial.h"
#include <iostream>

Serial::Serial() {
<<<<<<< HEAD
    mostraTela = false;
=======

>>>>>>> 01105cfe5582c578cf763d9555d103b739c31d21
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
<<<<<<< HEAD
        portaSelecionada.close();
        principal = new FormPrincipal(listaDePortasSeriais.at(porta));
        mostraTela = true;
        principal->show();
    }
}

bool Serial::getTela() {
    return mostraTela;
}
=======
        QString dialogStr = listaDePortas.at(porta);
        principal = new FormPrincipal(&portaSelecionada);

        principal->show();
        portaSelecionada.close();
    }
}
>>>>>>> 01105cfe5582c578cf763d9555d103b739c31d21
