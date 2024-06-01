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
    }

}
