#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = nullptr);

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    // composite objects
    QLabel *label{nullptr};
    QLineEdit *lineEdit{nullptr};
    QCheckBox *caseCheckBox{nullptr};
    QCheckBox *backwardCheckBox{nullptr};
    QPushButton *findButton{nullptr};
    QPushButton *closeButton{nullptr};
};

#endif
