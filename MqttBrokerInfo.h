#pragma once

#include "PropertyHelper.h"
#include <QObject>
#include <QtMqtt/QMqttClient>

const QString _hostname("broker.shiftr.io");
const qint16 _port(1883);
const QString _username("9524efc1");
const QString _password("00e4e690b38cc2c1");

class MqttBrokerInfo : public QObject
{
    Q_OBJECT
    AUTO_PROPERTY(QString, hostname)
    AUTO_PROPERTY(quint16, port)
    AUTO_PROPERTY(QString, username)
    AUTO_PROPERTY(QString, password)

public:
    explicit MqttBrokerInfo(QObject* parent = nullptr);
    Q_SIGNAL void mqttBrokerInfoDataChanged();
};

extern MqttBrokerInfo MqttBrokerInfoData;
