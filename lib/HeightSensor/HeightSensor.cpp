
#include <Arduino.h>
#include "HeightSensor.h"

HeightSensor::HeightSensor() {
    Adafruit_VL53L0X lox = Adafruit_VL53L0X();
    
}

void HeightSensor::begin() {
    Wire.begin();
    
    if (!lox.begin()) {
        Serial.println(F("Failed to boot VL53L0X"));
        while (1);
    }
    
    lox.setMeasurementTimingBudgetMicroSeconds(_timingBudget);
    
    Serial.println("Calibración completada. Comenzando medición...");
    delay(1000);
}

float HeightSensor::getDistance(){
    VL53L0X_RangingMeasurementData_t measure;
    lox.rangingTest(&measure, false);
    if (measure.RangeStatus != 4) { 
        float distance = (measure.RangeMilliMeter / 10);
        return distance;
    } else {
        return -1;
    }
}