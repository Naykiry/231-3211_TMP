#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QWidget>
//#include "functionsforclient.h"

namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();
   // FunctionsForClient* get_func();

private slots:
    void on_pushButtonAuth_clicked();
    void on_pushButtonChange_clicked();
    void on_pushButtonReg_clicked();

private:
    Ui::AuthRegForm *ui;
//    FunctionsForClient func;
signals:
    void auth(QString log, QString pass);
    void reg(QString log, QString pass, QString email);
};

#endif // AUTHREGFORM_H
