#pragma once
#include <QObject>
#include <QMap>

class CurrencyData;


/* ----------------------------------------------------------------------------------------
Manager
---------------------------------------------------------------------------------------- */
class CurrencyManager : public QObject
{
    Q_OBJECT
public:
    static CurrencyManager * init();
    static CurrencyManager * get_instance();
    virtual ~CurrencyManager();

    bool is_currency(const QString& pKey) const;
    const CurrencyData get_currency(const QString& pKey) const;

private:
    CurrencyManager * _CurrencyManager;
    static CurrencyManager * _instance;
    CurrencyManager();

    QMap<QString, CurrencyData> _currencyMap;

};
