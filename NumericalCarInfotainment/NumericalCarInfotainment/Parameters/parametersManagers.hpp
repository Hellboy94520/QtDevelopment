#pragma once

#include <QObject>
#include <QFile>

#include "Parameters/screenParam.hpp"
#include "Parameters/analogParam.hpp"
#include "GraphicsItems/CircleAnalogItem/circleAnalogParam.hpp"
#include "GraphicsItems/SemiHexaAnalogItem/semiHexaAnalogParam.hpp"


class ScreenParam;
class AnalogParam;
class CircleAnalogParam;
class SemiHexaAnalogParam;

class ParametersManagers : public QObject
{
    Q_OBJECT
public:
    /* @brief création d'un gestionnaire de fichier */
    static ParametersManagers * init();
    /* création de l'unique instance de la classe */
    static ParametersManagers * get_instance();

    //Setter
    //FAIRE : Verifier si c'est pas l'adresse que l'on renvoie
    /*
    void setCircleAnalogParam(const CircleAnalogParam& pParam) { _circleParam = pParam;}
    void setSemiHexaAnalogProgram(const SemiHexaAnalogParam& pParam) { _semiParam=pParam; }

    void setAnalogSpeedParam(const AnalogParam& pParam) { _analogSpeedParam=pParam; }
    void setAnalogRevParam(const AnalogParam& pParam) { _analogRevParam=pParam; }
    void setAnalogFuelParam(const AnalogParam& pParam) { _analogFuelParam=pParam; }
    void setAnalogWaterParam(const AnalogParam& pParam) { _analogWaterParam=pParam; }
    void setScreenParam(const ScreenParam& pParam) { _screenParam=pParam;}
   */

    //Getter
    CircleAnalogParam * getCircleAnalogParam() { _circleParam; }
    SemiHexaAnalogParam& getSemiHexaAnalogParam() { _semiParam; }

    AnalogParam * getAnalogSpeedParam() { return _analogSpeedParam; }
    AnalogParam * getAnalogRevParam() { return _analogRevParam; }
    AnalogParam * getAnalogFuelParam() { return _analogFuelParam; }
    AnalogParam * getAnalogWaterParam() { return _analogWaterParam; }
    ScreenParam * getScreenParam() { return _screenParam; }

private:
    ParametersManagers();
    virtual ~ParametersManagers();

    void updateItemParam();

    bool getInformations(QFile& pFile);

    static ParametersManagers * _instance;

    bool default_ParametersManagers;

    CircleAnalogParam * _circleParam;
    SemiHexaAnalogParam * _semiParam;

    AnalogParam * _analogSpeedParam;
    AnalogParam * _analogRevParam;
    AnalogParam * _analogFuelParam;
    AnalogParam * _analogWaterParam;
    ScreenParam * _screenParam;
};
