#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QWidget>
//#include "functionsforclient.h"

namespace Ui {
class AuthRegForm;
}

/**
 * @brief Класс формы авторизации и регистрации.
 *
 * Этот класс представляет собой окно для авторизации и регистрации пользователей.
 * Он наследуется от QWidget и предоставляет функционал для работы с полями ввода,
 * кнопками и сигналами для отправки данных на сервер.
 */
class AuthRegForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса AuthRegForm.
     * @param parent Родительский виджет (по умолчанию nullptr).
     */
    explicit AuthRegForm(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса AuthRegForm.
     */
    ~AuthRegForm();

    // FunctionsForClient* get_func(); // Закомментировано, так как функция не реализована

private slots:
    /**
     * @brief Обработчик нажатия кнопки "Авторизация".
     */
    void on_pushButtonAuth_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Изменить".
     */
    void on_pushButtonChange_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Регистрация".
     */
    void on_pushButtonReg_clicked();

private:
    Ui::AuthRegForm *ui; ///< Указатель на объект интерфейса формы.
    // FunctionsForClient func; // Закомментировано, так как объект не используется

signals:
    /**
     * @brief Сигнал для отправки данных авторизации.
     * @param log Логин пользователя.
     * @param pass Пароль пользователя.
     */
    void auth(QString log, QString pass);

    /**
     * @brief Сигнал для отправки данных регистрации.
     * @param log Логин пользователя.
     * @param pass Пароль пользователя.
     * @param email Email пользователя.
     */
    void reg(QString log, QString pass, QString email);
};

#endif // AUTHREGFORM_H

