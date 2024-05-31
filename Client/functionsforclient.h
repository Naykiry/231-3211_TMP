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

private:
    MainWindow * ui_main;
    AuthRegForm * ui_auth;
    Singltoneforclient* client;

public slots:
    void sendAuth(QString log, QString pass);
    void sendReg(QString log, QString pass, QString email);
    void msgHandler(QString msg);

};

#endif // FUNCTIONSFORCLIENT_H
