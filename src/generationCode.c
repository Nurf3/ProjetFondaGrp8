//
// Created by lucie on 14/11/2018.
//

#include "generationCode.h"
#include "param.h"
#include <stdio.h>
#include <stdlib.h>

void generationCode(int choix)
{
    FILE *fichier = NULL;

    //Ouverture du fichier param.h en mode écrirture
    fichier = fopen("src/param.h", "w");

    //Vérification si le fichier c'est bien ouvert
    if (fichier != NULL)
    {
        //Ecriture dans le fichier les prototype puis fermeture du fichier
        fprintf(fichier, "#ifndef __MODULE__\n#define __MODULE__\n\nconst int utilisation = %d;\n\n#endif", choix);
        fclose(fichier);
    }

    else
    {
        //Si le fichier c'est mal ouvert, affichage d'un message d'erreur
        printf("Impossible d'ouvrir le fichier param.h");
    }
}
