#include <Arduino.h>
#include "Trappe.hpp"

Trappe::Trappe(int brocheServo)
  : brocheServo(brocheServo) {
}

void Trappe::init(){
  pinMode(LED_BUILTIN, OUTPUT);
  myservo.attach(brocheServo);
}

void Trappe::ouvrir() {
  
  myservo.write(120);
  digitalWrite(LED_BUILTIN, HIGH);
}

void Trappe::fermer(){
  
  myservo.write(180);
  digitalWrite(LED_BUILTIN, LOW);
}