#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cv.h>
#include <highgui.h>

#include <QWidget>
#include <QImage>
#include <QTimer>

#define SAVE_PATH "/home/swimdi/swimfile/WebAPI/ObjectDetection/client/Temp/test.jpg"
#define CLIENT_COMMAND "python /home/swimdi/swimfile/WebAPI/ObjectDetection/client/web_api_client.py"

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
    void on_btnOpen_clicked();
    void on_btnPredict_clicked();
    void openCamara();
    void readFarme();
    void closeCamara();
    void takingPictures();

private:
    Ui::MainWindow *ui;
    CvCapture *cam;
    QTimer *timer;
    QImage *imag;
    IplImage *frame;
    int cam_width;
    int cam_height;
    int cam_focus;
    bool isopen;

};

#endif // MAINWINDOW_H
