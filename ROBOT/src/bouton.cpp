#include "bouton.hpp"
#include <Arduino.h>
#include "Couleur.hpp"

BoutonCouleur::BoutonCouleur(int broche) : brocheBoutonCouleur(broche){

    pinMode(brocheBoutonCouleur,INPUT_PULLUP);
};

BoutonCouleur::BoutonCouleur(int GND, int bouton): GND(GND),brocheBoutonCouleur(bouton){

    pinMode(GND,OUTPUT);
    digitalWrite(GND,LOW);

}

void BoutonCouleur :: setCouleurEquipe(){

    if (digitalRead(brocheBoutonCouleur) == LOW){

        couleurEquipe = Couleur::jaune;
    }
    else{
        couleurEquipe = Couleur::violet;
    }

    //return Couleur couleurEquipe;//
    
}

Couleur BoutonCouleur:: getCouleurEquipe(){

    return couleurEquipe;

}