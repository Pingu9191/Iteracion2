/** 
 * @brief It implements the set module
 * 
 * @file set.c
 * @author Nicolas Victorino 
 * @version 1.0
 * @date 21-02-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "set.h"

//Tengo que cambiar las funciones para encontrar el id  y el add space con realloc

struct _Set {
    int n_ids;
    Id *ids;
};

/*
* Creates a new set to save ids
*/
Set *set_create() 
{

    /*Creates a pointer to a set and allocates memory for it, returning NULL in case of error*/
    Set *newSet = NULL;

    newSet = (Set *) malloc(sizeof (Set));
    if (newSet == NULL) {
        return NULL;
    }

    /* Initialization of an empty set*/
    newSet->n_ids = NO_ID + 1;
    newSet->ids = NULL;

  return newSet;
}

/*
* Destroys a given set
*/
STATUS set_destroy (Set *set) 
{
    /*Error control*/
    if (!set) {
        return ERROR;
    }

    free(set);
    set = NULL;

    return OK;
}

/*
* Adds an id to a given set, reallocating memory for it and locating the first empty space
*/
STATUS set_add_id (Set *set, Id id)
{
    int i = 0;

    /*Error control*/
    if ((!set) || (!id)) {
        return ERROR;
    }

    Id *new_ids;

    if (!(new_ids = (Id *)realloc(set->ids, set->n_ids * sizeof(Id)))) {
        return ERROR;
    }

    while (i < set->n_ids && (set->ids[i] != NULL)) {
        i++;
    }

    set->ids[i] = id;
    set->n_ids++;

    return OK;
}

/*
* Deletes a given id of a set
*/
STATUS set_del_id (Set *set, Id id)
{
    int i = 0;

    /*Error control*/
    if ((!set) || (!id)) {
        return ERROR;
    }

    /*Checks the position where the id coincides*/
    while ((set->ids[i] != id) && i < set->n_ids) {
        i++;
    }

    /*If it has not located the position, it reaches n_ids and returns ERROR*/
    if ( i == set->n_ids) {
        return ERROR;
    }

    set->ids[i] = set->ids[set->n_ids - 1];
    set->ids[set->n_ids - 1] = NO_ID;
    set->n_ids--;

    return OK;
}

/*
* Prints all the ids saved in a set (for debbuging purpouses)
*/
STATUS set_print(Set *set)
{
    int i = 0;

    /*Error control*/
    if (!set) {
        return ERROR;
    }

    /*Prints the number of ids saved the set*/
    fprintf(stdout, "-Number of ids saved: %d\n", set->n_ids);

    /*Prints all the ids saved*/
    for (i= 0; i < set->n_ids; i++) {
        fprintf(stdout, "Id %d: %ld \n", i+1, set->ids[i]);
    }

    return OK;
}

//Funcion para ver si una id dada se encuentra en el set (añadida temporalmente, creo que puede ser útil)
BOOL set_idInSet (Set* set, Id id)
{
    int i = 0; 

    /*Error control*/
    if ((!set) || (!id)) {
        return FALSE;
    }


    /*Checks the position where the id coincides*/
    while (set->ids[i] != id && i < set->n_ids) {
        i++;
    }

    /*If it has not located the position, it reaches MAX_IDS and returns ERROR*/
    if ( i == set->n_ids) {
        return FALSE;
    } else {
        return TRUE;
    }
}

//Funcion para ver si un set esta vacio(añadida temporalmente, creo que puede ser útil)
BOOL set_is_empty(Set *set)
{
    /*Error control (esta implementado con true ya que si el set es NULL, aunque no este bien, ese set está vacio*/
    if (!set) {
        return TRUE;
    }

    /*Comprueba que esta vacio*/
    if (set->n_ids == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int set_get_n_ids(Set* set) {
    if (!set) {
        return NO_ID;
    }

    return set->n_ids;
}
