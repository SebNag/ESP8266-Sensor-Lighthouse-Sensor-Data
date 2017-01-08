#include "SensorData.h"

SensorData::SensorData(unsigned long timestamp) : 
    packetData{0}, timestamp(timestamp) 
{

}

void SensorData::printDataArray() const
{
    Serial.println("Current Data: "); 
    for(int i = 0; i < arrayLen; ++i){
        Serial.print(packetData[i]);
    }
}
