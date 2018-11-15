//
// Created by Lucien KLEIN on 12/11/2018.
//

#ifndef __ARDUINO_COEUR_H__
#define __ARDUINO_COEUR_H__
#include <Arduino.h>

/*---------------------------------------------Prototype des fonctions LED----------------------------------------*/
class coeur
{
public:
	void coeur1();
	void coeur2();
	void coeur3();
	void coeur4();
	void coeur5();
	void coeur6();
	void coeur7();
	void coeur1_low();
	void coeur2_low();
	void coeur3_low();
	void coeur6_low();

private:
	int i = 2;
	int j = 3;
	int tour = 0;
};

#endif //ARDUINO_COEUR_H