#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cv.h>
#include <highgui.h>
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cam     = NULL;
    timer   = new QTimer(this);
    imag    = new QImage();
    isopen = false;
    connect(timer, SIGNAL(timeout()), this, SLOT(readFarme()));
    ui->btnPredict->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOpen_clicked()
{
    if (!isopen){
        openCamara();
        readFarme();
        ui->btnOpen->setText("close");
        isopen = true;
    }
    else{
        closeCamara();
        ui->btnOpen->setText("open");
        isopen = false;
    }
}


void MainWindow::on_btnPredict_clicked()
{
    takingPictures();
    if(imag->isNull()){
        QMessageBox::warning(this, tr("Warning"), tr("Can not predict picture!\n"),
                                        QMessageBox::Cancel, QMessageBox::Cancel);
        return;
    }
    imag->save(SAVE_PATH, "jpg");
    QProcess process;
    process.start(CLIENT_COMMAND);
    process.waitForFinished();
    qDebug() << process.readAllStandardError();
    QMessageBox::about(NULL,"remind", "The picture predict successfully");

}


void MainWindow::openCamara()
{

    cam = cvCreateCameraCapture(0);
    if(!cam){
        //QMessageBox::warning(this, tr("Warning"), tr("Can not get camera!\n"),
        //                                QMessageBox::Cancel, QMessageBox::Cancel);
        return;
    }
    cvSetCaptureProperty(cam, CV_CAP_PROP_FRAME_WIDTH, cam_width);
    cvSetCaptureProperty(cam, CV_CAP_PROP_FRAME_HEIGHT, cam_height);
    //cvSetCaptureProperty(cam, CV_CAP_PROP_AUTOFOCUS, 0);
    //cvSetCaptureProperty(cam, CV_CAP_PROP_FOCUS, ((float)cam_focus)/1000);
    timer->start(33);
    ui->btnPredict->setEnabled(true);
}


void MainWindow::readFarme()
{
    frame = cvQueryFrame(cam);
    if (!frame){
        return;
    }
    QImage image = QImage((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888).rgbSwapped();
    ui->label->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::takingPictures()
{
    frame = cvQueryFrame(cam);
    if (!frame){
        QMessageBox::warning(this, tr("Warning"), tr("Can not taking picture!\n"),
                                        QMessageBox::Cancel, QMessageBox::Cancel);
        return;
    }

    QImage image = QImage((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888).rgbSwapped();
    *imag = image;
    ui->label_2->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::closeCamara()
{
    timer->stop();
    cvReleaseCapture(&cam);
    ui->label->clear();
    ui->btnPredict->setEnabled(false);
}



