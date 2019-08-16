#include "CommonDeviceEmulator.h"

CommonDeviceEmulator::CommonDeviceEmulator(QObject* parent)
    : QObject(parent)
    , m_pMACAddr(new MACAddress)
    , m_pClient(new QMqttClient)
{
    MACAddress mac;
    qDebug() << "MAC\n" << mac.toString() << "\n" << mac.toId();

    QObject::connect(this, &CommonDeviceEmulator::hardwareIdChanged, this, [this]() {
        if (a_hardwareId != "default")
        {
            m_pClient->setClientId(a_hardwareId);
        }
        else
        {
            a_hardwareId = m_pClient->clientId();
        }
        m_pClient->connectToHost();
    });

    QObject::connect(m_pClient, &QMqttClient::messageReceived, this, &CommonDeviceEmulator::onMessageReceived);

    QObject::connect(&MqttBrokerInfoData, &MqttBrokerInfo::mqttBrokerInfoDataChanged, this, [this]() {
        m_pClient->setHostname(MqttBrokerInfoData.hostname());
        m_pClient->setPort(MqttBrokerInfoData.port());
        m_pClient->setUsername(MqttBrokerInfoData.username());
        m_pClient->setPassword(MqttBrokerInfoData.password());
        m_pClient->connectToHost();
    });

    a_hardwareId = m_pMACAddr->toId().toLower();

    m_pClient->setHostname(MqttBrokerInfoData.hostname());
    m_pClient->setPort(MqttBrokerInfoData.port());
    m_pClient->setUsername(MqttBrokerInfoData.username());
    m_pClient->setPassword(MqttBrokerInfoData.password());
    m_pClient->setClientId(a_hardwareId);
}
