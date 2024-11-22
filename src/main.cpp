#include <Arduino.h>
#include "WifiConnect.h"
#include "Conductivity.h"
#include "HeightSensor.h"
#include "PHSensor.h"
#include "DataProcessor.h"


// Configura tu red WiFi
const char* ssid = "JONATANDLR 9133";            
const char* password = "87654321" ;    
// Configura el broker MQTT
const char* mqttServer = "192.168.137.1"; 

// topics
const char* topicConductivity = "esp/conductivity";
const char* topicHeight = "esp/height";
const char* topicPH = "esp/ph";


WifiConnect wifi(ssid, password, mqttServer, 1883);
Conductivity conductivity;
HeightSensor heightSensor;
PHSensor phSensor(32);


// DataProcessor processorConductivity;
// DataProcessor processorPH;
// DataProcessor processorHeight;
void setup() {
    Serial.begin(9600);
    wifi.setup_wifi();
    conductivity.begin();
    heightSensor.begin();
    phSensor.begin();
}

void loop() {
    wifi.begin();
    float con = conductivity.getConductivity();
    float ph = phSensor.readPH();
    float height = heightSensor.getDistance();
    Serial.print("Conductividad: ");
    Serial.println(con);
    Serial.print("pH: ");
    Serial.println(ph);
    Serial.print("Altura: ");
    Serial.println(height);
    
    // wifi.send_data(con, topicConductivity);
    // wifi.send_data(ph, topicPH);
    // wifi.send_data(height, topicHeight);

    // if (processorConductivity.getDataCount() < 10) {
    //     float sensorData = conductivity.getConductivity();
    //     Serial.print("Conductividad: ");
    //     Serial.println(sensorData);
    //     processorConductivity.addData(sensorData);
    // }
    // if (processorPH.getDataCount() < 10) {
    //     float sensorData = phSensor.readPH();
    //     processorPH.addData(sensorData);
    // }
    // // if (processorHeight.getDataCount() < 10)
    // // {
    // //     int sensorData = heightSensor.getDistance();
    // //     processorHeight.addData(sensorData);
    // // }

    // if (processorConductivity.getDataCount() >= 10 && processorPH.getDataCount() >= 10) {
    //     float averageConductivity = processorConductivity.getAverage();
    //     float averagePH = processorPH.getAverage();
    //     Serial.print("El promedio de conductividad es: ");
    //     Serial.println(averageConductivity);
    //     Serial.print("El promedio de pH es: ");
    //     Serial.println(averagePH);
    //     processorConductivity.reset();
    //     processorPH.reset();
    //     wifi.send_data(averageConductivity, topicConductivity);
    //     wifi.send_data(averagePH, topicHeight);
    // }
    delay(1000);
}