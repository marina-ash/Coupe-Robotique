#ifndef TIRETTE_HPP
#define TIRETTE_HPP



class Tirette {
private://atribut
   
   //quelle type d'atribut
    int brocheTirette;
    int brocheGND;
    
public:
    //methode (parametre)
    Tirette(int broche);
    
    bool estPresente();

    Tirette(int GND, int tirette);

};
#endif 