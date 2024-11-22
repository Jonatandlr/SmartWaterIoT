#include "PHSensor.h"
#include <Arduino.h>

PHSensor::PHSensor(const int pin) : _phSensor(pin)  { // Inicializa el sensor de pH
    _phReadings = 0;
    _TempReadings=0;
    oneWire = OneWire(4);
    sensors = DallasTemperature(&oneWire);
    Serial.println(F("Sensor de pH inicializado")); 
}

void PHSensor::begin()
{
    _phSensor.begin(); // Inicializa el sensor de pH
    delay(200);
    Serial.println(F("Recolectando datos"));
}

float PHSensor::readPH()
{
    _phReadings = _phSensor.read_ph(); // Lee y guarda el pH
    _TempReadings=sensors.getTempCByIndex(0);
    Serial.print(F("Temperatura: "));
    Serial.println(_TempReadings);
    float compensated_ph_value = (-0.010439*_TempReadings) + (1.01906*_phReadings);
    return compensated_ph_value;
}
