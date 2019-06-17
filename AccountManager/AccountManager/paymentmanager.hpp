#pragma once
#include <QObject>
#include <QList>

class PaymentData;

class PaymentManager : public QObject
{
    Q_OBJECT
public:
    static PaymentManager * init();
    static PaymentManager * get_instance();
    virtual ~PaymentManager();

signals:

public slots:

private:
    PaymentManager * _PaymentManager;
    static PaymentManager * _instance;
    PaymentManager();

    QList<PaymentData> _paymentList;

};
