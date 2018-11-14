#include "src/param.h"
#include "coeur.h"

//
int coeurs = 1;
//

void coeur1()
{
    //
    for (int i = 2; i <= 11; i++)
    {
        pinMode(i, OUTPUT);
    }
    //
    int i = 2;

    while (coeurs == 1)
    {
        if (i <= 11)
        {
            digitalWrite(i, HIGH);
            i++;
        }
    }
    for (int i = 2; i <= 11; i++)
    {
        digitalWrite(i, LOW);
    }
}

void coeur2()
{
    //
    for (int i = 2; i <= 11; i++)
    {
        pinMode(i, OUTPUT);
    }
    //
    int i = 2;

    while (coeurs == 1)
    {
        if (i <= 11)
        {
            digitalWrite(i, HIGH);
            i += 2;
        }
    }
    for (int i = 2; i <= 11; i++)
    {
        digitalWrite(i, LOW);
    }
}

void coeur3()
{
    //
    for (int i = 2; i <= 11; i++)
    {
        pinMode(i, OUTPUT);
    }
    //
    int i = 2;

    while (coeurs == 1)
    {
        if (i <= 11)
        {
            digitalWrite(i, HIGH);
            i += 3;
        }
    }
    for (int i = 2; i <= 11; i++)
    {
        digitalWrite(i, LOW);
    }
}

void coeur4()
{
    int i = 2;
    int tour = 1;
    while (coeurs == 1)
    {
        if (tour == 1)
        {
            if (i <= 11)
            {
                digitalWrite(i, HIGH);
                tour = 0;
            }
            else
                i = 0;
        }
    }
    digitalWrite(i, LOW);
    i++;
    tour = 1;
}

void coeur5()
{
    int i = 2;
    int j = 3;
    int tour = 1;
    while (coeurs == 1)
    {
        if (tour == 1)
        {
            if (i <= 11 && j <= 11)
            {
                digitalWrite(i, HIGH);
                digitalWrite(j, HIGH);
                delay(100);
                digitalWrite(i, LOW);
                i++;
                j++;
                tour = 0;
            }
        }
        tour = 1;
    }
}
