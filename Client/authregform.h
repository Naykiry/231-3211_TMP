/**
 * @file AuthRegForm.h
 * @brief Заголовочный файл для класса AuthRegForm.
 */

#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QWidget>
//#include "functionsforclient.h"

namespace Ui {
/**
 * @class AuthRegForm
 * @brief Класс для работы с формой авторизации и регистрации.
 */
class AuthRegForm;
}

class AuthRegForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса AuthRegForm.
     * @param parent Родительский виджет, по умолчанию nullptr.
     */
    explicit AuthRegForm(QWidget *parent = nullptr);
    /**
     * @brief Деструктор класса AuthRegForm.
     */
    ~AuthRegForm();
   // FunctionsForClient* get_func();

private slots:
    /**
     * @brief Слот для обработки нажатия кнопки авторизации.
     */
    void on_pushButtonAuth_clicked();

    /**
     * @brief Слот для обработки нажатия кнопки изменения данных.
     */
    void on_pushButtonChange_clicked();

    /**
     * @brief Слот для обработки нажатия кнопки регистрации.
     */
    void on_pushButtonReg_clicked();

private:
    Ui::AuthRegForm *ui; ///< Указатель на интерфейсный объект.
//    FunctionsForClient func;
signals:
    /**
     * @brief Сигнал для авторизации пользователя.
     * @param log Логин пользователя.
     * @param pass Пароль пользователя.
     */
    void auth(QString log, QString pass);

    /**
     * @brief Сигнал для регистрации пользователя.
     * @param log Логин пользователя.
     * @param pass Пароль пользователя.
     * @param email Электронная почта пользователя.
     */
    void reg(QString log, QString pass, QString email);
};

#endif // AUTHREGFORM_H
