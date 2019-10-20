#pragma once
#include <QList>

class CircleAnalogParam
{
public:
    CircleAnalogParam();

    //Setter
    void setRelationLargeAnalog(const double& pScale) { _relationLargeAnalog; }
    void setRadiusLargeCircle(const double& pRadius) { _radiusLargeCircle = pRadius; }
    void setRadiusSmallCircle(const double& pRadius) { _radiusSmallCircle = pRadius; }
    void setMinAngle(const double& pAngle) { _minAngle=pAngle; angleCalculated(); }
    void setMaxAngle(const double& pAngle) { _maxAngle=pAngle; angleCalculated(); }

    //Getter
    const double& getRelationLargeAnalog() const { return _relationLargeAnalog; }
    const double& getRadiusLargeCircle() const { return _radiusLargeCircle; }
    const double& getRadiusSmallCircle() const { return _radiusSmallCircle; }
    const double& getMinAngle() const { return _minAngle; }
    const double& getMaxAngle() const { return _maxAngle; }
    const double& getAngle() const { return _angle; }
    const double& getRelationDistanceOfCircle() const { return _relationDistanceOfCircle; }


private:
    //Calculation
    angleCalculated() { _angle = _maxAngle-_minAngle; }

    //Data
    double _height;
    double _width;
    double _relationLargeAnalog=0.95;
    double _radiusLargeCircle;
    double _radiusSmallCircle;
    double _minAngle = 135;
    double _maxAngle = 405;
    double _angle = _maxAngle-_minAngle;
    double _relationDistanceOfCircle = 0.9;

};
