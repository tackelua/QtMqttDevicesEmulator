#include "RelaysEmulator.h"

RelaysEmulator::RelaysEmulator()
{
    QObject::connect(this, &RelaysEmulator::statusChanged, this, [this]() {
        m_pClient->publish("RELAYS/STATUS/" + hardwareId(), a_status ? "ON" : "OFF");
    });

    QObject::connect(m_pClient, &QMqttClient::connected, this, [this]() {
        this->m_pClient->subscribe(QMqttTopicFilter("RELAYS/" + hardwareId()));
    });

    QObject::connect(m_pClient, &QMqttClient::messageReceived, this, &RelaysEmulator::onMessageReceived);
}

void RelaysEmulator::onMessageReceived(const QByteArray& message, const QMqttTopicName& topic)
{
    if (topic.name() == ("RELAYS/" + hardwareId()))
    {
        if (message == "ON")
        {
            status(true);
        }
        else if (message == "OFF")
        {
            status(false);
        }
    }
}
