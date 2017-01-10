#include "ESP8266WiFi.h"
#include "SensorData.h"
#include "NetworkIntf.h"
#include "NetworkClient.h"
//#include "Ticker.h"

#include <memory>

static const char* ssid = "nsa";
static const char* password = "shinternet";
//static Ticker configure; 

typedef std::unique_ptr<NetworkIntf> network_ptr;  
network_ptr pNetwork = nullptr; 

network_ptr createNetwork()
{
    network_ptr pNetwork = network_ptr(new NetworkClient()); 
    IPAddress remoteHostIP(192,168,43,141);
    pNetwork->UDP_SetHostConfig(8000, remoteHostIP);
    return pNetwork; 
}
 
void receiveData() {
    //unsigned long timestamp = millis();
    //SensorData data(timestamp);
    SensorData data(0);
    int counter = 0;
    while (counter < data.arrayLen && Serial.available) {
        data.packetData[counter++] = Serial.read(); 
    }
    pNetwork->UDP_SendSensorData(data);
}

void setupWiFi(){
    // periodically called from the timer; after a certain threshold of tries, start AP on the ESP to reconfiugre the target host
    static int timeoutCounter = 0; 

    if( timeoutCounter < 4 && WiFi.status() != WL_CONNECTED) {

        WiFi.mode(WIFI_STA); 
        WiFi.begin(ssid, password);
        Serial.print("....");

    }else if(WiFi.status() == WL_CONNECTED){
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.print(WiFi.localIP()); 

        pinMode(2 ,INPUT); 
        attachInterrupt(2, receiveData, HIGH);
        pNetwork = createNetwork(); 
        //configure.detach(); 
    }else{
        Serial.println(""); 
        Serial.println("Starting Access Point on the ESP8266"); 
        //configure.detach(); 
    }
}

void setup()
{ 
    Serial.begin(115200); 

    Serial.println("----------------------------"); 
    Serial.println("ESP8226 Transmit Sensor Data via UDP"); 
    Serial.println("----------------------------"); 
    Serial.println("");

    //configure.attach(10, setupWiFi); 
    WiFi.mode(WIFI_STA); 
    WiFi.begin(ssid, password);

   while (WiFi.status() != WL_CONNECTED) {
         delay(500);
         Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.print(WiFi.localIP()); 
    
    pinMode(2 ,INPUT); 
    attachInterrupt(2, receiveData, FALLING);
    pNetwork = createNetwork(); 
}

void loop() {
    delay(1000); 
}
