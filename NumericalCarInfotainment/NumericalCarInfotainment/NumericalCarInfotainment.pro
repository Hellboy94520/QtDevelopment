#-------------------------------------------------
#
# Project created by QtCreator 2018-04-13T09:05:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NumericalCarInfotainment
TEMPLATE = app

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
        trace.cpp \
        mainWindow.cpp mainView.cpp analogScene.cpp \
        mainApplication.cpp \
    GraphicsItems/aiguilleItem.cpp \
    GraphicsItems/CircleAnalogItem/circleAnalogItem.cpp GraphicsItems/CircleAnalogItem/circleAnalogParam.cpp \
    GraphicsItems/SemiHexaAnalogItem/semiHexaAnalogItem.cpp GraphicsItems/SemiHexaAnalogItem/semiHexaAnalogParam.cpp \
    Parameters/parametersManagers.cpp \
    GraphicsItems/aiguilleParam.cpp



HEADERS += \
        trace.hpp \
        mainWindow.hpp mainView.hpp analogScene.hpp \
        mainApplication.hpp \
    GraphicsItems/aiguilleItem.hpp \
    GraphicsItems/CircleAnalogItem/circleAnalogItem.hpp GraphicsItems/CircleAnalogItem/circleAnalogParam.hpp \
    GraphicsItems/SemiHexaAnalogItem/semiHexaAnalogItem.hpp GraphicsItems/SemiHexaAnalogItem/semiHexaAnalogParam.hpp \
    Parameters/parametersManagers.hpp Parameters/screenParam.hpp \
    GraphicsItems/aiguilleParam.hpp \
    Parameters/analogParam.hpp


