#ifndef __DONNEES__H__
#define __DONNEES__H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------------DEFINITION DU BOOLEEN----------------*/

typedef enum
{
    false,
    true
}Bool;

/*----------------STRUCTURE DE DONNEE----------------*/

typedef struct mesures 
{
    int Pouls;
    int Temps;
} mesures;

/*----------------DEFINITION DE LA FILE----------------*/

typedef struct File 
{
    int value;
    struct File *next;
}File;

/*----------------PARAMETRES DE LA FILE----------------*/

static File *first = NULL;
static File *last = NULL;
static int NombreElements = 0;

/*----------------PROTOTYPES DES FONCTIONS DE LA FILE----------------*/

Bool is_empty_File(void);
int File_length(void);
int File_first(void);
int File_last(void);
void print_file(void);
void push_file(int pouls);
void pop_file(void);
void clear_file(void);

#endif
