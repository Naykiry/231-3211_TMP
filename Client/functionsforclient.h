#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H

#include <QObject>
#include "mainwindow.h"
#include "authregform.h"
#include "singltoneforclient.h"

/**
 * @brief Класс для реализации функций клиента.
 */
class FunctionsForClient: public QObject
{
    Q_OBJECT
public:

    /**
     * @brief Конструктор класса FunctionsForClient.
     */
    FunctionsForClient();

signals:
    /**
     * @brief Сигнал, указывающий на успешную авторизацию.
     */
    void on_auth_ok();

    /**
     * @brief Сигнал для передачи решения.
     * @param text Текст решения.
     */
    void solution(QString text);

private:
    MainWindow * ui_main; ///< Указатель на главное окно.
    AuthRegForm * ui_auth; ///< Указатель на форму авторизации и регистрации.
    Singltoneforclient* client; ///< Указатель на синглтон клиента.

public slots:
    /**
     * @brief Отправляет данные для авторизации.
     * @param log Логин.
     * @param pass Пароль.
     */
    void sendAuth(QString log, QString pass);

    /**
     * @brief Отправляет данные для регистрации.
     * @param log Логин.
     * @param pass Пароль.
     * @param email Электронная почта.
     */
    void sendReg(QString log, QString pass, QString email);

    /**
     * @brief Обрабатывает входящие сообщения.
     * @param msg Сообщение.
     */
    void msgHandler(QString msg);

    /**
     * @brief Отправляет задачу типа 1.
     * @param text Текст задачи.
     */
    void sendTask1(QString text);

    /**
     * @brief Отправляет задачу типа 2.
     * @param text Текст задачи.
     */
    void sendTask2(QString text);

    /**
     * @brief Отправляет задачу типа 3.
     * @param func Функция.
     * @param x0 Начальное значение.
     * @param x1 Конечное значение.
     * @param epsilon Точность.
     * @param maxIter Максимальное количество итераций.
     */
    void sendTask3(QString func, QString x0, QString x1, QString epsilon, QString maxIter);
};

#endif // FUNCTIONSFORCLIENT_H
