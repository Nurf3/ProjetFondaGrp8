#include "C:\Program Files (x86)\Arduino\libraries\gene_code\src\param.h"
#include "coeur.h"

//

//

//Definition des 5 fonctions

void coeur::coeur1()
{
    for (i = 2; i <= 11; i++)
    {
        digitalWrite(i, HIGH);
    }
}

void coeur::coeur1_low() {
	for (i = 2; i <= 11; i++)
    {
        digitalWrite(i, LOW);
    }
}

void coeur::coeur2()
{
    for (i = 2; i <= 11; i += 2)
    {
        digitalWrite(i, HIGH);
    }
}

void coeur::coeur2_low()
{
    for (i = 2; i <= 11; i += 2)
    {
        digitalWrite(i, LOW);
    }
}

void coeur::coeur3()
{
    for (i = 2; i <= 11; i += 3)
    {
        digitalWrite(i, HIGH);
    }
}

void coeur::coeur3_low()
{
    for (i = 2; i <= 11; i += 3)
    {
        digitalWrite(i, LOW);
    }
}

void coeur::coeur4()
{
    if (i < 11)
    {
		digitalWrite(i, LOW);
		i++;
        digitalWrite(i, HIGH);
    } else {
        digitalWrite(11, LOW);
		i = 2;
        digitalWrite(i, HIGH);
    }
    
}

void coeur::coeur5()
{
    if (i <= 11 && j <= 11)
    {
        digitalWrite(i, HIGH);
        digitalWrite(j, HIGH);
        delay(100);
        digitalWrite(i, LOW);
        i++;
        j++;
    }	else if (i > 11)    {
        i = 2;
        digitalWrite(i, HIGH);
        digitalWrite(j, HIGH);
        delay(100);
        digitalWrite(i, LOW);
        i++;
        j++;
    }    else if (j > 11)    {
        j = 2;
        digitalWrite(i, HIGH);
        digitalWrite(j, HIGH);
        delay(100);
        digitalWrite(i, LOW);
        i++;
        j++;
    }
}