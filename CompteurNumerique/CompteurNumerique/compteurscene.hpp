#pragma once

#include <QObject>
#include <QGraphicsScene>


class CompteurItem;
class CompteTours;
class CompteurItemV2;
class ScreenParam;
class AnalogSpeedParam;
class TextParam;

class CompteurScene : public QGraphicsScene
{

public:
    CompteurScene(const QRect& pScreenSize);
    virtual ~CompteurScene();

    void launchInitAnimation();

private:
    CompteurItem * _speedoMeter;
    CompteurItemV2 * _fuelMeter;

    ScreenParam * _screenParam;
    AnalogSpeedParam * _analogSpeedParam;
    TextParam * _textParam;
};
