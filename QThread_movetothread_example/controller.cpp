#include "controller.h"
#include <QThread>
#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent)
{
    qDebug() << "Controller's thread is :" << QThread::currentThreadId();

    m_worker = new Worker();
    m_worker->moveToThread(&m_workThread);

    connect(this, &Controller::startRunning, m_worker, &Worker::on_doSomething);
    connect(&m_workThread, &QThread::finished, m_worker, &QObject::deleteLater);
    connect(m_worker, &Worker::resultReady, this, &Controller::on_receivResult);

    m_workThread.start();
}

Controller::~Controller()
{
    m_workThread.quit();
    m_workThread.wait();
}

void Controller::start()
{
    emit startRunning();
}

void Controller::on_receivResult(const QString &str)
{
    qDebug() << str;
}
