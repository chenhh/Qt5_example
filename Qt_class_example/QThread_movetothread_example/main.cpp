#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "controller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "The main threadID is :" << QThread::currentThreadId();
    Controller controller;
    controller.start();
    return a.exec();
}
