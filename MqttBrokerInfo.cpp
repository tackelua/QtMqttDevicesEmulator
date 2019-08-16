#include "MqttBrokerInfo.h"
#include <QtDebug>

MqttBrokerInfo::MqttBrokerInfo(QObject* parent)
    : QObject(parent)
    , a_hostname(_hostname)
    , a_port(_port)
    , a_username(_username)
    , a_password(_password)
{
    QObject::connect(this, &MqttBrokerInfo::hostnameChanged, this, &MqttBrokerInfo::mqttBrokerInfoDataChanged);
    QObject::connect(this, &MqttBrokerInfo::portChanged, this, &MqttBrokerInfo::mqttBrokerInfoDataChanged);
    QObject::connect(this, &MqttBrokerInfo::usernameChanged, this, &MqttBrokerInfo::mqttBrokerInfoDataChanged);
    QObject::connect(this, &MqttBrokerInfo::passwordChanged, this, &MqttBrokerInfo::mqttBrokerInfoDataChanged);
}

MqttBrokerInfo MqttBrokerInfoData;
