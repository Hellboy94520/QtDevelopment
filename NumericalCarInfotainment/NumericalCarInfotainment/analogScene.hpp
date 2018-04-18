#pragma once

#include <QObject>
#include <QGraphicsScene>


class CompteurItem;
class CompteTours;
class CompteurItemV2;
class ScreenParam;
class AnalogSpeedParam;
class TextParam;

class AnalogScene : public QGraphicsScene
{

public:
    AnalogScene(const QRect& pScreenSize);
    virtual ~AnalogScene();

    void launchInitAnimation();

private:
    CompteurItem * _speedoMeter;
    CompteurItemV2 * _fuelMeter;

    ScreenParam * _screenParam;
    AnalogSpeedParam * _analogSpeedParam;
    TextParam * _textParam;
};
