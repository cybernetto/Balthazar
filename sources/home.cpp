#include "./headers/home.h"
#include "ui_home.h"

Home::Home(QWidget *parent): QMainWindow(parent), ui(new Ui::Home)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    ports.append(ui->lineEdit->text());
    services = new Services;

}
Home::~Home()
{
    delete ui;
}
void Home::setText()
{
    QString test = "";
    for(int i = 0; i< services->nPorts; i++){
        test.append(services->test[i]->ipp);
        services->test[i]->ipp = "";

    }
    ui->textEdit->append(test);
}
void Home::on_pushButton_clicked()
{
    services->parse_cmdline(ui->lineEdit->text());


    if(services->nPorts == 0){
        ui->textEdit->append("need one argument");
    }else{
        services->multiServer();
        ui->textEdit->append("serviço iniciado");

      for(int i = 0; i< services->nPorts; i++){

          connect(services->test[i]->servidor,SIGNAL(newConnection()),this,SLOT(setText()));

      }

    }
}
void Home::on_pushButton_2_clicked()
{
    for(int i = 0; i< services->nPorts; i++){
        services->test[i]->stpServer();
        ui->textEdit->append(services->test[i]->msg);
    }

}
void Home::on_checkBox_stateChanged(int arg1)
{
    qDebug() << arg1;
    socks1->beep = arg1;
}

