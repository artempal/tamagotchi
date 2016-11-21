#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <cmath>
#include <string>
#include <time.h>

using namespace std;

class Pet //имя класса
{
public: // спецификатор доступа
    Pet(string Yname_, string name_, string gender_) //конструктор класса
    {
        setDan(Yname_, name_, gender_); //вызов функции установки имени, имени пола животного
        health = 100; // инициализация здоровье
        hunger = 100; //инициализация голод
    }

    void setDan(string Yname_, string name_, string gender_)//установка имени , имени пола здоровья голода животного
    {
        Yname = Yname_; //инициализация имя игрока
        name = name_; //инициализация имя
        gender = gender_; //инициализация пол
    }
    void setSignDan(int health_, int hunger_)
    {
        health = health_; // инициализация здоровье
        hunger = hunger_; //инициализация голод
    }
    int getSign()
    {
        return health;
    }

    /*void getDan() //отобажение показателей животного
    {
        cout << "Your's name: "  << Yname
            << " \nthe name of your pet: " << name
            << " \nthe gender of your pet: " << gender
            << " \nthe health of your pet: " << health
            << " \nthe hunger of your pet: " << hunger << endl;
    }
*/

private: //спецификатор доступа
    std::string Yname; //имя игрока
    std::string name; //имя животного
    std::string gender; //пол
    int health; //здоровье
    int hunger; //голод
}; //конец объявления класса Pet

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

};

#endif // MAINWINDOW_H
