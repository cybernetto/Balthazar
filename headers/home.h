#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <QObject>
#include <QObject>
#include "services.h"
#include <QMetaMethod>


QT_BEGIN_NAMESPACE
namespace Ui { class Home; }
QT_END_NAMESPACE

class Home : public QMainWindow
{
    Q_OBJECT


public:
    Home(QWidget *parent = nullptr);
    ~Home();
    QString ports;
    int position;

    Socks *socks1;


    Services *services;



public slots:






private slots:
    void setText();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Home *ui;
};
#endif // HOME_H
