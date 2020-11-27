#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window{}; //top widget
    window.setWindowTitle("Enter Your Age");

    QSpinBox* spinBox = new QSpinBox;
    spinBox->setRange(0, 130);
    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 130);

    // new style signal and slot
    /* qOverload<int>是為了overload同名的函式 */
    QObject::connect(spinBox,qOverload<int>(&QSpinBox::valueChanged),
                     slider, &QSlider::setValue);
    /* 當Slider改變時, SpinBox跟著改變 */
    QObject::connect(slider, &QSlider::valueChanged,
                     spinBox, &QSpinBox::setValue);
    /* spinbox的初始值 */
    spinBox->setValue(35);

    QHBoxLayout* layout = new QHBoxLayout;
    /* 如果在建構時，直接指定parnet, 則不必使用window.setLayout */
//    QHBoxLayout* layout = new QHBoxLayout(&window);

    layout->addWidget(spinBox);
    layout->addWidget(slider);
    /* 由window管理layout，再由layout管理spinbox與slider物件 */
    window.setLayout(layout);

    window.show();
    return app.exec();
}
