#include "coeur.h"

//
int i = 2;
int j = 3;
//

//Definition des 5 fonctions

void coeur1()
{
    for (i = 2; i <= 11; i++)
    {
        digitalWrite(i, HIGH);
    }
}

void coeur2()
{
    for (i = 2; i <= 11; i += 2)
    {
        digitalWrite(i, HIGH);
    }
}

void coeur3()
{
    for (i = 2; i <= 11; i += 3)
    {
        digitalWrite(i, HIGH);
    }
}

void coeur4()
{
    if (i <= 11)
    {
        digitalWrite(i, HIGH);
    }

    else
    {
        i = 2;
        digitalWrite(i, HIGH);
    }
    i++;
}

void coeur5()
{

    if (i <= 11 && j <= 11)
    {
        digitalWrite(i, HIGH);
        digitalWrite(j, HIGH);
        delay(50);
        digitalWrite(i, LOW);
        i++;
        j++;
    }

    else if (i > 11)
    {
        int i = 2;
        digitalWrite(i, HIGH);
        digitalWrite(j, HIGH);
        delay(50);
        digitalWrite(i, LOW);
        i++;
        j++;
    }

    else if (j > 11)
    {
        int j = 2;
        digitalWrite(i, HIGH);
        digitalWrite(j, HIGH);
        delay(50);
        digitalWrite(i, LOW);
        i++;
        j++;
    }
}
