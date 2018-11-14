#include <stdio.h>
#include <stdlib.h>

int generationCode(int choix)
{
    char *fonction[100];
    FILE *fichier = NULL;

    //On définie le valeur de fonction d'après le choix de l'utilisateur
    switch (choix)
    {
    case 1:
        *fonction = "int allum();\nvoid coeur1();";
        break;
    case 2:
        *fonction = "int allum();\nvoid coeur2();";
        break;
    case 3:
        *fonction = "int allum();\nvoid coeur3();";
        break;
    case 4:
        *fonction = "void coeur4();";
        break;
    case 5:
        *fonction = "void coeur5();";
        break;
    }

    //Ouverture du fichier param.h en mode écrirture
    fichier = fopen("src/param.h", "w");

    //Vérification si le fichier c'est bien ouvert
    if (fichier != NULL)
    {
        //Ecriture dans le fichier les prototype puis fermeture du fichier
        fprintf(fichier, "#ifndef __COEUR__\n#define __COEUR__\n\n%s\n\n#endif", *fonction);
        fclose(fichier);
    }

    else
    {
        //Si le fichier c'est mal ouvert, affichage d'un message d'erreur
        printf("Impossible d'ouvrir le fichier param.h");
    }
}