#include <Arduino.h>
#include <cardio.h>
#include <coeur.h>


cardio cardio;                        //setup le nom à utiliser pour la librairie cardio
coeur coeur;                          //setup le nom à utiliser pour la librairie coeur (voir bloc 2)

void setup() {
    Serial.begin(128000);             //initialise le moniteur série
    //Serial.println("CLEARDATA");    //clear pour le programme PLX-DAQ

    //initialise tout les pin des LED (de 2 à 11)
    for(int o = 2; o<= 11; o++) {
      pinMode(o, OUTPUT);
    }
}

void loop() {
    int temps = millis();              //prend le temps actuel
    cardio.mesure(temps);              //mesure le pouls
}
