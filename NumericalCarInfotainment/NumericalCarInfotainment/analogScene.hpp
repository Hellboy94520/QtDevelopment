#pragma once

#include <QObject>
#include <QGraphicsScene>


class CircleAnalogItem;
class SemiHexaAnalogItem;
class ScreenParam;


class AnalogScene : public QGraphicsScene
{

public:
    AnalogScene();
    virtual ~AnalogScene();

    void initSpeedMeter();
    void launchInitAnimation();

private:
    CircleAnalogItem * _speedMeter;
    CircleAnalogItem * _revMeter;
    SemiHexaAnalogItem * _fuelMeter;
};
