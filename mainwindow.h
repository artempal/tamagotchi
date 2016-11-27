#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <createdialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    const int start_timer_hp = 20000;
    const int start_timer_hunger = 5000;
    const int update_indicators_timer = 1000;
    const int hunger_lavel = 5;
    const int update_timer_hp = 15000;
    const int update_timer_hunger = 8000;
    QString _user_name; //имя игрока
    QString _pet_name; //имя питомца
    int _gender; //пол
    int _hp = 100; //здоровье
    int _hunger = 100; //голод
    void create_main_wid(); //функция создания окна игры
    void update_indicators(); //функция обновления индикаторов
    QTimer* timer = new QTimer(this); //таймер обновления показателей
    QTimer* btn_timer_hp = new QTimer(this); //таймер активации кнопки здоровья
    QTimer* btn_timer_hunger = new QTimer(this); //таймер активации кнопки голода
    void death(); //смерть питомца
private slots:
    void open_createdialog(); //открытие диалога ввода
    void set_data(QString, QString, int); //установка данных
    void slot_update_indicators(); // слот обновления индикаторов по таймеру
    void slot_add_hp(); //добавление здоровья
    void slot_add_hunger();//добавление еды
    void slot_hp_enable(); //слот, который запускается по таймеру и делает активной кнопку здоровья
    void slot_hunger_enable();//слот, который запускается по таймеру и делает активной кнопку голода
};

#endif // MAINWINDOW_H
