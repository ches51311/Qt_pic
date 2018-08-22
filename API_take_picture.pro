#-------------------------------------------------
#
# Project created by QtCreator 2018-08-17T10:54:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = API_take_picture
TEMPLATE = app

INCLUDEPATH += /usr/local/include \
                /usr/include/x86_64-linux-gnu/qt5 \
                /usr/include/x86_64-linux-gnu/qt5/QtCore \
                /usr/include/x86_64-linux-gnu/qt5/QtWidgets \
                /usr/local/include/opencv \
                /usr/local/include/opencv2 \

LIBS += /home/swimdi/swimfile/caffe-ssd/build/lib/libcaffe.so \
        /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so \
        /usr/local/lib/libopencv_imgcodecs.so \
        /usr/local/lib/libopencv_features2d.so \
        /usr/local/lib/libopencv_calib3d.so \
        /usr/local/lib/libopencv_videoio.so \
        /usr/lib/x86_64-linux-gnu/libboost_regex.so \
        /usr/lib/x86_64-linux-gnu/libboost_system.so \
        /usr/lib/x86_64-linux-gnu/libboost_filesystem.so \
        /usr/lib/x86_64-linux-gnu/libglog.so \
        /usr/lib/x86_64-linux-gnu/libgflags.so \
        /usr/lib/x86_64-linux-gnu/libprotobuf.so \
        /usr/lib/x86_64-linux-gnu/libm.so \
        /usr/lib/x86_64-linux-gnu/libhdf5_hl_cpp.so \
        /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so \
        /usr/local/cuda/lib64/libcudart.so \
        /usr/local/cuda/lib64/libcublas.so \
        /usr/local/cuda/lib64/libcurand.so \
        /usr/lib/x86_64-linux-gnu/libcudnn.so

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui
