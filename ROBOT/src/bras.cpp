#include"bras.hpp"
#include"Arduino.h"
#include <Servo.h>
//#include "Ohmmetre.hpp"//

Bras::Bras(int brocheServo, int brocheOhmmetre): brocheServo(brocheServo),brocheOhmmetre(brocheOhmmetre){

}

void Bras:: initialisation(){
    servo.attach(brocheServo);
}

void Bras:: sortirPousser(){
    servo.write(90);
}

int Bras::sortirMesurer(){
    servo.write(90);
    //mesurer//
    //return la valeur mesurer//
}

void Bras::rentrer(){
    servo.write(0);
}