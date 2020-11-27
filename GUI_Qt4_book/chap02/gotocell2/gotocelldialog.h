#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>
#include "ui_gotocelldialog.h"

/* 多重繼承, 均使用公開繼承
 *  Ui::GoToCellDialog並不知道其生成的是Qdialog，
 * 而是到setUI傳入的QDialog的instance才建構出.
 */
class GoToCellDialog : public QDialog, public Ui::GoToCellDialog
{
    Q_OBJECT

public:
    // ctor
    GoToCellDialog(QWidget *parent = nullptr);

private slots:
    void on_lineEdit_textChanged();
};

#endif
