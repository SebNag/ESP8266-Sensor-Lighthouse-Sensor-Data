#ifndef NETWORKINTF_H
#define NETWORKINTF_H

#include <stdint.h>
#include "IPAddress.h"
#include "SensorData.h"

class NetworkIntf 
{
    public:
        void UDP_SendSensorData(SensorData& data); 
        void UDP_SetHostConfig(uint16_t port, IPAddress hostIP); 

        virtual ~NetworkIntf()  = 0; 
    private: 
        virtual void sendData(SensorData& data)          = 0;
        virtual void setHostPort(uint16_t port)          = 0; 
        virtual void setHostIP(IPAddress hostIP)         = 0; 
};

#endif 
