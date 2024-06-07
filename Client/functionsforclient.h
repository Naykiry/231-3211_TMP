#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H

#include <QObject>
#include "mainwindow.h"
#include "authregform.h"
#include "singltoneforclient.h"
class FunctionsForClient: public QObject
{
    Q_OBJECT
public:

    FunctionsForClient();

signals:
    void on_auth_ok();

    void solution(QString text);

private:
    MainWindow * ui_main;
    AuthRegForm * ui_auth;
    Singltoneforclient* client;

public slots:
    void sendAuth(QString log, QString pass);
    void sendReg(QString log, QString pass, QString email);
    void msgHandler(QString msg);

    void sendTask1(QString text);
    void sendTask2(QString text);
    void sendTask3(QString func, QString x0, QString x1, QString epsilon, QString maxIter);
};

#endif // FUNCTIONSFORCLIENT_H
