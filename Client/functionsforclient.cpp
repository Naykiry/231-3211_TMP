#include "functionsforclient.h"

FunctionsForClient::FunctionsForClient()
{
    client = Singltoneforclient::getInstance();

    ui_auth = new AuthRegForm;
    ui_auth->show();
    connect(ui_auth, &AuthRegForm::auth, this, &FunctionsForClient::sendAuth);
    connect(ui_auth, &AuthRegForm::reg, this, &FunctionsForClient::sendReg);
    connect(client, &Singltoneforclient::msgFromServer, this, &FunctionsForClient::msgHandler);

}

void FunctionsForClient::sendAuth(QString log, QString pass)
{
    client->sendMsgToServer("auth&" + log + "&" + pass);
}

void FunctionsForClient::sendReg(QString log, QString pass, QString email)
{
    client->sendMsgToServer("reg&" + log + "&" + pass + "&" + email);
}

void FunctionsForClient::msgHandler(QString msg)
{
    if (msg == "auth\n" || msg == "reg\n")
    {
        delete ui_auth;
        ui_main = new MainWindow;
        ui_main->show();
        connect(ui_main, &MainWindow::Task1, this, &FunctionsForClient::sendTask1);
        connect(ui_main, &MainWindow::Task2, this, &FunctionsForClient::sendTask2);
        connect(ui_main, &MainWindow::Task3, this, &FunctionsForClient::sendTask3);

        connect(this, &FunctionsForClient::solution, ui_main, &MainWindow::solution);
    }
    else
    {
        emit solution(msg);
    }

}

void FunctionsForClient::sendTask1(QString text)
{
    client->sendMsgToServer("task1&" + text);
}

void FunctionsForClient::sendTask2(QString text)
{
    client->sendMsgToServer("task2&" + text);
}

void FunctionsForClient::sendTask3(QString func, QString x0, QString x1, QString epsilon, QString maxIter)
{
    client->sendMsgToServer("task3&" + func + "&" + x0 + "&" + x1 + "&" + epsilon + "&" + maxIter);
}
