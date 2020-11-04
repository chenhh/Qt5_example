#include <QCoreApplication>
#include <QDate>
#include <QDebug>
#include <QTime>

void qdate_example()
{
    QDate D1;
    QDate D2(1995,1,26);
    qDebug() << "D2:" <<D2;
    D1=QDate::currentDate();
    qDebug() << "D1:" << D1;//獲取當前日期
    qDebug() << "year:" << D1.year();//獲取年
    qDebug() << "month:" << D1.month();//獲取月
    qDebug() << "day:" << D1.day();//獲取日
    qDebug() << "isValid:" << D1.isValid();//日期是否合法
    qDebug() << "dayOfWeek:" << D1.dayOfWeek();//今天是周幾
    qDebug() << "dayOfYear:" << D1.dayOfYear();//當前是這一年的第多少天
    qDebug() << "daysInMonth:" << D1.daysInMonth();//這個月有多少天
    qDebug() << "daysInYear:" << D1.daysInYear();//這一年有多少天
    qDebug() << "isNull:" << D1.isNull();//日期是否為空，為空返回true
    qDebug() << "daysTo:" << D1.daysTo(D2);//比較兩個日期相差多少天,D2比D1早為負數
    qDebug() << "isLeapYear:" << QDate::isLeapYear(D1.year());//是否閏年
}

void qtime_example()
{
    QTime T1;
    QTime T2(12,9,26);

    qDebug() << "T2:" <<T2;
    T1=QTime::currentTime();
    qDebug() << "T1:" << T1;//獲取當前日期
    qDebug() << "hour:" << T1.hour();//獲取時
    qDebug() << "minute:" << T1.minute();//獲取分
    qDebug() << "second:" << T1.second();//獲取秒
    qDebug() << "msec:" << T1.msec();//獲取毫秒

    qDebug() << "isValid:" << T1.isValid();//時間是否合法
    qDebug() << "secsTo:" << T1.secsTo(T2);//比較兩個時間相差多少秒,T2比T1早為負數
    qDebug() << "msecsTo:" << T1.msecsTo(T2);//比較兩個時間相差多少毫秒,T2比T1早為負數
    qDebug() << "msecsSinceStartOfDay:" << T1.msecsSinceStartOfDay();//返回自當天的毫秒數
    qDebug() << "isNull:" << T1.isNull();//日期是否為空，為空返回true


}

int main()
{
    qdate_example();
    qtime_example();
}
