#pragma once

#include "CommonDeviceEmulator.h"

class RelaysEmulator : public CommonDeviceEmulator
{
    Q_OBJECT
    AUTO_PROPERTY(bool, status)

public:
    RelaysEmulator();

    void onMessageReceived(const QByteArray& message, const QMqttTopicName& topic = QMqttTopicName()) override;
};
