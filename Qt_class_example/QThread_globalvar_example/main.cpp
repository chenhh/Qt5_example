#include <QCoreApplication>
#include "workthread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* 建立兩個thread */
    WorkThread thread1;
    WorkThread thread2;

    thread1.start();
    thread2.start();
    return a.exec();
}
