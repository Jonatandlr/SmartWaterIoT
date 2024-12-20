#include "Conductivity.h"

Conductivity::Conductivity() : _myserial(2) {
}

void Conductivity::begin() {
    _myserial.begin(9600, SERIAL_8N1, _RXD2, _TXD2);
}


float Conductivity::getConductivity() {
    while (!_sensorStringComplete)
    {   
        // Serial.println("while");
        if (_myserial.available() > 0) {
            char inchar = (char)_myserial.read();
            _sensorData += inchar;
            if (inchar == '\r') {
                _sensorStringComplete = true;
            }
        }
    }
    // Serial.println("aqui ando");
    _sensorStringComplete = false;
    float sensorValue = _sensorData.toFloat();
    _sensorData = "";
    return sensorValue;
}
