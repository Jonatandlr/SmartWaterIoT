#include <Arduino.h>
#include "WifiConnect.h"
#include "Conductivity.h"
#include "HeightSensor.h"
#include "readpH.h"

// Configura tu red WiFi
const char* ssid = "M16_HUGOS 2728";            
const char* password = "12345678" ;    
// Configura el broker MQTT
const char* mqttServer = "192.168.137.76";      

WifiConnect wifi(ssid, password, mqttServer, 1883);
Conductivity conductivity;
ReadPH phSensor(34); // Pin GPIO 34 para lectura de pH

void setup() {
    Serial.begin(9600);
    wifi.setup_wifi();
    conductivity.begin();
    phSensor.begin(); // Inicializa el sensor de pH
}

void loop() {
    wifi.begin();
    float sensorData = conductivity.getConductivity();
    printf("Conductividad: %f\n", sensorData);
    // wifi.send_data(sensorData, "esp/conductividad");

    // Obtiene y muestra los datos de pH
    phSensor.readPH();

    delay(1000);
}