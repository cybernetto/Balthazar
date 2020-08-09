#include "socks.h"
#include <iostream>

Socks::Socks(QObject *parent) : QObject(parent)
{

}

void Socks::server(QString portArm)
{

    this->portArm = portArm;
    servidor = new QTcpServer;
    connect(servidor,SIGNAL(newConnection()),this,SLOT(sockets()));
    if(!servidor->listen(QHostAddress::AnyIPv4,portArm.toInt())){
        qDebug() << "falha!!";
        this->ativo = 0;
    }else{
        qDebug() << "funfou";
        this->ativo = 1;
    }
    if(ativo){
       msg = ("Serviço Iniciado!\n");
    }else{
        msg = ("Serviço já está ativo\n");
    }
}
void Socks::sockets()
{
    QTcpSocket *socket = servidor->nextPendingConnection();
    ipp = ("Tentativa de Conexão: " + socket->peerAddress().toString() + ":"+ portArm);
    qDebug() << ipp;
    //if (beep == 2){
       // QApplication::beep();
    //}
    socket->close();
}
void Socks::stpServer(){

    if(!ativo){
        msg = "Serviço está parado\n";
    }else{
        msg = "Parando Serviço!\n";
        servidor->close();
        ativo = 0;
    }

}

