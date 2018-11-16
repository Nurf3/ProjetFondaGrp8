//
// Created by Teerath on 13/11/2018.
//

#include "cardio.h" //inclus le header cardio.h

coeur coeur2; //setup le nom à utiliser pour la librairie coeur (voir bloc 2)

//Fonction qui mesure la différence de temps entre deux battements pour ensuite envoyer cette valeur dans la fonction calcul_pouls
//Cette fonction s'occupe également de l'animation du coeur en fonction du rythme cardiaque
//Cette fonction prend en paramètre la variable temps, qui est égal au temps lors du dernier battement
void cardio::mesure(int temps)
{

	float valeur = (analogRead(0) * 5.0) / 1023.0; //Fais une table de trois pour convertir la valeur analogique lue en volt

	//tant que le voltage lu est supérieur à 2.5V :
	while (valeur >= 2.5)
	{
		valeur = (analogRead(0) * 5.0) / 1023.0;
	}

	//Le choix est lu dans le fichier param.h grâce à une variable globale
	switch (choix)
	{
	case 1:
		coeur2.coeur1_low(); //allume les LED pour le choix 1
		break;

	case 2:
		coeur2.coeur2_low();
		break;

	case 3:
		coeur2.coeur3_low();
		break;

	case 6:
		coeur2.coeur6_low();
		break;

	default:
		Serial.println("Erreur de choix");
		break;
	}

	//tant que le voltage lu est inférieure à 2.5V :
	while (valeur < 2.5)
	{
		valeur = (analogRead(0) * 5.0) / 1023.0;
	}

	float temporaire = millis() - temps; //la variable temporaire prend la valeur du temps actuel - le temps au dernier battement
	temporaire = temporaire / 1000;		 //on convertit les millisecondes en secondes

	//Le choix est lu dans le fichier param.h grâce à une variable globale
	switch (choix)
	{
	case 1:
		coeur2.coeur1(); //allume les LED pour le choix 1
		break;

	case 2:
		coeur2.coeur2();
		break;

	case 3:
		coeur2.coeur3();
		break;

	case 4:
		coeur2.coeur4();
		break;

	case 5:
		coeur2.coeur5();
		break;

	case 6:
		coeur2.coeur6();
		break;

	case 7:
		coeur2.coeur7();
		break;

	default:
		Serial.println("Erreur de choix");
		break;
	}

	//permet la lecture de données pour le programme sur processing
	Serial.print(calcul_pouls(temporaire), 0);
	Serial.print(";");
	
	secondes = millis()/1000; //convect millisecondes en secondes
	minutes=secondes/60; //convertir secondes en minutes
	heures=minutes/60; //convertir minutes en heures

	secondes=secondes-(minutes*60); // soustraire les secondes converties afin d'afficher 59 secondes max
	minutes=minutes-(heures*60);    //soustraire les minutes converties afin d'afficher 59 minutes max
	Serial.print(heures);
	Serial.print(":");
	Serial.print(minutes);
	Serial.print(":");
	Serial.println(secondes);

	//permet la lecture de données pour le programme PLX-DAQ
	/*Serial.print("DATA,TIME,");
	Serial.print(millis());
	Serial.print(",");
	Serial.println(calcul_pouls(temporaire),0);
    */

	return;
}

//calcul le pouls
float cardio::calcul_pouls(float compte)
{
	return 60 / compte;
}
