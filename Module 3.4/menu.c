#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donnees.h"
#include "actions.h"
#include "generationCode.h"
#include "menu.h"

void MenuPrincipal()
{
    /*------------------------------------------VARIABLES MENU------------------------------------------*/

    void MenuPrincipal()
{
    /*------------------------------------------VARIABLES MENU------------------------------------------*/

    int menu; //variable qui va nous permettre de gérer l'affichage du menu

    /*------------------------------------------AFFICHAGE MENU------------------------------------------*/

    printf("\t\tProjet HeXart Care - Un coeur qui bat au rythme de vos reves\n");
    printf("\n");
    printf("\t\t\t\t\tMenu principal\n");
    printf("\n");
    printf ("Entrez une valeur pour menu \n");
    printf("\n");
    printf ("0 : Quitter l'application\n");
    printf ("1 : Notice d'utilisation\n");
    printf ("2 : Menu du choix d'allumage des LED\n");
    printf ("3 : Menu du choix d'actions sur le fichier\n");
    printf ("\n");

    /*------------------------------------FONCTIONS ET ACTIONS DU MENU------------------------------------*/

    scanf ("%d", &menu); //demande la valeur de la variable du menu
    printf("Vous avez choisi la valeur %d pour le menu\n", menu);
    printf("\n");

    switch(menu)
    {
        case 0 : //valeur qui ne correspond pas à une fonction, elle correspond à une sortie de programme
            printf("Sortie de l'application\n");
            printf("\n");
            exit(EXIT_SUCCESS);
            break;

        case 1 : 
            printf("Redirection vers la notice d'utilisation\n");
            printf("\n");
            NoticeUtilisation(); 
            break;

        case 2 : 
            printf("Redirection vers le menu de choix du fonctionnement des LED\n");
            printf("\n");
            MenuChoixLED(); 
            break;

        case 3 : 
            printf("Redirection vers le menu d'interaction avec le fichier\n"); 
            printf("\n");
            MenuActionsFichier();
            break;
    }
}
    
void NoticeUtilisation()
{
    /*------------------------------------------VARIABLES MENU------------------------------------------*/

    int quitter;

    /*------------------------------------------AFFICHAGE MENU------------------------------------------*/

    printf ("\t\t\tNotice d'utilisation de l'outil HeXart Care\n");
    printf ("\n");
    printf ("\t Cet outil vous est propose par le groupe 8 du centre CESI Exia de Strasbourg\n");
    printf ("\t     COSTEIRA Jaime \t AMARY Clement \t KLEIN Lucien \t GIRARDI Guillaume \t\n");
    printf ("\n");
    printf ("1 - Choisissez une configuration pour l'affichage de vos LED dans le menu principal\n");
    printf ("2 - Mettez votre doigt en place dans la pince\n");
    printf ("3 - Allez sur le programme Arduino\n");
    printf ("4 - Televersez le programme\n");
    printf ("5 - Attendez un certain temps afin que les mesures se fassent\n");
    printf ("6 - Retirez votre doigt de la pince\n");
    printf ("7 - Retournez sur le programme C et allez dans le menu d'actions\n");
    printf ("8 - Selectionnez les actions que vous voulez réaliser\n");
    printf ("\n");

    printf ("Entrez la valeur 0 pour quitter cette notice\n");
    scanf ("%d", &quitter);
    if (quitter == 0);
    {
        MenuPrincipal();
    }
}

void MenuChoixLED()
{
    /*------------------------------------------VARIABLES MENU------------------------------------------*/

    int choix; //variable qui va nous permettre de gérer l'affichage du menu

    /*------------------------------------------AFFICHAGE MENU------------------------------------------*/

    printf("\t\t\t\tEntrez une valeur pour le type d'allumage des LED \n");
    printf("\n");
    printf("0 : Quitter le menu \n");
    printf("1 : Clignotement de toutes les LED\n");
    printf("2 : Clignotement de 1 LED sur 2\n");
    printf("3 : Clignotement de 1 LED sur 3\n");
    printf("4 : Clignotement en chenille\n");
    printf("5 : Clignotement en chenille avec effet de fondu\n");
    printf("6 : Clignotement de 1 LED sur 2 en mode alternatif\n");
    printf("7 : Clignotement en chenille boucle\n");
    printf("\n");

    /*------------------------------------FONCTIONS ET ACTIONS DU MENU------------------------------------*/

    scanf("%d", &choix); //demande la valeur de la variable du menu
    printf("Vous avez choisi la valeur %d pour le menu\n", choix);
    printf("\n");
    if (choix > 0 && choix < 8)
    {
        generationCode(choix);
    }
    else if (choix == 0)
    {
        MenuPrincipal();
    }
    else
    {
        printf("ERREUR, retour au menu principal\n");
        MenuPrincipal();
    }
}

void MenuActionsFichier()
{
    /*------------------------------------------VARIABLES MENU------------------------------------------*/

    int menu; //variable qui va nous permettre de gérer l'affichage du menu
    int x;    //variable du pouls dans la file

    /*------------------------------------------AFFICHAGE MENU------------------------------------------*/
    
    printf("\t\t\t\tMenu du choix des actions\n");
    printf("\n");
    printf("Entrez une valeur pour menu \n");
    printf("\n");
    printf(" 0 : Quitter le menu \n");
    printf(" 1 : Ajouter une valeur \n");
    printf(" 2 : Afficher la taille de la file \n");
    printf(" 3 : Supprimer l'element superieur de la file\n");
    printf(" 4 : Nettoyer la file\n");
    printf(" 5 : Ecrire la file\n");
    printf(" 6 : Afficher les données contenues dans le fichier\n");
    printf(" 7 : Afficher la valeur maximum du pouls mesure\n");
    printf(" 8 : Afficher la valeur minimum du pouls mesure\n");
    printf(" 9 : Rechercher un pouls precis dans le fichier\n");
    printf("10 : Rechercher un temps precis dans le fichier\n");
    printf("11 : Calculer la moyenne des pouls present dans le fichier\n");
    printf("12 : Trier les valeurs du pouls dans l'ordre croissant\n");
    printf("13 : Trier les valeurs du pouls dans l'ordre decroissant\n");
    printf("14 : Trier les valeurs du temps dans l'ordre croissant\n");
    printf("15 : Trier les valeurs du temps dans l'ordre decroissant\n");
    printf("\n");

    /*------------------------------------FONCTIONS ET ACTIONS DU MENU------------------------------------*/

    do
    {

        scanf("%d", &menu); //demande la valeur de la variable du menu
        printf("Vous avez choisi la valeur %d pour le menu\n", menu);
        printf("\n");

        switch (menu)
        {
        case 0: //valeur qui ne correspond pas à une fonction, elle correspond à une sortie de programme
            printf("Sortie du menu, retour au menu principal\n");
            printf("\n");
            MenuPrincipal();
            break;

        case 1: //ajouter un élément
            printf("Entrez la valeur du pouls que vous venez de mesurer\n");
            printf("\n");
            scanf("%d", &x);
            push_file(x); //appel de la fonction pushfile qui ajoute l'élément [x] donné dans la file
            printf("vous avez rentre la valeur [%d] dans la pile\n", x);
            printf("\n");
            break;

        case 2:                                                //affiche le nombre de données en mémoire
            printf("Taille de la file : %d\n", File_length()); //appelle la fonction filelength qui calcule la taille de la file et donc du nombre de données en mémoire
            printf("\n");
            break;

        case 3: //supprimer un élément de la file
            printf("On supprime l'element situe en premier dans la liste\n");
            printf("\n");
            pop_file();
            break;

        case 4: //supprimer tous les éléments de la file
            printf("Nettoyage de la file\n");
            printf("\n");
            clear_file(); //appel de la fonction clearfile qui supprime les éléments de manière récursive
            break;

        case 5: //affiche la file dans la console
            printf("Affichage de la file\n");
            printf("\n");
            print_file(); //appel de la foncton print_file qui écrit la file
            break;

        case 6: //affiche les données dans la console
            printf("Affichage des donnees du fichier\n");
            printf("\n");
            AfficherDonnees();
            break;

        case 7: //affiche la valeur maximale du pouls dans la console
            printf("Affichage de la valeur maximale du pouls mesure\n");
            printf("\n");
            MaxPouls();
            break;

        case 8: //affiche la valeur minimale du pouls dans la console
            printf("Affichage de la valeur minimale du pouls mesure\n");
            printf("\n");
            MinPouls();
            break;

        case 9: //recherche un pouls dans le fichier
            printf("Recherche d'un pouls précis dans le fichier\n");
            printf("\n");
            RecherchePouls();
            break;

        case 10: //recherche un temps dans le fichier
            printf("Recherche d'un temps précis dans le fichier\n");
            printf("\n");
            RechercheTemps();
            break;

        case 11: //calcule la moyenne du total des pouls du fichier
            MoyennePouls();
            break;

        case 12: //trie les données du pouls dans l'ordre croissant
            printf("Tri des valeurs du pouls dans l'ordre croissant\n");
            printf("\n");
            TriPoulsCroissant();
            printf("\n");
            break;

        case 13: //trie les données du pouls dans l'ordre décroissant
            printf("Tri des valeurs du pouls dans l'ordre decroissant\n");
            printf("\n");
            TriPoulsDecroissant();
            printf("\n");
            break;

        case 14: //trie les données du temps dans l'ordre croissant
            printf("Tri des valeurs du temps dans l'ordre croissant\n");
            printf("\n");
            TriTempsCroissant();
            printf("\n");
            break;

        case 15: //trie les données du temps dans l'ordre décroissant
            printf("Tri des valeurs du temps dans l'ordre decroissant\n");
            printf("\n");
            TriTempsDecroissant();
            printf("\n");
            break;
        }
    } while (menu < 16);
}
