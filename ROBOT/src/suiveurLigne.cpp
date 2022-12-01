#include "suiveurLigne.hpp"
#include <Arduino.h>
#include <QTRSensors.h>

SuiveurLigne::SuiveurLigne(int brocheCapteur1, int brocheCapteur2){

    const int CTRL = A0;
    const int Br1 = A1;
    const int Br3 = A3;
    const int D3 = 3;
    QTRSensors qtr;

    const uint8_t SensorCount = 2;

    pinMode(CTRL, INPUT);
    pinMode(Br1, INPUT);
    pinMode(Br3, INPUT);
    pinMode(D3, OUTPUT); 
  
    Serial.begin(9600);
    qtr.setTypeAnalog();
    qtr.setSensorPins((const uint8_t[]){A1, A3}, SensorCount);
    qtr.setEmitterPin(2);

    for (uint16_t i = 0; i < 400; i++)
    {
        qtr.calibrate();
    }
    digitalWrite(LED_BUILTIN, LOW);

    for (uint8_t i = 0; i < SensorCount; i++)
    {
        Serial.print(qtr.calibrationOn.maximum[i]);
        Serial.print(' ');
    }

    Serial.println();
    delay(1000);

};

bool SuiveurLigne:: devieG(){
    if (brocheCapteur1 == 1000){
        return true;
    }

    else{
        return false;
    }

};

bool SuiveurLigne:: devieD(){
    if (brocheCapteur2 == 1000){
        return true;
    }

    else{
        return false;
    };

};

void SuiveurLigne::setVersAV(){

    const uint8_t SensorCount = 2;
    uint16_t sensorValues[SensorCount];
    uint16_t position = qtr.readLineBlack(sensorValues);
    for (uint8_t i = 0; i < SensorCount; i++){
    Serial.print(sensorValues[i]);
    Serial.print('\t');
    };
    Serial.println(position);

    if(brocheCapteur1 = false, brocheCapteur2 ==false ){
        /* avancer robot*/
    };

    if (brocheCapteur1 = true, brocheCapteur2 == false){
        /* tournerG */
    };

    if (brocheCapteur2 = true, brocheCapteur1 =false){
        /* tourneD */
    };

};