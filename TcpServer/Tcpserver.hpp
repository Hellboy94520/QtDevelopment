#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    TcpServer(QObject *parent=0);

private slots:
    void slotNewConnection();
    void slotIncommingMessage();

private:
    QTcpServer * _server;
    QTcpSocket * _socket;
};
