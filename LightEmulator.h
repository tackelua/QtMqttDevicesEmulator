#pragma once

#include "CommonDeviceEmulator.h"

class LightEmulator : public CommonDeviceEmulator
{
    Q_OBJECT
    AUTO_PROPERTY(bool, status)
public:
    explicit LightEmulator();

    void onMessageReceived(const QByteArray& message, const QMqttTopicName& topic = QMqttTopicName()) override;
};
