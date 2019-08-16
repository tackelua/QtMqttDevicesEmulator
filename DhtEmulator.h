#pragma once

#include "CommonDeviceEmulator.h"
#include <QTimer>

class DhtEmulator : public CommonDeviceEmulator
{
    Q_OBJECT
    AUTO_PROPERTY(qint32, interval)
    AUTO_PROPERTY(bool, active)
    READ_PROPERTY(double, temperature)
    READ_PROPERTY(double, humidity)

public:
    DhtEmulator();

    double getTemperature();
    double getHumidity();
    QString getDhtData();

private:
    QTimer* m_pTimer;
};
