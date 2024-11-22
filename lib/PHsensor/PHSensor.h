#ifndef PHSENSOR_H
#define PHSENSOR_H
#include <Arduino.h>
#include "ph_surveyor.h"
#include <OneWire.h>
#include <DallasTemperature.h>

class PHSensor
{
public:
    PHSensor(int pin);
    void begin();
    float readPH(); // Método para recolectar y mostrar lecturas de pH

private:
    Surveyor_pH _phSensor;
    float _phReadings;
    float _TempReadings;
    const int ONE_WIRE_BUS = 4;
    OneWire oneWire;
    DallasTemperature sensors;
};

#endif
