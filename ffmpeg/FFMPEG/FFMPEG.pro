QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14 sdk_no_version_check

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ffmpegmanager.cpp \
    hmi/mainwindow.cpp \
    hmi/mainwindow/inputpathwidget.cpp \
    hmi/mainwindow/metadatawidget.cpp \
    hmi/mainwindow/outputpathwidget.cpp \
    hmi/mainwindow/pathpushbutton.cpp \
    hmi/mainwindow/pathpushbutton/filedialog.cpp \
    hmi/mainwindow/streamwidget/streamaudiowidget.cpp \
    hmi/mainwindow/streamwidget/streamsubtitlewidget.cpp \
    hmi/mainwindow/streamwidget/streamvideowidget.cpp \
    hmi/mainwindow/streamwidget/streamwidget.cpp \
    hmi/mainwindow/streamswidget.cpp \
    main.cpp \
    mainmanager.cpp \
    tools/logger.cpp

HEADERS += \
    ffmpegdata.hpp \
    ffmpegmanager.hpp \
    hmi/mainwindow.hpp \
    hmi/mainwindow/inputpathwidget.hpp \
    hmi/mainwindow/metadatawidget.hpp \
    hmi/mainwindow/outputpathwidget.hpp \
    hmi/mainwindow/pathpushbutton.hpp \
    hmi/mainwindow/pathpushbutton/filedialog.hpp \
    hmi/mainwindow/streamwidget/streamaudiowidget.hpp \
    hmi/mainwindow/streamwidget/streamsubtitlewidget.hpp \
    hmi/mainwindow/streamwidget/streamvideowidget.hpp \
    hmi/mainwindow/streamwidget/streamwidget.hpp \
    hmi/mainwindow/streamswidget.hpp \
    mainmanager.hpp \
    tools/logger.hpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
