
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donnees.h"

/*-----------------------------------------------------------------------*/

Bool is_empty_File(void)
{
    if(first == NULL && last == NULL) 
        {
            return true;
        }
    else
    {
        return false;
    }
}

/*------------------------------------------------*/

int File_length()
{
    return NombreElements;
}

/*------------------------------------------------*/

int File_first()
{
    if(is_empty_File())
        exit(1);

    return first->value;
}

/*------------------------------------------------*/

int File_last()
{
    if(is_empty_File())
        exit(1);

    return last->value;
}

/*------------------------------------------------*/

void print_file()
{
    if(is_empty_File())
    {
        printf("File vide\n");
        return;
    }

    File *temp = first;

    while(temp != NULL)
    {
        printf("Pouls mesure : [%d]\n", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

/*------------------------------------------------*/

void push_file(int x)
{
    File *element;

    element = malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr, "Erreur\n");
        exit(EXIT_FAILURE);
    }

    element->value = x;
    element->next = NULL;

    if(is_empty_File())
    {
        first = element;
        last = element;
    }
    else
    {
        last->next = element;
        last = element;
    }

    NombreElements++;
}

/*------------------------------------------------*/

void pop_file()
{
    if(is_empty_File())
    {
        printf("File vide\n");
        return;
    }

    File *temp = first;

    if(first == last)
    {
        first = NULL;
        last = NULL;
    }
    else
        first = first->next;

    free(temp);
    NombreElements--;
}

/*------------------------------------------------*/

void clear_file()
{
    if(is_empty_File())
    {
        printf("File vide\n");
        return;
    }

    while(!is_empty_File())
        pop_file();
}


