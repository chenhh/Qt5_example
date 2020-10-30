#include <QApplication>

#include "sortdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SortDialog dialog{};
    dialog.setColumnRange('C', 'F');
    dialog.show();
    return app.exec();
}
