#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    QLabel *label = new QLabel("Hello Qt!");
//    label->show();
    QLabel label{"<h2><font color='red'>Hello</font> "
                 "<i>Qt!</i></h2>"};
    label.show();
    return app.exec();
}
