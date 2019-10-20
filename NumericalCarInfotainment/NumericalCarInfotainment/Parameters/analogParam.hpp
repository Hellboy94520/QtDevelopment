#pragma once

#include <QList>

class AnalogParam
{
public:
    /* Initialisation */
    void setSpeedParam()
    {
        _numberList << "0" << "20" << "40" << "60" << "80"
                     << "100" << "120" << "140" << "160" << "180";
        _unity="KM/H";
    }
    void setRevAnalog()
    {
        _numberList << "0" << "1000" << "1500" << "2000"
                     << "3000" << "4000" << "5000" << "6000" << "7000";
        _unity="RPM";
    }

    //Setter
    void setNumberList(const QList<QString>& pNumberList) { _numberList=pNumberList; }
    void setUnity(const QString& pUnity) { _unity=pUnity; }

    //Getter
    const QList<QString>& getNumberList() const { return _numberList; }
    const QString& getUnity() const { return _unity; }

private:
    //Data
    QList<QString> _numberList;
    QString _unity="null";
};
