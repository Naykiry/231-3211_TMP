#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H

#include <QString>
#include <QStringList>
#include <QByteArray>

// Функция для парсинга данных от клиента
QByteArray parsing(QString data_from_client);

// Функция для обработки авторизации
QByteArray auth(QString log, QString pass);

// Функция для обработки регистрации
QByteArray reg(QString log, QString pass, QString mail);

QByteArray stat(QString log);

QByteArray check(QString log, QString pass, QString mail);

#endif // FUNCTIONSFORSERVER_H
