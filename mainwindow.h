#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <cmath>
#include <string>
#include <time.h>

using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void set_indicators(QString Yname, QString name, int gender);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int _health = 100; //показатель жизни
    int _hunger = 100; //показатель голода
    QString _Yname; //имя животного
    QString _name; // имя пользователя
    int _gender; //пол пользователя

};

#endif // MAINWINDOW_H
