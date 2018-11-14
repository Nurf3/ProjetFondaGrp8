#include <Arduino.h>
#include <cardio.h>
#include <coeur.h>


cardio cardio;
coeur coeur;

void setup() {
    Serial.begin(128000);
    //Serial.println("CLEARDATA");
    int choix = 1;

    for(int o = 2; o<= 11; o++) {
      pinMode(o, OUTPUT);
    }
}

void loop() {
    int temps = millis();
    cardio.mesure(temps);
}
