#include "authregform.h"
#include "ui_authregform.h"

AuthRegForm::AuthRegForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthRegForm)
{
    ui->setupUi(this);
    ui->labelEmail->setVisible(false);
    ui->lineEmail->setVisible(false);
    ui->pushButtonReg->setVisible(false);

}

AuthRegForm::~AuthRegForm()
{
    delete ui;
}

void AuthRegForm::on_pushButtonAuth_clicked()
{
    emit is_auth(ui->lineLogin->text(),ui->linePass->text());
}


void AuthRegForm::on_pushButtonChange_clicked()
{
    bool flag = ui->labelEmail->isVisible();


    ui->labelEmail->setVisible(!flag);
    ui->lineEmail->setVisible(!flag);
    ui->pushButtonReg->setVisible(!flag);
    ui->pushButtonAuth->setVisible(flag);
}
/*
FunctionsForClient* AuthRegForm::get_func()
{
    return &(this->func);
}
*/
