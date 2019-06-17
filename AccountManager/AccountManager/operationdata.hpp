#pragma once

#include <QString>
#include <QDate>

#include "currencydata.hpp"

class OperationData
{
public:
    OperationData(const QDate pDate, const QString pName, const float& pCost, const bool& pChecked)
    {
        _date = pDate;
        _name = pName;
        _cost = pCost;
        _checked = pChecked;
    }

    // Getter
    const QDate&    get_date()  const { return _date; }
    const QString&  get_name()  const { return _name; }
    const float&    get_cost()  const { return _cost; }
    const bool&     get_checked()   const { return _checked; }

    // Setter
    void set_date(const QDate pDate)   { _date = pDate; }
    void set_name(const QString pName) { _name = pName; }
    void set_cost(const float pCost)   { _cost = pCost; }
    void set_checked(const bool pChecked) { _checked = pChecked; }

private:
    QDate   _date;
    QString _name;
    float   _cost;
    CurrencyData _currency;
    //type
    //category
    bool    _checked;   // Operation checked
};
