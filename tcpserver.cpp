#include "tcpserver.h"
#include "functionsforserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>


TcpServer::~TcpServer()
{

    mTcpServer->close();
    //server_status=0;
}

TcpServer::TcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &TcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
}

void TcpServer::slotNewConnection(){
    // if(server_status==1){
    mTcpSocket = mTcpServer->nextPendingConnection();
    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
    connect(mTcpSocket, &QTcpSocket::readyRead,this,&TcpServer::slotServerRead);
    connect(mTcpSocket,&QTcpSocket::disconnected,this,&TcpServer::slotClientDisconnected);
    // }
}

void TcpServer::slotServerRead(){
    QString res = "";
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array =mTcpSocket->readAll();
        res.append(array);
    }
    qDebug()<<res;
    mTcpSocket->write(parsing(res));
}


void TcpServer::slotClientDisconnected(){
    mTcpSocket->close();
}
