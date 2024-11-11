#include <Arduino.h>
#include "WifiConnect.h"
#include "Conductivity.h"
#include "HeightSensor.h"
#include "DataProcessor.h"

// Configura tu red WiFi
const char* ssid = "M16_HUGOS 2728";            
const char* password = "12345678" ;    
// Configura el broker MQTT
const char* mqttServer = "192.168.137.76"; 

// topics
const char* topicConductivity = "esp/conductivity";
const char* topicHeight = "esp/height";


WifiConnect wifi(ssid, password, mqttServer, 1883);
Conductivity conductivity;
HeightSensor heightSensor;
DataProcessor processorConductivity(10);
DataProcessor processorHeight(10);
void setup() {
    Serial.begin(9600);
    wifi.setup_wifi();
    conductivity.begin();
    heightSensor.begin();
}

void loop() {
    wifi.begin();

    if (processorConductivity.getDataCount() < 10) {
        float sensorData = conductivity.getConductivity();
        processorConductivity.addData(sensorData);
    }
    if (processorHeight.getDataCount() < 10)
    {
        int sensorData = heightSensor.getDistance();
        processorHeight.addData(sensorData);
    }

    if (processorConductivity.getDataCount() >= 10 && processorHeight.getDataCount() >= 10){
        float averageConductivity = processorConductivity.getAverage();
        int averageHeight = processorHeight.getAverage();
        Serial.print("El promedio de conductividad es: ");
        Serial.println(averageConductivity);
        Serial.print("El promedio de altura es: ");
        Serial.println(averageHeight);
        processorConductivity.reset();
        processorHeight.reset();
    }
    delay(1000);
}