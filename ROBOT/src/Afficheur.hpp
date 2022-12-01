#ifndef AFFICHEUR_HPP
#define AFFICHEUR_HPP
#include "rgb_lcd.h"
#include "Couleur.hpp"

class Afficheur {

    public :
        void begin();
        void afficherScore(int score);
        void afficherInfo(char texte[]);
        void changerCouleur(Couleur color);

    private :
        rgb_lcd lcd;


};

#endif