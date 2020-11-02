#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:
    /* 向外界傳送結果 */
    void resultReady(const QString &str);

public slots:
    /* 耗時操作 */
    void on_doSomething();
};

#endif // WORKER_H
