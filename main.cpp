#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include "dialogstart.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogStart w;
    w.show();
    return a.exec ( ) ; //Запускаем программу на выполнение exec() выполняет
    //цикл обработки событий. Программа ожидает действия пользователя и выполняет их обработку.
}
