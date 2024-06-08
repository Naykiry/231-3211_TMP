#ifndef SINGLTONEFORCLIENT_H
#define SINGLTONEFORCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class Singltoneforclient;

/**
 * @class SingltoneforclientDestroyer
 * @brief Класс для уничтожения единственного экземпляра Singltoneforclient.
 */
class SingltoneforclientDestroyer
{
private:
    Singltoneforclient* p_instance; ///< Указатель на единственный экземпляр Singltoneforclient.

public:
    /**
     * @brief Деструктор. Удаляет единственный экземпляр Singltoneforclient.
     */
    ~SingltoneforclientDestroyer() { delete p_instance; }

    /**
     * @brief Инициализирует указатель на единственный экземпляр Singltoneforclient.
     * @param p Указатель на экземпляр Singltoneforclient.
     */
    void initialize(Singltoneforclient* p) { p_instance = p; }

};

/**
 * @class Singltoneforclient
 * @brief Класс-синглтон для работы с TCP-сокетом.
 * @details Позволяет отправлять сообщения на сервер и получать ответы.
 */
class Singltoneforclient : public QObject
{
    Q_OBJECT

private:
    static Singltoneforclient* p_instance; ///< Указатель на единственный экземпляр класса.
    static SingltoneforclientDestroyer destroyer; ///< Уничтожитель экземпляра класса.
    QTcpSocket* mTcpSocket; ///< Указатель на объект TCP-сокета.

private slots:
    /**
     * @brief Слот для чтения данных от сервера.
     */
    void slotServerRead();

protected:
    /**
     * @brief Защищенный конструктор.
     * @param parent Родительский объект.
     */
    explicit Singltoneforclient(QObject* parent = nullptr);

    /// Запрещаем копирование.
    Singltoneforclient(Singltoneforclient&) = delete;

    /// Запрещаем присваивание.
    Singltoneforclient& operator=(Singltoneforclient&) = delete;

    friend class SingltoneforclientDestroyer;


public:
    /**
     * @brief Получает единственный экземпляр класса.
     * @return Указатель на экземпляр класса Singltoneforclient.
     */
    static Singltoneforclient* getInstance();

    /**
     * @brief Отправляет сообщение на сервер.
     * @param msg Сообщение для отправки.
     */
    void sendMsgToServer(QString msg);

signals:
    /**
     * @brief Сигнал, который испускается при получении сообщения от сервера.
     * @param msg Сообщение от сервера.
     */
    void msgFromServer(QString msg);
};

#endif // SINGLTONEFORCLIENT_H
