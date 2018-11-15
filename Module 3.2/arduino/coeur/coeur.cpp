//
// Created by Lucien KLEIN on 13/11/2018.
//

#include "C:\Program Files (x86)\Arduino\libraries\gene_code\src\param.h"
#include "coeur.h"

/*-----------------------------------------Definition Fonction LEDs------------------------------------------------*/

//Allumer toutes les LEDs à chaque battement
void coeur::coeur1()
{
    for (i = 2; i <= 11; i++)
    {
        digitalWrite(i, HIGH);
    }
}

// Eteindre toutes les LEDs
void coeur::coeur1_low()
{
    for (i = 2; i <= 11; i++)
    {
        digitalWrite(i, LOW);
    }
}

//Allumer une LED sur deux à chaque battement
void coeur::coeur2()
{
    for (i = 2; i <= 11; i += 2)
    {
        digitalWrite(i, HIGH);
    }
}

//Eteindre toutes les LEDs allumées
void coeur::coeur2_low()
{
    for (i = 2; i <= 11; i += 2)
    {
        digitalWrite(i, LOW);
    }
}

//Allumer une LED sur trois à chaque battement
void coeur::coeur3()
{
    for (i = 2; i <= 11; i += 3)
    {
        digitalWrite(i, HIGH);
    }
}

//Eteindre toutes les LEDs allumées
void coeur::coeur3_low()
{
    for (i = 2; i <= 11; i += 3)
    {
        digitalWrite(i, LOW);
    }
}

//Allumer les LEDs en mode chenille à chaque battement
void coeur::coeur4()
{
    //Eteindre la LED(port i), incrémenter i puis allumer la LED suivante (port i)
    if (i < 11)
    {
        digitalWrite(i, LOW);
        i++;
        digitalWrite(i, HIGH);
    }

    //Lorsque on a fait le tour du coeur, éteindre la dernier LED (port 11)
    //Remettre la variable i à 2
    //Puis allumer la première LED (port 2)
    else
    {
        digitalWrite(11, LOW);
        i = 2;
        digitalWrite(i, HIGH);
    }
}

//Allumer les LEDs en mode chenille avec un fondu à chaque battement
void coeur::coeur5()
{
    //Allumer les LEDs (port i et j)
    //Mettre une pause pour un meilleur effet de transition
    //Eteindre la LED précédente (port i)
    //Incrémenter i & j
    if (i <= 11 && j <= 11)
    {
        digitalWrite(i, HIGH);
        digitalWrite(j, HIGH);
        delay(100);
        digitalWrite(i, LOW);
        i++;
        j++;
    }

    //Si i a fait le tour, remettre i à la position du début du coeur (port 2)
    //Puis programme normale
    else if (i > 11)
    {
        i = 2;
        digitalWrite(i, HIGH);
        digitalWrite(j, HIGH);
        delay(100);
        digitalWrite(i, LOW);
        i++;
        j++;
    }

    //Si j a fait le tour, remettre j à la position du début du coeur (port2)
    //Puis programme normale
    else if (j > 11)
    {
        j = 2;
        digitalWrite(i, HIGH);
        digitalWrite(j, HIGH);
        delay(100);
        digitalWrite(i, LOW);
        i++;
        j++;
    }
}

//Allumer une LED sur deux (en mode alternatif) à chaque battement
void coeur::coeur6()
{
    if (tour == 0)
    {
        for (i = 2; i <= 11; i += 2)
        {
            digitalWrite(i, HIGH);
        }
    }
    else
    {
        for (i = 3; i <= 11; i += 2)
        {
            digitalWrite(i, HIGH);
        }
    }
}

//Eteindre toutes les LEDs allumées
void coeur::coeur6_low()
{
    if (tour == 0)
    {
        for (i = 2; i <= 11; i += 2)
        {
            digitalWrite(i, LOW);
        }
        tour = 1;
    }
    else
    {
        for (i = 3; i <= 11; i += 2)
        {
            digitalWrite(i, LOW);
        }
        tour = 0;
    }
}

//Allumer en mode chenille accélérer
void coeur::coeur7()
{
    for (i = 2; i <= 11; i++)
    {
        digitalWrite(i, HIGH);
        delay(20);
        digitalWrite(i, LOW);
    }
}
