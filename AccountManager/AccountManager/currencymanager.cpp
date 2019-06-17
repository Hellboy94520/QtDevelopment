#include "currencymanager.hpp"

#include "currencydata.hpp"

/* ----------------------------------------------------------------------------------------
Instance
---------------------------------------------------------------------------------------- */
CurrencyManager * CurrencyManager::_instance = NULL;

CurrencyManager * CurrencyManager::init()
{
    if(_instance!=NULL) { return 0; }
    _instance = new CurrencyManager();
    return _instance;
}

CurrencyManager * CurrencyManager::get_instance()
{
    if(_instance) { return _instance; }
    return 0;
}


/* ----------------------------------------------------------------------------------------
Public functions
---------------------------------------------------------------------------------------- */
bool CurrencyManager::is_currency(const QString &pKey) const
{
    return _currencyMap.contains(pKey);
}

const CurrencyData CurrencyManager::get_currency(const QString& pKey) const
{
    return _currencyMap.value(pKey, CurrencyData());
}


/* ----------------------------------------------------------------------------------------
Constructor/Destructor
---------------------------------------------------------------------------------------- */
CurrencyManager::CurrencyManager()
{
    //Creation of currency map
    _currencyMap.insert("EUR", CurrencyData("euros",
                                            "euros",
                                            "€",
                                            "EUR"));
    _currencyMap.insert("USD", CurrencyData("dollars",
                                            "dollars",
                                            "$",
                                            "USD"));
    _currencyMap.insert("GBP", CurrencyData("livres britannique",
                                            "pounds",
                                            "£",
                                            "GBP"));
}


CurrencyManager::~CurrencyManager()
{
}


