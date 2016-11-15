#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QtNetwork/QHostInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_iPort(8090)
{
    ui->setupUi(this);
    this->_initData();
    this->_initWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}


//---------------------------
void MainWindow::_initData()
{
    //--------------------------
    this->m_pIPEdit = ui->IPEditBox;

    //--------------------------
    QString localHostName = QHostInfo::localHostName();

    QHostInfo info = QHostInfo::fromName(localHostName);
    foreach (QHostAddress address, info.addresses())
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
        {
            this->m_strIP = address.toString();
        }
    }



}

void MainWindow::_initWindow()
{
    this->setWindowTitle("DebugHelper");
//    this->setWindowIcon(QIcon(":/new/prefix1/icon_48px"));
    this->setMaximumSize(600,400);
    this->setMinimumSize(600,400);

    if(this->m_pIPEdit)
    {
        this->m_pIPEdit->setPlainText(this->m_strIP);
    }
}

//void MainWindow::_initUI()
//{

//}
void MainWindow::startServer()
{
    this->m_pTcpServer = new QTcpServer(this,this->m_iPort);
    QObject::connect(
                m_pTcpServer,
                SIGNAL(_updateServer(QString,int)),
                this,
                SLOT(_updateServer(QString,int))
                );
}
void MainWindow::restartServer()
{

}
void MainWindow::resertClient()
{

}
void MainWindow::saveLog()
{

}

void MainWindow::_updateServer(QString message, int length)
{
    this->ui->listView->addItem(message,left(length));
}






//---------------------------


void MainWindow::on_StartServer_clicked()
{
    this->startServer();
    this->ui->StartServer->setEnabled(false);
}

void MainWindow::on_RestartClient_clicked()
{
    this->resertClient();
}

void MainWindow::on_SaveLog_clicked()
{
    this->saveLog();
}

void MainWindow::on_RestartServer_clicked()
{
    this->restartServer();
}

void MainWindow::on_IPEditBox_textChanged()
{

}
