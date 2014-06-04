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

    connect(portasDisponiveis,SIGNAL(currentIndexChanged(int)),this,SLOT(selecionaPorta(int)));

}

Tela::~Tela() {

}

void Tela::selecionaPorta(int a){
    portas->selecionaPorta(a);
}
