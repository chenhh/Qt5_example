#include <QApplication>
#include <QDebug>
#include <iostream>
#include "finddialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FindDialog dialog{};
    qDebug() <<"Widget type name:" << dialog.metaObject()->className();
    dialog.show();
    return app.exec();
}
