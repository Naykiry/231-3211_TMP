#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

/**
 * @class TcpServer
 * @brief Класс для реализации TCP сервера.
 *
 * Этот класс предоставляет функциональность для создания и управления
 * TCP сервером, который может обрабатывать несколько подключений клиентов.
 */
class TcpServer : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Конструктор класса TcpServer.
     * @param parent Указатель на родительский объект.
     *
     * Инициализирует новый экземпляр класса TcpServer.
     */
    explicit TcpServer(QObject *parent = nullptr);

    /**
     * @brief Деструктор класса TcpServer.
     *
     * Уничтожает объект TcpServer и освобождает используемые ресурсы.
     */
    ~TcpServer();

private slots:
    /**
     * @brief Слот для обработки новых подключений.
     *
     * Этот слот вызывается при новом подключении клиента к серверу.
     */
    void slotNewConnection();

    /**
     * @brief Слот для чтения данных с клиента.
     *
     * Этот слот вызывается, когда сервер получает данные от клиента.
     */
    void slotServerRead();

    /**
     * @brief Слот для обработки отключения клиента.
     *
     * Этот слот вызывается, когда клиент отключается от сервера.
     */
    void slotClientDisconnected();

private:
    QTcpServer *mTcpServer; ///< Указатель на объект QTcpServer.
    QList<QTcpSocket*> mTcpSockets; ///< Список указателей на объекты QTcpSocket для каждого клиента.
};

#endif
