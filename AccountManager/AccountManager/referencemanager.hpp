#pragma once
#include <QObject>

class ReferenceData;

class ReferenceManager : public QObject
{
    Q_OBJECT
public:
    static ReferenceManager * init();
    static ReferenceManager * get_instance();
    virtual ~ReferenceManager();

signals:

public slots:

private:
    ReferenceManager * _ReferenceManager;
    static ReferenceManager * _instance;
    ReferenceManager();

    QList<ReferenceData> _referenceList;

};
