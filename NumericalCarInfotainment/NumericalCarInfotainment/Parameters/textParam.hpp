#pragma once
#include <QList>
#include <QString>

class TextParam
{
public:
    TextParam();

    //Getter
    const QList<QString>& getSpeedNumber() const { return _speedNumber; }
    const QString& getUnitySpeed() const { return _unitySpeed; }
    const double& getLargeScaleNumber() const { return _largeScale; }

    //Setter
    //void setNewTextParam(const TextParam pTextParam) { this=pTextParam; }

private:
    //Data
    QList<QString> _speedNumber;
    QString _unitySpeed="KM/H";
    double _largeScale=0.005;
};
