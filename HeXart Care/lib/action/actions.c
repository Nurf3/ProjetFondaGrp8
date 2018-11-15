#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actions.h"

/*--------------------------------FONCTION AFFICHER DONNEES--------------------------------*/

void AfficherDonnees()
{
    FILE *fp = fopen("Battements.csv", "r+");

    if (fp == NULL){
        fclose(fp);
        exit(1);
    }

    char donnees[100];
    printf("Donnees     Temps\n");
    while (fgets(donnees, 100, fp) != NULL)
    {
        printf("[%d]", atoi(strtok(donnees, ";")));
        printf("\t");
        printf("    [%d]\n", atoi(strtok(NULL, ";")));
    }
    printf("\n");

    fclose(fp);
}

/*--------------------------------FONCTION MAX POULS--------------------------------*/

void MaxPouls()
{
    FILE *fp = fopen("Battements.csv", "r+");

    if (fp == NULL){
        fclose(fp);
        exit(1);
    }

    int max = 0;
    int tps, premiere_colonne, deuxieme_colonne;

    char donnees[100];
    while (fgets(donnees, 100, fp) != NULL)
    {

        premiere_colonne = atoi(strtok(donnees, ";"));

        deuxieme_colonne = atoi(strtok(NULL, ";"));


        if (premiere_colonne>max)
        {
            max = premiere_colonne;
            tps = deuxieme_colonne;
        }

    }

    printf("Maximum: [%d] \t Temps: [%d millisecondes]\n", max, tps);
    printf("\n");

    fclose(fp);
}

/*--------------------------------FONCTION MIN POULS--------------------------------*/

void MinPouls()
{
    FILE *fp = fopen("Battements.csv", "r+");

    if (fp == NULL){
        fclose(fp);
        exit(1);
    }

    int min = 200000;
    int tps, premiere_colonne, deuxieme_colonne;

    char donnees[100];
    while (fgets(donnees, 100, fp) != NULL)
    {

        premiere_colonne = atoi(strtok(donnees, ";"));
        deuxieme_colonne = atoi(strtok(NULL, ";"));

          if (premiere_colonne<min)
        {
            min = premiere_colonne;
            tps = deuxieme_colonne;
        }

    }

    printf("\nMinimum: [%d] \t Temps: [%d millisecondes]\n", min, tps);
    printf("\n");

    fclose(fp);
}

/*--------------------------------FONCTION RECHERCHE POULS--------------------------------*/

void RecherchePouls()
{

    int tpsrech;

    FILE *fp = fopen("Battements.csv", "r+");

    if (fp == NULL){
        fclose(fp);
        exit(1);
    }

    printf("A quel temps voulez-vous connaitre la pulsation? \t");
    scanf("%d", &tpsrech);
    printf("\n");

    int premiere_colonne, deuxieme_colonne;

    char donnees[100];
    while (fgets(donnees, 100, fp) != NULL)
    {

        premiere_colonne = atoi(strtok(donnees, ";"));
        deuxieme_colonne = atoi(strtok(NULL, ";"));

        if (tpsrech == deuxieme_colonne)
        {
            printf("Temps: [%d]\n", deuxieme_colonne);
            printf("Pouls: [%d]\t \n", premiere_colonne);
            printf("\n");
        }

    }

    fclose(fp);
}

/*--------------------------------FONCTION RECHERCHE TEMPS--------------------------------*/

void RechercheTemps()
{

    int pulsrech;

    FILE *fp = fopen("Battements.csv", "r+");

    if (fp == NULL){
        fclose(fp);
        exit(1);
    }

    printf("A quelle pulsation voulez-vous connaitre le temps? \t");
    scanf("%d", &pulsrech);
    printf("\n");

    int premiere_colonne, deuxieme_colonne;

    char donnees[100];
    while (fgets(donnees, 100, fp) != NULL)
    {

        premiere_colonne = atoi(strtok(donnees, ";"));
        deuxieme_colonne = atoi(strtok(NULL, ";"));

        if (pulsrech == premiere_colonne)
        {
            printf("Pouls: [%d]\n", premiere_colonne);
            printf("Temps: [%d]\t \n", deuxieme_colonne);
            printf("\n");
        }

    }

    fclose(fp);
}

/*--------------------------------FONCTION MOYENNE POULS--------------------------------*/

void MoyennePouls()

{

    int premiere_colonne, deuxieme_colonne;
    float moyenne;
    float nb_elem = 0;
    float total;

    FILE *fp = fopen("Battements.csv", "r+");

    if (fp == NULL){
        fclose(fp);
        exit(1);
    }

    char donnees[100];
    while (fgets(donnees, 100, fp) != NULL)
    {

        premiere_colonne = atoi(strtok(donnees, ";"));
        deuxieme_colonne = atoi(strtok(NULL, ";"));


        total = total + atoi(strtok(donnees, ";"));

        nb_elem++;

    }

    moyenne = total / nb_elem ;

    printf("La somme de l'ensemble des pouls est : [%f].\n", total);
    printf("Nous avons egalement [%f] elements.\n", nb_elem);
    printf("\n");
    printf("La moyenne du pouls est donc: [%f] .\n", moyenne);

    fclose(fp);
}

