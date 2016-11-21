#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

#include <QDialog>
#include <QString>
#include <mainwindow.h>

namespace Ui {
class CreateDialog;
}

class CreateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDialog(QWidget *parent = 0);
    ~CreateDialog();

private:
    Ui::CreateDialog *ui;
private slots:
    void onSendData();
signals:
void sendData(QString,QString,int);
};

#endif // CREATEDIALOG_H
