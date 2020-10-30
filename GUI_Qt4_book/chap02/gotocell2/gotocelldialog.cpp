#include <QtGui>

#include "gotocelldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    // 在Ui::GoToCellDialog的method
    setupUi(this);

    /* 限定只能輪入1個英文字母(不分大小寫, 1~9的1個數字, 0~9的最多2個數字 */
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

    connect(okButton, &QPushButton::clicked, this, &GoToCellDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &GoToCellDialog::reject);
}

void GoToCellDialog::on_lineEdit_textChanged()
{
    okButton->setEnabled(lineEdit->hasAcceptableInput());
}
