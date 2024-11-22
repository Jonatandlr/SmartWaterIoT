#include "WifiConnect.h"



WifiConnect::WifiConnect(const char* ssid, const char* password, const char* mqttServer, int mqttPort):_client(_espClient){
    _ssid = ssid;
    _password = password;
    _mqttServer = mqttServer;
    _mqttPort = mqttPort;
}

void WifiConnect::setup_wifi() {
    delay(10);
    Serial.print("Conectando a WiFi ");
    WiFi.begin(_ssid, _password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Conectado");
    _client.setServer(_mqttServer, _mqttPort);
}

void WifiConnect::reconnect() {
    while (!_client.connected()) {
        Serial.print("Intentando conectar al MQTT...");
        if (_client.connect("ESP32Client")) {
            Serial.println("Conectado");
        } else {
            Serial.print("Falló con error: ");
            Serial.println(_client.state());
            delay(2000);
        }
    }
}

void WifiConnect::begin() {
    if (!_client.connected()) {                     
        reconnect();
    }
    _client.loop();                                
}

void WifiConnect::send_data(float sensorData, String topic) {
    _sensorData = String(sensorData);                       // Asignar el valor de sensorData a _sensorData
    char sensorstring_array[30];                    // Crear un array de caracteres
    char *EC;                                       // Puntero a char
    _sensorData.toCharArray(sensorstring_array, 30); // Convertir el String a un array de caracteres
    EC = strtok(sensorstring_array, ",");           // Separar el array de caracteres por comas
    // Serial.print("EC: ");
    // Serial.println(EC);                             // Imprimir el valor de EC
    _client.publish(topic.c_str(), EC);              // Publicar el valor de EC en el topic especificado
}




