#include "Tela.h"

Tela::Tela() {
    portasDisponiveis = new QComboBox();
    portas = new Serial();
    QList <QString> dialog = portas->listaPortas();
    for(int i = 0; i < dialog.size(); i++) {
        portasDisponiveis->addItem(dialog.at(i));
    }
    principal = new QHBoxLayout();
    principal->addWidget(portasDisponiveis);
    this->setLayout(principal);

<<<<<<< HEAD
    fechaTela = new QTimer();
    fechaTela->start(100);
    connect(portasDisponiveis,SIGNAL(currentIndexChanged(int)),this,SLOT(selecionaPorta(int)));
    connect(fechaTela,SIGNAL(timeout()),this,SLOT(fecharTela()));
=======
    connect(portasDisponiveis,SIGNAL(currentIndexChanged(int)),this,SLOT(selecionaPorta(int)));

>>>>>>> 01105cfe5582c578cf763d9555d103b739c31d21
}

Tela::~Tela() {

}

void Tela::selecionaPorta(int a){
    portas->selecionaPorta(a);
}
<<<<<<< HEAD

void Tela::fecharTela() {
    if(portas->getTela())
        this->close();
}
=======
>>>>>>> 01105cfe5582c578cf763d9555d103b739c31d21
