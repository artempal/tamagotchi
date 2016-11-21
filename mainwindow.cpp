#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_indicators(QString Yname, QString name, int gender)
{
    _Yname = Yname;
    _name = name;
    _gender = gender;
}

