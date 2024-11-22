#ifndef HeightSensor_h
#define HeightSensor_h

#include <Wire.h>
#include <Adafruit_VL53L0X.h>

class HeightSensor {
  public:
    HeightSensor();
    void begin();
    float getDistance();
    
  private:
    Adafruit_VL53L0X lox;
    int _distance;
    const long _timingBudget = 50000;
};

#endif