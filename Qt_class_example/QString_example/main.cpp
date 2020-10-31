#include <QCoreApplication>
#include <QString>
#include <QDebug>

/* Usage of QDebug
 * qInfo() << "C++ Style Info Message";
 * qInfo( "C Style Info Message" );
 * qDebug() << "C++ Style Debug Message";
 * qDebug( "C Style Debug Message" );
 *
 * qWarning() << "C++ Style Warning Message";
 * qWarning( "C Style Warning Message" );
 *
 * qCritical() << "C++ Style Critical Error Message";
 * qCritical( "C Style Critical Error Message" );
 *
 * qFatal does not have a C++ style method.
 * qFatal( "C Style Fatal Error Message" );
 */

void QString_example()
{
    QString str1{"hello"};
    QString str2{"world"};
    /* 必須用toLatin1()轉成byteArray才可正確印出 */
    // hello world
    qInfo(str1.toLatin1()  + " " + str2.toLatin1());
    // "hello" "world"
    qInfo() << str1 << str2;

    QString str3;
    str3 = QString("%1 %2").arg("World", "Hello");
    // "World Hello"
    qInfo() << str3;

    str3 = QString("%1 %2").arg("Hi").arg("you");
    // "Hi you"
    qInfo() << str3;

    /* QString QString::arg(int a, int fieldWidth = 0, int base = 10,
     * QChar fillChar = QLatin1Char( ' ' )) const
     */
    // "Decimal 63 = Hex 3f"
    str3 = QString("Decimal 63 = Hex %1")
                .arg(63, 0, 16);
    qInfo() << str3;

    double d = 12.345689;
    /* 輸出為："delta: 12.35"     ---這裡進行了四捨五入 */
    str3 = QString("delta: %1").arg(d, 0, 'g',4);
    qInfo()<<str3;

    /* 輸出為："delta: 12.346"     ---這裡進行了四捨五入 */
    str3 = QString("delta: %1").arg(d, 0, 'G',5);
    qInfo()<<str3;

    /* 輸出為："delta: 1.234e+01" */
    str3 = QString("delta: %1").arg(d, 0, 'e',4);
    qInfo()<<str3;

    /* 輸出為："delta: 1.234E+01" */
    str3 = QString("delta: %1").arg(d, 0, 'E',4);
    qInfo()<<str3;

    /* 輸出為："delta: 12.345689" */
    str3 = QString("delta: %1").arg(d, 0, 'r',4);
    qInfo()<<str3;

    /* 輸出為："delta: 12.345689" */
    str3 = QString("delta: %1").arg(d, 0, 'Q',4);
    qInfo()<<str3;

    str3 = QString("hi");
    str3.append(" there");
    // "hi there"
    qInfo()<<str3;

    // ""
    str3.clear();
    qInfo()<<str3;

    int x = QString::compare("aUtO", "AuTo", Qt::CaseInsensitive);  // x == 0
    int y = QString::compare("auto", "Car", Qt::CaseSensitive);     // y > 0
    int z = QString::compare("auto", "Car", Qt::CaseInsensitive);   // z < 0
    // "x= 0, y= 30, z= -2"
    qInfo()<<QString("x= %1, y= %2, z= %3").arg(x).arg(y).arg(z);

    str3 = "abc";
    /* 'a'
     * 'b'
     * 'c'
     */
    for(const auto& ch: str3){
        qInfo()<<ch;
    }
    for(auto iter=str3.begin(); iter!=str3.end(); ++iter){
        qInfo()<<*iter;
    }
    for(auto iter=str3.cbegin(); iter!=str3.cend(); ++iter){
        qInfo()<<*iter;
    }
    for(auto iter=str3.rbegin(); iter!=str3.rend(); ++iter){
        qInfo()<<*iter;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString_example();
    return a.exec();
}
