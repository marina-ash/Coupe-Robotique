#include "Electroaimant.hpp"
#include "Arduino.h"


Electroaimant::Electroaimant(int broche) 
    : brocheElectroaimant (broche)
    {
        pinMode(brocheElectroaimant, OUTPUT);
    }
    

void Electroaimant::activer() {

    digitalWrite(brocheElectroaimant, HIGH);

}

void Electroaimant::desactiver() {

    digitalWrite(brocheElectroaimant,LOW);
    
}

bool Electroaimant::estActif() {

    return digitalRead(brocheElectroaimant);
    

}
