#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton button{"Quit"};
    // Qt5 signal/slot syntax
    QObject::connect(&button, &QPushButton::clicked,
                     &app, &QApplication::quit);
    button.show();
    return app.exec();
}
