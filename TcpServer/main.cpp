#include <QCoreApplication>

#include <Tcpserver.hpp>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TcpServer * lServer = new TcpServer();

    return a.exec();
}
