#include "createdialog.h"
#include "ui_createdialog.h"
#include "mainwindow.h"

CreateDialog::CreateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateDialog)
{
    ui->setupUi(this);
    connect(ui->ok_btn, SIGNAL(clicked()), this, SLOT(onSendData()));
}

CreateDialog::~CreateDialog()
{
    delete ui;
}

void CreateDialog::onSendData()
{
    int gender;
    if(ui->radioButton->isChecked())
    {
        gender = 1;
    }
    else
    {
        gender = 2;
    }
    emit sendData( ui->lineEdit->text(), ui->lineEdit_2->text() ,gender);
    QDialog::close();
}
