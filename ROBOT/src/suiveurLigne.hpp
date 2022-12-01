#ifndef SUIVEURLIGNE_HPP
#define SUIVEURLIGNE_HPP
#include <QTRSensors.h>

class SuiveurLigne{

    public :
        SuiveurLigne(int brocheCapteur1, int brocheCapteur2);

        bool devieG();

        bool devieD();

        void setVersAV();
        
        int brocheCapteur1;
        int brocheCapteur2;
        QTRSensors qtr; 
};

#endif