#include <Arduino.h>
#include "multitaxel.h" // Inclui a classe que irá converter o nível de pressão para valores lógicos
#include <TimerOne.h>

#define IN_A0 A0
#define IN_A1 A1
#define IN_A2 A2
#define IN_A3 A3


bool flagInit = false; // Define uma flag para inicialização

void verifySerialPort();
void Timer1_ISR();


void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial com uma taxa de 9600 bauds
  pinMode(IN_A0, INPUT); // Define o pino A0 como entrada
  pinMode(IN_A1, INPUT); // Define o pino A1 como entrada
  pinMode(IN_A2, INPUT); // Define o pino A2 como entrada
  pinMode(IN_A3, INPUT); // Define o pino A3 como entrada
  
  Timer1.initialize(1000000); // Fire An Interrupt Every 1000ms
  Timer1.attachInterrupt(Timer1_ISR);
  Timer1.start();
  }

void loop() {
  verifySerialPort(); // Verifica a porta serial
  delay(10); // Pequeno atraso no loop principal para permitir a leitura correta
}

void verifySerialPort() {
  while (Serial.available() > 0) 
  {
    delay(100);
    if (Serial.available())
    { 
      byte c = Serial.read(); 
      Serial.println(c);
      if (c == 65) // Verifica se o caractere recebido é 'A'
      {  
        flagInit = !flagInit; // Ativa a flag caso meu programa de leitura envie 'A'
      }
    }
  }
}

void Timer1_ISR() {
  if (flagInit) {
    int a0 = analogRead(IN_A0);
    int a1 = analogRead(IN_A1);
    int a2 = analogRead(IN_A2);
    int a3 = analogRead(IN_A3);
    Serial.print(a0);
    Serial.print(",");
    Serial.print(a1);
    Serial.print(",");
    Serial.print(a2);
    Serial.print(",");
    Serial.println(a3);
  }
}