#pragma once

#include <QString>

class PaymentData
{
public:
    // Constructor
    PaymentData()
    {
        _name = "";
    }

    PaymentData(const QString& pName)
    {
        _name = pName;
    }

    // Getter
    const QString& get_name() const
    { return _name; }


private:
    QString _name;
};
