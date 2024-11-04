#ifndef WifiConnect_h
#define WifiConnect_h

#include <Arduino.h>
#include <WiFi.h>                              
#include <PubSubClient.h>  


class WifiConnect
{
  public:
    WifiConnect(const char* ssid, const char* password, const char* mqttServer, int mqttPort);
    void setup_wifi();
    void reconnect();
    void begin();
    void send_data(float sensorData, String topic);
  private:
    const char* _ssid;
    const char* _password;
    const char* _mqttServer;
    int _mqttPort;
    WiFiClient _espClient;
    PubSubClient _client;
    String _sensorData;
};




#endif