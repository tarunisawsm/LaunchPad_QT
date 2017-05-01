#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTextToSpeech>
#include <QQmlEngine>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QProcess>
#include <QQmlComponent>
#include "appswindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool checkInternetConnection();

private slots:

    void on_internet_clicked();

    void on_media_clicked();

    void on_settings_clicked();

    void on_nav_clicked();

    void on_computer_clicked();

    void on_apps_clicked();

private:
    Ui::MainWindow *ui;
    QTextToSpeech *m_speech;
    AppsWindow *apps;
};

#endif // MAINWINDOW_H
