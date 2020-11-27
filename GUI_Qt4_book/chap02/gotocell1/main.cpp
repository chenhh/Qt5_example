#include <QApplication>
#include <QDialog>

/* gotocelldialog.ui經qmake後，
   會生成ui_gotocelldialog.h標頭檔
*/
#include "ui_gotocelldialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Ui::GoToCellDialog ui;
    QDialog dialog;
    /* ui 綁定dialog物件 */
    ui.setupUi(&dialog);
    dialog.show();

    return app.exec();
}
