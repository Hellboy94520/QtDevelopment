#include "aiguilleItem.hpp"
#include <QDebug>


AiguilleItem::AiguilleItem(const double& X, const double& Y)
{
    QVector<QPointF> lAiguille;
    lAiguille << QPointF(0,0) << QPointF(0,Y/2)
            << QPointF(X*0.95,Y/2) << QPointF(X,0)
            << QPointF(X*0.95,-Y/2)<< QPointF(0,-Y/2) << QPointF(0,0);
    QPolygonF lPolygon(lAiguille);
    setPolygon(lPolygon);
}

void AiguilleItem::launchInitAnimation(const double& pAngleMin, const double& pAngleMax)
{
    /* Enregistrement des valeurs d'angles pour l'animation */
    _angleMin = pAngleMin;
    _angleMax = pAngleMax;
    /* Déclaration de l'animation */
    _animationTimer = new QTimer();
    _animationTimer->setInterval(_animationInterval);
    QObject::connect(_animationTimer, SIGNAL(timeout()), this, SLOT(doRotation()));
    /* Calcul de l'angle pour chaque rotation */
    const unsigned int lTotalAngle = (pAngleMax-pAngleMin)*2;
    _animationStepsAngle=lTotalAngle/((_animationTime/1000)*48);
    _animationTimer->start();
}


void AiguilleItem::doRotation()
{
    double lRotation = rotation();
    if(_currentTypeAnimation==0 && lRotation>395) //360+45 = 395
    {
        _currentTypeAnimation=1;
        reverseNumber(_animationStepsAngle);
    }
    else if(_currentTypeAnimation==1 && lRotation==135)
    {
        _currentTypeAnimation=2;
        _animationTimer->stop();
        return;
    }
    setRotation(lRotation+_animationStepsAngle);
}

void AiguilleItem::reverseNumber(double & pNombre)
{
    pNombre = 0-pNombre;
}

AiguilleItem::~AiguilleItem()
{
    if(_animationTimer) delete _animationTimer;
}
