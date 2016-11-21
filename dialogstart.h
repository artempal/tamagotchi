#ifndef DIALOGSTART_H
#define DIALOGSTART_H

#include <QDialog>

namespace Ui {
class DialogStart;
}

class DialogStart : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStart(QWidget *parent = 0);
    ~DialogStart();

private:
    Ui::DialogStart *ui;
private slots:
    void on_pushButton_clicked();
};

#endif // DIALOGSTART_H
