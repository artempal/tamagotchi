#include "dialog.h"
#include "ui_dialog.h"
#include "QString"
#include "QDebug"
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::accept()
{
   QString Yname=ui->lineEdit->text();
   QString name=ui->lineEdit_2->text();
   QString gender_text = ui->lineEdit_3->text();
   int gender = gender_text.toInt();
   QWidget::close();
}
