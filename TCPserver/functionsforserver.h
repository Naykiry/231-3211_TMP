#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H

#include <QString>
#include <QStringList>
#include <QByteArray>

/**
 * @brief Парсинг данных от клиента
 * 
 * @param data_from_client Данные, полученные от клиента
 * @return QByteArray Результат парсинга
 */
QByteArray parsing(QString data_from_client);

/**
 * @brief Обработка авторизации
 * 
 * @param log Логин пользователя
 * @param pass Пароль пользователя
 * @return QByteArray Результат авторизации
 */
QByteArray auth(QString log, QString pass);

/**
 * @brief Обработка регистрации
 * 
 * @param log Логин пользователя
 * @param pass Пароль пользователя
 * @param mail Электронная почта пользователя
 * @return QByteArray Результат регистрации
 */
QByteArray reg(QString log, QString pass, QString mail);

/**
 * @brief Выполнение задачи 1
 * 
 * @param text Входные данные для задачи
 * @return QByteArray Результат выполнения задачи
 */
QByteArray task1(const QString &text);

/**
 * @brief Выполнение задачи 2
 * 
 * @param text Входные данные для задачи
 * @return QByteArray Результат выполнения задачи
 */
QByteArray task2(QString text);

/**
 * @brief Выполнение задачи 3
 * 
 * @param func Функция для выполнения
 * @param x0 Начальное значение
 * @param x1 Конечное значение
 * @param elipson Точность
 * @param maxIter Максимальное количество итераций
 * @return QByteArray Результат выполнения задачи
 */
QByteArray task3(QString func, QString x0, QString x1, QString elipson, QString maxIter);

/**
 * @brief Получение статистики пользователя
 * 
 * @param log Логин пользователя
 * @return QByteArray Статистика пользователя
 */
QByteArray stat(QString log);

/**
 * @brief Проверка данных пользователя
 * 
 * @param log Логин пользователя
 * @param pass Пароль пользователя
 * @param mail Электронная почта пользователя
 * @return QByteArray Результат проверки
 */
QByteArray check(QString log, QString pass, QString mail);

#endif // FUNCTIONSFORSERVER_H
