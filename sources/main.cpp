#include "./headers/home.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Home w;
    w.show();
    w.setFixedSize(w.size());
    return a.exec();
}

