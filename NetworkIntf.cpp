#include "NetworkIntf.h"

void NetworkIntf::UDP_SetHostConfig(uint16_t port, IPAddress hostIP)
{
    setHostPort(port); 
    setHostIP(hostIP); 
}

void NetworkIntf::UDP_SendSensorData(SensorData& data)
{
    sendData(data);
}

NetworkIntf::~NetworkIntf()
{

}

