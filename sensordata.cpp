#include "sensordata.h"

SensorData::SensorData(QString time, QString data, QString sensor)
{
    this->key = time;
    this->value = data;
    this->type = sensor;

}

void SensorData::SetKey(QString time)
{
    this->key = time;
}

void SensorData::SetValue(QString altitude)
{
    this->value = altitude;
}

void SensorData::SetType(QString sensor)
{
    this->type = sensor;
}

QString SensorData::GetKey()
{
    return this->key;
}

QString SensorData::GetValue()
{
    return this->value;
}

QString SensorData::GetType()
{
    return this->type;
}

SensorData::~SensorData()
{

}
