// #include "DataProcessor.h"

// // Crear instancia de DataProcessor
// DataProcessor processor;

// void setup() {
//     Serial.begin(9600); // Inicializar comunicación serial

//     // Configurar el pin del sensor (suponiendo un sensor analógico en A0)
//     pinMode(A0, INPUT);
// }

// void loop() {
//     // Leer el valor del sensor
//     float sensorValue = analogRead(A0); 

//     // Añadir el dato al procesador
//     processor.addData(sensorValue);

//     // Verificar si se han acumulado 20 datos
//     if (processor.getDataCount() >= 20) {
//         // Calcular el promedio sin los cuartiles extremos
//         float average = processor.getAverage();

//         // Imprimir el promedio en el monitor serial
//         Serial.print("El promedio sin los cuartiles es: ");
//         Serial.println(average);

//         // Reiniciar el contador de datos para comenzar de nuevo
//         processor.reset();
//     }

//     // Espera un tiempo antes de tomar otro dato, ajustable según la velocidad deseada
//     delay(1000); // Espera 1 segundo
// }
