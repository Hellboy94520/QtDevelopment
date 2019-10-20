#include "Tcpserver.hpp"

#include <QDebug>

TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    _server = new QTcpServer(this);

    connect(_server, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

    if(!_server->listen(QHostAddress::Any, 9999))
    {
        qDebug() << "Server could not start";
        return;
    }

    qDebug() << "Server started";

}

void TcpServer::slotNewConnection()
{
    qDebug() << "New object";

    _socket = _server->nextPendingConnection();
    connect(_socket, SIGNAL(readyRead()), this, SLOT(slotIncommingMessage()));

    quint64 lSize = _socket->write("Hello Hellboy - Galaxy S8");

    qDebug() << "Size Of Send : " << lSize;
}

void TcpServer::slotIncommingMessage()
{
    qDebug() << "New Message";

    //A FAIRE : reprendre le code de LIB_MTP
}
