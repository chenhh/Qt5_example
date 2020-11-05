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
    qDebug()<<"map example";
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
    qDebug()<<"mapped example";
    qDebug() <<list;
    qDebug() << future.results();
}

void map_reduced_example()
{
    QList<int> list {1,2,3,4,5};
    QFuture<int> future = QtConcurrent::mappedReduced(list, function2, reducedFunction);
    future.waitForFinished();
    qDebug()<<"map_reduce example";
    qDebug() << future.result(); //150
}


bool filter_function(const int &num)
{
    return num > 3;
}

void filter_example()
{
    QList<int> list {1,2,3,4,5};
    QFuture<void> future  = QtConcurrent::filter(list, filter_function);
    future.waitForFinished();
    /* (4, 5)
     * 直接修改list的內容, 保留條件為true的元素
     */
    qDebug()<<"filter example";
    qDebug() << list;
}

bool filtered_function(const int &num)
{
    return num > 3;
}


void filtered_example()
{
    QList<int> list {1,2,3,4,5};
    auto future  = QtConcurrent::filtered(list, filtered_function);
    future.waitForFinished();
    /* (1,2,3, 4, 5)
     * (4, 5)
     * 複制list的內容, 保留條件為true的元素
     */
    qDebug()<<"filtered example";
    qDebug() << list;
    qDebug() << future.results();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    map_example();
    mapped_example();
    map_reduced_example();
    filter_example();
    filtered_example();
    return a.exec();
}

