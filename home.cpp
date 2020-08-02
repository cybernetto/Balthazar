#include "home.h"
#include "ui_home.h"

int beep;


Home::Home(QWidget *parent): QMainWindow(parent), ui(new Ui::Home)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);


}

Home::~Home()
{
    delete ui;
}

void Home::server()
{
    servidor = new QTcpServer;
    connect(servidor,SIGNAL(newConnection()),this,SLOT(sockets()));
    QString portArm = ui->lineEdit->text();
;
    if(!servidor->listen(QHostAddress::AnyIPv4,portArm.toInt())){
        qDebug() << "falha!!";
        ativo = 0;

    }else{
        qDebug() << "funfou";
        ativo = 1;
    }
}

void Home::sockets()
{
    QTcpSocket *socket = servidor->nextPendingConnection();
    QByteArray escrever("alo alo cliente");
    QString portArm = ui->lineEdit->text();
    QString ipp = ("Tentativa de Conexão: " + socket->peerAddress().toString() + ":"+ portArm);
    if (beep == 2){
        QApplication::beep();
    }
    ui->textEdit->append(ipp);
    //socket->write(escrever);
    //socket->waitForReadyRead();
    //socket->flush();
    //socket->waitForBytesWritten(3000);
    socket->close();
}


void Home::on_pushButton_clicked()
{
    server();
    if(ativo){
       ui->textEdit->append("Serviço Iniciado!\n");
    }else{
        ui->textEdit->append("Serviço já está ativo\n");
    }


}


void Home::on_pushButton_2_clicked()
{
    if(!ativo){
        ui->textEdit->append("Serviço está parado\n");
    }else{
        ui->textEdit->append("Parando Serviço!\n");
        servidor->close();
        ativo = 0;
    }

}

void Home::on_checkBox_stateChanged(int arg1)
{
    qDebug() << arg1;
    beep = arg1;
}
