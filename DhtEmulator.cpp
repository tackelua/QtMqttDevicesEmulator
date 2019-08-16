#include "DhtEmulator.h"
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>

DhtEmulator::DhtEmulator()
    : a_interval(1000)
    , a_active(true)
    , m_pTimer(new QTimer)
{
    QObject::connect(this, &DhtEmulator::hardwareIdChanged, this, [this]() {
        if (hardwareId() != "" || hardwareId() != "default")
        {
            m_pClient->setClientId(hardwareId());
        }
        else
        {
            hardwareId(QString("DHT-") + m_pMACAddr->toId().toLower());
        }
        m_pClient->connectToHost();
    });

    QObject::connect(&MqttBrokerInfoData, &MqttBrokerInfo::mqttBrokerInfoDataChanged, this, [this]() {
        m_pClient->setHostname(MqttBrokerInfoData.hostname());
        m_pClient->setPort(MqttBrokerInfoData.port());
        m_pClient->setUsername(MqttBrokerInfoData.username());
        m_pClient->setPassword(MqttBrokerInfoData.password());
        m_pClient->connectToHost();
    });

    QObject::connect(this, &DhtEmulator::activeChanged, this, [this]() {
        if (a_active)
            m_pTimer->start();
        else
            m_pTimer->stop();
    });

    QObject::connect(m_pTimer, &QTimer::timeout, this, [this]() {
        m_pClient->publish("DHT/" + hardwareId(), getDhtData().toLocal8Bit());
    });

    qsrand(static_cast<uint>(QDateTime::currentMSecsSinceEpoch() / 1000));
    a_temperature = getTemperature();
    a_humidity = getHumidity();

    m_pTimer->setInterval(a_interval);
    if (a_active)
    {
        m_pTimer->start();
    }
}

double DhtEmulator::getTemperature()
{
    // random from 25 to 30
    static double temp = 25.0 + static_cast<double>(qrand() % 1000) / 100.0;
    double offset = static_cast<double>(qrand() % 100) / 100.0;
    if (qrand() % 2)
    {
        temp += offset;
    }
    else
    {
        temp -= offset;
    }
    a_temperature = temp;
    Q_EMIT temperatureChanged(temp);
    return a_temperature;
}

double DhtEmulator::getHumidity()
{ // random from 80 to 100
    static double humi = 80.0 + static_cast<double>(qrand() % 2000) / 200.0;
    double offset = static_cast<double>(qrand() % 100) / 100.0;
    if (qrand() % 2)
    {
        humi += offset;
    }
    else
    {
        humi -= offset;
    }
    a_humidity = humi;
    Q_EMIT humidityChanged(humi);
    return humi;
}

QString DhtEmulator::getDhtData()
{
    QJsonObject data{{"temp", QString::number(getTemperature(), 'f', 2)},
                     {"humi", QString::number(getHumidity(), 'f', 2)}};
    QJsonDocument doc(data);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    return strJson;
}
