#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createdialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->hide();
    connect(ui->start_btn,SIGNAL(clicked(bool)), this, SLOT(open_createdialog()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::open_createdialog()
{
    CreateDialog d;
    connect(&d,SIGNAL(sendData(QString,QString,int)),this,SLOT(set_data(QString,QString,int)));
    d.exec();
}

void MainWindow::set_data(QString user_name, QString pet_name, int gender)
{
    _user_name = user_name;
    _pet_name = pet_name;
    _gender = gender;
    ui->start_btn->hide();
    ui->label->show();
}


