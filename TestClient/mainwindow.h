#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_connectButton_clicked();
    void on_sendButton_clicked();
    void on_disconnectButton_clicked();

    void tcpConnected();
    void tcpDisconnected();
    void dataReceived();

private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;
    bool status;

    QString userName;
};

#endif // MAINWINDOW_H
