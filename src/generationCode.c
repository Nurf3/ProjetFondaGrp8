#include <stdio.h>
#include <stdlib.h>

int generationCode(int choix)
{
    char *fonction[100];
    FILE *fichier = NULL;

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

    fichier = fopen("src/param.h", "w");

    if (fichier != NULL)
    {
        fprintf(fichier, "#ifndef __COEUR__\n#define __COEUR__\n\n%s\n\n#endif", *fonction);
        fclose(fichier);
    }

    else
    {
        printf("Impossible d'ouvrir le fichier param.h");
    }
}