#include <stdio.h>
#include <stdlib.h>

int generationCode(int choix)
{
    char *fonction[100];
    FILE *fichier = NULL;

    switch (choix)
    {
    case 1:
        *fonction = "\nint allum();\nvoid coeur1();\n";
        break;
    case 2:
        *fonction = "\nint allum();\nvoid coeur2();\n";
        break;
    case 3:
        *fonction = "\nint allum();\nvoid coeur3();\n";
        break;
    case 4:
        *fonction = "\nvoid coeur4();\n";
        break;
    case 5:
        *fonction = "\nvoid coeur5();\n";
        break;
    }

    fichier = fopen("src/param.h", "w");

    if (fichier != NULL)
    {
        fprintf(fichier, "#ifndef COEUR\n#define COEUR\n%s\n#endif", *fonction);
        fclose(fichier);
    }

    else
    {
        printf("Impossible d'ouvrir le fichier param.h");
    }
}