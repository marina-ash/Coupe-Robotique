#include <Arduino.h>
#include <MsTimer2.h>
#include"Afficheur.hpp"
#include"BaseRoulante.hpp"
#include"bouton.hpp"
#include"bras.hpp"
#include"Couleur.hpp"
#include"Electroaimant.hpp"
#include"suiveurLigne.hpp"
#include"Tirette.hpp"
#include"Trappe.hpp"
#include"telemetreIR.hpp"


Tirette tirette(2);
BoutonCouleur boutonCouleur(0);
Electroaimant aimant(9);
Electroaimant aimant2(11);
BaseRoulante baseRoulante;
Trappe trappe(10);
Afficheur afficheur;
//DetectionObstacle detectionObstacle(A0,A1,A2,A3);

int score {4};
int temps {0};

void veriFiniMatch(){
    temps++;
    if (temps == 99){
        while (true){

        }
    }
}

void setup() {

    afficheur.begin();
    trappe.init();
    trappe.fermer();
    

    while(!tirette.estPresente()){

    }
    while(tirette.estPresente()){
        boutonCouleur.setCouleurEquipe();
        afficheur.changerCouleur(boutonCouleur.getCouleurEquipe());
    }

    MsTimer2::set(1000,veriFiniMatch); 
    MsTimer2::start();
    afficheur.afficherScore(score);


    if (boutonCouleur.getCouleurEquipe() == Couleur::violet) {
        baseRoulante.avancer(290); 
        baseRoulante.tournerGauche90();
        baseRoulante.avancer(779);
        baseRoulante.tournerGauche45();
        aimant.activer();
        aimant2.activer();
        afficheur.afficherInfo("Aimant Actif"); 
        baseRoulante.avancer(260);
        delay(1000);
        baseRoulante.reculer(50);
        score = score+5;
        afficheur.afficherScore(score);
        delay(1000);
        baseRoulante.tournerDroite90();
        baseRoulante.tournerDroite90();
        baseRoulante.reculer(4);
        trappe.ouvrir();
        afficheur.afficherInfo("Trappe ouverte");
        delay(1000);
        baseRoulante.avancer(30);
        trappe.fermer();
        score = score+10;
        afficheur.afficherScore(score);
        afficheur.afficherInfo("Trappe fermee");
        baseRoulante.avancer(50);
        delay(300);
        baseRoulante.tournerDroite45();
        aimant2.activer();
        aimant.activer();
        delay(300);
        baseRoulante.avancer(1000);
        delay(300);
        baseRoulante.tournerDroite90();
        delay(300);
        baseRoulante.avancer(190);
        delay(300);
        baseRoulante.tournerGauche90();
        delay(300);
        baseRoulante.desactiverDetection();
        baseRoulante.avancer(780);
        delay(500);
        aimant.desactiver();
        aimant2.desactiver();
        afficheur.afficherInfo("Aimant Inactif");
        delay(1000);
        baseRoulante.reculer(700);
        score = score+15;
        afficheur.afficherScore(score);
        score = score+20;
        afficheur.afficherScore(score);
    }

    if (boutonCouleur.getCouleurEquipe() == Couleur::jaune) {
        baseRoulante.avancer(290); 
        baseRoulante.tournerDroite90();
        baseRoulante.avancer(779);
        baseRoulante.tournerDroite45();
        aimant.activer();
        aimant2.activer();
        afficheur.afficherInfo("Aimant Actif"); 
        baseRoulante.avancer(260);
        delay(1000);
        baseRoulante.reculer(50);
        score = score+5;
        afficheur.afficherScore(score);
        delay(1000);
        baseRoulante.tournerGauche90();
        baseRoulante.tournerGauche90();
        baseRoulante.reculer(4);
        trappe.ouvrir();
        afficheur.afficherInfo("Trappe ouverte");
        delay(1000);
        baseRoulante.avancer(30);
        trappe.fermer();
        score = score+10;
        afficheur.afficherScore(score);
        afficheur.afficherInfo("Trappe fermee");
        baseRoulante.avancer(50);
        delay(300);
        baseRoulante.tournerGauche45();
        aimant2.activer();
        aimant.activer();
        delay(300);
        baseRoulante.avancer(1000);
        delay(300);
        baseRoulante.tournerGauche90();
        delay(300);
        baseRoulante.avancer(170);
        delay(300);
        baseRoulante.tournerDroite90();
        delay(300);
        baseRoulante.desactiverDetection();
        baseRoulante.avancer(780);
        delay(500);
        aimant.desactiver();
        aimant2.desactiver();
        afficheur.afficherInfo("Aimant Inactif");
        delay(1000);
        baseRoulante.reculer(700);
        score = score+15;
        afficheur.afficherScore(score);
        score = score+20;
        afficheur.afficherScore(score);
    } 
}

void loop() {
  // put your main code here, to run repeatedly:
}