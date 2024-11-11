#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <Arduino.h>

class DataProcessor {
public:
    DataProcessor(int len){
        //pegar el cpp
    }         // Constructor
    void addData(float value); // Añadir un dato
    float getAverage();        // Calcular y devolver el promedio
    int getDataCount();        // Obtener el número de datos almacenados
    void reset();              // Reiniciar el almacenamiento de datos

private:
    float data[20]; 
    int _len;           // Array para almacenar hasta 20 datos
    int dataCount;             // Contador de datos almacenados
    void sortData();           // Ordenar el array
    float calculateAverage();  // Calcular el promedio sin cuartiles
};

#endif

//crear el main