#ifndef SERVICES_H
#define SERVICES_H

#include <QObject>
#include "socks.h"
class Services : public QObject
{
    Q_OBJECT

public:
    explicit Services(QObject *parent = nullptr);
    void multiServer();

    QString ports;
    QString sodale;
    QList <Socks*> test;
    Socks *socks1;
    QStringList list;
    int nPorts;
    QString publica;

    void parse_cmdline(QString arg1);

public slots:

signals:

};

#endif // SERVICES_H
