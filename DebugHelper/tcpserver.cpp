#include "tcpserver.h"
#include <QtNetwork/QTcpSocket>

TcpServer::TcpServer(QObject *parent,int port)
    : QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}

void TcpServer::incomingConnection(int socketDescriptor)
{
    TcpSocket * tcpSocket = new TcpSocket(this);
    connect(tcpSocket,SIGNAL(updateClients(QString,int)),
            this,SLOT(updateClients(QString,int)));
    connect(tcpSocket,SIGNAL(disconnected(int)),
            this,SLOT(tcpDisconnected(int)));
    tcpSocket->setSocketDescriptor(socketDescriptor);
    tcpSocketList.append(tcpSocket);
}

void TcpServer::updateClients(QString message, int length)
{
    emit updateServer(message,length);
    for(int i = 0; i < tcpSocketList.count(); i++)
    {
        QTcpSocket *temp = tcpSocketList.at(i);
        if(temp->write(message.toLatin1(),length) != length)
        {
            continue;
        }
    }
}

void TcpServer::tcpDisconnected(int descriptor)
{
    for(int i = 0; i < tcpSocketList.count(); i++)
    {
        QTcpSocket * temp = tcpSocketList.at(i);
        if(temp->socketDescriptor() == descriptor)
        {
            tcpSocketList.removeAt(i);
            return;
        }
    }
}

