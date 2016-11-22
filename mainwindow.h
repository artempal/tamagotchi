#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    QString _user_name; //имя игрока
    QString _pet_name; //имя питомца
    int _gender; //пол
    int _hp = 100; //здоровье
    int _hunger = 100; //голод
    void create_main_wid(); //функция создания окна игры
    void update_indicators(); //функция обновления индикаторов
private slots:
    void open_createdialog(); //открытие диалога ввода
    void set_data(QString, QString, int); //установка данных
};

#endif // MAINWINDOW_H
