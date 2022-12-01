#include "Tirette.hpp"
#include "Arduino.h"
//constructeur
//nom méthode, nom classe
Tirette::Tirette(int broche) 
    : brocheTirette (broche){

    pinMode(brocheTirette,INPUT_PULLUP);
}

Tirette::Tirette(int GND, int tirette)
    : brocheGND (GND), brocheTirette(tirette){

    pinMode(brocheTirette,INPUT_PULLUP);
    pinMode(GND,OUTPUT);
    digitalWrite(GND,LOW);
    
    }

//methode qui envoie vrai ou faux si presente
bool Tirette::estPresente() {
    
    if (digitalRead (brocheTirette) == LOW ){
        
        return true;
    }
    else {
        return false;
    }
}