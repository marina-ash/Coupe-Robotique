#include "Arduino.h"
#include "Ohmmetre.hpp"


Ohmmetre::Ohmmetre(int brocheOhmmetre, int tensionEntree, int resistanceFix, int resistancePin)
    :brocheOhmmetre(brocheOhmmetre), tensionEntree(tensionEntree), resistanceFix(resistanceFix), resistancePin(resistancePin)
{
    //implémentation
}

int Ohmmetre::mesurerResistance()
{
    unsigned int  resistanceInconnue = analogRead(resistancePin); 
    double tensionSortie = resistanceInconnue * 5.0 / 1023; //Pour obtenir la tension de sortie 
    resistanceInconnue = resistanceFix * tensionSortie / (tensionEntree - tensionSortie); //pour obtenir la valeur de la R2

    return resistanceInconnue;
}

