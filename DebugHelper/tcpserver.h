#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QTcpServer>
#include <QtNetwork>


class tcpserver:public QTcpServer
{
    Q_OBJECT
public:
    tcpserver();
};

#endif // TCPSERVER_H
