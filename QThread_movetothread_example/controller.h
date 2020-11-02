#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include "worker.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    void start();

signals:
    /* 用於觸發新執行緒中的耗時操作函式 */
    void startRunning();

public slots:
    /*  接收新執行緒中的結果 */
    void on_receivResult(const QString &str);

private:
    QThread m_workThread;
    Worker *m_worker;
};

#endif // CONTROLLER_H
