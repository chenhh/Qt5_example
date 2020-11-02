#include "worker.h"
#include <QDebug>
#include <QThread>

Worker::Worker(QObject *parent) : QObject(parent)
{
}

void Worker::on_doSomething()
{
  qDebug() << "I'm working in thread:" << QThread::currentThreadId();
  emit resultReady("Hello");
}
