#pragma once
#include <QString>
#include <QList>
#include "operationdata.hpp"

class AccountData
{
public:
    AccountData();

    // Getter
    const QString& get_name()       { return _name; }
    const QString& get_bankname()   { return _bankname; }
    const QList<OperationData>& get_operations() { return _operationList; }

    // Setter
    void set_name       (const QString pName)       { _name = pName; }
    void set_bankname   (const QString pBankName)   { _bankname = pBankName; }
    void add_operation  (const OperationData pOperation)
    { _operationList.append(pOperation); }

private:
    QString _name;
    QString _bankname;
    float   _amout;
    QList<OperationData> _operationList;
};
