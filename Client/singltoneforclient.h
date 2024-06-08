#ifndef SINGLTONEFORCLIENT_H
#define SINGLTONEFORCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class Singltoneforclient;

/**
 * @brief Класс SingltoneforclientDestroyer
 * Уничтожитель экземпляра синглтона Singltoneforclient.
 */
class SingltoneforclientDestroyer
{
private:
    Singltoneforclient* p_instance; ///< Указатель на экземпляр синглтона.

public:
    /**
     * @brief Деструктор
     * Удаляет экземпляр синглтона.
     */
    ~SingltoneforclientDestroyer() { delete p_instance; }

    /**
     * @brief Инициализация
     * @param p Указатель на экземпляр синглтона.
     * Инициализирует указатель на экземпляр синглтона.
     */
    void initialize(Singltoneforclient* p) { p_instance = p; }
};

/**
 * @brief Класс Singltoneforclient
 * Синглтон для работы с QTcpSocket.
 */
class Singltoneforclient : public QObject
{
    Q_OBJECT

private:
    static Singltoneforclient* p_instance; ///< Указатель на единственный экземпляр класса.
    static SingltoneforclientDestroyer destroyer; ///< Уничтожитель экземпляра класса.
    QTcpSocket* mTcpSocket; ///< Указатель на сокет для соединения с сервером.

private slots:
    /**
     * @brief Слот для чтения данных с сервера.
     * Срабатывает при поступлении данных от сервера.
     */
    void slotServerRead();

protected:
    /**
     * @brief Конструктор
     * @param parent Родительский объект.
     * Защищенный конструктор для реализации паттерна Singleton.
     */
    explicit Singltoneforclient(QObject* parent = nullptr);

    /**
     * @brief Удаленный конструктор копирования
     * Запрещает копирование экземпляра класса.
     */
    Singltoneforclient(Singltoneforclient&) = delete;

    /**
     * @brief Оператор присваивания
     * Запрещает присваивание экземпляра класса.
     */
    Singltoneforclient& operator=(Singltoneforclient&) = delete;

    /**
     * @brief Класс-друг
     * Предоставляет доступ к приватным членам класса.
     */
    friend class ClientDestroyer;

public:
    /**
     * @brief Получение экземпляра синглтона
     * @return Указатель на единственный экземпляр класса.
     * Возвращает указатель на единственный экземпляр класса.
     */
    static Singltoneforclient* getInstance();

    /**
     * @brief Отправка сообщения на сервер
     * @param msg Сообщение для отправки.
     * Отправляет сообщение на сервер.
     */
    void sendMsgToServer(QString msg);

signals:
    /**
     * @brief Сигнал получения сообщения от сервера
     * @param msg Сообщение от сервера.
     * Сигнализирует о получении сообщения от сервера.
     */
    void msgFromServer(QString msg);
};

#endif // SINGLTONEFORCLIENT_H



#endif // SINGLTONEFORCLIENT_H
