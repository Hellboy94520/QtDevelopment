#pragma once
#include <QList>

class AnalogSpeedParam
{
public:


private:
    //Data
    double _scaleLargeAnalog=0.95;
    double _minAngle = 135;
    double _maxAngle = 405;
    double _angle = _maxAngle-_minAngle;
    double _numberDistanceOfCircle = 0.9;
};
