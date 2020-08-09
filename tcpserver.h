#ifndef TCPSERVER_H
#define TCPSERVER_H


#include <QTcpServer>
#include <QTcpSocket>
#include <QtDebug>
#include <QObject>

class tcpServer : public QObject
{
    Q_OBJECT

    QTcpServer *servidor;
    QString ip;
public:
    explicit tcpServer(QObject *parent = nullptr);
    bool server();





signals:

public slots:
    void sockets();


};

#endif // TCPSERVER_H
