#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui_reg = new AuthRegForm;
    //ui_reg->show();
    //connect(ui_reg->get_func(), &FunctionsForClient::on_auth_ok, this, &MainWindow::slot_on_auth_ok);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonExit_clicked()
{
    this->close();
}
/*
void MainWindow::slot_on_auth_ok()
{
    delete ui_reg;
    this->show();
}
*/



void MainWindow::on_pushButtonTask1_clicked()
{
    emit Task1(ui->lineEditTask->text());
}


void MainWindow::on_pushButtonTask2_clicked()
{
    emit Task2(ui->lineEditTask->text());
}


void MainWindow::on_pushButtonTask3_clicked()
{
    emit Task3(ui->lineEditTask->text());
}




