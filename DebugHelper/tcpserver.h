#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtNetwork>
#include <QTcpSocket>
#include "tcpsocket.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0,int port = 0);
    QList<QTcpSocket *> tcpSocketList;
protected:
    void incomingConnection(int socketDescriptor);
signals:
    void updateServer(QString, int);
public slots:
    void updateClients(QString,int);
    void tcpDisconnected(int);
};

#endif // TCPSERVER_H
