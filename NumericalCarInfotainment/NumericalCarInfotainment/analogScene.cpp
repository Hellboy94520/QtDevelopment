#include "analogScene.hpp"
#include "Parameters/parametersManagers.hpp"
#include "GraphicsItems/CircleAnalogItem/circleAnalogItem.hpp"
#include "GraphicsItems/SemiHexaAnalogItem/semiHexaAnalogItem.hpp"


/* -------------------------------------------------
 * Constructeur
 -------------------------------------------------*/
AnalogScene::AnalogScene()
{
    /* Récupération des informations nécessaires */
    ScreenParam * _screenParam = ParametersManagers::get_instance()->getScreenParam();
     double lHeightScreen = _screenParam->getHeight();
     double lWidthScreen = _screenParam->getWidth();

    /* On détermine la taille de chaque objet ainsi que leur emplacement */
    /* --- Speedo Meter --- */
    _speedMeter = new CircleAnalogItem(ParametersManagers::get_instance()->getAnalogSpeedParam());
    _speedMeter->setPos((lWidthScreen/2)-(lHeightScreen/2)*0.95,0);

    /* --- Fuel Meter --- */
    _fuelMeter = new SemiHexaAnalogItem(lHeightScreen*0.95);
    QPointF lFuelPoint = _speedMeter->getRightPoint();
    _fuelMeter->setPositionFromLeftPoint(lFuelPoint.x()-_fuelMeter->getSize().x()
                                        ,(lHeightScreen/2)*0.95);
    addItem(_fuelMeter);
    addItem(_speedMeter);

    //A FAIRE :
    /* Puis Placer les graduations de Fuel et une aiguille
    */

    setBackgroundBrush(QColor(0,0,0));
}

/* -------------------------------------------------
 * Animations
 -------------------------------------------------*/
void AnalogScene::launchInitAnimation()
{
    if(_speedMeter)
    {
        QPointF lPosFuelMeter = _speedMeter->getRightPoint();
        lPosFuelMeter.setX(lPosFuelMeter.x()+1);
        _fuelMeter->launchAnimation();
    }
    if(_speedMeter) _speedMeter->launchInitAnimation();
}


AnalogScene::~AnalogScene()
{
}
