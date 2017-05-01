#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QTextToSpeech>

namespace Ui {
class Camera;
}

class Camera : public QWidget
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = 0);
    ~Camera();

private:
    Ui::Camera *ui;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewFinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOptionsMenu;
    QAction *mStartAction;
    QAction *mPauseAction;
    QAction *mCaptureAction;
    QTextToSpeech *mSpeech;
};

#endif // CAMERA_H
