#include <stdlib.h>
#include <stdio.h>
#include "donnees.h"

int main(void)
{   
    int oui;
    push_file(15);
    push_file(24);
    push_file(21);
    push_file(17);
    push_file(18);
    push_file(12);
    push_file(26);
    push_file(18);
    push_file(17);
    push_file(18);
    push_file(20);
    push_file(23);
    push_file(17);
    push_file(25);
    push_file(18);

    printf("Taille de la file : %d\n", File_length());
    printf("\n");

    print_file();

    pop_file();
    pop_file();
    pop_file();
    pop_file();
    pop_file();

    printf("Taille de la file : %d\n", File_length());
    printf("\n");

    print_file();

    clear_file();

    print_file();

    scanf("%d", &oui);

    return 0;
}