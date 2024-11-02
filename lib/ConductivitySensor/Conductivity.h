
#ifndef Conductivity_h
#define Conductivity_h
#include <Wire.h>
#include <WiFi.h>                              
#include <PubSubClient.h>                       
#include <Arduino.h>
         


class Conductivity
{
  public:
    Conductivity();
    void begin();
    void getConductivity();
  private:
    float _conductivity;
    int _TXD2=17;
    int _RXD2=16;
};


#endif