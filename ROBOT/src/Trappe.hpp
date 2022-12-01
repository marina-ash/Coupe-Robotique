#ifndef TRAPPE_HPP 
#define TRAPPE_HPP

#include <Servo.h>

class Trappe {

    public:
        Trappe(int brocheServo);
        void init();
        void ouvrir();
        void fermer();
        bool estOuverte();
      
    private:
        int brocheServo;
        bool trappeOuverte;
        Servo myservo;  

};

#endif