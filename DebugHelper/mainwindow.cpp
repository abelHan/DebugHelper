#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QtNetwork/QHostInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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







//---------------------------


void MainWindow::on_StartServer_clicked()
{
    this->startServer();
}

void MainWindow::on_RestartClient_clicked()
{

}

void MainWindow::on_SaveLog_clicked()
{

}

void MainWindow::on_RestartServer_clicked()
{

}

void MainWindow::on_IPEditBox_textChanged()
{

}
