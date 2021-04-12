#include <Arduino.h>
#include <VirtualTester.h>

void setup() {
  // put your setup code here, to run once:
  VirtualTester.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  VirtualTester.task();
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}