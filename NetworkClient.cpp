#include "NetworkClient.h"

NetworkClient::NetworkClient() : 
    mUDP(),
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
    uint8_t *addr = (uint8_t*)&data.timestamp;
    for(int i =  0; i < 2; i++){
          mUDP.write(addr[i]);
    }
    for(int i =  0; i < data.arrayLen; i++){
          mUDP.write(data.packetData[i]);
          Serial.println(data.packetData[i]);       
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

