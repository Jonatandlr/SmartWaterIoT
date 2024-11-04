#include <Arduino.h>
#include "WifiConnect.h"
#include "Conductivity.h"
#include "HeightSensor.h"

// Configura tu red WiFi
const char* ssid = "M16_HUGOS 2728";            
const char* password = "12345678" ;    
// Configura el broker MQTT
const char* mqttServer = "192.168.137.76";      

WifiConnect wifi(ssid, password, mqttServer, 1883);
Conductivity conductivity;

void setup() {
    Serial.begin(9600);
    wifi.setup_wifi();
    conductivity.begin();
}

void loop() {
    wifi.begin();
    float sensorData = conductivity.getConductivity();
    printf("Conductividad: %f\n", sensorData);
    // wifi.send_data(sensorData, "esp/conductividad");
    delay(1000);
}