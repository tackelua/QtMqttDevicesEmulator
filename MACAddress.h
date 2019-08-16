#pragma once

#include <QDebug>
#include <QString>

class MACAddress
{
public:
    MACAddress();
    MACAddress(MACAddress& mac);
    MACAddress(uint16_t octet0, uint16_t octet1, uint16_t octet2, uint16_t octet3, uint16_t octet4, uint16_t octet5);

    QString toString();

    QString toId();
    QString toIdShort();

private:
    uint16_t octet[6];
};
