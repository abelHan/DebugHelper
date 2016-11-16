#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qdebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    userName("abel")
{
    ui->setupUi(this);
    this->setWindowTitle("测试客户端");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    QString ipAddress= this->ui->ipEdit->text();
    QString strPort =this->ui->portEdit->text();
    qDebug()<<"ip>>" <<ipAddress;
    qDebug()<<"port>>" <<strPort;
    bool ok;
    int iPort = strPort.toInt(&ok);
    if(ok != true)
    {
        qDebug()<< "error port>>" << strPort;
        return;
    }

    if(!status)
    {
        tcpSocket = new QTcpSocket(this);
        connect(tcpSocket,SIGNAL(connected()),
                this,SLOT(tcpConnected()));
        connect(tcpSocket,SIGNAL(disconnected()),
                this,SLOT(tcpDisconnected()));
        connect(tcpSocket,SIGNAL(readyRead()),
                this, SLOT(dataReceived()));
        tcpSocket->connectToHost(ipAddress, iPort);
        status = true;
    }
    else
    {
        int length = 0;
        QString message = userName + tr(":Leave Chat Room");
        length = tcpSocket->write(message.toLatin1(),message.length());
        if(length != message.length())
        {
            return;
        }
        tcpSocket->disconnectFromHost();
        status = false;
    }
}

void MainWindow::on_sendButton_clicked()
{
    if(ui->sendEdit->text().isEmpty())
    {
        return;
    }

    QString message = userName + tr(":") + ui->sendEdit->text();
    tcpSocket->write(message.toLatin1(), message.length());
    ui->sendEdit->clear();
}

void MainWindow::on_disconnectButton_clicked()
{

}

void MainWindow::tcpConnected()
{
    int length = 0;
    QString message = userName + tr(":Enter Chat Room");
    length = tcpSocket->write(message.toLatin1(),message.length());
    if(length != message.length())
    {
        return;
    }
}
void MainWindow::tcpDisconnected()
{

}
void MainWindow::dataReceived()
{
    while(tcpSocket->bytesAvailable() >0)
    {
        QByteArray datagram;
        datagram.resize(tcpSocket->bytesAvailable());

        tcpSocket->read(datagram.data(), datagram.length());
        QString message = datagram.data();
        ui->listWidget->addItem(message);

    }
}
