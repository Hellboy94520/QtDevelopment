#include "paymentmanager.hpp"

#include "paymentdata.hpp"

/* ----------------------------------------------------------------------------------------
Instance
---------------------------------------------------------------------------------------- */
PaymentManager * PaymentManager::_instance = NULL;

PaymentManager * PaymentManager::init()
{
    if(_instance!=NULL) { return 0; }
    _instance = new PaymentManager();
    return _instance;
}

PaymentManager * PaymentManager::get_instance()
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
PaymentManager::PaymentManager()
{

}


PaymentManager::~PaymentManager()
{
}


