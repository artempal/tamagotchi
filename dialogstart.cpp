#include "dialogstart.h"
#include "ui_dialogstart.h"
#include "dialog.h"
DialogStart::DialogStart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStart)
{
    ui->setupUi(this);
}

DialogStart::~DialogStart()
{
    delete ui;
}
void DialogStart::on_pushButton_clicked()
{
    Dialog dan(this);
    dan.exec();
    QWidget::close();
}
