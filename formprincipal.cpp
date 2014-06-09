#include "formprincipal.h"
#include <QPainter>
#include <iostream>

FormPrincipal::FormPrincipal(QSerialPortInfo port)

{
    QString filename = ":/new/img/usina-eolica-turbina-eolica-energia-eolica_yubqha.jpg";

    this->image = new QImage(filename);
    this->formTemperatura = new temperatura();
    this->formPotencia = new potencia();
    this->formRotacao = new rotacao();
    this->formTensao = new tensao();

    this->setFixedHeight(image->height());
    this->setFixedWidth(image->width());

    this->rtPotencia    = 0;
    this->rtRotacao     = 0;
    this->rtTemperatura = 0;
    this->rtTensao      = 0;

    this->atualizaSensores = new QTimer();
    atualizaSensores->start(800);
    this->atualizaTela = new QTimer();

    portaSelecionada.setPort(port);

    connect(this,SIGNAL(atualizaTemperatura(double,double)),formTemperatura,SLOT(atualizaGrafico(double,double)));
    connect(this,SIGNAL(atualizaTensao(double,double)),formTensao,SLOT(atualizaGrafico(double,double)));
    connect(this,SIGNAL(atualizaRotacao(double,double)),formRotacao,SLOT(atualizaGrafico(double,double)));
    connect(this,SIGNAL(atualizaPotencia(double,double)),formPotencia,SLOT(atualizaGrafico(double,double)));
    connect(atualizaSensores,SIGNAL(timeout()),this,SLOT(leDados()));
    update();
}

FormPrincipal ::~FormPrincipal(){

}

void FormPrincipal::paintEvent(QPaintEvent *e){
    QPainter painter(this);

    painter.drawImage(QPoint(0,0), *image);
    painter.setPen(Qt::green); //Rotação
    painter.drawRect(425,265,10,20);
    painter.setPen(Qt::yellow); //Potencia
    painter.drawRect(265,275,10,20);
    painter.setPen(Qt::red); //Temperatura
    painter.drawRect(345,270,10,20);
    painter.setPen(Qt::white); //Tensão
    painter.drawRect(320,330,10,20);

    //VALORES EM TEMPO REAL
    painter.setPen(Qt::lightGray);
    painter.drawRect(10,15,200,100);

    QString s = "Valores Em Tempo Real";
    QString x;
    painter.drawText(15,10,s);
    painter.setPen(Qt::green); //Rotação
    x.setNum(rtRotacao);
    s = "Rotação da turbina: ";
    s.append(x);
    painter.drawText(15,30,s);

    painter.setPen(Qt::yellow); //Tensão
    x.setNum(rtTensao);
    s = "Tensão do Motor: ";
    s.append(x);
    painter.drawText(15,50,s);

    painter.setPen(Qt::red); //Temperatura
    x.setNum(rtTemperatura);
    s = "Temperatura da turbina: ";
    s.append(x);
    painter.drawText(15,70,s);

    painter.setPen(Qt::white); //Potencia
    x.setNum(rtPotencia);
    s = "Potência do Motor: ";
    s.append(x);
    painter.drawText(15,90,s);


    //LEGENDA
    s = "Legenda";
    painter.setPen(Qt::lightGray);
    painter.drawText(10,400,s);

    painter.setPen(Qt::green); //Rotação
    painter.drawRect(10,405,10,20);
    s = "Rotação Do Motor";
    painter.drawText(25,417,s);

    painter.setPen(Qt::white); //Tensão
    painter.drawRect(10,427,10,20);
    s = "Potência Do Motor";
    painter.drawText(25,439,s);

    painter.setPen(Qt::red); //Temperatura
    painter.drawRect(10,450,10,20);
    s = "Temperatura Da Turbina";
    painter.drawText(25,462,s);

    painter.setPen(Qt::yellow); //Potencia
    painter.drawRect(10,473,10,20);
    s = "Tensão Do Circuito";
    painter.drawText(25,485,s);
}

bool ehTemperatura(int x, int y){
    if ((x >= 345 && x <=375)
        && (y >= 270&& y <= 280)) {
        return true;
    } else {
        return false;
    }
}

bool ehTensao(int x, int y){
    if ((x >= 265 && x <=285)
        && (y >= 275&& y <= 295)) {
        return true;
    } else {
        return false;
    }
}

bool ehPotencia(int x, int y){
    if ((x >= 320 && x <=340)
        && (y >= 330&& y <= 350)) {
        return true;
    } else {
        return false;
    }
}

bool ehRotacao(int x, int y){
    if ((x >= 425 && x <=445)
        && (y >= 265&& y <= 285)) {
        return true;
    } else {
        return false;
    }
}


void FormPrincipal::mousePressEvent(QMouseEvent *e){
    QMainWindow::mousePressEvent(e);

    int x = e->localPos().x();
    int y = e->localPos().y();

    if(ehTemperatura(x,y)){    
        formTemperatura->show();
    }else if(ehPotencia(x,y)){
        formPotencia->show();
    }else if(ehRotacao(x,y)){
        formRotacao->show();
    }else if(ehTensao(x,y)){
        formTensao->show();
    }
}

void FormPrincipal::leDados(){
    if(portaSelecionada.open(QIODevice::ReadWrite)) {
        QByteArray dados = portaSelecionada.read(10);
        QString str(dados.data());

        if(str == "String da Temperatura") {
            rtTemperatura++;
            emit atualizaTemperatura(rtTemperatura,1.0);
        }
        if(str == "String da Tensão") {
            rtTensao++;
            emit atualizaTensao(rtTensao,1.0);
        }
        if(str == "String da Potencia") {
            rtPotencia++;
            emit atualizaPotencia(rtPotencia,1.0);
        }
        if(str == "String da Rotação") {
            rtRotacao++;
            emit atualizaRotacao(rtRotacao,1.0);
        }
        update();
        portaSelecionada.close();
    }
}


