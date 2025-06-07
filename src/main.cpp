#include <Arduino.h>

const int Delay_ms = 500;

void setup() {
  pinMode(PIN_PD0, OUTPUT);
  pinMode(PIN_PD1, OUTPUT);
  // delay(2000);

  // Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_PD0, HIGH);
  digitalWrite(PIN_PD1, LOW);
  delay(Delay_ms);
  digitalWrite(PIN_PD0, LOW);
  digitalWrite(PIN_PD1, HIGH);
  delay(Delay_ms);

  // Serial.println("Test");
  // delay(10);
}
