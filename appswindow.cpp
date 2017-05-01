#include "appswindow.h"
#include "ui_appswindow.h"

AppsWindow::AppsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AppsWindow)
{
    ui->setupUi(this);
    m_speech = new QTextToSpeech(this);
}

AppsWindow::~AppsWindow()
{
    delete ui;
}

void AppsWindow::on_calc_clicked()
{
    m_speech->say("Calculator");
    QProcess proc;
    proc.startDetached("calc.exe");
}

void AppsWindow::on_notepad_clicked()
{
    m_speech->say("Notepad");
    QProcess proc;
    proc.startDetached("notepad.exe");
}

void AppsWindow::on_paint_clicked()
{
    m_speech->say("Paint");
    QProcess proc;
    proc.startDetached("mspaint.exe");
}

void AppsWindow::on_cam_clicked()
{
    m_speech->say("Camera");
    m_speech->say("Please select start from options to start camera.");
    Camera *newCam = new Camera();
    newCam->show();
}
