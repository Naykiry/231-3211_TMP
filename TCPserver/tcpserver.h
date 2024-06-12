/**
 * @file TcpServer.h
 * @brief Заголовочный файл класса TcpServer.
 */

#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

/**
 * @class TcpServer
 * @brief Класс для управления TCP сервером.
 * 
 * Класс TcpServer отвечает за создание и управление TCP сервером, 
 * а также за обработку подключений клиентов и передачу данных.
 */
class TcpServer : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Конструктор класса TcpServer.
     * @param parent Указатель на родительский объект, по умолчанию nullptr.
     */
    explicit TcpServer(QObject *parent = nullptr);

    /**
     * @brief Деструктор класса TcpServer.
     */
    ~TcpServer();

private slots:
    /**
     * @brief Слот, вызываемый при новом подключении клиента.
     * 
     * Этот слот обрабатывает новые подключения клиентов к серверу.
     */
    void slotNewConnection();

    /**
     * @brief Слот для чтения данных от клиента.
     * 
     * Этот слот вызывается при получении данных от подключенного клиента.
     */
    void slotServerRead();

    /**
     * @brief Слот, вызываемый при отключении клиента.
     * 
     * Этот слот обрабатывает отключение клиента от сервера.
     */
    void slotClientDisconnected();

private:
    QTcpServer *mTcpServer; /**< Указатель на объект QTcpServer для управления сервером. */
    QList<QTcpSocket*> mTcpSockets; /**< Список сокетов для управления подключенными клиентами. */
};

#endif // TCPSERVER_H

