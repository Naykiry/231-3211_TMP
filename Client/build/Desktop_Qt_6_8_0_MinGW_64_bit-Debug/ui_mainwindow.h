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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QLineEdit *lineEditTask2;
    QPushButton *pushButtonStat;
    QLineEdit *lineEditTask1;
    QPushButton *pushButtonTask2;
    QPushButton *pushButtonTask1;
    QPushButton *pushButtonExit;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineTask31;
    QLineEdit *lineTask32;
    QLineEdit *lineTask33;
    QLineEdit *lineTask34;
    QLineEdit *lineTask35;
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
        gridLayoutWidget->setGeometry(QRect(10, 30, 741, 531));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonTask3 = new QPushButton(gridLayoutWidget);
        pushButtonTask3->setObjectName("pushButtonTask3");

        gridLayout->addWidget(pushButtonTask3, 3, 0, 1, 1);

        lineEditTask2 = new QLineEdit(gridLayoutWidget);
        lineEditTask2->setObjectName("lineEditTask2");

        gridLayout->addWidget(lineEditTask2, 2, 2, 1, 1);

        pushButtonStat = new QPushButton(gridLayoutWidget);
        pushButtonStat->setObjectName("pushButtonStat");

        gridLayout->addWidget(pushButtonStat, 8, 0, 1, 1);

        lineEditTask1 = new QLineEdit(gridLayoutWidget);
        lineEditTask1->setObjectName("lineEditTask1");

        gridLayout->addWidget(lineEditTask1, 1, 2, 1, 1);

        pushButtonTask2 = new QPushButton(gridLayoutWidget);
        pushButtonTask2->setObjectName("pushButtonTask2");

        gridLayout->addWidget(pushButtonTask2, 2, 0, 1, 1);

        pushButtonTask1 = new QPushButton(gridLayoutWidget);
        pushButtonTask1->setObjectName("pushButtonTask1");

        gridLayout->addWidget(pushButtonTask1, 1, 0, 1, 1);

        pushButtonExit = new QPushButton(gridLayoutWidget);
        pushButtonExit->setObjectName("pushButtonExit");

        gridLayout->addWidget(pushButtonExit, 8, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 8, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineTask31 = new QLineEdit(gridLayoutWidget);
        lineTask31->setObjectName("lineTask31");

        horizontalLayout_2->addWidget(lineTask31);

        lineTask32 = new QLineEdit(gridLayoutWidget);
        lineTask32->setObjectName("lineTask32");

        horizontalLayout_2->addWidget(lineTask32);

        lineTask33 = new QLineEdit(gridLayoutWidget);
        lineTask33->setObjectName("lineTask33");

        horizontalLayout_2->addWidget(lineTask33);

        lineTask34 = new QLineEdit(gridLayoutWidget);
        lineTask34->setObjectName("lineTask34");

        horizontalLayout_2->addWidget(lineTask34);

        lineTask35 = new QLineEdit(gridLayoutWidget);
        lineTask35->setObjectName("lineTask35");

        horizontalLayout_2->addWidget(lineTask35);


        gridLayout->addLayout(horizontalLayout_2, 3, 2, 1, 1);

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
        pushButtonStat->setText(QCoreApplication::translate("MainWindow", "Stat", nullptr));
        pushButtonTask2->setText(QCoreApplication::translate("MainWindow", "Task2", nullptr));
        pushButtonTask1->setText(QCoreApplication::translate("MainWindow", "Task1", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
