#ifndef MULTITAXEL_H
#define MULTITAXEL_H

class AnalogClass {
public:
    void analogInput(int pin1, int pin2, int pin3, int pin4, int analogValues[4]);
};

class BitsClass {
    const int threshold = 200;
public:
    AnalogClass analogArray;
    int* digitalOutput(int analogValues[4]);
};

#endif // MULTITAXEL_H