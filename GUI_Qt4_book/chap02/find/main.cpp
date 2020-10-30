#include <QApplication>
#include <QDebug>
#include <iostream>
#include "finddialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // dialog在此可以用stack or heap生成
//    FindDialog* dialog = new FindDialog;
//    dialog->show();
    FindDialog dialog{};
    qDebug() <<"Widget type name:" << dialog.metaObject()->className();
    dialog.show();
    return app.exec();
}
