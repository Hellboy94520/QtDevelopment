#include "Parameters/ParametersManagers.hpp"
#include <QDebug>
//#include <QDomDocument>
#include <QDir>

/* -------------------------------------
 * Instance
 ------------------------------------ */

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

/* -------------------------------------
 * Mise à jour
 ------------------------------------ */
void ParametersManagers::updateItemParam()
{
    //FAIRE : Mettre à jour les items au niveau de leur taille, à voir si on reconstruit tous ou on modifie les objets existants

}


/* -------------------------------------
 * Constructeur / Destructeur
 ------------------------------------ */
ParametersManagers::ParametersManagers()
{
    //FAIRE : une lecture de fichier XML pour lire les paramètres modifiable pour l'utilisateur
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

    _circleParam = new CircleAnalogParam;
    _semiParam = new SemiHexaAnalogParam;

    _analogSpeedParam = new AnalogParam;
    _analogSpeedParam->setSpeedParam();
    _analogRevParam = new AnalogParam;
    _analogRevParam->setRevAnalog();
    _analogFuelParam = new AnalogParam;
    _analogWaterParam = new AnalogParam;
}

ParametersManagers::~ParametersManagers()
{
    //A FAIRE
}
