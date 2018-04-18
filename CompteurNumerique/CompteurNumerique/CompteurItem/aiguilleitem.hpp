#pragma once

#include <QObject>
#include <QGraphicsPolygonItem>
#include <QTimer>

class AiguilleItem : public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT
public:
    AiguilleItem(const double& X, const double& Y);

    void launchInitAnimation(const double& pAngleMin, const double& pAngleMax);
    ~AiguilleItem();

private slots:
    void doRotation();

private:
    // Fonction
    void reverseNumber(double &pNombre);

    // Objets
    QTimer * _animationTimer;

    // Variables
    const double _animationTime=1400;
    const unsigned int _animationInterval=19;   // 48 FPS
    double _angleMin;
    double _angleMax;
    double _animationStepsAngle;
    double _currentAngleAnimation;
    unsigned char _currentTypeAnimation=0;
};
