#pragma once

#include "MACAddress.h"
#include "MqttBrokerInfo.h"
#include "PropertyHelper.h"
#include <QObject>
#include <QString>

class CommonDeviceEmulator : public QObject
{
    Q_OBJECT
    AUTO_PROPERTY(QString, hardwareId)

public:
    explicit CommonDeviceEmulator(QObject* parent = nullptr);

    MACAddress* m_pMACAddr;
    QMqttClient* m_pClient;

    virtual void onMessageReceived(const QByteArray&, const QMqttTopicName&) {}
};
