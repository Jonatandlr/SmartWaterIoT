#ifndef HeightSensor_h
#define HeightSensor_h

#include <Wire.h>
#include <Adafruit_VL53L0X.h>

class HeightSensor {
  public:
    HeightSensor();
    void begin();
    void loop();
    void setTimingBudget(long timingBudget);
    void setAjusteDistancia(int ajusteDistancia);
    void setAlturaTanque(int alturaTanque);
    void setNivelMaximo(int nivelMaximo);
    void setNivelMinimo(int nivelMinimo);
  private:
    Adafruit_VL53L0X lox;
    int ajusteDistancia;
    long timingBudget;
    int alturaTanque;
    int nivelMaximo;
    int nivelMinimo;
};

#endif