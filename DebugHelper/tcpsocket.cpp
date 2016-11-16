#include "tcpsocket.h"

TcpSocket::TcpSocket(QObject *parent)
    : QTcpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),
            this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),
            this,SLOT(datadisconnected()));

}


//void TcpSocket::updateClients(QString,int)
//{

//}
//void TcpSocket::disconnected(int)
//{

//}

void TcpSocket::dataReceived()
{
    while(this->bytesAvailable() > 0)
    {
        char buf[1024];
        int length = bytesAvailable();
        this->read(buf,length);
        QString message = buf;
        emit updateClients(message,length);
    }
}

void TcpSocket::datadisconnected()
{
    emit disconnected(this->socketDescriptor());
}
