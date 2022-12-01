#include "BaseRoulante.hpp"
#include "telemetreIR.hpp"
#include <AccelStepper.h>

// The X Stepper pins
const int STEPPER1_DIR_PIN {7};
const int STEPPER1_STEP_PIN {6};
const int STEPPER1_ENABLE_PIN {8};
// The Y stepper pins
const int STEPPER2_DIR_PIN {4};
const int STEPPER2_STEP_PIN {5};
const int STEPPER2_ENABLE_PIN {12};

DetectionObstacle telemetre(A0,A1,A2,A3);


BaseRoulante::BaseRoulante()
    :stepper1(AccelStepper::DRIVER, STEPPER1_STEP_PIN, STEPPER1_DIR_PIN, false),
     stepper2(AccelStepper::DRIVER, STEPPER2_STEP_PIN, STEPPER2_DIR_PIN, false)
{
    stepper1.setPinsInverted(false,false,true);
    stepper1.setEnablePin(STEPPER1_ENABLE_PIN); // stepper1 = moteur droit par rapport a la carte
    stepper1.setMaxSpeed(200.0);
    stepper1.setAcceleration(700.0);
    
    stepper2.setPinsInverted(false,false,true);
    stepper2.setEnablePin(STEPPER2_ENABLE_PIN); // stepper2 = moteur gauche par rapport a la carte il doit avoir - pour avancer
    stepper2.setMaxSpeed(200.0);
    stepper2.setAcceleration(700.0);
    
}

void BaseRoulante::tournerGauche90 (){
    stepper1.move(142.5);
    stepper2.move(142.5);

    while(stepper1.distanceToGo() != 0 and stepper2.distanceToGo() != 0){
        stepper1.run();
        stepper2.run();
    }
}

void BaseRoulante::tournerGauche45 (){
    stepper1.move(71.5);
    stepper2.move(71.5);

    while(stepper1.distanceToGo() != 0 and stepper2.distanceToGo() != 0){
        stepper1.run();
        stepper2.run();
    }
}

void BaseRoulante::tournerDroite90 (){
    stepper1.move(-141.2);
    stepper2.move(-141.5);

    while(stepper2.distanceToGo() != 0 and stepper1.distanceToGo() != 0){
        stepper1.run();
        stepper2.run();
    }
}
void BaseRoulante::tournerDroite45 (){
    stepper1.move(-71.5);
    stepper2.move(-71.5);

    while(stepper2.distanceToGo() != 0 and stepper1.distanceToGo() != 0){
        stepper1.run();
        stepper2.run();
    }
}

void BaseRoulante::avancer (int mm){
    int pas {0};
    pas = mm/1.318;

    stepper1.move(-pas);
    stepper2.move(pas);

    while(stepper2.distanceToGo() != 0 and stepper1.distanceToGo() != 0){
        while(!telemetre.avancePossible()){
        }
        stepper1.run();
        stepper2.run();
    }
}

void BaseRoulante::reculer (int mm){
    int pas {0};
    pas = mm/1.318;

    stepper1.move(pas);
    stepper2.move(-pas);

    while(stepper2.distanceToGo() != 0 and stepper1.distanceToGo() != 0){
        while(!telemetre.reculerPossible()){
        }
        stepper1.run();
        stepper2.run();
    }
}

void BaseRoulante::arreter () {
    stepper1.move(0);
    stepper2.move(0);

    while(stepper2.distanceToGo() != 0){
        stepper1.run();
        stepper2.run();
    }
}

void BaseRoulante::desactiverDetection(){
  telemetre.desactiver();
}

/*void BaseRoulante::aller (int x_, int y_, int a_){
int x {200};
int y {700};
int a {0};

x= x_-x;
y= y_-y;

if (x<0) {
    x=(x*-1);
}
if (y<0) {
    y=y*(-1);
}

avancer(x);

if (a_ == 0) {
    if (a == 0) {
    }
    else if (a == 90) {
        tournerGauche();
    }
    else if (a == -90) {
        tournerDroite();
    }
    else if (a == 180) {
        tournerDroite();
        tournerDroite();
    }
}

if (a_ == 90) {
    if (a == 0) {
        tournerGauche();
    }
    else if (a == 90) {
    }
    else if (a == -90) {
        tournerDroite();
        tournerDroite();
    }
    else if (a == 180) {
        tournerGauche();
    }
}

if (a_ == -90) {
    if (a == 0) {
        tournerDroite();
    }
    else if (a == 90) {
        tournerDroite();
        tournerDroite();
    }
    else if (a == -90) {
    }
    else if (a == 180) {
        tournerGauche();
    }
}

if (a_ == 180) {
    if (a == 0) {
        tournerDroite();
        tournerDroite();
    }
    else if (a == 90) {
        tournerDroite();
    }
    else if (a == -90) {
        tournerGauche();
    }
    else if (a == 180) {
    }
}

avancer(y);
}
*/


//131.8 cm 0.1318 cm par pas donc 1.318 mm par pas 
// pour 1000 pas 1318 mm parcouru

