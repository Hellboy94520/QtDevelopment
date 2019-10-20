#pragma once
#include <QString>
#include <QFile>


class ParameterData
{
public:
    ParameterData();
    virtual ~ParameterData();

    // Functions
    bool is_first_start();
    bool first_start();
    bool load_param();

private:

    // Variables
    QString _paramFileName;
    QFile * _paramFile;
    QString _lastFileOpen;
};
