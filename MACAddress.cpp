#include "MACAddress.h"

MACAddress::MACAddress()
{
    for (int i = 0; i < 6; ++i)
    {
        octet[i] = qrand() % 255;
    }
}

MACAddress::MACAddress(MACAddress& mac)
{
    memcpy(octet, mac.octet, 6 * sizeof(uint8_t));
}

MACAddress::MACAddress(uint16_t octet0,
                       uint16_t octet1,
                       uint16_t octet2,
                       uint16_t octet3,
                       uint16_t octet4,
                       uint16_t octet5)
{
    octet[0] = octet0;
    octet[1] = octet1;
    octet[2] = octet2;
    octet[3] = octet3;
    octet[4] = octet4;
    octet[5] = octet5;
}

QString MACAddress::toString()
{
    QString mac;
    for (int i = 0; i < 6; ++i)
    {
        mac += octet[i] < 16 ? ("0" + QString::number(octet[i], 16).toUpper())
                             : QString::number(octet[i], 16).toUpper();
        i < 5 ? mac += ":" : "";
    }
    return mac;
}

QString MACAddress::toId()
{
    QString id;
    for (int i = 0; i < 6; ++i)
    {
        id += octet[i] < 16 ? ("0" + QString::number(octet[i], 16).toUpper()) : QString::number(octet[i], 16).toUpper();
    }
    return id;
}

QString MACAddress::toIdShort()
{
    QString id;
    for (int i = 3; i < 6; ++i)
    {
        id += octet[i] < 16 ? ("0" + QString::number(octet[i], 16).toUpper()) : QString::number(octet[i], 16).toUpper();
    }
    return id;
}
