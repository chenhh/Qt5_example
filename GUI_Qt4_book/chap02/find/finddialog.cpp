#include <QtGui>

#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    /*  以下的widget是以composite存在FindDialog中，
     *  因此使用new生成物件後，delete的部份是交給FindDialog管理
     */
    label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit;
    // 當使用者按下label的快速鍵alt + w時，
    // setBuddy會將focus指向lineEdit部件
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    // 改成新的signal slot syntax
    QObject::connect(lineEdit, &QLineEdit::textChanged,
                     this, &FindDialog::enableFindButton);
    QObject::connect(findButton,  &QPushButton::clicked,
            this,  &FindDialog::findClicked);
    QObject::connect(closeButton, &QPushButton::clicked,
            this,  &FindDialog::close);


    // Layout物件雖然沒有宣告在FindDialog class中，
    // 但是使用setLayout動態交給Dialog管理
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

void FindDialog::findClicked()
{
    QString text {lineEdit->text()};
    Qt::CaseSensitivity cs {
            caseCheckBox->isChecked() ? Qt::CaseSensitive
                                      : Qt::CaseInsensitive
    };
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

void FindDialog::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}
