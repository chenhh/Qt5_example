#include <QtGui>

#include "gotocelldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    /* 在Ui::GoToCellDialog的method */
    setupUi(this);

    /* 限定只能輪入1個英文字母(不分大小寫, 1~9的1個數字, 0~9的最多2個數字 */
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    /* validator只有在regExp滿足條件下，才會得到AcceptableInput為true */
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

    connect(okButton, &QPushButton::clicked, this, &GoToCellDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &GoToCellDialog::reject);
}

// slot function
void GoToCellDialog::on_lineEdit_textChanged()
{
    /* 在lineEdit的輸入值滿足條件時，obButton才可被按下 */
    okButton->setEnabled(lineEdit->hasAcceptableInput());
}
