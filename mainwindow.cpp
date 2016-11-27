#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createdialog.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->main_wid->hide();
    ui->death_wid->hide();
    ui->start_wid->show(); //открываем виджет с кнопкой начала игры


    connect(ui->start_btn,SIGNAL(clicked()), this, SLOT(open_createdialog())); //открытие диалога при нажатии на кнопки
    connect(timer, SIGNAL(timeout()), SLOT(slot_update_indicators())); //обновление индикаторов по таймеру
    connect(btn_timer_hunger, SIGNAL(timeout()), SLOT(slot_hunger_enable())); //по таймеру делаем кнопку Кормить доступной
    connect(btn_timer_hp, SIGNAL(timeout()), SLOT(slot_hp_enable())); //по таймеру делаем кнопку Лечить доступной
    connect(ui->feed_btn,SIGNAL(clicked()),this,SLOT(slot_add_hunger())); //привязываем кнопку пополнения показателя голода к слоту
    connect(ui->heal_btn,SIGNAL(clicked()),this,SLOT(slot_add_hp())); //привязываем кнопку пополнения показателя здоровья к слоту

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::open_createdialog()
{
    CreateDialog d;
    connect(&d,SIGNAL(sendData(QString,QString,int)),this,SLOT(set_data(QString,QString,int))); //ловим сигнал обновления из диалога ввода и запускаем обработку данных
    d.exec(); //открываем диалог
}

void MainWindow::set_data(QString user_name, QString pet_name, int gender)
{
    if(user_name.isEmpty() || pet_name.isEmpty() || !gender) //если каких-то данных не получили
    {
        QMessageBox::information(this,"Ошибка","Введите данные!");
        open_createdialog();
        return;
    }
    _user_name = user_name;
    _pet_name = pet_name;
    _gender = gender;
    create_main_wid(); //наполняем главное окно данными
    ui->start_wid->hide(); //закрываем стартовое окно
    ui->main_wid->show(); //открываем окно игры
}

void MainWindow::create_main_wid()
{
    QString user_name = _user_name;
    QString pet_name = _pet_name;
    ui->name_label->setText(user_name.prepend("Привет, ").append("!"));
    ui->pet_name_label->setText(pet_name.prepend("Твой питомец ").append(" ждет тебя!"));
    //QMovie *movie = new QMovie("animations/fire.gif");
    //ui->photo->setMovie(movie);
    //movie->start();
    if(_gender == 1)ui->gender_label->setText("Мужчина"); else ui->gender_label->setText("Женщина");
    update_indicators();
    ui->heal_btn->setEnabled(false); //делаем кнопки неактивными
    ui->feed_btn->setEnabled(false);
    ui->news_label->setText("У нас дома нет ни крошки, я позвонил в магазин, скоро нам доставят продукты.");
    timer->start(update_indicators_timer); //запускаем таймер обновления индикаторов
    btn_timer_hunger->start(start_timer_hunger);//делаем кнопку покормить активной по таймеру
    btn_timer_hp->start(start_timer_hp);//делаем кнопку лечить активной по таймеру
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

void MainWindow::slot_update_indicators()
{
     if(_hunger>0) //если голод больше нуля, то снижаем его
     {
         int rand = qrand() % hunger_lavel;
         if(_hunger>rand) //если сгенерированное число больше, чем показатель, то обнуляем показатель
         {
             _hunger-=rand;
         }
         else
         {
             _hunger=0;
         }
     }
     if(_hp > 0 && _hunger < 50) //при значении голода больше 50% начинаем снижать здоровье
     {
         int delta = (100-_hunger) / 10 - 4; //меняем здоровье в зависимости от голода
         if(_hp>delta)
         {
             _hp-=delta;
         }
         else
         {
             _hp=0;
         }
     }
     if(_hp == 0) //если здоровье стало равно нулю - игра окончена
     {
         update_indicators();
         timer->stop();
         death();
     }
    update_indicators();
}
void MainWindow::death()
{
    QString text = "";
    text.append(_pet_name);
    text.append(" умер");
    ui->death_text->setText(text);
    ui->main_wid->hide();
    ui->death_wid->show();
}
void MainWindow::slot_add_hp()
{
    if(_hp < 90)
    {
        _hp += 10;
    }
    else
    {
        _hp = 100;
    }
    update_indicators(); //обновляем индикаторы
    btn_timer_hp->start(update_timer_hp); //запускаем таймер
    ui->heal_btn->setEnabled(false); //делаем кнопку неактивной
}
void MainWindow::slot_add_hunger()
{
    if(_hunger < 90) //если голод меньше 90 - кормим
    {
        _hunger+=10;
        if(_hp < 95) _hp+=5; //если здоровье меньше 95 - прибавим чуть-чуть здоровья
    }
    update_indicators(); //обновляем индикаторы
    btn_timer_hunger->start(update_timer_hunger);//запускаем таймер
    ui->feed_btn->setEnabled(false);//делаем кнопку неактивной
}
void MainWindow::slot_hp_enable()
{
     ui->news_label->setText("Здравствуйте, доставка из интернет-аптеки 'Ласточка'. Теперь можно лечить питомца!");
     ui->heal_btn->setEnabled(true);
     btn_timer_hp->stop();
}
void MainWindow::slot_hunger_enable()
{
     ui->news_label->setText("Здравствуйте, мы доставили вам продукты. Теперь можно кормить питомца!");
     ui->feed_btn->setEnabled(true);
     btn_timer_hunger->stop();
}
