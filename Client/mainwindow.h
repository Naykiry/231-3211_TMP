#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//#include "authregform.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonExit_clicked();
    //void slot_on_auth_ok();

    void on_pushButtonTask3_clicked();

    void on_pushButtonTask1_clicked();

    void on_pushButtonTask2_clicked();
public slots:
    void solution(QString text);

private:
    Ui::MainWindow *ui;
    //AuthRegForm * ui_reg;
signals:
    void Task1(QString text);
    void Task2(QString text);
    void Task3(QString func, QString x0, QString x1, QString epsilon, QString maxIter);
};
#endif // MAINWINDOW_H
