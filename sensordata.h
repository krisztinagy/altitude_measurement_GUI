#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <QString>

class SensorData
{
    QString key;
    QString value;
    QString type;



public:
    SensorData(QString time, QString data, QString sensor);
    ~SensorData();

    void SetKey(QString time);
    void SetValue(QString altitude);
    void SetType(QString sensor);

    QString GetKey();
    QString GetValue();
    QString GetType();


};

#endif // SENSORDATA_H
