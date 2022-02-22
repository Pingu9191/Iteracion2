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

struct _Set {
    int n_ids;
    Id ids[MAX_IDS];
};

/*
* Creates a new set to save ids
*/
Set *set_create() 
{

    int i = 0;
    /*Creates a pointer to a set and allocates memory for it, returning NULL in case of error*/
    Set *newSet = NULL;

    newSet = (Set *) malloc(sizeof (Set));
    if (newSet == NULL) {
        return NULL;
    }

    /* Initialization of an empty set*/
    newSet->n_ids = NO_ID + 1;
    for (i = 0; i < MAX_IDS; i++) {
        newSet->ids[i] = NO_ID;
    }

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
* Adds an id to a given set
*/
STATUS set_add_id (Set *set, Id id)
{
    /*Error control*/
    if ((!set) || (!id)) {
        return ERROR;
    }

    /*Checks if it has found any space, and if not it returns ERROR. In case it has, it saves the id in the new space, that corresponds in the array to the number of ids already saved*/
    if (set->n_ids >= MAX_IDS) {
        return ERROR;
    } else {
        set->ids[set->n_ids] = id;
        set->n_ids++;
    }

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
    while (set->ids[i] != id && i < MAX_IDS) {
        i++;
    }

    /*If it has not located the position, it reaches MAX_IDS and returns ERROR*/
    if ( i == MAX_IDS) {
        return ERROR;
    }

    set->ids[i] = NO_ID;

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
        return ERROR;
    }


    /*Checks the position where the id coincides*/
    while (set->ids[i] != id && i < MAX_IDS) {
        i++;
    }

    /*If it has not located the position, it reaches MAX_IDS and returns ERROR*/
    if ( i == MAX_IDS) {
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

//Funcion para ver si un set esta lleno(añadida temporalmente, creo que puede ser útil)
BOOL set_is_full(Set *set)
{
    /*Error control (esta implementado con false ya que si el set es NULL, aunque no este bien, ese set está vacio*/
    if (!set) {
        return FALSE;
    }

    /*Comprueba que esta lleno*/
    if (set->n_ids == MAX_IDS) {
        return TRUE;
    } else {
        return FALSE;
    }
}
