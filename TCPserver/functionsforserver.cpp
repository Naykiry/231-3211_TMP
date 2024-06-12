#include "functionsforserver.h"
#include "database.h"
#include "aes.h"
#include "sha384.h"
#include "chordmethod.h"

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
    else if (nameOfFunc == "task1")
        return task1(data_from_client_list.at(0));
    else if (nameOfFunc == "task2")
        return task2(data_from_client_list.at(0));
    else if (nameOfFunc == "task3")
        return task3(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2), data_from_client_list.at(3), data_from_client_list.at(4));
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

QByteArray task1(const QString &text)
{
    std::string key = "0123456789abcdef"; // Example key
    AES aes(key);
    std::string encryptedText = aes.encrypt(text.toStdString());
    return QByteArray::fromStdString(encryptedText);
}

QByteArray task2(QString text)
{
    unsigned char digest[SHA384::DIGEST_SIZE];
    memset(digest, 0, SHA384::DIGEST_SIZE);

    SHA384 ctx = SHA384();
    ctx.init();
    ctx.update((unsigned char*)text.toUtf8().constData(), text.length());
    ctx.final(digest);

    char buf[2*SHA384::DIGEST_SIZE+1];
    buf[2*SHA384::DIGEST_SIZE] = 0;
    for (int i = 0; i < SHA384::DIGEST_SIZE; i++)
        sprintf(buf+i*2, "%02x", digest[i]);

    return QByteArray(buf);
}


QByteArray task3(QString func, QString x0, QString x1, QString epsilon, QString maxIter)
{
    double x0_val = x0.toDouble();
    double x1_val = x1.toDouble();
    double epsilon_val = epsilon.toDouble();
    int maxIter_val = maxIter.toInt();

    try {
        ChordMethod chordMethod(func, x0_val, x1_val, epsilon_val, maxIter_val);
        double result = chordMethod.solve();
        return QByteArray::number(result);
    } catch (const std::runtime_error &e) {
        return QByteArray("Error: ") + e.what() + "\n";
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
