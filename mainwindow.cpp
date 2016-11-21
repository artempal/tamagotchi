#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createdialog.h"

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
    d.exec();
}
