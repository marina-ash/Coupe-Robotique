#ifndef ELECTROAIMANT_HPP
#define ELECTROAIMANT_HPP

class Electroaimant {

    public :
        Electroaimant(int broche);
        void activer();
        void desactiver();
        bool estActif();

    private :

        int brocheElectroaimant;


};

#endif