#include <QApplication>

#include "sortdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SortDialog dialog;
    dialog.setColumnRange('C', 'H');
    dialog.show();
    return app.exec();
}
