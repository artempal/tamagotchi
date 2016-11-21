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
private slots:
    void open_createdialog();
    void set_data(QString, QString, int);
};

#endif // MAINWINDOW_H
