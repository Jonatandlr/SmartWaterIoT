#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_VL53L0X.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

const int ajusteDistancia = 2; 
const long timingBudget = 50000;

const int alturaTanque = 90; // Altura del tanque en cm
const int nivelMaximo = 10;  // Nivel máximo de agua: 80 cm (90 - 80 = 10 cm desde el sensor)
const int nivelMinimo = 70;  // Nivel mínimo de agua: 20 cm (90 - 20 = 70 cm desde el sensor)

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }

  lox.setMeasurementTimingBudgetMicroSeconds(timingBudget);

  Serial.println("Calibración completada. Comenzando medición...");
  delay(1000);
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);

  if (measure.RangeStatus != 4) { 
    int distance = (measure.RangeMilliMeter / 10) + ajusteDistancia;

    if (distance > alturaTanque) {
      Serial.print("Error: medida fuera de rango (");
      Serial.print(distance);
      Serial.println(" cm)");
    } else if (distance <= nivelMaximo) {
      Serial.print("Alerta: Nivel máximo alcanzado (");
      Serial.print(distance);
      Serial.println(" cm)");
    } else if (distance >= nivelMinimo) {
      Serial.print("Alerta: Nivel mínimo alcanzado (");
      Serial.print(distance);
      Serial.println(" cm)");
    } else {
      Serial.print("Distancia al agua: ");
      Serial.print(distance);
      Serial.println(" cm");
    }
  } else {
    Serial.println("Error de medida");
  }

  delay(500);
}