#ifndef BRAS_HPP
#define BRAS_HPP
#include<Servo.h>

    class Bras{

        private:
            int brocheServo;
            int brocheOhmmetre;
            int resistanceMesurer;
            Servo servo;
        
        public:
            Bras(int brocheServo, int brocheOhmmetre);
            void sortirPousser();
            int sortirMesurer();
            void rentrer();
            void initialisation();
    };

#endif