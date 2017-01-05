#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <stdint.h>
#include "HardwareSerial.h"

class SensorData 
{
    public:
        SensorData(); 

        uint8_t dataEle(int index) const;
        void writeByte(const uint8_t data, const int pos);
        void printDataArray() const; 

        static int packageLen();
        const static int arrayLen = 4; 
        uint8_t  packetData[arrayLen];
};

#endif // SENSORDATA_H
