//
// Created by Teerath on 13/11/2018.
//

#include "cardio.h"

coeur coeur2;

void cardio::mesure(int temps) {
	
    float valeur = (analogRead(0) * 5.0) / 1023.0;

    while(valeur >= 2.5) {
        valeur = (analogRead(0) * 5.0) / 1023.0;
    }
	
	if(choix == 1) {
		coeur2.coeur1_low();
	} else if(choix == 2) {
		coeur2.coeur2_low();
	} else if(choix == 3) {
		coeur2.coeur3_low();
	}
	
	while(valeur < 2.5) {
        valeur = (analogRead(0) * 5.0) / 1023.0;
    }
	
	float temporaire = millis() - temps;
	temporaire = temporaire / 1000;
	
	if(choix == 1) {
		coeur2.coeur1();
	} else if(choix == 2) {
		coeur2.coeur2();
	} else if(choix == 3) {
		coeur2.coeur3();
	} else if(choix == 4) {
		coeur2.coeur4();
	} else {
		coeur2.coeur5();
	}
	
	Serial.print(calcul_pouls(temporaire),0);
	Serial.print(";");
	Serial.println(millis());
	
	/*Serial.print("DATA,TIME,");
	Serial.print(millis());
	Serial.print(",");
	Serial.println(calcul_pouls(temporaire),0);
    */
	
    return;
}


float cardio::calcul_pouls(float compte) {
    return 60 / compte;
}