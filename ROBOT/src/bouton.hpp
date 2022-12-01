#ifndef BOUTON_HPP
#define BOUTON_HPP
#include "Couleur.hpp"

class BoutonCouleur{

    private :
        int brocheBoutonCouleur;
        Couleur couleurEquipe;
        int GND;


    public :
        BoutonCouleur(int broche);

        Couleur getCouleurEquipe();
        
        void setCouleurEquipe();

        BoutonCouleur(int GND, int bouton);
    
};


#endif