#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPlainTextEdit>
#include <QMainWindow>
#include "syntax.h"
#include "keychecker.h"
#include <QEvent>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    KeyChecker* key = new KeyChecker();

    Highlighter *highlighter;

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
