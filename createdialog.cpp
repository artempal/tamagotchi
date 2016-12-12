#include "createdialog.h"
#include "ui_createdialog.h"
#include "mainwindow.h"

CreateDialog::CreateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateDialog)
{
    ui->setupUi(this);
    open_photo(1);
    connect(ui->ok_btn, SIGNAL(clicked()), this, SLOT(onSendData())); //при нажатии на кнопку запускаем функцию отправки данных
    connect(ui->radioButton, SIGNAL(clicked()),this, SLOT(clik_on_radio_1())); //при изменении radio - меняем картинку
    connect(ui->radioButton_2, SIGNAL(clicked()),this, SLOT(clik_on_radio_2()));
}

CreateDialog::~CreateDialog()
{
    delete ui;
}

void CreateDialog::onSendData()
{
    int gender; //пол животного
    if(ui->radioButton->isChecked()) //мужчина или женщина?
    {
        gender = 1;
    }
    else
    {
        gender = 2;
    }
    emit sendData( ui->lineEdit->text(), ui->lineEdit_2->text() ,gender); //испускаем сигнал установки данных в главном окне
    QDialog::close();
}

void CreateDialog::open_photo(int gender)
{
    QString name;
    if(gender == 1) name="male"; else if(gender == 2) name = "female";
    QPixmap img(":/img/" + name + ".png");
    ui->label_4->setPixmap(img);
}

void CreateDialog::clik_on_radio_1()
{
    open_photo(1);
}
void CreateDialog::clik_on_radio_2()
{
    open_photo(2);
}
