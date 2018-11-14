//
// Created by Teerath on 13/11/2018.
//

#ifndef __ARDUINO_CARDIO_H__
#define __ARDUINO_CARDIO_H__
#include <Arduino.h>
#include <coeur.h>
#include "C:\Program Files (x86)\Arduino\libraries\gene_code\src\param.h"

class cardio
{
  public:
    void mesure(int temps);
    float calcul_pouls(float compte);
  private:
    float valeur;
    float pouls;
	float temporaire;
};

#endif //ARDUINO_CARDIO_H