#include "functionsforserver.h"
#include "database.h"

QByteArray parsing(QString data_from_client)
{
    data_from_client = data_from_client.trimmed();

    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();
    if (nameOfFunc == "auth")
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));
    else if (nameOfFunc == "reg")
        return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));
    else if (nameOfFunc == "stat")
        return stat(data_from_client_list.at(0));
    else if (nameOfFunc == "check")
        return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));
    else
        return "Error\n";
}

QByteArray auth(QString log, QString pass)
{
    DataBase& dbInstance = DataBase::getInstance();
    QStringList selectQuery;
    selectQuery << "SELECT * FROM users WHERE login = :login AND password = :password"
                << ":login" << log
                << ":password" << pass;

    QSqlQuery query(dbInstance.getDatabase());
    query.prepare(selectQuery[0]);
    query.bindValue(selectQuery[1], selectQuery[2]);
    query.bindValue(selectQuery[3], selectQuery[4]);

    if (query.exec() && query.first()) {
        return "auth\n";
    } else {
        return "Error: Authentication failed\n";
    }
}

QByteArray reg(QString log, QString pass, QString mail)
{
    DataBase& dbInstance = DataBase::getInstance();
    QStringList insertQuery;
    insertQuery << "INSERT INTO users (login, password, email) VALUES (:login, :password, :email)"
                << ":login" << log
                << ":password" << pass
                << ":email" << mail;

    QSqlQuery query(dbInstance.getDatabase());
    query.prepare(insertQuery[0]);
    query.bindValue(insertQuery[1], insertQuery[2]);
    query.bindValue(insertQuery[3], insertQuery[4]);
    query.bindValue(insertQuery[5], insertQuery[6]);

    if (query.exec()) {
        return "reg\n";
    } else {
        return "Error: Registration failed\n";
    }
}

QByteArray stat(QString log)
{
    return "stat\n";
}

QByteArray check(QString task, QString var, QString ans)
{
    return "check\n";
}
