#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actions.h"

// "atoi" permet de convertir un string en int
// "strtok" nous permet de séparer une chaîne de charactères en tokens grâce à un délimiteur (ici ";" )

/*--------------------------------FONCTION AFFICHER DONNEES--------------------------------*/

void AfficherDonnees()
{
    FILE *fp = fopen("Battements.csv", "r+"); //Ouverture du fichier .csv : Battements enregistré avec le programme .pde

    if (fp == NULL){ //Mesure de sécurité si jamais le fichier est inexistant
        fclose(fp);
        exit(1);
    }

    char donnees[100]; //Creation d'un tableau donnees contenant 100 char
    printf("Donnees     Temps\n");
    while (fgets(donnees, 100, fp) != NULL) //Temps que la lecture du fichier n'arrive pas à la fin de celui-ci :
    {
        printf("[%d]", atoi(strtok(donnees, ";"))); //Affiche le contenu de la ligne avant le point-virgule
        printf("\t");
        printf("    [%d]\n", atoi(strtok(NULL, ";"))); //Affiche le contenu de la ligne avant le point-virgule
    }
    printf("\n");

    fclose(fp); //Fermeture du fichier
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


        if (premiere_colonne>max) //Dès que la valeur du pouls est supérieure à la précédente :
        {
            max = premiere_colonne; //On attribue à la var max la valeur du pouls
            tps = deuxieme_colonne; //On attribue à la var tps le temps associé au pouls
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

          if (premiere_colonne<min) //Dès que la valeur du pouls est inférieure à la précédente :
        {
            min = premiere_colonne; //On attribue à la var min la valeur du pouls
            tps = deuxieme_colonne; //On attribue à la var tps le temps associé au pouls
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
    scanf("%d", &tpsrech); //On attribue à la var tpsrech le temps saisi par l'utilisateur pour trouver le pouls correspondant
    printf("\n");

    int premiere_colonne, deuxieme_colonne;

    char donnees[100];
    while (fgets(donnees, 100, fp) != NULL)
    {

        premiere_colonne = atoi(strtok(donnees, ";"));
        deuxieme_colonne = atoi(strtok(NULL, ";"));

        if (tpsrech == deuxieme_colonne) //Si le temps recherché est le même que le fichier a trouvé lors de sa lecture :
        {
            printf("Temps: [%d]\n", deuxieme_colonne); //On affiche le temps
            printf("Pouls: [%d]\t \n", premiere_colonne); //Et le pouls correspondant
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
    scanf("%d", &pulsrech); //On attribue à la valeur pulsrech le pouls saisi par l'utilisateur dont il veut savoir le temps correspondant
    printf("\n");

    int premiere_colonne, deuxieme_colonne;

    char donnees[100];
    while (fgets(donnees, 100, fp) != NULL)
    {

        premiere_colonne = atoi(strtok(donnees, ";"));
        deuxieme_colonne = atoi(strtok(NULL, ";"));

        if (pulsrech == premiere_colonne) //Si le pouls saisi est le même que le pouls
        {
            printf("Pouls: [%d]\n", premiere_colonne); //On affiche la valeur du pouls
            printf("Temps: [%d]\t \n", deuxieme_colonne); //Et le temps associé
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


        total = total + atoi(strtok(donnees, ";")); //Ceci calcule la somme des pouls entre eux

        nb_elem++; //On compte le nombre d'elements dans le fichier csv (correspond au nombre de lignes)

    }

    moyenne = total / nb_elem ; //Calcul de la moyenne

    printf("La somme de l'ensemble des pouls est : [%f].\n", total); //Affichage du pouls total (somme)
    printf("Nous avons egalement [%f] elements.\n", nb_elem); //Affichage du nombre d'éléments totaux
    printf("\n");
    printf("La moyenne du pouls est donc: [%f] .\n", moyenne); //Affichage de la moyenne

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

    //Initialisation des tab et des var
    char donnees[100];
    int tab[100];
    int i = 0;
    int j = 0;
    int temp, tri;

        while (fgets(donnees, 100, fp) != NULL) //Lecture du fichier
        {
            premiere_colonne = atoi(strtok(donnees, ";"));
            deuxieme_colonne = atoi(strtok(NULL, ";"));

            tab[i] = premiere_colonne; //On insère la valeur lue à un certain indice du tableau
            i++; //Qui change ici à chaque ligne (++)
            nb_elem++; //Comptage du nombre d'éléments nous permettra d'afficher par la suite les membres du tableau
        }

    do
    {
        tri = 0;
        for(i=1;i<nb_elem-j;i++) //Tri à bulles
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

    for (i=0;i<nb_elem;i++) //Affichage du tableau
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
