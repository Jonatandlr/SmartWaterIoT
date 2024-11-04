
#ifndef Conductivity_h
#define Conductivity_h
#include <Arduino.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include <string.h>

class Conductivity
{
  public:
    Conductivity();
    void begin();
    float getConductivity();
  private:
    float _conductivity;
    int _TXD2=17;
    int _RXD2=16;
    HardwareSerial _myserial;
    String _sensorData = "";
    bool _sensorStringComplete = false;
};


#endif