#include "./headers/services.h"

Services::Services(QObject *parent) : QObject(parent)
{

}

void Services::parse_cmdline(QString arg1)
{
  sodale = arg1;
  list = sodale.split(" ", QString::SkipEmptyParts);
  nPorts = list.size();
  for(int i = 0; i<nPorts ;i++){
      qDebug() << list[i];
  }
   qDebug() << nPorts;
}


void Services::multiServer()
{

    for(int i = 0; i< nPorts; i++){
        test.append(new Socks);
        //test[i] = new Socks;
        test[i]->server(list[i]);
        }

}

