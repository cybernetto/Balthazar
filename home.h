#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtDebug>
#include <QObject>


QT_BEGIN_NAMESPACE
namespace Ui { class Home; }
QT_END_NAMESPACE

class Home : public QMainWindow
{
    Q_OBJECT
    QTcpServer *servidor;
    QString ip;
    bool ativo = 0;

public:
    Home(QWidget *parent = nullptr);
    ~Home();
    void server();



public slots:


    void sockets();
    void on_pushButton_clicked();

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Home *ui;
};
#endif // HOME_H
