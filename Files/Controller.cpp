#include "Controller.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    highlighter = new Highlighter(ui->plainTextEdit->document());

    ui->plainTextEdit->setTabStopWidth(20);

    ui->plainTextEdit->installEventFilter(key);

}

MainWindow::~MainWindow()
{
    delete ui;
}
