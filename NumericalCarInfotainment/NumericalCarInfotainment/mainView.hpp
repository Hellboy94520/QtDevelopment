#pragma once

#include <QObject>
#include <QGraphicsView>

class AnalogScene;

class MainView : public QGraphicsView
{
public:
    MainView();
    virtual ~MainView();

private:
    void init();

    AnalogScene * _analogScene;
};
