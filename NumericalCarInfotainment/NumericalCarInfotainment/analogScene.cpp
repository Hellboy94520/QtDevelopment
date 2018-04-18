#include "analogScene.hpp"
#include "GraphicsItems/compteurItem.hpp"
#include "GraphicsItems/compteurItemv2.hpp"

#include "Parameters/parametersManagers.hpp"
#include "Parameters/screenParam.hpp"
#include "Parameters/analogSpeedParam.hpp"
#include "Parameters/textParam.hpp"

AnalogScene::AnalogScene(const QRect& pScreenSize)
{
    /* Récupération des informations nécessaires */
    _screenParam = ParametersManagers::get_instance()->getScreenParam();
    _analogSpeedParam = ParametersManagers::get_instance()->getAnalogSpeedParam();
    _textParam = ParametersManagers::get_instance()->getTextParam();

    /* On détermine la taille de chaque objet ainsi que leur emplacement */
    /* --- Speedo Meter --- */
    double lHeightScreen = _screenParam->getScreenHeight();
    _speedoMeter = new CompteurItem(lHeightScreen*0.95,
                                    _textParam->getSpeedNumber(),
                                    _textParam->getUnitySpeed());

    _speedoMeter->setPos((pScreenSize.width()/2)-(pScreenSize.height()/2)*0.95,0);

    /* --- Fuel Meter --- */
    _fuelMeter = new CompteurItemV2(pScreenSize.height()*0.95);
    QPointF lFuelPoint = _speedoMeter->getRightPoint();
    _fuelMeter->setPositionFromLeftPoint(lFuelPoint.x()-_fuelMeter->getSize().x()
                                        ,(pScreenSize.height()/2)*0.95);

    addItem(_fuelMeter);
    addItem(_speedoMeter);

    //A FAIRE :
    /* Puis Placer les graduations de Fuel et une aiguille
     * Puis Créer Animation le faisant apparaitre derrière le cercle puis qui en sort pour ce mettre sur le côté droite
    */

    setBackgroundBrush(QColor(0,0,0));
}

void AnalogScene::launchInitAnimation()
{
    QPointF lPosFuelMeter = _speedoMeter->getRightPoint();
    lPosFuelMeter.setX(lPosFuelMeter.x()+1);
    if(_speedoMeter) _speedoMeter->launchInitAnimation();
    if(_fuelMeter) _fuelMeter->launchAnimation();
}


AnalogScene::~AnalogScene()
{
    if(_speedoMeter) delete _speedoMeter;
}