/*--------------------------------FONCTION TRI POULS CROISSANT--------------------------------*/

void TriPoulsCroissant()
{

    FILE *fp = fopen("Battements.csv", "r+");

    if (fp == NULL){
        fclose(fp);
        exit(1);
    }

    int min = 200000;
    int tps, premiere_colonne, deuxieme_colonne;
    int nb_elem = 0;

    char donnees[100];
    int tab[100];
    int i = 0;
    int j = 0;
    int temp, tri;

        while (fgets(donnees, 100, fp) != NULL)
        {
            premiere_colonne = atoi(strtok(donnees, ";"));
            deuxieme_colonne = atoi(strtok(NULL, ";"));

            tab[i] = premiere_colonne;
            i++;
            nb_elem++;
        }

    do
    {
        tri = 0;
        for(i=1;i<nb_elem-j;i++)
        {
            if(tab[i-1]>tab[i])
            {
                temp = tab[i-1];
                tab[i-1] = tab[i];
                tab[i] = temp;
                tri = 1;
            }
        }
        j++;
    }
    while(tri);

    for (i=0;i<nb_elem;i++)
    {
        printf("[%d]\n", tab[i]);
    }

    fclose(fp);
}

/*--------------------------------FONCTION TRI POULS DECROISSANT--------------------------------*/

void TriPoulsDecroissant()
{

    FILE *fp = fopen("Battements.csv", "r+");

    if (fp == NULL){
        fclose(fp);
        exit(1);
    }

    int min = 200000;
    int tps, premiere_colonne, deuxieme_colonne;
    int nb_elem = 0;

    char donnees[100];
    int tab[100];
    int i = 0;
    int j = 0;
    int temp, tri;

        while (fgets(donnees, 100, fp) != NULL)
        {

            premiere_colonne = atoi(strtok(donnees, ";"));
            deuxieme_colonne = atoi(strtok(NULL, ";"));

            tab[i] = premiere_colonne;
            i++;
            nb_elem++;
        }

    do
    {
        tri = 0;
        for(i=1;i<nb_elem-j;i++)
        {
            if(tab[i-1]<tab[i])
            {
                temp = tab[i-1];
                tab[i-1] = tab[i];
                tab[i] = temp;
                tri = 1;
            }
        }
        j++;
    }
    while(tri);

    for (i=0;i<nb_elem;i++)
    {
        printf("[%d]\n", tab[i]);
    }

    fclose(fp);
}

/*--------------------------------FONCTION TRI TEMPS CROISSANT--------------------------------*/

void TriTempsCroissant()
{

    FILE *fp = fopen("Battements.csv", "r+");

    if (fp == NULL){
        fclose(fp);
        exit(1);
    }

    int min = 200000;
    int tps, premiere_colonne, deuxieme_colonne;
    int nb_elem = 0;

    char donnees[100];
    int tab[100];
    int i = 0;
    int j = 0;
    int temp, tri;

        while (fgets(donnees, 100, fp) != NULL)
        {

            premiere_colonne = atoi(strtok(donnees, ";"));
            deuxieme_colonne = atoi(strtok(NULL, ";"));
            
            tab[i] = deuxieme_colonne;
            i++;
            nb_elem++;
        }

    do
    {
        tri = 0;
        for(i=1;i<nb_elem-j;i++)
        {
            if(tab[i-1]<tab[i])
            {
                temp = tab[i-1];
                tab[i-1] = tab[i];
                tab[i] = temp;
                tri = 1;
            }
        }
        j++;
    }
    while(tri);

    for (i=0;i<nb_elem;i++)
    {
        printf("[%d]\n", tab[i]);
    }

    fclose(fp);
}

/*--------------------------------FONCTION TRI TEMPS DECROISSANT--------------------------------*/

void TriTempsDecroissant()
{

    FILE *fp = fopen("Battements.csv", "r+");

    if (fp == NULL){
        fclose(fp);
        exit(1);
    }

    int min = 200000;
    int tps, premiere_colonne, deuxieme_colonne;
    int nb_elem = 0;

    char donnees[100];
    int tab[100];
    int i = 0;
    int j = 0;
    int temp, tri;

        while (fgets(donnees, 100, fp) != NULL)
        {

            premiere_colonne = atoi(strtok(donnees, ";"));
            deuxieme_colonne = atoi(strtok(NULL, ";"));

            tab[i] = deuxieme_colonne;
            i++;
            nb_elem++;
        }

    do
    {
        tri = 0;
        for(i=1;i<nb_elem-j;i++)
        {
            if(tab[i-1]<tab[i])
            {
                temp = tab[i-1];
                tab[i-1] = tab[i];
                tab[i] = temp;
                tri = 1;
            }
        }
        j++;
    }
    while(tri);

    for (i=0;i<nb_elem;i++)
    {
        printf("[%d]\n", tab[i]);
    }

    fclose(fp);
}