/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonTask3;
    QPushButton *pushButtonExit;
    QPushButton *pushButtonTask2;
    QLineEdit *lineEditTask;
    QPushButton *pushButtonTask1;
    QPushButton *pushButtonStat;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(29, 9, 741, 531));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonTask3 = new QPushButton(gridLayoutWidget);
        pushButtonTask3->setObjectName("pushButtonTask3");

        gridLayout->addWidget(pushButtonTask3, 4, 0, 1, 1);

        pushButtonExit = new QPushButton(gridLayoutWidget);
        pushButtonExit->setObjectName("pushButtonExit");

        gridLayout->addWidget(pushButtonExit, 11, 0, 1, 1);

        pushButtonTask2 = new QPushButton(gridLayoutWidget);
        pushButtonTask2->setObjectName("pushButtonTask2");

        gridLayout->addWidget(pushButtonTask2, 2, 0, 1, 1);

        lineEditTask = new QLineEdit(gridLayoutWidget);
        lineEditTask->setObjectName("lineEditTask");

        gridLayout->addWidget(lineEditTask, 9, 0, 1, 1);

        pushButtonTask1 = new QPushButton(gridLayoutWidget);
        pushButtonTask1->setObjectName("pushButtonTask1");

        gridLayout->addWidget(pushButtonTask1, 1, 0, 1, 1);

        pushButtonStat = new QPushButton(gridLayoutWidget);
        pushButtonStat->setObjectName("pushButtonStat");

        gridLayout->addWidget(pushButtonStat, 10, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonTask3->setText(QCoreApplication::translate("MainWindow", "Task3", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        pushButtonTask2->setText(QCoreApplication::translate("MainWindow", "Task2", nullptr));
        pushButtonTask1->setText(QCoreApplication::translate("MainWindow", "Task1", nullptr));
        pushButtonStat->setText(QCoreApplication::translate("MainWindow", "Stat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
