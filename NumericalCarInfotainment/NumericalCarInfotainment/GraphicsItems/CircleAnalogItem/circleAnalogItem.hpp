#pragma once

#include <QObject>
#include <QGraphicsItemGroup>
#include <QPointF>

#include "GraphicsItems/CircleAnalogItem/circleAnalogParam.hpp"

class CircleAnalogParam;
class AnalogParam;

class AiguilleItem;
class QTimer;

class CircleAnalogItem : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    CircleAnalogItem(AnalogParam * pAnalogParam);
    virtual ~CircleAnalogItem();

    //Getter
    const QPointF& getRightPoint() { calculSize(); return _rightOriginPoint; }

    //Fonction d'animation
    void launchInitAnimation();

private slots:
    void doRotation();

private:
    //Fonction d'initialisation
    void initLargeCircle(const double&);
    void initSmallCircle(const double&);
    void initAiguille();
    void initNumber(const QList<QString>& pNumber, const QString& pText);


    //Fonction Modification de la vitesse
    void changeSpeedValueAngle(const double& pAngle);
    void changeSpeedValue(const unsigned int& pValue);

    //Fonction de conversion et calcul
    void searchAngleBySpeed(const QList<QString>& pNumber);
    double conversionDegreeToRadian(const double &lAngle) const;
    void calculSize();

    //Object du compteur
    QGraphicsEllipseItem * _Circle;
    QGraphicsEllipseItem * _LittleCircle;
    AiguilleItem * _Aiguille;
    QList<QGraphicsTextItem *> _NumberList;
    QGraphicsTextItem * _Unity;
    QGraphicsTextItem * _SpeedNumber;

    //Point pour les autres objets
    QPointF _rightOriginPoint;

    //Object et variable pour l'animation
    QTimer * _animationTimer;
    double _animationTime;
    double _animationStepsAngle;
    const unsigned char _animationInterval=19;
    unsigned char _animationSteps=0;

    //Variables
    double _size;
    const double _littleCircleValue=0.15;
    const double _minAngle=135;
    const double _maxAngle=405;     //360+45
    const double _numberArea=270;   //360-90
    const double _distanceToCircle=0.90;
    const double _scaleText=0.005;
    const double _scaleSpeed=0.01;
    double _angleSpeedStep;


    QColor _bleu = QColor(0,0,255);
    QColor _rouge = QColor(255,0,0);
    QColor _blanc = QColor(255,255,255);
    QColor _noir = QColor(0,0,0);

};

