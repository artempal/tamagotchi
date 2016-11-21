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
    connect(ui->lineEdit,SIGNAL(clicked()),this,SLOT(send_form()));


}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::send_form()
{

 QString Yname = ui->lineEdit->text();

}
