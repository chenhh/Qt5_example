#include <QCoreApplication>
#include <QtConcurrent>
#include <QDebug>

void function(int &num)
{
    /* 直接修改值，不必回傳 */
    num = num * 10;
}

int function2(const int &num)
{
    /* 要有回傳值 */
    return num * 10;
}

void reducedFunction(int &result, const int &intermedia)
{
    result += intermedia;
}

void map_example()
{
    QList<int> list {1,2,3,4,5};
    QFuture<void> future  = QtConcurrent::map(list, function);
    future.waitForFinished();
    /* (10, 20, 30, 40, 50)
     * 直接修改list的內容
     */
    qDebug() << list;
}

void mapped_example()
{
    QList<int> list {1,2,3,4,5};
    QFuture<int> future  = QtConcurrent::mapped(list, function2);
    future.waitForFinished();
    /* (1, 2, 3, 4, 5)
     * (10, 20, 30, 40, 50)
     * 回傳複製修改後的內容
     */
    future.waitForFinished();
    qDebug() <<list;
    qDebug() << future.results();
}

void map_reduced_example()
{
    QList<int> list {1,2,3,4,5};
    QFuture<int> future = QtConcurrent::mappedReduced(list, function2, reducedFunction);
    future.waitForFinished();
    qDebug() << future.result(); //150
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"map example";
    map_example();
    qDebug()<<"mapped example";
    mapped_example();
    qDebug()<<"map_reduce example";
    map_reduced_example();
    return a.exec();
}

