#include "Parameters/ParametersManagers.hpp"

#include "Parameters/analogSpeedParam.hpp"
#include "Parameters/screenParam.hpp"
#include "Parameters/textParam.hpp"
#include <QDebug>
//#include <QDomDocument>
#include <QDir>

ParametersManagers * ParametersManagers::_instance = NULL;

ParametersManagers * ParametersManagers::init()
{
    if(_instance==NULL)
    {
        _instance = new ParametersManagers();
    }
    return _instance;
}

ParametersManagers * ParametersManagers::get_instance()
{
    if(_instance) return _instance;
    return 0;
}

bool ParametersManagers::getInformations(QFile& pFile)
{
    /*
    QDomDocument doc("myDocument");
    if( !doc.setContent(&pFile) ) { return false; }
    */
    return true;
}


ParametersManagers::ParametersManagers()
{
    //Faire une lecture de fichier XML pour lire les paramètres modifiable pour l'utilisateur
    default_ParametersManagers=false;
    /*
    QFile _File("ParametersManagers_default.xml");
    if(!_File.exists() || !_File.open(QIODevice::ReadWrite))
    {
        qDebug() << "Impossible to open ParametersManagers File";
        return;
    }
    _File.write("TOTO");
    _File.close();
    if(!getInformations(_File))
    {
        qDebug() << "Impossible to get ParametersManagers File";
        return;
    }
    */
    default_ParametersManagers=true;

    //Initialisation des Headers
    _textParam = new TextParam;
    _screenParam = new ScreenParam;
    _analogSpeedParam = new AnalogSpeedParam;
}
