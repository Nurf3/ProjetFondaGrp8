//
// Created by Teerath on 13/11/2018.
//

#ifndef __ARDUINO_CARDIO_H__
#define __ARDUINO_CARDIO_H__
#include <Arduino.h>
#include <coeur.h>
#include "C:\Program Files (x86)\Arduino\libraries\gene_code\src\param.h"

//initialisation de la class cardio qui permet l'utilisation des fonctions et des variables interne de cette librairie
class cardio
{
  public:									//fonctions et variables utilisables par les autres fichiers
    void mesure(int temps);					//fonction de mesure du battement cardiaque
    float calcul_pouls(float compte);		//fonction de calcul du pouls
  private:									//fonctions et variables interne à cette librairie
    float valeur;							//valeur lu par l'arduino au pin A0
	float temporaire;						//différence de temps entre deux battements
};

#endif //ARDUINO_CARDIO_H