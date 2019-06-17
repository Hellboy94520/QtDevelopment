#pragma once
#include <QObject>
#include <QFile>
#include <QList>

class DataManager : public QObject
{
    Q_OBJECT
public:
    static DataManager * init(const QString& pFileName);
    static DataManager * get_instance();
    virtual ~DataManager();

signals:

public slots:

private:
    DataManager * _dataManager;
    static DataManager * _instance;
    DataManager(const QString& pFileName);

    QFile * _dataFile;
    QList<QString> _referenceList;
    QList<QString> _paymentTypeList;

};
