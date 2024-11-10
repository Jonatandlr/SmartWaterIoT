#include "readpH.h"

ReadPH::ReadPH(int pin) : _phSensor(pin) {}

void ReadPH::begin() {
    _phSensor.begin();  // Inicializa el sensor de pH
    delay(200);
    Serial.println(F("Recolectando datos de pH cada minuto"));
}

void ReadPH::readPH() {
    // Recolectar datos de pH durante un minuto
    for (int i = 0; i < SAMPLE_DURATION; i++) {
        _phReadings[i] = _phSensor.read_ph(); // Lee y guarda el pH
        Serial.print("Lectura ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(_phReadings[i]);
        delay(SAMPLE_INTERVAL); // Espera el intervalo de muestreo
    }
}
