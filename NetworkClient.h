#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <stdint.h>

#include "ESP8266WiFi.h"
#include "WiFiUdp.h"
#include "NetworkIntf.h"
#include "SensorData.h"

class NetworkClient : public NetworkIntf
{
    public: 
        NetworkClient(); 
        ~NetworkClient();  
    private: 
        void sendData(SensorData& data); 
        void setHostPort(uint16_t port); 
        void setHostIP(IPAddress hostIP); 

        WiFiUDP     mUDP; 
        SensorData  mSensorData; 
        IPAddress   mHostIP; 
        uint16_t    mHostPort;  
};

#endif
