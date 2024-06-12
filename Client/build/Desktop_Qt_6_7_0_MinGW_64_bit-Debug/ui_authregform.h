/********************************************************************************
** Form generated from reading UI file 'authregform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHREGFORM_H
#define UI_AUTHREGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthRegForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineLogin;
    QLabel *labelLogin;
    QLineEdit *lineEmail;
    QLabel *labelEmail;
    QLineEdit *linePass;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAuth;
    QPushButton *pushButtonReg;
    QPushButton *pushButtonChange;

    void setupUi(QWidget *AuthRegForm)
    {
        if (AuthRegForm->objectName().isEmpty())
            AuthRegForm->setObjectName("AuthRegForm");
        AuthRegForm->resize(591, 455);
        verticalLayoutWidget = new QWidget(AuthRegForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 30, 501, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lineLogin = new QLineEdit(verticalLayoutWidget);
        lineLogin->setObjectName("lineLogin");

        gridLayout->addWidget(lineLogin, 0, 1, 1, 1);

        labelLogin = new QLabel(verticalLayoutWidget);
        labelLogin->setObjectName("labelLogin");

        gridLayout->addWidget(labelLogin, 0, 0, 1, 1);

        lineEmail = new QLineEdit(verticalLayoutWidget);
        lineEmail->setObjectName("lineEmail");

        gridLayout->addWidget(lineEmail, 1, 1, 1, 1);

        labelEmail = new QLabel(verticalLayoutWidget);
        labelEmail->setObjectName("labelEmail");

        gridLayout->addWidget(labelEmail, 1, 0, 1, 1);

        linePass = new QLineEdit(verticalLayoutWidget);
        linePass->setObjectName("linePass");

        gridLayout->addWidget(linePass, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonAuth = new QPushButton(verticalLayoutWidget);
        pushButtonAuth->setObjectName("pushButtonAuth");

        horizontalLayout->addWidget(pushButtonAuth);

        pushButtonReg = new QPushButton(verticalLayoutWidget);
        pushButtonReg->setObjectName("pushButtonReg");

        horizontalLayout->addWidget(pushButtonReg);

        pushButtonChange = new QPushButton(verticalLayoutWidget);
        pushButtonChange->setObjectName("pushButtonChange");

        horizontalLayout->addWidget(pushButtonChange);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AuthRegForm);

        QMetaObject::connectSlotsByName(AuthRegForm);
    } // setupUi

    void retranslateUi(QWidget *AuthRegForm)
    {
        AuthRegForm->setWindowTitle(QCoreApplication::translate("AuthRegForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("AuthRegForm", "Password", nullptr));
        labelLogin->setText(QCoreApplication::translate("AuthRegForm", "Login", nullptr));
        labelEmail->setText(QCoreApplication::translate("AuthRegForm", "Email", nullptr));
        pushButtonAuth->setText(QCoreApplication::translate("AuthRegForm", "Auth", nullptr));
        pushButtonReg->setText(QCoreApplication::translate("AuthRegForm", "Reg", nullptr));
        pushButtonChange->setText(QCoreApplication::translate("AuthRegForm", "Change", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthRegForm: public Ui_AuthRegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHREGFORM_H
