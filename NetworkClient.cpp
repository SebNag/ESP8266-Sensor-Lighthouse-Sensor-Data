#include "NetworkClient.h"

NetworkClient::NetworkClient() : 
    mUDP(),
    mSensorData(),
    mHostIP(), 
    mHostPort()
{

}

NetworkClient::~NetworkClient() 
{

}

inline void NetworkClient::sendData(SensorData& data) 
{
    mUDP.beginPacket(mHostIP, mHostPort); 
    for(int i =  0; i < SensorData::packageLen(); i++){
          mUDP.write(data.dataEle(i));
          Serial.println(data.dataEle(i));       
    }
    mUDP.endPacket(); 
}

inline void NetworkClient::setHostPort(uint16_t port)
{
    mHostPort = port;  
}

inline void NetworkClient::setHostIP(IPAddress hostIP)
{
    mHostIP = hostIP; 
}

