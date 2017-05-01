#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_speech(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString engineName = "default";
    m_speech = new QTextToSpeech(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_internet_clicked()
{
    if( true == checkInternetConnection() )
    {
    m_speech->say("Internet Explorer");
    QDesktopServices::openUrl(QUrl("http://www.3logix.com.au/"));
    }
    else
    {
        m_speech->say("Internet connection not available. Please connect and try again");
    }
}

void MainWindow::on_media_clicked()
{
    m_speech->say("Windows Media Player");
    QProcess proc;
    proc.startDetached("\"C:\\Program Files\\Windows Media Player\\wmplayer.exe\"");
}

void MainWindow::on_settings_clicked()
{
    m_speech->say("Control Panel");
    QProcess proc;
    proc.startDetached("control.exe");
}

void MainWindow::on_nav_clicked()
{
    if( true == checkInternetConnection() )
    {
        m_speech->say("Navigation");
        QQmlEngine engine;
        QQmlComponent component(&engine);
        component.setProperty("Title", "Map");
        component.loadUrl(QUrl(QStringLiteral("qrc:/NavForm.qml")));
        component.create();
    }
    else
    {
        m_speech->say("Internet connection not available. Please connect and try again.");
    }
}

void MainWindow::on_computer_clicked()
{
    m_speech->say("My Computer");
    QProcess proc;
    proc.startDetached("explorer.exe");
}

void MainWindow::on_apps_clicked()
{
    m_speech->say("Applications");
    apps = new AppsWindow(this);
    apps->show();
}

bool MainWindow::checkInternetConnection()
{
    bool result = false;
    QNetworkAccessManager nMgr;
    QNetworkRequest req(QUrl("http://www.google.com"));
    QNetworkReply *reply = nMgr.get(req);
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if(reply->bytesAvailable())
        result = true;
    return result;
}
