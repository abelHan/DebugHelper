#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startServer();
    void restartServer();
    void resertClient();
    void saveLog();
private slots:
    void on_StartServer_clicked();

    void on_RestartClient_clicked();

    void on_SaveLog_clicked();

    void on_RestartServer_clicked();

    void on_IPEditBox_textChanged();

    void _initWindow();
    void _initData();
private:
    Ui::MainWindow *ui;

//    void _initUI();

    QTextEdit * m_pIPEdit;
    QString   m_strIP;
};

#endif // MAINWINDOW_H
