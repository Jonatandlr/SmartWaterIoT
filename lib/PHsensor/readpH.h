#ifndef ReadPH_h
#define ReadPH_h
#include <Arduino.h>
#include "ph_surveyor.h"

class ReadPH {
public:
    ReadPH(int pin);
    void begin();
    void readPH(); // Método para recolectar y mostrar lecturas de pH

private:
    Surveyor_pH _phSensor;
    static const int SAMPLE_DURATION = 60; // Duración de muestreo en segundos (1 minuto)
    static const int SAMPLE_INTERVAL = 1000; // Intervalo de muestreo en milisegundos
    float _phReadings[SAMPLE_DURATION]; // Arreglo para almacenar las lecturas de pH
};

#endif
