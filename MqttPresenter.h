#ifndef MQTTPRESENTER_H
#define MQTTPRESENTER_H

#include <QObject>

class MqttPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MqttPresenter(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MQTTPRESENTER_H
