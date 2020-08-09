#ifndef SOCKS_H
#define SOCKS_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtDebug>
#include <QVector>

class Socks : public QObject
{
    Q_OBJECT

QString portArm;
public:

    QTcpServer *servidor;
    QString ipp;
    QString msg;
    QStringList list;





    bool ativo = 0;
    bool beep = 0;
    explicit Socks(QObject *parent = nullptr);
    void server(QString portArm);
    void stpServer();

public slots:
    void sockets();
signals:

};

#endif // SOCKS_H
