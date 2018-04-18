#pragma once

#include <QObject>
#include <QFile>


class AnalogSpeedParam;
class ScreenParam;
class TextParam;

class ParametersManagers
{
public:
    /* @brief création d'un gestionnaire de fichier */
    static ParametersManagers * init();
    /* création de l'unique instance de la classe */
    static ParametersManagers * get_instance();

    //Getter
    TextParam * getTextParam() { return _textParam; }
    ScreenParam * getScreenParam() { return _screenParam; }
    AnalogSpeedParam * getAnalogSpeedParam() { return _analogSpeedParam; }

private:
    ParametersManagers();
    bool getInformations(QFile& pFile);

    static ParametersManagers * _instance;

    bool default_ParametersManagers;

    TextParam * _textParam;
    ScreenParam * _screenParam;
    AnalogSpeedParam * _analogSpeedParam;
};
