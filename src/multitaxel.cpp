#include "multitaxel.h"

// Implementação da classe AnalogClass
void AnalogClass::analogInput(int pin1, int pin2, int pin3, int pin4, int analogValues[4]) {
    analogValues[0] = pin1;
    analogValues[1] = pin2;
    analogValues[2] = pin3;
    analogValues[3] = pin4;
}

// Implementação da classe BitsClass
int* BitsClass::digitalOutput(int analogValues[4]) {
    static int bitsArray[4] = {0, 0, 0, 0};
    for (int n = 0; n < 4; ++n) {
        if (analogValues[n] < threshold) {
            bitsArray[n] = 1;
        } else {
            bitsArray[n] = 0;
        }
    }
    return bitsArray;
}