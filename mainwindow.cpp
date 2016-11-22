#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createdialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->main_wid->hide();
    ui->start_wid->show();
    connect(ui->start_btn,SIGNAL(clicked(bool)), this, SLOT(open_createdialog())); //открытие диалога при нажатии на кнопку

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::open_createdialog()
{
    CreateDialog d;
    connect(&d,SIGNAL(sendData(QString,QString,int)),this,SLOT(set_data(QString,QString,int))); //ловим сигнал обновления из диалога ввода и запускаем обработку данных
    d.exec();
}

void MainWindow::set_data(QString user_name, QString pet_name, int gender)
{
    _user_name = user_name;
    _pet_name = pet_name;
    _gender = gender;
    ui->start_wid->hide();
    ui->main_wid->show();
    create_main_wid();
}

void MainWindow::create_main_wid()
{
    ui->name_label->setText(_user_name.prepend("Привет, ").append("!"));
    ui->pet_name_label->setText(_pet_name.prepend("Твой питомец ").append(" ждет тебя!"));
    //QMovie *movie = new QMovie("animations/fire.gif");
    //ui->photo->setMovie(movie);
    //movie->start();
    if(_gender == 1)ui->gender_label->setText("Мужчина"); else ui->gender_label->setText("Женщина");
    update_indicators();
}

void MainWindow::update_indicators()
{
    QString text = "Здоровье: ";
    text.append(QString::number(_hp))
            .append("/100");
    ui->hp_label->setText(text);
    text = "Голод: ";
    text.append(QString::number(_hunger))
            .append("/100");
    ui->hunger_label->setText(text);
}

