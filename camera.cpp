#include "camera.h"
#include "ui_camera.h"

Camera::Camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
    mSpeech = new QTextToSpeech( this );
    mCamera = new QCamera( this );
    mCameraViewFinder = new QCameraViewfinder( this );
    mCameraImageCapture = new QCameraImageCapture( mCamera, this );
    mLayout = new QVBoxLayout;
    mOptionsMenu = new QMenu( "Options", this );
    mStartAction = new QAction( "Start", this );
    mPauseAction = new QAction( "Pause", this );
    mCaptureAction = new QAction( "Capture", this );

    mOptionsMenu->addActions( { mStartAction, mPauseAction,
                                mCaptureAction } );
    ui->optionsPushButton->setMenu( mOptionsMenu );
    mCamera->setViewfinder( mCameraViewFinder );
    mLayout->addWidget( mCameraViewFinder );
    mLayout->setMargin(0);
    ui->scrollArea->setLayout( mLayout );

    connect( mStartAction, &QAction::triggered, [&]() {
        mSpeech->say( "Starting Camera" );
        mCamera->start();
    });
    connect( mPauseAction, &QAction::triggered, [&]() {
        mSpeech->say( "Camera paused for capturing image" );
        mCamera->stop();
    });
    connect( mCaptureAction, &QAction::triggered, [&]() {
        mSpeech->say( "Image Captured" );
        mCameraImageCapture->setCaptureDestination(
                    QCameraImageCapture::CaptureToFile );
    auto fileName = QFileDialog::getSaveFileName
                        ( this, "Capture", "/",
                          "Image ( *.jpg, *.jpeg )");
    if( fileName.isEmpty() )
    {
        return;
    }
    QImageEncoderSettings imgSettings;
    imgSettings.setCodec( "image/jpeg" );
    imgSettings.setResolution( 1600, 1200 );
    mCameraImageCapture->setEncodingSettings( imgSettings );
    mCamera->setCaptureMode( QCamera::CaptureStillImage );
    mCamera->start();
    mCamera->searchAndLock();
    mCameraImageCapture->capture( fileName );
    mCamera->unlock();
    });
}

Camera::~Camera()
{
    delete ui;
}
