#include "LightEmulator.h"

LightEmulator::LightEmulator()
    : a_status(false)
{
    QObject::connect(this, &LightEmulator::statusChanged, this, [this]() {
        m_pClient->publish("LIGHT/STATUS/" + hardwareId(), a_status ? "ON" : "OFF");
    });

    QObject::connect(m_pClient, &QMqttClient::connected, this, [this]() {
        this->m_pClient->subscribe(QMqttTopicFilter("RELAYS/STATUS/#"));
    });
}

void LightEmulator::onMessageReceived(const QByteArray& message, const QMqttTopicName& topic)
{
    if (message == "ON")
    {
        qDebug() << "status true";
        status(true);
    }
    if (message == "OFF")
    {
        qDebug() << "status false";
        status(false);
    }
}
