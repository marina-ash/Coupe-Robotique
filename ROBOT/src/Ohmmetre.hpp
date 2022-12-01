#ifndef OHMMETRE_HPP
#define OHMMETRE_HPP

class Ohmmetre 
{
    public:
        int mesurerResistance ();
        Ohmmetre(int brocheOhmmetre, int tensionEntree, int resistanceFix, int resistancePin);
        
    private:
        int brocheOhmmetre;
        int tensionEntree;
        int resistanceFix;
        int resistancePin;
};

#endif