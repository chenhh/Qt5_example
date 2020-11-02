#include "controller.h"
#include <QThread>
#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent)
{
    //ctor
    qDebug() << "Controller's thread is :" << QThread::currentThreadId();

    /*  設定thread的stack size為10M */
    m_workThread.setStackSize(10*1024*1024);

    /* 建立worker thread後，移到新的m_workThread執行 */
    m_worker = new Worker();
    m_worker->moveToThread(&m_workThread);

    /* controller發出startRunning訊號給Worker的on_doSomething函數
     * workerThread完成後，發出finished訊號給delterLater
     * worker完成後，發出resultReady給controller的on_receivResult函數
     */
    connect(this, &Controller::startRunning, m_worker, &Worker::on_doSomething);
    connect(&m_workThread, &QThread::finished, m_worker, &QObject::deleteLater);
    connect(m_worker, &Worker::resultReady, this, &Controller::on_receivResult);

    m_workThread.start();
}

Controller::~Controller()
{
    //dtor
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
