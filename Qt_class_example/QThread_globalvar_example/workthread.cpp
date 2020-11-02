#include "workthread.h"
#include <QDebug>
#include <QThreadStorage>

WorkThread::WorkThread()
{
}

// global variable
quint64 g_value1 = 0;
void WorkThread::run()
{
    /* 相異thread均把自已的tid存在g_value1中 */
    g_value1 = quint64(currentThreadId());
    qDebug() << g_value1;
}
