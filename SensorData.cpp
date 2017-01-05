#include "SensorData.h"

SensorData::SensorData() : 
    packetData{0}  
{

}

int SensorData::packageLen() 
{
    return arrayLen; 
}


void SensorData::printDataArray() const
{
    Serial.println("Current Data: "); 
    for(int i = 0; i < SensorData::packageLen(); ++i){
        Serial.print(packetData[i]);
    }
}

void SensorData::writeByte(const uint8_t data, const int pos)
{
    if(pos < arrayLen) {
        packetData[pos] = data; 
    }
}

uint8_t SensorData::dataEle(int index) const 
{
    return packetData[index];
}

