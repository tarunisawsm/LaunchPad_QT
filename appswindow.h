#ifndef APPSWINDOW_H
#define APPSWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QTextToSpeech>
#include <QDesktopServices>
#include "camera.h"

namespace Ui {
class AppsWindow;
}

class AppsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppsWindow(QWidget *parent = 0);
    ~AppsWindow();

private slots:
    void on_calc_clicked();

    void on_notepad_clicked();

    void on_paint_clicked();

    void on_cam_clicked();

private:
    Ui::AppsWindow *ui;
    QTextToSpeech *m_speech;
};

#endif // APPSWINDOW_H
