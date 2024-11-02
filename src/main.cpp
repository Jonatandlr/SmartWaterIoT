#include <WiFi.h>                              
#include <PubSubClient.h>                       
#include <Arduino.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include <string.h>
#define RXD2 16                                 
#define TXD2 17                                 

HardwareSerial myserial(2);                    
String inputstring = "";                       
String sensorstring = "";                     
boolean sensor_string_complete = false;        

// Configura tu red WiFi
const char* ssid = "M16_HUGOS 2728";            
const char* password = "12345678";             

// Configura el broker MQTT
const char* mqttServer = "192.168.137.34";     
const int mqttPort = 1883;                     

WiFiClient espClient;                          
PubSubClient client(espClient);                

unsigned long previousMillis = 0;               
const long interval = 1000;                 

void setup_wifi() {                           
  delay(10);
  Serial.print("Conectando a WiFi ");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {    
    delay(500);
    Serial.print(".");
  }
  Serial.println(" conectado");
}

void reconnect() {                            
  while (!client.connected()) {
    Serial.print("Intentando conectar al MQTT...");
    if (client.connect("ESP32Client")) { 
      Serial.println("conectado");
    } else {
      Serial.print("falló con error: ");
      Serial.print(client.state());
      delay(2000);                           
    }
  }
}

void send_EC_data() {                          
  char sensorstring_array[30];                  
  char *EC;                                    
  sensorstring.toCharArray(sensorstring_array, 30); 

  EC = strtok(sensorstring_array, ",");       

  Serial.print("EC: ");
  Serial.println(EC);                          


  client.publish("esp/conductividad", EC);   
}
void setup() {
  Serial.begin(9600);                          
  myserial.begin(9600, SERIAL_8N1, RXD2, TXD2); 
  inputstring.reserve(10);                      
  sensorstring.reserve(30);                   
  // setup_wifi();                              
  // client.setServer(mqttServer, mqttPort);    
}

void loop() {
  if (myserial.available() > 0) {              
    char inchar = (char)myserial.read();        
    sensorstring += inchar;                
    if (inchar == '\r') {                     
      sensor_string_complete = true;          
    }
  }
  unsigned long currentMillis = millis();      
  if (sensor_string_complete) {               
    if (isdigit(sensorstring[0])) {           
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;         
        send_EC_data();                          
      }
    }
    sensorstring = "";                      
    sensor_string_complete = false;           
  }

}

