#include "referencemanager.hpp"

#include "referencedata.hpp"

/* ----------------------------------------------------------------------------------------
Instance
---------------------------------------------------------------------------------------- */
ReferenceManager * ReferenceManager::_instance = NULL;

ReferenceManager * ReferenceManager::init()
{
    if(_instance!=NULL) { return 0; }
    _instance = new ReferenceManager();
    return _instance;
}

ReferenceManager * ReferenceManager::get_instance()
{
    if(_instance) { return _instance; }
    return 0;
}


/* ----------------------------------------------------------------------------------------
Public functions
---------------------------------------------------------------------------------------- */



/* ----------------------------------------------------------------------------------------
Constructor/Destructor
---------------------------------------------------------------------------------------- */
ReferenceManager::ReferenceManager()
{

}


ReferenceManager::~ReferenceManager()
{
}


