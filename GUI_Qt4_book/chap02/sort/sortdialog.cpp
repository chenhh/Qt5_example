#include <QtGui>

#include "sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)
{
    /* 建構 widget */
    setupUi(this);

    /* 第2,3個GroupBox預先隱藏起來 */
    secondaryGroupBox->hide();
    tertiaryGroupBox->hide();
    /* 限制使用者不可修改widget大小 */
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    /* widgets的signal/slot已經在ui中指定 */

    setColumnRange('A', 'Z');
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    primaryColumnCombo->clear();
    secondaryColumnCombo->clear();
    tertiaryColumnCombo->clear();

    secondaryColumnCombo->addItem(tr("None"));
    tertiaryColumnCombo->addItem(tr("None"));

    /* sizeHint()可傳回布局系統認為最佳的大小 */
    primaryColumnCombo->setMinimumSize(
            secondaryColumnCombo->sizeHint());

    QChar ch = first;
    while (ch <= last) {
        primaryColumnCombo->addItem(QString(ch));
        secondaryColumnCombo->addItem(QString(ch));
        tertiaryColumnCombo->addItem(QString(ch));
        ch = ch.unicode() + 1;
    }
}
