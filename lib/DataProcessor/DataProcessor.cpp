#include "DataProcessor.h"

DataProcessor::DataProcessor() {
    _len=10;
    dataCount = 0; // Inicializamos el contador de datos a cero
    data [_len];
}

void DataProcessor::addData(float value) {
    if (dataCount < _len) {
        data[dataCount++] = value; // Añadimos el dato y aumentamos el contador
    }
}

int DataProcessor::getDataCount() {
    return dataCount; // Retorna el número actual de datos
}

void DataProcessor::reset() {
    dataCount = 0; // Reinicia el contador de datos
}

void DataProcessor::sortData() {
    for (int i = 0; i < dataCount - 1; i++) {
        for (int j = 0; j < dataCount - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                float temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

float DataProcessor::calculateAverage() {
    if (dataCount < 4) {
        float sum = 0;
        for (int i = 0; i < dataCount; i++) {
            sum += data[i];
        }
        return sum / dataCount;
    }
    
    sortData();
    
    int lowerQuartileIndex = dataCount / 4;
    int upperQuartileIndex = dataCount - lowerQuartileIndex;
    float sum = 0;
    int count = 0;

    for (int i = lowerQuartileIndex; i < upperQuartileIndex; i++) {
        sum += data[i];
        count++;
    }

    return sum / count;
}

float DataProcessor::getAverage() {
    return calculateAverage(); // Llama al cálculo del promedio
}
