#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QLabel>
#include <QStatusBar>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>
#include "finddialog.h"
#include "spreadsheet.h"

class MainWindow : public QMainWindow
{
    /* 因為類中定義了自已的signal與slots，因此必須使用Q_OBJECT macro */
    Q_OBJECT

public:
    // ctor
    MainWindow();

protected:
    /* override QWidget中的函式，當user關閉(top-level)
     * window時, 此函數會被調用
     */
    void closeEvent(QCloseEvent *event) override;

private slots:
    void newFile(); //item in the File menu
    void open();    //item in the File menu
    bool save();    //item in the File menu
    bool saveAs();  //item in the File menu
    void find();    //item in the Edit menu
    void goToCell();  //item in the Edit menu
    void sort();    //item in the Tool menu
    void about();   // //item in the Help menu
    void openRecentFile();
    void updateStatusBar();
    void spreadsheetModified();

private:
    /* 用於實作功能的私有函數 */
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool okToContinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    QString strippedName(const QString &fullFileName);

    /* 視窗組件 */
    Spreadsheet *spreadsheet;
    FindDialog *findDialog;
    QLabel *locationLabel;
    QLabel *formulaLabel;
    QStringList recentFiles;
    QString curFile;

    /* 設定最近開啟過的檔案數量 */
    enum { MaxRecentFiles = 5 };
    QAction *recentFileActions[MaxRecentFiles]; // array of pointer
    QAction *separatorAction;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *selectSubMenu;
    QMenu *toolsMenu;
    QMenu *optionsMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;
    QAction *selectRowAction;
    QAction *selectColumnAction;
    QAction *selectAllAction;
    QAction *findAction;
    QAction *goToCellAction;
    QAction *recalculateAction;
    QAction *sortAction;
    QAction *showGridAction;
    QAction *autoRecalcAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
};

#endif
