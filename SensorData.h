#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <stdint.h>
#include "HardwareSerial.h"

class SensorData 
{
    public:
        SensorData(unsigned long timestamp); 
        void printDataArray() const; 

        const static int arrayLen = 4; 
        uint8_t  packetData[arrayLen];
        long unsigned timestamp;
};

#endif // SENSORDATA_H
