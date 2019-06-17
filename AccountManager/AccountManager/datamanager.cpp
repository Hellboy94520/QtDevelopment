#include "datamanager.hpp"

#include <QDebug>
#include "logger.hpp"

/* ----------------------------------------------------------------------------------------
Instance
---------------------------------------------------------------------------------------- */
DataManager * DataManager::_instance = NULL;

DataManager * DataManager::init(const QString& pFileName)
{
    if(_instance!=NULL) { return 0; }
    _instance = new DataManager(pFileName);
    return _instance;
}

DataManager * DataManager::get_instance()
{
    if(_instance) { return _instance; }
    return 0;
}



/* ----------------------------------------------------------------------------------------
Constructor/Destructor
---------------------------------------------------------------------------------------- */
DataManager::DataManager(const QString& pFileName)
{
    _dataFile = new QFile(pFileName);

    // If Database file not exist
    if(!_dataFile->exists())
    {
        qDebug(logCritical()) << "Impossible to open database file \'" << pFileName << "\'";
        //TODO: Show pop-up to choose another file
    }

    //TODO: Load data
}


DataManager::~DataManager()
{
    if(_dataFile) { delete _dataFile; }
}


