#include"telemetreIR.hpp"

DetectionObstacle::DetectionObstacle(int brocheAVD, int brocheAVG, int brocheARG, int brocheARD)
 : telemetreAVD(SharpIR::GP2Y0A21YK0F, brocheAVD), telemetreAVG(SharpIR::GP2Y0A21YK0F, brocheAVG), telemetreARD(SharpIR::GP2Y0A21YK0F, brocheARG), telemetreARG(SharpIR::GP2Y0A21YK0F, brocheARD) {
} 

bool DetectionObstacle::avancePossible(){

    mesureDistance1 = telemetreAVD.getDistance();
    mesureDistance2 = telemetreAVG.getDistance();

    if (actif == false){
        return true;
    }


    if ((mesureDistance1 > distMiniPourDepl) and ( mesureDistance2 > distMiniPourDepl)) {
        //Programme pour avancer
        return true;
    }

    else {

        return false;
    }

}

bool DetectionObstacle::reculerPossible(){
    mesureDistance1 = telemetreARD.getDistance();
    mesureDistance2 = telemetreARG.getDistance();

    if (actif == false){
        return true;
    }

    if ((mesureDistance1 > distMiniPourDepl) and ( mesureDistance2 > distMiniPourDepl)) {
        //Programme pour reculer
        return true;
    }

    else {

        return false;
    }

}

bool DetectionObstacle::tournerDroitePossible(){
    mesureDistance1 = telemetreAVD.getDistance();  
    mesureDistance2 = telemetreAVG.getDistance();

    if (actif == false){
        return true;
    }

    if ((mesureDistance1 > distMiniPourDepl) and ( mesureDistance2 < distMiniPourDepl)) {
        //Programme pour tourner à droite
        return true;
    }

    else {
        //Programme pour avancer 
        return false;
    }
}

bool DetectionObstacle::tournerGauchePossible(){
    mesureDistance1 = telemetreAVD.getDistance();  
    mesureDistance2 = telemetreAVG.getDistance();

    if (actif == false){
        return true;
    }

    if ((mesureDistance1 < distMiniPourDepl) and ( mesureDistance2 > distMiniPourDepl)) {
        //Programme pour tourner à gauche
        return true;
    }

    else {
        //Programme pour avancer 
        return false;
    }
}

void DetectionObstacle::desactiver(){

    actif = false;
}