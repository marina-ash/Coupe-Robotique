#include "Afficheur.hpp"
#include "Arduino.h"
#include "Couleur.hpp"


void Afficheur::begin() {

  lcd.begin(16, 2);
}

void Afficheur::afficherScore(int score) {

  lcd.setCursor(0,0);
  lcd.print(score);

}

void Afficheur::afficherInfo(char texte[]) {

  lcd.setCursor(0,1);
  lcd.print(texte);

}

void Afficheur::changerCouleur(Couleur color) {
  
  
  if (color == Couleur::violet) {

    const byte colorR = 255;
    const byte colorG = 0;
    const byte colorB = 230;

    lcd.setRGB(colorR, colorG, colorB);
  }
  
  if (color == Couleur::jaune) {
    
    const byte colorR = 255;
    const byte colorG = 150;
    const byte colorB = 0;

    lcd.setRGB(colorR, colorG, colorB);
  }
}
